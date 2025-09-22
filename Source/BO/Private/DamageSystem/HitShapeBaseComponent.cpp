// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageSystem/HitShapeBaseComponent.h"
#include "Components/PrimitiveComponent.h"

DEFINE_LOG_CATEGORY(LogDamageSystem)

// Sets default values for this component's properties
UHitShapeBaseComponent::UHitShapeBaseComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	AActor* Owner = GetOwner();
	if (Owner)
	{
		bool bResult = Owner->Implements<UDamageble>();
		if (!bResult)
		{
			UE_LOG(LogDamageSystem, Warning, TEXT("HitShapeBaseComponent says: Owner does not implement \"IDamageble\" interface, solve problem or else this component won't work"));
		}
		else
		{
			UE_LOG(LogDamageSystem, Log, TEXT("HitShapeBaseComponent says: Owner correctly implements \"IDamageble\" interface"));
		}
	}
	// ...
}


// Called when the game starts
void UHitShapeBaseComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHitShapeBaseComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHitShapeBaseComponent::I_TakeDamage_Implementation(FDamageInfo DamageInfo)
{
	DamageInfo.Damage = DamageInfo.Damage * DamageMultiplier;
	DamageInfo.HitBodyPart = BodyPart;

	Execute_I_TakeDamage(GetOwner(), DamageInfo);
}

bool UHitShapeBaseComponent::CheckAndUpdateCollisionProfile(UPrimitiveComponent* ShapeComponent, const FCollisionProfileName& InCollisionProfile)
{
	if (ShapeComponent)
	{
		if (ShapeComponent->GetCollisionProfileName() != InCollisionProfile.Name)
		{
			ShapeComponent->SetCollisionProfileName(InCollisionProfile.Name);
			ShapeComponent->UpdateCollisionProfile();
			return true;
		}
	}
	return false;
}


