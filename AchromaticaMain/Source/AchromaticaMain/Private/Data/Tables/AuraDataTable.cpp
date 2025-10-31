// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraDataTable.h"

#include "Data/Structs/FAuraDataTableRow.h"

UAuraDataTable::UAuraDataTable()
{
	RowStruct = FAuraDataTableRow::StaticStruct();
}

void UAuraDataTable::GetAuraDataByType(EAuraType AuraType, FAuraDataTableRowHandle& OutHandle) const
{
	// uint8* const* RowDataPtr = AuraTypeToRowMap.Find(AuraType);
	// if (RowDataPtr != nullptr)
	// {
	// 	uint8* RowData = *RowDataPtr;
	// 	check(RowData);
	//
	// 	
	// }

	
}


void UAuraDataTable::PostLoad()
{
	Super::PostLoad();
}
