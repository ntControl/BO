// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelSystem/LevelManagerSubsystem.h"

void ULevelManagerSubsystem::AddCountable(ECountableType Type)
{	
	if (!Countables.Contains(Type))
	{
		Countables.Add(Type, FCountableData());
	}

	FCountableData* Data = Countables.Find(Type);

	if (!Data)
	{
		return;
	}

	Data->MaxNumber++;
}

void ULevelManagerSubsystem::IncrementCounter(ECountableType Type)
{
	FCountableData* Data = Countables.Find(Type);

	if (!Data)
	{
		return;
	}

	Data->CurrentNum++;

	FInternalCounterUpdatedSignature* Delegate = CountableUpdatedDelegates.Find(Type);
	if (Delegate)
	{
		Delegate->Broadcast(*Data);
	}
}

FCountableData ULevelManagerSubsystem::GetCountableData(ECountableType Type) const
{
	return *Countables.Find(Type);
}

void ULevelManagerSubsystem::BindCounterUpdatedEvents(ECountableType Type, FCounterUpdatedSignature InEvent)
{
	if (!CountableUpdatedDelegates.Contains(Type))
	{
		CountableUpdatedDelegates.Add(Type, FInternalCounterUpdatedSignature());
	}

	FInternalCounterUpdatedSignature* Delegate = CountableUpdatedDelegates.Find(Type);

	if (!Delegate)
	{
		return;
	}

	Delegate->Add(InEvent);
}
