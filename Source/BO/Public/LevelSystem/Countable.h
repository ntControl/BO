// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Countable.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType, Blueprintable)
struct FCountable
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxValue = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentValue = 0;
};
