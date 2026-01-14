// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ECountableTypes : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	Kill = 1 UMETA(DisplayName = "Kill"),
	Powerfuel = 2 UMETA(DisplayName = "Powerfuel"),
	Token = 3 UMETA(DisplayName = "Token")
};
