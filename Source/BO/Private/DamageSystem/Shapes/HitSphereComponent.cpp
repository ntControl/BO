// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageSystem/Shapes/HitSphereComponent.h"
#include "Components/SphereComponent.h"

UHitSphereComponent::UHitSphereComponent()
{
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("HitSphere"));
	SphereComponent->SetupAttachment(this);

	if (SphereComponent)
	{
		SphereRadius = SphereComponent->GetUnscaledSphereRadius();
	}
}

#if WITH_EDITOR
void UHitSphereComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (CheckAndUpdateCollisionProfile(SphereComponent, CollisionProfile))
	{
		return;
	}

	if (SphereComponent->GetUnscaledSphereRadius() != SphereRadius)
	{
		SphereComponent->SetSphereRadius(SphereRadius);
	}
}
#endif
