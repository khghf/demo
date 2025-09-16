// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include<InputAction.h>
#include<GameplayTagContainer.h>
#include<DateAssets/Input/DataAsset_InputConfig.h>
#include "WarriorEnhancedInputComponent.generated.h"


 
class UDataAsset_InputConfig;
UCLASS()
class PRACTICEDEMO_API UWarriorEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
public:
	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);
	template<class UserObject, typename CallbackFunc>
	void BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject, CallbackFunc InputPressedFunc, CallbackFunc InputReleasedFunc);
};
template<class UserObject, typename CallbackFunc>
inline void UWarriorEnhancedInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	checkf(InInputConfig, TEXT("Input config data asset is null"));
	if (UInputAction* FindAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{//in.InputTagΪ�����ص������Ĳ������ͣ��ص���������������֮ƥ����߱���
			//�ڲ��õı��ģ��ɽ��ܶ������
		BindAction(FindAction, TriggerEvent, ContextObject, Func);
	}
}

template<class UserObject, typename CallbackFunc>
inline void UWarriorEnhancedInputComponent::BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject, CallbackFunc InputPressedFunc, CallbackFunc InputReleasedFunc)
{
	checkf(InInputConfig, TEXT("Input config data asset is null"));
	for (const FWarriorInputActionConfig& in : InInputConfig->AbilityInputAction)
	{
		if (in.IsValid())
		{
			BindAction(in.InputAction, ETriggerEvent::Started, ContextObject, InputPressedFunc,in.InputTag);
			BindAction(in.InputAction, ETriggerEvent::Completed, ContextObject, InputReleasedFunc, in.InputTag);
		}
	}
}


