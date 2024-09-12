// Fill out your copyright notice in the Description page of Project Settings.


#include "PoolingSystem/PoolingSubsystem.h"
#include "PoolingSystem/PoolActorFunc.h"

AActor* UPoolingSubsystem::GetActorItem(FString Name)
{
	if (Pool)
	{
		AActor* PooledActor = Pool->GetActorItem(Name);
		if (PooledActor)
		{
			return PooledActor;
		}
	}
	return nullptr;
}

UObject* UPoolingSubsystem::GetObjectItem(FString Name)
{
	if (Pool)
	{
		UObject* PooledObject = Pool->GetObjectItem(Name);
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
