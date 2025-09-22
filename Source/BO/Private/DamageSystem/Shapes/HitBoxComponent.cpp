// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageSystem/Shapes/HitBoxComponent.h"
#include "Components/BoxComponent.h"

UHitBoxComponent::UHitBoxComponent()
{
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));

	if (BoxComponent)
	{
		BoxComponent->SetupAttachment(this);
		BoxExtents = BoxComponent->GetUnscaledBoxExtent();
	}
}

#if WITH_EDITOR
void UHitBoxComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (CheckAndUpdateCollisionProfile(BoxComponent, CollisionProfile))
	{
		return;
	}

	FVector OldBoxExtents = BoxComponent->GetUnscaledBoxExtent();

	if (FMath::Abs(OldBoxExtents.X - BoxExtents.X) > FLOAT_ACCEPTANCE || FMath::Abs(OldBoxExtents.Y - BoxExtents.Y) > FLOAT_ACCEPTANCE || FMath::Abs(OldBoxExtents.Z - BoxExtents.Z) > FLOAT_ACCEPTANCE)
	{
		BoxComponent->SetBoxExtent(BoxExtents);
	}
}
#endif