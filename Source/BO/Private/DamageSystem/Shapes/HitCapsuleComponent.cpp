// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageSystem/Shapes/HitCapsuleComponent.h"
#include "Components/CapsuleComponent.h"

UHitCapsuleComponent::UHitCapsuleComponent()
{
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("HitBox"));

	if (CapsuleComponent)
	{
		CapsuleComponent->SetupAttachment(this);
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

	if (FMath::Abs(CapsuleComponent->GetUnscaledCapsuleHalfHeight() - CapsuleHalfHeight) > FLOAT_ACCEPTANCE)
	{
		CapsuleComponent->SetCapsuleHalfHeight(CapsuleHalfHeight);
		return;
	}

	if (FMath::Abs(CapsuleComponent->GetUnscaledCapsuleRadius() - CapsuleRadius) > FLOAT_ACCEPTANCE)
	{
		CapsuleComponent->SetCapsuleRadius(CapsuleRadius);
	}
}
