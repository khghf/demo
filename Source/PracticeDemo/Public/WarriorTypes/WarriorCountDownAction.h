// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include<WarriorTypes/WarriorEnumTypes.h>
#include "UObject/WeakObjectPtr.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"
/**
 * 
 */
class FWarriorCountDownAction:public FPendingLatentAction
{
public:
	FWarriorCountDownAction(float InTotalCountTime, float InUpdateInterval, float& InOutRemainingTime, EWarriorCountDownActionOutInput& InCountOutput,const FLatentActionInfo&LatentInfo)
	:bNeedToCancel(false), bRefreshNow(false),
	TotalCountTime(InTotalCountTime),
	UpdateInterval(InUpdateInterval),
	OutRemainingTime(InOutRemainingTime),
	CountOutput(InCountOutput),
	ExecutionFunction(LatentInfo.ExecutionFunction),
	OutputLink(LatentInfo.Linkage),
	CallbackTarget(LatentInfo.CallbackTarget),
	ElapsedInterval(0.f),
	ElapsedTimeSinceStart(0.f)
	{

	}
private:
	bool bNeedToCancel;
	bool bRefreshNow;//�Ƿ�����ˢ�¼���
	float TotalCountTime;
	float UpdateInterval;//���¼��
	float& OutRemainingTime;
	EWarriorCountDownActionOutInput& CountOutput;
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	float ElapsedInterval;//�೤ʱ��û����
	float ElapsedTimeSinceStart;
public:
	virtual void UpdateOperation(FLatentResponse& Response)override;
	virtual void NotifyObjectDestroyed()override;
	virtual void NotifyActionAborted()override;
	void CancelAction();
	void RefreshNow();
};
