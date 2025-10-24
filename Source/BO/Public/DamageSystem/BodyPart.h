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
	UpperTorso = 2 UMETA(DisplayName = "UpperTorso"),
	LowerTorso = 3	UMETA(DisplayName = "LowerTorso"),
	Pelvis = 4 UMETA(DisplayName = "Pelvis"),
	UpperArm = 5 UMETA(DisplayName = "UpperArm"), 
	ForeArm = 6 UMETA(DisplayName = "ForeArm"),
	Hand = 7 UMETA(DisplayName = "Hand"),
	Thigh = 8 UMETA(DisplayName = "Thigh"),
	LowerLeg = 9 UMETA(DisplayName = "LowerLeg"),
	Foot = 10 UMETA(DisplayName = "Foot")
};
