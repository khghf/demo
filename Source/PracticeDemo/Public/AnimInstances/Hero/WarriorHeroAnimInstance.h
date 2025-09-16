// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/WarriorCharacterAnimInstance.h"
#include<WarriorTypes/WarriorEnumTypes.h>
#include<Kismet/KismetMathLibrary.h>
#include "WarriorHeroAnimInstance.generated.h"

struct FFloatSpringState;
class AHeroCharacter;
UCLASS()
class PRACTICEDEMO_API UWarriorHeroAnimInstance : public UWarriorCharacterAnimInstance
{
	GENERATED_BODY()
public:
	UWarriorHeroAnimInstance();
	virtual void NativeInitializeAnimation()override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds)override;
protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Refrences")
	AHeroCharacter* OwnningHeroCharacter;
	///////////////////--------------------------------------------

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Locomotion")
	bool bShouldEnterRelaxState;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Locomotion")
	float EnterRelaxStateThreshold = 5.f;
	float IdleElpasedTime; 
	UPROPERTY(BlueprintReadOnly, Category = "AnimData|LocationData")
	FVector WorldLocation=FVector::ZeroVector;
	UPROPERTY(BlueprintReadOnly, Category = "AnimData|LocationData")
	float DisplacementSinceLastUpdate=0.f;
	UPROPERTY(BlueprintReadOnly, Category = "AnimData|LocationData")
	float DisplacementSpeed=0.f;
	///////////////////--------------------------------------------

	UPROPERTY(BlueprintReadOnly, Category = "AnimData|RotationData")
	FRotator WorldRotation = FRotator::ZeroRotator;
	UPROPERTY(BlueprintReadOnly, Category = "AnimData|RotationData")
	float YawDeltaSinceLastUpdate = 0.f;
	///////////////////--------------------------------------------

	UPROPERTY(BlueprintReadOnly, Category = "AnimData|VelocityData")
	FVector WorldVelocity = FVector::ZeroVector;
	UPROPERTY(BlueprintReadOnly, Category = "AnimData|VelocityData")
	FVector WorldVelocity2D = FVector::ZeroVector;
	UPROPERTY(BlueprintReadOnly, Category = "AnimData|VelocityData")
	FVector LocalVelocity2D = FVector::ZeroVector;
	UPROPERTY(BlueprintReadOnly, Category = "AnimData|VelocityData")
	bool bWasMovingLastUpdate = false;
	UPROPERTY(BlueprintReadOnly, Category = "AnimData|VelocityData")
	bool bHasVelocity = false;
	//角色速度相对其朝向的夹角
	UPROPERTY(BlueprintReadOnly, Category = "AnimData|VelocityData")
	float LocalVelocityDirectionAngle = 0.f;
	/*UPROPERTY(BlueprintReadOnly, Category = "AnimData|VelocityData")
	float LocalVelocityDirectionAngleWithOffset = 0.f;*/
	///////////////////--------------------------------------------

	UPROPERTY(BlueprintReadOnly, Category = "AnimData|Acceleration")
	FVector WorldAcceleration2D = FVector::ZeroVector;
	UPROPERTY(BlueprintReadOnly, Category = "AnimData|Acceleration")
	FVector LocalAcceleration2D = FVector::ZeroVector;
	UPROPERTY(BlueprintReadOnly, Category = "AnimData|Acceleration")
	FVector PivotDirection2D = FVector::ZeroVector;
	UPROPERTY(BlueprintReadOnly, Category = "AnimData|Acceleration")
	ECardinalDirection CardinalDirectionFromAcceleration;
	///////////////////--------------------------------------------

	UPROPERTY(BlueprintReadOnly, Category = "AnimData|MovementState")
	bool  bIsOnGround = false;
	UPROPERTY(BlueprintReadOnly, Category = "AnimData|MovementState")
	bool  bIsFalling = false;
	UPROPERTY(BlueprintReadOnly, Category = "AnimData|MovementState")
	bool  bIsJumping = false;
	///////////////////--------------------------------------------
	//控制器与角色夹角(归一化)
	UPROPERTY(BlueprintReadWrite, Category = "AnimData|TurnInPlace|ALS_Solution")
	float YawControler_Actor;
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category = "AnimData|TurnInPlace|ALS_Solution")
	float TurnCheckMinAngle=45.f;
	//转身前的延迟时间
	UPROPERTY()
	float ElapsedDelayTime = 0.f;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "AnimData|TurnInPlace|ALS_Solution")
	float MinAngleDelay = 0.75f;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "AnimData|TurnInPlace|ALS_Solution")
	float MaxAngleDelay = 0.f;
	UPROPERTY(BlueprintReadOnly,Category = "AnimData|TurnInPlace|ALS_Solution")
	bool bCanTurnInPlace = false;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "AnimData|TurnInPlace|ALS_Solution")
	float TurnInPlaceRotationScale = 1.f;
	UPROPERTY(BlueprintReadWrite, Category = "AnimData|TurnInPlace|ALS_Solution")
	float Turn180Threshold = 130.f;
	///////////////////--------------------------------------------
	UPROPERTY(BlueprintReadOnly, Category = "AnimData")
	float  GroundDistance = 0.f;
	UPROPERTY(BlueprintReadOnly, Category = "CharacterStateData")
	bool bIsRunningIntoWall = false;
	UPROPERTY(BlueprintReadWrite, Category = "Locomotion|Data")
	ECardinalDirection StartDirection;
private:
	bool bIsFirstUpdate =true;
	float DeltaTime;
protected:
	//void NativeUpdateLocationData();
	UFUNCTION(meta = (BlueprintThreadSafe = "true"), BlueprintCallable, Category = "ThreadSafeFunc")
	void UpdateLocationData();
	UFUNCTION(meta = (BlueprintThreadSafe = "true"), BlueprintCallable, Category = "ThreadSafeFunc")
	void UpdateRotationData();
	UFUNCTION(meta = (BlueprintThreadSafe = "true"), BlueprintCallable, Category = "ThreadSafeFunc")
	void UpdateVelocityData();
	UFUNCTION(meta = (BlueprintThreadSafe = "true"), BlueprintCallable, Category = "ThreadSafeFunc")
	void UpdateWallDetectionHeuristic();
	UFUNCTION(meta = (BlueprintThreadSafe = "true"), BlueprintCallable, Category = "ThreadSafeFunc")
	void UpdateAccelerationData();
	UFUNCTION(meta = (BlueprintThreadSafe = "true"), BlueprintCallable, Category = "ThreadSafeFunc")
	void UpdateCharacterMovementState();
	
	UFUNCTION(meta = (BlueprintThreadSafe = "true"), BlueprintCallable, Category = "ThreadSafeFunc")
	void UpdateTurnInPlaceData();
	void TurnInPlace(const FRotator&TargetRotation,float AnimPlayRate=1.f,float AnimStartTime=0.f,bool bOverrideCurrentAnim=false);
	UFUNCTION(meta = (BlueprintThreadSafe = "true"), BlueprintCallable, Category = "ThreadSafeFunc")
	void UpdateGroundDistance();
protected:
};
