// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ECountableType : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	Kills = 1 UMETA(DisplayName = "Kills"),
	PowerFuels = 2 UMETA(DisplayName = "PowerFuels"),
	Tokens = 3 UMETA(DisplayName = "Tokens")
};

