#pragma once

#include "Engine/DataTable.h"
#include "FAuraDataTableRowHandle.generated.h"

USTRUCT(BlueprintType)
struct FAuraDataTableRowHandle
{
	GENERATED_BODY()

	FAuraDataTableRowHandle()
	{
		DataTable = nullptr;
		RowName = NAME_None;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Values|DataTable")
	TObjectPtr<const UDataTable> DataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Values|DataTable")
	FName RowName;



	bool IsNull() const
	{
		return DataTable == nullptr && RowName.IsNone();
	}

	
};
