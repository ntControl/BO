// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelSystem/LevelSubsystem.h"

void ULevelSubsystem::AddCountable(ECountableTypes Type)
{
	FCountable* Countable = Countables.Find(Type);

	if (!Countable)
	{
		Countable = &Countables.Add(Type, FCountable());
	}

	Countable->MaxValue++;
}

void ULevelSubsystem::IncrementCountable(ECountableTypes Type)
{
	FCountable* Countable = Countables.Find(Type);

	if (!Countable)
	{
		return;
	}

	Countable->CurrentValue++;

	FInternalCountableUpdatedSignature* UpdateEvent = CountableUpdatedEvents.Find(Type);

	if (!UpdateEvent)
	{
		return;
	}

	UpdateEvent->Broadcast(*Countable);
}

FCountable ULevelSubsystem::GetCountable(ECountableTypes Type)
{
	FCountable* Countable = Countables.Find(Type);

	if (!Countable)
	{
		return FCountable();
	}

	return *Countable;
}

void ULevelSubsystem::RegisterOnCountableUpdatedEvent(ECountableTypes Type, FCountableUpdatedSignature InEvent)
{
	FInternalCountableUpdatedSignature* UpdateEvent = CountableUpdatedEvents.Find(Type);

	if (!UpdateEvent)
	{
		UpdateEvent = &CountableUpdatedEvents.Add(Type, FInternalCountableUpdatedSignature());
	}

	UpdateEvent->Add(InEvent);
}
