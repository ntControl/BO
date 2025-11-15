// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EElement : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	Fire = 1 UMETA(DisplayName = "Fire"),
	Cryo = 2 UMETA(DisplayName = "Cryo"),
	Electricity = 3 UMETA(DisplayName = "Electricity")
};
