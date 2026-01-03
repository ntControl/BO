// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableTypeFlag.generated.h"

/**
 * 
 */
UENUM(BlueprintType, meta = (BitFlags, UseEnumValuesAsMaskValuesInEditor = "true"))
enum class E_InteractableTypeFlag : uint8
{
	ZeroEntry = 0, 
	Medikit = 1,
	PrimaryAmmo = 2,
	SecondaryAmmo = 4,
	TertiaryAmmo = 8
};

ENUM_CLASS_FLAGS(E_InteractableTypeFlag)