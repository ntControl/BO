// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PoolActorFunc.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPoolActorFunc : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BO_API IPoolActorFunc
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION()
	virtual AActor* GetActorItem(FString Name);

	UFUNCTION()
	virtual UObject* GetObjectItem(FString Name);
};
