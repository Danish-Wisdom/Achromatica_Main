// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/SubSystems/Auras/AuraManagerSubsystem.h"
#include "Game/SubSystems/AchromaticaMainGameInstance.h"

#include "AchromaticaMain/Private/ToolsUtilities/AchromaticaMacros.h"

void UAuraManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	if (UAchromaticaMainGameInstance* GameInstance = Cast<UAchromaticaMainGameInstance>(GetGameInstance()))
	{
		if (GameInstance->AuraDataTable.IsValid())
		{
			AuraDataTable = GameInstance->AuraDataTable.Get();
		}
		else
		{
			// Load it synchronously if it wasn't loaded yet
			AuraDataTable = GameInstance->AuraDataTable.LoadSynchronous();
		}

		if (AuraDataTable)
		{
			UE_LOG(LogTemp, Warning, TEXT("Aura DataTable loaded successfully: %s"), *AuraDataTable->GetName());
			
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Aura DataTable is not assigned!"));
		}
		
	}
	
	LoadAuraData();
}

void UAuraManagerSubsystem::Deinitialize()
{
	Super::Deinitialize();

}

// const FAuraDataTableRow* UAuraManagerSubsystem::FindRowByAuraType(const EAuraType AuraType) const
// {
// 	if (FAuraDataTableRow* const* FoundRowPtr = AuraTypeRowMap.Find(AuraType))
// 	{
// 		return *FoundRowPtr;
// 	}
//
// 	return nullptr;
// }

const FAuraDataTableRow* UAuraManagerSubsystem::FindRowByAuraTag(const FGameplayTag AuraTag) const
{
	if (FAuraDataTableRow* const* FoundRowPtr = AuraTagRowMap.Find(AuraTag))
	{
		return *FoundRowPtr;
	}

	return nullptr;
}

/*bool UAuraManagerSubsystem::GetAuraDataByType(EAuraType Type, FAuraDataTableRow& OutData)
{
	if (const FAuraDataTableRow* Ptr = FindRowByAuraType(Type))
	{
		if (Ptr)
		{
			OutData = *Ptr;
			return true;
		}
	}
	
	return false;
}*/

bool UAuraManagerSubsystem::GetAuraDataByTag(const FGameplayTag AuraTag, FAuraDataTableRow& OutData)
{
	if (const FAuraDataTableRow* Ptr = FindRowByAuraTag(AuraTag))
	{
		if (Ptr)
		{
			OutData = *Ptr;
			return true;
		}
	}
	
	return false;
}

/*void UAuraManagerSubsystem::BuildAuraTypeRowMap(UDataTable* Data)
{
	AuraTypeRowMap.Empty();


	if (IsValid(Data))
	{
		for (const auto RowPair : Data->GetRowMap())
		{
			if (FAuraDataTableRow* RowData = reinterpret_cast<FAuraDataTableRow*>(RowPair.Value))
			{
				AuraTypeRowMap.Add(RowData->AuraType, RowData);
			}
		}
	}
}*/

void UAuraManagerSubsystem::BuildAuraTagRowMap(UDataTable* Data)
{
	AuraTagRowMap.Empty();

	if (IsValid(Data))
	{
		for (const auto RowPair : Data->GetRowMap())
		{
			if (FAuraDataTableRow* RowData = reinterpret_cast<FAuraDataTableRow*>(RowPair.Value))
			{
				AuraTagRowMap.Add(RowData->AuraTag, RowData);
			}
		}
	}
}

void UAuraManagerSubsystem::LoadAuraData()
{
	LOG("Starting Mapping!")
	LOGF("Type Data Row Count: %d", AuraTypeRowMap.Num())
	LOGF("Tag Data Row Count: %d", AuraTagRowMap.Num())


	if (AuraDataTable.IsValid())
	{
		if (UDataTable* DataTable = AuraDataTable.LoadSynchronous())
		{
			BuildAuraTagRowMap(DataTable);
			//BuildAuraTypeRowMap(DataTable);

			LOG("Something")
		}
		else
		{
			LOG("Failed to load Data Table Asset")
		}
	}

	LOG("Completed Mapping!")
	LOGF("Type Data Row Count: %d", AuraTypeRowMap.Num())
	LOGF("Tag Data Row Count: %d", AuraTagRowMap.Num())

	SCREEN_LOG("Welcome To Achromatica");
}


