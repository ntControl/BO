// Fill out your copyright notice in the Description page of Project Settings.


#include "MarcoBlueprintFunctionLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"


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

UNiagaraComponent* UMarcoBlueprintFunctionLibrary::SpawnNiagaraSystemAtLocation(const AActor* ActorContext, UNiagaraSystem* SystemTemplate, FVector SpawnLocation, FRotator SpawnRotation, FVector Scale, bool bAutoDestroy, bool bAutoActivate, ENCPoolMethod PoolingMethod, bool bPreCullCheck)
{
	UWorld* World = ActorContext->GetWorld();

	FFXSystemSpawnParameters SpawnParams;
	SpawnParams.WorldContextObject = World;
	SpawnParams.SystemTemplate = SystemTemplate;
	SpawnParams.Location = SpawnLocation;
	SpawnParams.Rotation = SpawnRotation;
	SpawnParams.Scale = Scale;
	SpawnParams.bAutoDestroy = bAutoDestroy;
	SpawnParams.bAutoActivate = bAutoActivate;
	SpawnParams.PoolingMethod = ToPSCPoolMethod(PoolingMethod);
	SpawnParams.bPreCullCheck = bPreCullCheck;
	return UNiagaraFunctionLibrary::SpawnSystemAtLocationWithParams(SpawnParams);
}