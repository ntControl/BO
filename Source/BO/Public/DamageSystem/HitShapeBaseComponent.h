// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Damageble.h"
#include "HitShapeBaseComponent.generated.h"

#define FLOAT_ACCEPTANCE 0.001f

DECLARE_LOG_CATEGORY_EXTERN(LogDamageSystem, Log, All)

class UPrimitiveComponent;

UCLASS(Abstract, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BO_API UHitShapeBaseComponent : public USceneComponent, public IDamageble
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHitShapeBaseComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	bool CheckAndUpdateCollisionProfile(UPrimitiveComponent* ShapeComponent, const FCollisionProfileName& InCollisionProfile);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void I_TakeDamage_Implementation(FDamageReturn& DamageReturn, FDamageInfo DamageInfo, const AActor* DamageCauser) override;


protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "HitShapeComponent")
	float DamageMultiplier;

	UPROPERTY(EditDefaultsOnly, Category = "HitShapeComponent")
	EBodyPart BodyPart;

	UPROPERTY(EditDefaultsOnly, Category = "HitShapeComponent");
	FCollisionProfileName CollisionProfile;
};
