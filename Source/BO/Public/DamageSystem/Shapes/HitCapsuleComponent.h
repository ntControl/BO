// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageSystem/HitShapeBaseComponent.h"
#include "HitCapsuleComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BO_API UHitCapsuleComponent : public UHitShapeBaseComponent
{
	GENERATED_BODY()

public:
	UHitCapsuleComponent();

	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

private:
	UPROPERTY()
	class UCapsuleComponent* CapsuleComponent;

	UPROPERTY(EditDefaultsOnly, Category = "HitBoxParams")
	float CapsuleRadius;

	UPROPERTY(EditDefaultsOnly, Category = "HitBoxParams")
	float CapsuleHalfHeight;
};
