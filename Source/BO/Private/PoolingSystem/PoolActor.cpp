// Fill out your copyright notice in the Description page of Project Settings.


#include "PoolingSystem/PoolActor.h"
#include "PoolingSystem/Poolable.h"
#include "PoolingSystem/PoolingSubsystem.h"
#include "Dialogs/Dialogs.h"

// Sets default values
APoolActor::APoolActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APoolActor::BeginPlay()
{
	Super::BeginPlay();

	UGameInstance* GameInstance = GetGameInstance();
	UPoolingSubsystem* PoolSubsystem = GameInstance->GetSubsystem<UPoolingSubsystem>();
	PoolSubsystem->InitPool(this);
	
	GenerateActors();
	GenerateObjects();
}

// Called every frame
void APoolActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AActor* APoolActor::GetActorItem(FString Name)
{
	for(TPair<FString, FActorArray> Elem : ActorPools)
	{
		if (Elem.Key != Name)
		{
			continue;
		}
		for (int i = 0; i < Elem.Value.Actors.Num(); i = i + 1)
		{
			AActor* ActorItem = Elem.Value.Actors[i];
			if (!IPoolable::Execute_GetActive(ActorItem))
			{
				return ActorItem;
			}
		}
	}
	return nullptr;
}

UObject* APoolActor::GetObjectItem(FString Name)
{
	for (TPair<FString, FObjectArray> Elem : ObjectPools)
	{
		if (Elem.Key != Name)
		{
			continue;
		}
		for (int i = 0; i < Elem.Value.Objects.Num(); i = i + 1)
		{
			UObject* ObjectItem = Elem.Value.Objects[i];
			IPoolable* PoolItem = Cast<IPoolable>(ObjectItem);
			if (PoolItem && !PoolItem->GetActive())
			{
				return ObjectItem;
			}
		}
	}
	return nullptr;
}

void APoolActor::GenerateActors()
{
	for (FActorPoolData ActorData : ActorPoolData)
	{
		if (!ActorData.Class->ImplementsInterface(UPoolable::StaticClass()))
		{
			UE_LOG(LogTemp, Error, TEXT("Actor named \"%s\" does not implement Poolable interface"), *ActorData.Name);
			continue;
		}
		FActorArray NewActorArray = FActorArray();
		for (int i = 0; i < ActorData.Count; i = i + 1)
		{
			AActor* NewActor = GetWorld()->SpawnActor(ActorData.Class);
			IPoolable::Execute_OnDeactivation(NewActor);
			NewActorArray.Actors.Add(NewActor);
		}
		ActorPools.Add(ActorData.Name, NewActorArray);
	}
}

void APoolActor::GenerateObjects()
{
	for (FObjectPoolData ObjectData : ObjectPoolData)
	{
		if (!ObjectData.Class->ImplementsInterface(UPoolable::StaticClass()))
		{
			UE_LOG(LogTemp, Error, TEXT("Object named \"%s\" does not implement Poolable interface"), *ObjectData.Name);
			continue;
		}
		FObjectArray NewObjectArray = FObjectArray();
		for (int i = 0; i < ObjectData.Count; i = i + 1)
		{
			UObject* ConstructedObject = NewObject<UObject>(this, ObjectData.Class);
			IPoolable* Poolable = Cast<IPoolable>(ConstructedObject);
			if (Poolable)
			{
				Poolable->OnDeactivation();
			}
			NewObjectArray.Objects.Add(ConstructedObject);
		}
		ObjectPools.Add(ObjectData.Name, NewObjectArray);
	}
}

