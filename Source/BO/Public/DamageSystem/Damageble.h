// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DamageInfo.h"
#include "Damageble.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDamageble : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BO_API IDamageble
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void I_TakeDamage(FDamageInfo DamageInfo);
};
