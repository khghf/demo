// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Hero/WarriorHeroAnimInstance.h"

#include<Kismet/KismetMathLibrary.h>
#include<Characters/HeroCharacter.h>
#include<GameFramework/CharacterMovementComponent.h>
#include<WarriorGameplayTags.h>
#include<WarriorFunctionLibrary.h>
UWarriorHeroAnimInstance::UWarriorHeroAnimInstance()
{
	bUseMultiThreadedAnimationUpdate = true;
}

void UWarriorHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (OwningCharacter)
	{
		OwnningHeroCharacter = Cast<AHeroCharacter>(OwningCharacter);
	}
}
void UWarriorHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	if (!OwnningHeroCharacter||!OwningMovementComponent)return;
	DeltaTime = DeltaSeconds;
	UpdateLocationData();
	UpdateRotationData();
	UpdateVelocityData();
	UpdateAccelerationData();
	UpdateWallDetectionHeuristic();
	UpdateCharacterMovementState();
	UpdateTurnInPlaceData();
	UpdateGroundDistance();
	bIsFirstUpdate = false;
}



void UWarriorHeroAnimInstance::UpdateLocationData()
{

	if (bIsFirstUpdate)return;
	DisplacementSinceLastUpdate = (OwnningHeroCharacter->GetActorLocation() - WorldLocation).Size2D();
	WorldLocation = OwnningHeroCharacter->GetActorLocation();
	DisplacementSpeed = UKismetMathLibrary::SafeDivide(DisplacementSinceLastUpdate, DeltaTime);
}

void UWarriorHeroAnimInstance::UpdateRotationData()
{
	YawDeltaSinceLastUpdate = (OwningCharacter->GetActorRotation() - WorldRotation).Yaw;
	WorldRotation = OwningCharacter->GetActorRotation();
	if (bIsFirstUpdate)
	{
		YawDeltaSinceLastUpdate = 0.f;
	}
	
}

void UWarriorHeroAnimInstance::UpdateVelocityData()
{
	bWasMovingLastUpdate = !LocalVelocity2D.IsNearlyZero();
	WorldVelocity = OwningMovementComponent->Velocity;
	WorldVelocity2D = FVector(WorldVelocity.X, WorldVelocity.Y, 0.f);
	LocalVelocity2D = UKismetMathLibrary::Quat_UnrotateVector(WorldRotation.Quaternion(), WorldVelocity2D);
	bHasVelocity = !UKismetMathLibrary::NearlyEqual_FloatFloat(LocalVelocity2D.Size2D(), 0.f);
	LocalVelocityDirectionAngle = UKismetMathLibrary::NormalizedDeltaRotator(WorldVelocity.Rotation(), WorldRotation).Yaw;
	LocalVelocityDirection = SelectCardinalDirectionalFromAngle(LocalVelocityDirectionAngle, 10.f, LocalVelocityDirection, bWasMovingLastUpdate);
	LocalVelocityDirectionNoOffset = SelectCardinalDirectionalFromAngle(LocalVelocityDirectionAngle, 10.f, LocalVelocityDirectionNoOffset, bWasMovingLastUpdate);
}

void UWarriorHeroAnimInstance::UpdateAccelerationData()
{
	WorldAcceleration2D = OwningMovementComponent->GetCurrentAcceleration() * FVector(1.f, 1.f, 0.f);
	LocalAcceleration2D = UKismetMathLibrary::Quat_UnrotateVector(WorldRotation.Quaternion(), WorldAcceleration2D);
	bHasAcceleration = !UKismetMathLibrary::NearlyEqual_FloatFloat(LocalAcceleration2D.Size2D(), 0.f);
	//基于加速度计算一个用于Pivot运动的主要方向
	PivotDirection2D = UKismetMathLibrary::VLerp(PivotDirection2D, WorldAcceleration2D.GetSafeNormal(), 0.5f).GetSafeNormal();
	const float PivotAngle = UKismetMathLibrary::NormalizedDeltaRotator(PivotDirection2D.Rotation(), WorldRotation).Yaw;
	CardinalDirectionFromAcceleration = GetOppositeCaridinalDirection(SelectCardinalDirectionalFromAngle(PivotAngle, 10.f, ECardinalDirection::Forward, false));
}

void UWarriorHeroAnimInstance::UpdateWallDetectionHeuristic()
{
	//该逻辑通过检查速度和加速度之间是否有很大的角度（即角色正在向墙壁推，但实际上滑向一侧）
	// 以及角色是否试图加速但速度相对较低来猜测角色是否撞到了墙上。
	bIsRunningIntoWall = LocalAcceleration2D.Size2D() > 0.1f;
	bIsRunningIntoWall = bIsRunningIntoWall && LocalVelocity2D.Size2D() < 200.f;
	bIsRunningIntoWall = bIsRunningIntoWall &&
		UKismetMathLibrary::InRange_FloatFloat(
			FVector::DotProduct(LocalAcceleration2D.GetSafeNormal(), LocalVelocity2D.GetSafeNormal()),
			-0.6f, 0.6f
		);
}

void UWarriorHeroAnimInstance::UpdateCharacterMovementState()
{
	bIsOnGround=OwningMovementComponent->IsMovingOnGround();
	bIsFalling = bIsJumping = false;
	if (OwningMovementComponent->MovementMode == EMovementMode::MOVE_Falling)
	{
		if (OwningMovementComponent->Velocity.Z > 0)
		{
			bIsJumping = true;
		}
		else
		{
			UWarriorFunctionLibrary::RemoveGameplayTagFromActorIfFound(OwningCharacter, WarriorGameplayTags::Player_Status_Jumping);
			bIsFalling = true;
		}
	}
}


void UWarriorHeroAnimInstance::UpdateTurnInPlaceData()
{
	if (bHasVelocity||OwningCharacter->HasAnyRootMotion())
	{
		ElapsedDelayTime = 0.f;
		bCanTurnInPlace = false;
		return;
	}
	YawControler_Actor = UKismetMathLibrary::NormalizedDeltaRotator(OwningCharacter->GetControlRotation(), WorldRotation).Yaw;
	const float& TurnAngleAbs = UKismetMathLibrary::Abs(YawControler_Actor);
	if (TurnAngleAbs > TurnCheckMinAngle)
	{
		ElapsedDelayTime += DeltaTime;
		const float& DelayTimeThreshold = UKismetMathLibrary::MapRangeClamped(
			TurnAngleAbs,
			TurnCheckMinAngle, 180.f,
			MinAngleDelay, MaxAngleDelay
		);
		if (ElapsedDelayTime > DelayTimeThreshold)
		{
			bCanTurnInPlace = true;
			const float& AnimTurnAngle = TurnAngleAbs >= Turn180Threshold ? 180.f : 90.f;
			TurnInPlaceRotationScale = TurnAngleAbs / AnimTurnAngle;
		}
	}
	else
	{
		ElapsedDelayTime = 0.f;
		bCanTurnInPlace = false;
	}
}

void UWarriorHeroAnimInstance::TurnInPlace(const FRotator& TargetRotation, float AnimPlayRate, float AnimStartTime, bool bOverrideCurrentAnim)
{
	const float&TurnAngle= UKismetMathLibrary::NormalizedDeltaRotator(OwningCharacter->GetControlRotation(), WorldRotation).Yaw;

}


void UWarriorHeroAnimInstance::UpdateGroundDistance()
{
	if (bIsFalling)
	{
		FFindFloorResult Res;
		OwningMovementComponent->ComputeFloorDist(OwningCharacter->GetActorLocation(), 0.f, 10000.f, Res, 1.f);
		GroundDistance = Res.FloorDist;
		return;
	}
	GroundDistance = 10000.f;
}










