// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageClass.h"
#include "Element.h"
#include "BodyPart.h"
#include "DamageInfo.generated.h"

USTRUCT(BlueprintType)
struct FDamageInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	float Damage;

	UPROPERTY(BlueprintReadWrite)
	EDamageClass DamageClass;

	UPROPERTY(BlueprintReadWrite)
	EElement Element;

	UPROPERTY(BlueprintReadWrite)
	EBodyPart HitBodyPart;
};

