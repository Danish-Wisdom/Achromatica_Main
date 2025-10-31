// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Data/Enums/EAuraType.h"
#include "NiagaraSystem.h"
#include "Materials/MaterialInstance.h"

#include "FAuraDataTableRow.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FAuraDataTableRow : public FTableRowBase
{

	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Values")
	TEnumAsByte<EAuraType> AuraType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Values")
	FName AuraName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Values")
	TObjectPtr<UMaterialInstance> AuraMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Values")
	TObjectPtr<UNiagaraSystem> AuraNiagaraSystem;

	FAuraDataTableRow() { Reset(); }

	
	void Reset()
	{
		AuraType = EAuraType::None;
		AuraName = NAME_None;
		AuraMaterial = nullptr;
		AuraNiagaraSystem = nullptr;
	}


};