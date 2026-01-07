// Fill out your copyright notice in the Description page of Project Settings.


#include "PoolingSystem/PoolActorFunc.h"

// Add default functionality here for any IPoolActorFunc functions that are not pure virtual.

AActor* IPoolActorFunc::GetActorItem(TSubclassOf<AActor> Class)
{
	return nullptr;
}

UObject* IPoolActorFunc::GetObjectItem(TSubclassOf<UObject> Class)
{
	return nullptr;
}
