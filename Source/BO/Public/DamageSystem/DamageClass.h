// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EDamageClass : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	Melee = 1 UMETA(DisplayName = "Melee"),
	Projectile = 2 UMETA(DisplayName = "Projectile"),
	Hazard = 3 UMETA(DisplayName = "Hazard")
};