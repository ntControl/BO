// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EDamageResponse : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	HitReaction = 1 UMETA(DisplayName = "HitReaction"),
	Stagger = 2 UMETA(DisplayName = "Stagger"),
	Stun = 3 UMETA(DisplayName = "Stun"),
	KnockBack = 4 UMETA(DisplayName = "KnockBack")
};
