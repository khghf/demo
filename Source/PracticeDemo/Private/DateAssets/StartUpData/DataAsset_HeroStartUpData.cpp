// Fill out your copyright notice in the Description page of Project Settings.


#include "DateAssets/StartUpData/DataAsset_HeroStartUpData.h"


#include<AbilitySystem/Abilities/WarriorGameplayAbility.h>
#include<AbilitySystem/WarriorAbilitySystemComponent.h>
#include<AbilitySystem/Abilities/WarriorHeroGameplayAbility.h>
#include<WarriorTypes/WarriorStructTypes.h>
void UDataAsset_HeroStartUpData::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASC, const int32& ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASC, ApplyLevel);
	for (const auto& in : HeroStartUpAbilitySets)
	{
		if (in.IsValid())
		{
			FGameplayAbilitySpec spec(in.AbilityToGrant, ApplyLevel);
			spec.SourceObject = InASC->GetAvatarActor();
			//��������ʱ��Ҫ����DynamicAbilityTagsӵ�еı�ǩ���ж�
			spec.DynamicAbilityTags.AddTag(in.InputTag);
			InASC->GiveAbility(spec);
		}
	}
}
