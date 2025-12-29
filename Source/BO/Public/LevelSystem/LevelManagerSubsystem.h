// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CountableType.h"
#include "CountableData.h"
#include "LevelManagerSubsystem.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInternalCounterUpdatedSignature, FCountableData, CountableData);
DECLARE_DYNAMIC_DELEGATE_OneParam(FCounterUpdatedSignature, FCountableData, CountableData);

/**
 * 
 */
UCLASS()
class BO_API ULevelManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TMap<ECountableType, FCountableData> Countables;

	TMap<ECountableType, FInternalCounterUpdatedSignature> CountableUpdatedDelegates;
	
public:
	UFUNCTION(BlueprintCallable)
	void AddCountable(ECountableType Type);

	UFUNCTION(BlueprintCallable)
	void IncrementCounter(ECountableType Type);

	UFUNCTION(BlueprintCallable)
	FCountableData GetCountableData(ECountableType Type) const;

	UFUNCTION(BlueprintCallable)
	void BindCounterUpdatedEvents(ECountableType Type, const FCounterUpdatedSignature InEvent);
};
