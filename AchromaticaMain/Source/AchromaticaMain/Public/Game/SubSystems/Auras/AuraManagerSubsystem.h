// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"
#include "AchromaticaMain/Private/Data/Structs/FAuraDataTableRow.h"

#include "AuraManagerSubsystem.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class ACHROMATICAMAIN_API UAuraManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "Custom Values")
	TSoftObjectPtr<UDataTable> AuraDataTable;

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// UFUNCTION(BlueprintCallable, Category = "Custom Values|Functions")
	// bool GetAuraDataByType(EAuraType Type, FAuraDataTableRow& OutData);

	UFUNCTION(BlueprintCallable, Category = "Custom Values|Functions")
	bool GetAuraDataByTag(const FGameplayTag AuraTag, FAuraDataTableRow& OutData);

	
protected:
	TMap<EAuraType, FAuraDataTableRow*> AuraTypeRowMap;
	TMap<FGameplayTag, FAuraDataTableRow*> AuraTagRowMap;

	// void BuildAuraTypeRowMap(UDataTable* Data);
	void BuildAuraTagRowMap(UDataTable* Data);

	
	void LoadAuraData();

private:

	// const FAuraDataTableRow* FindRowByAuraType(const EAuraType AuraType) const;
	const FAuraDataTableRow* FindRowByAuraTag(const FGameplayTag AuraTag) const;
};


