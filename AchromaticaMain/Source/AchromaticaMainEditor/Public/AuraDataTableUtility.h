// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Engine/DataTable.h"
#include "AchromaticaMain/Private/Data/Tables/AuraDataTable.h"
#include "AuraDataTableUtility.generated.h"

/**
 * Editor-only utility to convert normal DataTable into a AuraDataTable
 */
UCLASS(BlueprintType, Blueprintable, EditInlineNew)
class ACHROMATICAMAINEDITOR_API UAuraDataTableUtility : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(CallInEditor, Category = "Custom Editor Functions")
	static UAuraDataTable* ConvertToAuraDataTable(UDataTable* SourceTable);
};
