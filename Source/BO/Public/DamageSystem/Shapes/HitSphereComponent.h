// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageSystem/HitShapeBaseComponent.h"
#include "HitSphereComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BO_API UHitSphereComponent : public UHitShapeBaseComponent
{
	GENERATED_BODY()

public:
	UHitSphereComponent();

	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	void SetCollisionEnabled(ECollisionEnabled::Type Value) override;

private:
	UPROPERTY()
	class USphereComponent* SphereComponent;

	UPROPERTY(EditDefaultsOnly, Category = "HitSphereParams")
	float SphereRadius;
};
