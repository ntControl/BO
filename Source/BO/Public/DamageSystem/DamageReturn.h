// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageReturn.generated.h"

USTRUCT(BlueprintType)
struct FDamageReturn
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	bool bWasDamaged;

	UPROPERTY(BlueprintReadWrite)
	bool bIsDead;

	UPROPERTY(BlueprintReadWrite)
	bool bIsHeadshot;
};
