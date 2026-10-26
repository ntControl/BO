// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelSystem/LevelLoadSubsystem.h"
#include "UObject/UObjectGlobals.h"
#include "Kismet/GameplayStatics.h"
#include "AssetRegistry/AssetRegistryModule.h" 

void ULevelLoadSubsystem::StartLevelTransition(const FString LevelName)
{
    FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
    IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();

    FARFilter Filter;
    Filter.ClassPaths.Add(UWorld::StaticClass()->GetClassPathName());
    Filter.PackagePaths.Add(TEXT("/Game/MyContent/Maps"));
    Filter.bRecursivePaths = true;
    Filter.bIncludeOnlyOnDiskAssets = true;

    TArray<FAssetData> FoundAssets;
    AssetRegistry.GetAssets(Filter, FoundAssets);

    for (const FAssetData& AssetData : FoundAssets)
    {
        if (AssetData.AssetName.ToString() != LevelName)
        {
            continue;
        }

        FString LevelPath = AssetData.PackageName.ToString();
	
        LoadPackageAsync(LevelPath, FLoadPackageAsyncDelegate::CreateUObject(this, &ULevelLoadSubsystem::OnLoadPackageEnd), 0, PKG_ContainsMap);
        break;
    }

}

void ULevelLoadSubsystem::OnPostWorldInitialization(UWorld* World, ELevelTick Tick, float f)
{
    LevelLoaded.Broadcast(Map->FileName);
}

void ULevelLoadSubsystem::OnLoadPackageEnd(const FName& PackageName, UPackage* LoadedPackage, EAsyncLoadingResult::Type Result)
{
	if (Result == EAsyncLoadingResult::Succeeded)
	{
        Map = LoadedPackage;

        if (Map)
        {
            //FWorldDelegates::OnPostWorldInitialization.AddUObject(this, &ULevelLoadSubsystem::OnPostWorldInitialization);
            FWorldDelegates::OnWorldPreActorTick.AddUObject(this, &ULevelLoadSubsystem::OnPostWorldInitialization);

            UGameplayStatics::OpenLevel(this, Map->FileName);
        }
	}
}