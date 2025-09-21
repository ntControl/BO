// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageSystem/Shapes/HitCapsuleComponent.h"
#include "Components/CapsuleComponent.h"

UHitCapsuleComponent::UHitCapsuleComponent()
{
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("HitBox"));
	CapsuleComponent->SetupAttachment(this);

	if (CapsuleComponent)
	{
		CapsuleRadius = CapsuleComponent->GetUnscaledCapsuleRadius();
		CapsuleHalfHeight = CapsuleComponent->GetUnscaledCapsuleHalfHeight();
	}
}

void UHitCapsuleComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (CheckAndUpdateCollisionProfile(CapsuleComponent, CollisionProfile))
	{
		return;
	}

	if (CapsuleComponent->GetUnscaledCapsuleHalfHeight() != CapsuleHalfHeight)
	{
		CapsuleComponent->SetCapsuleHalfHeight(CapsuleHalfHeight);
		return;
	}

	if (CapsuleComponent->GetUnscaledCapsuleRadius() != CapsuleRadius)
	{
		CapsuleComponent->SetCapsuleRadius(CapsuleRadius);
	}
}
