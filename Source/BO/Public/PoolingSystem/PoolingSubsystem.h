// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PoolActorFunc.h"
#include "PoolingSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class BO_API UPoolingSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
private:
	UPROPERTY()
	TScriptInterface<IPoolActorFunc> Pool;

public:
	UFUNCTION(BlueprintCallable)
	AActor* GetActorItem(FString Name);

	UFUNCTION(BlueprintCallable)
	UObject* GetObjectItem(FString Name);

	UFUNCTION()
	void InitPool(AActor* PoolActor);
};
