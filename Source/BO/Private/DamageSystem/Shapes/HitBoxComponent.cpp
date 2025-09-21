// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageSystem/Shapes/HitBoxComponent.h"
#include "Components/BoxComponent.h"

UHitBoxComponent::UHitBoxComponent()
{
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	BoxComponent->SetupAttachment(this);

	if (BoxComponent)
	{
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

	if (OldBoxExtents.X != BoxExtents.X || OldBoxExtents.Y != BoxExtents.Y || OldBoxExtents.Z != BoxExtents.Z)
	{
		BoxComponent->SetBoxExtent(BoxExtents);
	}
}
#endif