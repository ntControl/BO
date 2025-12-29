// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CountableData.Generated.h"

/**
 * 
 */
USTRUCT(BlueprintType, Blueprintable)
struct FCountableData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentNum;
};
