// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "WarriorAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
class IPawnUIInterface;
UCLASS()
class PRACTICEDEMO_API UWarriorAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UWarriorAttributeSet();
	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, CurrentHealth);
	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, MaxHealth);
	//����ֵ��Ӱ�������Լ����
	UPROPERTY(BlueprintReadOnly, Category = "Staying")
	FGameplayAttributeData CurrentSTA;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, CurrentSTA);
	UPROPERTY(BlueprintReadOnly, Category = "Staying")
	FGameplayAttributeData MaxSTA;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, MaxSTA);
	//ÿ�θ�Ҫ���ĵĻ�����STAֵ
	UPROPERTY(BlueprintReadOnly, Category = "Staying")
	FGameplayAttributeData STACost_Block;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, STACost_Block);
	//ÿ�θ�Ҫ����STA��ϵ��
	UPROPERTY(BlueprintReadOnly, Category = "Staying")
	FGameplayAttributeData STACost_Coefficient;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, STACost_Coefficient);
	//ŭ��ֵ��
	UPROPERTY(BlueprintReadOnly, Category = "Rage")
	FGameplayAttributeData CurrentRage;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, CurrentRage);
	UPROPERTY(BlueprintReadOnly, Category = "Rage")
	FGameplayAttributeData MaxRage;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, MaxRage);
	//Ӱ����ɵ��˺�
	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, AttackPower);
	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData DefensePower;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, DefensePower);
	//�˺���ר����ʱ�޸�DamageTaken�����Ӧ����HP��
	UPROPERTY(BlueprintReadOnly, Category = "Damage") 
	FGameplayAttributeData DamageTaken;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, DamageTaken);

	//������Ӱ�������ܻ��󱻻��˾��룬�Լ��ܷ񱻻���
	UPROPERTY(BlueprintReadOnly, Category = "Weight")
	FGameplayAttributeData Weight;
	ATTRIBUTE_ACCESSORS(UWarriorAttributeSet, Weight);
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)override; 
private:
	TWeakInterfacePtr<IPawnUIInterface>CachedPawnUIInterface;

};
