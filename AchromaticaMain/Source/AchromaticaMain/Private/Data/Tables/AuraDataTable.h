// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/Enums/EAuraType.h"
#include "Engine/DataTable.h"
#include  "Data/Structs/FAuraDataTableRow.h"
#include "Data/Structs/FAuraDataTableRowHandle.h"


#include "AuraDataTable.generated.h"

/**
 * 
 */
UCLASS()
class ACHROMATICAMAIN_API UAuraDataTable : public UDataTable
{
	GENERATED_BODY()

public:

	UAuraDataTable();

	UFUNCTION(BlueprintCallable, Category = "Custom Values|DataTable")
	void GetAuraDataByType(EAuraType AuraType, FAuraDataTableRowHandle& OutHandle) const;

	virtual void PostLoad() override;

protected:
	TMap<EAuraType, uint8*> AuraTypeToRowMap;

	
};
