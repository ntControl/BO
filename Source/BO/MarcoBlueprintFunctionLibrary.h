// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MarcoBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class BO_API UMarcoBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	static bool SphereOverlapActorsForObjectClass(const AActor* ActorContext, const FVector SpherePos, float SphereRadius, const TArray<TEnumAsByte<EObjectTypeQuery> >& ObjectTypes, UClass* ActorClassFilter, const TArray<AActor*>& ActorsToIgnore, TArray<AActor*>& OutActors);

	UFUNCTION(BlueprintCallable)
	static UNiagaraComponent* SpawnNiagaraSystemAtLocation(const AActor* ActorContext, UNiagaraSystem* SystemTemplate, FVector SpawnLocation, FRotator SpawnRotation, FVector Scale, bool bAutoDestroy, bool bAutoActivate, ENCPoolMethod PoolingMethod, bool bPreCullCheck);
};
