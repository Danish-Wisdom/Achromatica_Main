// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraDataTable.h"

#include "Data/Structs/FAuraDataTableRow.h"

UAuraDataTable::UAuraDataTable()
{
	RowStruct = FAuraDataTableRow::StaticStruct();
}




void UAuraDataTable::PostLoad()
{
	Super::PostLoad();

	BuildAuraTypeMap();
}

#if WITH_EDITOR
void UAuraDataTable::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	//BuildAuraTypeMap();
}
#endif

void UAuraDataTable::BuildAuraTypeMap()
{
	AuraTypeRowMap.Empty();

	for (const auto& RowPair : GetRowMap())
	{
		if (FAuraDataTableRow* RowData = reinterpret_cast<FAuraDataTableRow*>(RowPair.Value))
		{
			AuraTypeRowMap.Add(RowData->AuraType, RowData);
		}
	}
}

const FAuraDataTableRow* UAuraDataTable::FindRowByAuraType(const EAuraType AuraType) const
{
	if (FAuraDataTableRow* const* FoundRowPtr = AuraTypeRowMap.Find(AuraType))
	{
		return *FoundRowPtr;
	}

	return nullptr;

	
}

bool UAuraDataTable::FindByAuraType(EAuraType AuraType, FAuraDataTableRow& OutRow) const
{
	
	// if (FAuraDataTableRow* const* RowPtr = AuraTypeRowMap.Find(AuraType))
	// {
	// 		if (*RowPtr)
	// 		{
	// 			OutRow = **RowPtr;
	// 			return true;
	// 		}
	// }

	if (const FAuraDataTableRow* Ptr = FindRowByAuraType(AuraType))
	{
		if (Ptr)
		{
			OutRow = *Ptr;
			return true;
		}
	}
	

	return false;
}
