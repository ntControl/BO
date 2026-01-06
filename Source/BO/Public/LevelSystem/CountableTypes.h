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
	Token = 1 UMETA(DisplayName = "Token"),
	Kill = 2 UMETA(DisplayName = "Kill"),
	Powerfuel = 3 UMETA(DisplayName = "Powerfuel")
};
