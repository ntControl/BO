// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Poolable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UPoolable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BO_API IPoolable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnActivation();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnDeactivation();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	bool GetActive();
};
