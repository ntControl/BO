// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Countable.h"
#include "CountableTypes.h"
#include "LevelSubsystem.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FCountableUpdatedSignature, FCountable, NewCountable);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInternalCountableUpdatedSignature, FCountable, InternalNewCountable);
/**
 * 
 */
UCLASS()
class BO_API ULevelSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TMap<ECountableTypes, FCountable> Countables;

	UPROPERTY()
	TMap<ECountableTypes, FInternalCountableUpdatedSignature> CountableUpdatedEvents;

public:	
	UFUNCTION(BlueprintCallable)
	void AddCountable(ECountableTypes Type);

	UFUNCTION(BlueprintCallable)
	void IncrementCountable(ECountableTypes Type);

	UFUNCTION(BlueprintCallable)
	FCountable GetCountable(ECountableTypes Type);

	UFUNCTION(BlueprintCallable)
	void RegisterOnCountableUpdatedEvent(ECountableTypes Type, FCountableUpdatedSignature InEvent);
};
