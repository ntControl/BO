// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PoolActorFunc.h"
#include "PoolActor.generated.h"

USTRUCT()
struct FActorArray
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TArray<AActor*> Actors;
};

USTRUCT()
struct FObjectArray
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TArray<UObject*> Objects;
};

USTRUCT(BlueprintType)
struct FActorPoolData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> Class;

	UPROPERTY(EditAnywhere)
	FString Name;

	UPROPERTY(EditAnywhere)
	int Count;
};

USTRUCT(BlueprintType)
struct FObjectPoolData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<UObject> Class;

	UPROPERTY(EditAnywhere)
	FString Name;

	UPROPERTY(EditAnywhere)
	int Count;
};

UCLASS()
class BO_API APoolActor : public AActor, public IPoolActorFunc
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APoolActor();

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
	TArray<FActorPoolData> ActorPoolData;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly)
	TArray<FObjectPoolData> ObjectPoolData;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UPROPERTY()
	TMap<FString, FActorArray> ActorPools;

	UPROPERTY()
	TMap<FString, FObjectArray> ObjectPools;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual AActor* GetActorItem(FString Name) override;

	UFUNCTION()
	virtual UObject* GetObjectItem(FString Name) override;

private:
	void GenerateActors();
	void GenerateObjects();
};
