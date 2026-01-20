// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageSystem/HitShapeBaseComponent.h"
#include "HitBoxComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BO_API UHitBoxComponent : public UHitShapeBaseComponent
{
	GENERATED_BODY()

public:
	UHitBoxComponent();

#if WITH_EDITOR

	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

#endif

	void SetCollisionEnabled(ECollisionEnabled::Type Value) override;

private:
	UPROPERTY()
	class UBoxComponent* BoxComponent;

	UPROPERTY(EditDefaultsOnly, Category = "HitBoxParams")
	FVector BoxExtents;
};
