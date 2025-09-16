// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/HeroCombatComponent.h"
#include<Items/Weapons/WarriorHeroWeapon.h>
#include<AbilitySystemBlueprintLibrary.h>
#include "WarriorGameplayTags.h"
#include<WarriorFunctionLibrary.h>

#include<DebugHelper/Debug.h>
AWarriorHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
    return Cast<AWarriorHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}

AWarriorHeroWeapon* UHeroCombatComponent::GetHeroCurrentEquippedWeapon() const
{
    return Cast<AWarriorHeroWeapon>(GetCharacterCurrentEquippedWeapon());
}

float UHeroCombatComponent::GetHeroCurrentEquippedWeaponDamageAtLevel(float InLevel) const
{
    return GetHeroCurrentEquippedWeapon()->HeroWeaponData.WeaponBaseDamage.GetValueAtLevel(InLevel);
} 

void UHeroCombatComponent::OnHitTargetActor(AActor* HitActor)
{
    if (OverlapedActors.Contains(HitActor))return;
    OverlapedActors.AddUnique(HitActor);
    //�����¼�Shared_Event_MeleeHit
    //Attack GA�н��ܵ���ִ��GE_Share_DealDamage,GEͨ��UGEExecCalc_DamageTakenִ���˺�����
    //GE_Share_DealDamage�ɹ�Ӧ������Shared.Event.HitReact�¼���HitActor
    //HitActor�����ܻ���������
    //const bool bAttackWasDodged = UWarriorFunctionLibrary::NativeDoesActorHasTag(HitActor, WarriorGameplayTags::Player_Status_Dodging_Invinciable);
    bool bIsValidBlock = false;
    bool bIsTargetBlocking = UWarriorFunctionLibrary::NativeDoesActorHasTag(HitActor, WarriorGameplayTags::Shared_Status_Block_Holding);
    const bool bIsMyAttachUnblockable = UWarriorFunctionLibrary::NativeDoesActorHasTag(GetOwningPawn(), WarriorGameplayTags::Shared_Status_Unblockable);
    FGameplayEventData Data;
    Data.Instigator = GetOwningPawn();
    Data.Target = HitActor;
   /* if (bAttackWasDodged)
    {
        UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
            HitActor,
            WarriorGameplayTags::Player_Event_PerfectDodge,
            Data
        );
        return;
    }*/
    if (bIsTargetBlocking && !bIsMyAttachUnblockable)
    {
        bIsValidBlock = UWarriorFunctionLibrary::IsValidBlock(GetOwningPawn(), HitActor);
    }
   
    if (bIsValidBlock == true)
    {
        UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
            HitActor,
            WarriorGameplayTags::Shared_Event_Block_Successful,
            Data
        );
    }
    else
    {
        UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
            GetOwningPawn(),
            WarriorGameplayTags::Shared_Event_MeleeHit,
            Data
        );
        UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
            GetOwningPawn(),
            WarriorGameplayTags::Player_Event_HitPause,
            FGameplayEventData()
        );
    }
}

void UHeroCombatComponent::OnWeaponPulledFromTargetActor(AActor* InteractedActor)
{
    UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
        GetOwningPawn(),
        WarriorGameplayTags::Player_Event_HitPause,
        FGameplayEventData()
    );
}
