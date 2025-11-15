// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageClass.h"
#include "Element.h"
#include "BodyPart.h"
#include "DamageResponse.h"
#include "DamageInfo.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct FDamageInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDamageClass DamageClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDamageResponse DamageResponse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EElement Element;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EBodyPart HitBodyPart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bShouldDamageInvincible;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanBeBlocked;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanBeParried;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bShouldForceInterrupt;
};

