// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "LevelLoadSubsystem.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLevelLoadSuccessSignature, FName, LevelName);

UCLASS()
class BO_API ULevelLoadSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnLevelLoadSuccessSignature LevelLoaded;

	UFUNCTION(BlueprintCallable)
	void StartLevelTransition(const FString LevelName);

	void OnPostWorldInitialization(UWorld* World, ELevelTick Tick, float f);

private:
	UPROPERTY()
	UPackage* Map;

	void OnLoadPackageEnd(const FName& PackageName, UPackage* LoadedPackage, EAsyncLoadingResult::Type Result);
};
