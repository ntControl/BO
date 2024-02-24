// Fill out your copyright notice in the Description page of Project Settings.


#include "MarcoBlueprintFunctionLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

bool UMarcoBlueprintFunctionLibrary::SphereOverlapActorsForObjectClass(const AActor* ActorContext, const FVector SpherePos, float SphereRadius, const TArray<TEnumAsByte<EObjectTypeQuery> >& ObjectTypes, UClass* ActorClassFilter, const TArray<AActor*>& ActorsToIgnore, TArray<AActor*>& OutActors)
{
	UWorld* World = ActorContext->GetWorld();
	UKismetSystemLibrary::SphereOverlapActors(World, SpherePos, SphereRadius, ObjectTypes, ActorClassFilter, ActorsToIgnore,OutActors);
	OutActors.Empty();

	TArray<UPrimitiveComponent*> OverlapComponents;
	bool bOverlapped = UKismetSystemLibrary::SphereOverlapComponents(World, SpherePos, SphereRadius, ObjectTypes, NULL, ActorsToIgnore, OverlapComponents);
	if (bOverlapped)
	{
		UKismetSystemLibrary::GetActorListFromComponentList(OverlapComponents, ActorClassFilter, OutActors);
	}

	return (OutActors.Num() > 0);

}