// Fill out your copyright notice in the Description page of Project Settings.


#include "PoolingSystem/PoolingSubsystem.h"
#include "PoolingSystem/PoolActorFunc.h"

AActor* UPoolingSubsystem::GetActorItem(TSubclassOf<AActor> ActorClass)
{
	if (Pool)
	{
		AActor* PooledActor = Pool->GetActorItem(ActorClass);
		if (PooledActor)
		{
			return PooledActor;
		}
	}
	return nullptr;
}

UObject* UPoolingSubsystem::GetObjectItem(TSubclassOf<UObject> ObjectClass)
{
	if (Pool)
	{
		UObject* PooledObject = Pool->GetObjectItem(ObjectClass);
		if (PooledObject)
		{
			return PooledObject;
		}
	}
	return nullptr;
}

void UPoolingSubsystem::InitPool(AActor* PoolActor)
{
	if (PoolActor)
	{
		IPoolActorFunc* PoolActorInt = Cast<IPoolActorFunc>(PoolActor);
		if (PoolActorInt)
		{
			Pool.SetObject(PoolActor);
			Pool.SetInterface(PoolActorInt);
		}
	}
}
