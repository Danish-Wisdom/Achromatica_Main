// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AchromaticaMain/Private/Data/Structs/FAuraDataTableRow.h"


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
	virtual void PostLoad() override;
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;  


	const FAuraDataTableRow* FindRowByAuraType(const EAuraType AuraType) const;

	
	UFUNCTION(BlueprintCallable, Category = "_Custom Values")
	bool FindByAuraType(EAuraType AuraType, FAuraDataTableRow& OutRow) const;
	
protected:
	TMap<EAuraType, FAuraDataTableRow*> AuraTypeRowMap;

	void BuildAuraTypeMap();

	//UFUNCTION(BlueprintCallable, Category = "Custom Values|DataTable")
};
