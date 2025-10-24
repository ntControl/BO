// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageSystem/Shapes/HitSphereComponent.h"
#include "Components/SphereComponent.h"

UHitSphereComponent::UHitSphereComponent()
{
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("HitSphere"));

	if (SphereComponent)
	{
		SphereComponent->SetupAttachment(this);
		SphereRadius = SphereComponent->GetUnscaledSphereRadius();
	}
}

void UHitSphereComponent::SetCollisionEnabled(ECollisionEnabled::Type Value)
{
	SphereComponent->SetCollisionEnabled(Value);
}

#if WITH_EDITOR
void UHitSphereComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (CheckAndUpdateCollisionProfile(SphereComponent, CollisionProfile))
	{
		return;
	}

	if (FMath::Abs(SphereComponent->GetUnscaledSphereRadius() - SphereRadius) > FLOAT_ACCEPTANCE)
	{
		SphereComponent->SetSphereRadius(SphereRadius);
	}
}
#endif
