// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EBodyPart : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	Head = 1 UMETA(DisplayName = "Head"),
	Torso = 2 UMETA(DisplayName = "Torso")
};
