// Fill out your copyright notice in the Description page of Project Settings.


#include "PoolingSystem/PoolActor.h"
#include "PoolingSystem/Poolable.h"
#include "PoolingSystem/PoolingSubsystem.h"

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

AActor* APoolActor::GetActorItem(TSubclassOf<AActor> Class)
{

	FActorArray* ActorArray = ActorPools.Find(Class);
	for (AActor* CurrentActor : ActorArray->Actors)
	{
		if (CurrentActor != nullptr && !IPoolable::Execute_GetActive(CurrentActor))
		{
			return CurrentActor;
		}
	}
	
	return nullptr;
}

UObject* APoolActor::GetObjectItem(TSubclassOf<UObject> Class)
{
	FObjectArray* ObjectArray = ObjectPools.Find(Class);
	for (UObject* CurrentObject : ObjectArray->Objects)
	{
		if (CurrentObject != nullptr && !IPoolable::Execute_GetActive(CurrentObject))
		{
			return CurrentObject;
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
			UE_LOG(LogTemp, Error, TEXT("Actor named \"%s\" does not implement Poolable interface"), *ActorData.Class);
			continue;
		}
		FActorArray NewActorArray = FActorArray();
		for (int i = 0; i < ActorData.Count; i = i + 1)
		{
			AActor* NewActor = GetWorld()->SpawnActor(ActorData.Class, &GetActorTransform());
			IPoolable::Execute_OnDeactivation(NewActor);
			NewActorArray.Actors.Add(NewActor);
		}
		ActorPools.Add(ActorData.Class, NewActorArray);
	}
}

void APoolActor::GenerateObjects()
{
	for (FObjectPoolData ObjectData : ObjectPoolData)
	{
		if (!ObjectData.Class->ImplementsInterface(UPoolable::StaticClass()))
		{
			UE_LOG(LogTemp, Error, TEXT("Object named \"%s\" does not implement Poolable interface"), *ObjectData.Class);
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
		ObjectPools.Add(ObjectData.Class, NewObjectArray);
	}
}

