// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/Character/Components/AchromaticaAuraComponent.h"
#include "Game/SubSystems/Auras/AuraManagerSubsystem.h"
#include "AchromaticaMain/Private/ToolsUtilities/AchromaticaMacros.h"
#include "Engine/GameInstance.h"


// Sets default values for this component's properties
UAchromaticaAuraComponent::UAchromaticaAuraComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UAchromaticaAuraComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	if (GetWorld() && GetWorld()->GetGameInstance())
	{
		AuraManagerSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UAuraManagerSubsystem>();
	}

	if (CurrentAuraTag.IsValid())
	{
		UpdateAuraDataFromTag();
	}
}

void UAchromaticaAuraComponent::UpdateAuraDataFromTag()
{
	if (!AuraManagerSubsystem)
	{
		LOG("Aura Subsystem not Connected!")
	}

	if (!CurrentAuraTag.IsValid())
	{
		LOG("No Aura Tag set!")
		ClearAura();
		return;
	}

	FAuraDataTableRow RowData;
	if (AuraManagerSubsystem->GetAuraDataByTag(CurrentAuraTag, RowData))
	{
		CurrentAuraData = RowData;
		//LOGF("Aura: %s | Material: %s | FX : %s", CurrentAuraData.AuraName, CurrentAuraData.AuraMaterial.GetFName(), CurrentAuraData.AuraNiagaraSystem.GetFName())
		LOGF("Name: %s", *CurrentAuraData.AuraName.ToString())
		LOGF("Material: %s", *CurrentAuraData.AuraMaterial.GetFName().ToString())
		LOGF("VFX: %s", *CurrentAuraData.AuraNiagaraSystem.GetFName().ToString())
	}
	else
	{
		LOGF("AuraTag '%s' not found in DataTable!", *CurrentAuraTag.ToString())
	}
}

void UAchromaticaAuraComponent::ClearAura()
{
	CurrentAuraTag = FGameplayTag();
	CurrentAuraData = FAuraDataTableRow();
}




