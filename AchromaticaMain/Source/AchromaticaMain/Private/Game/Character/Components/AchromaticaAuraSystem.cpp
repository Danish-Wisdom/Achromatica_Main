// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/Character/Components/AchromaticaAuraSystem.h"

#include "Game/Character/AchromaticaCharacter.h"


#define LOG(x) UE_LOG(LogTemp, Warning, TEXT(x))
#define VALID(x) if(IsValid(x))

// Sets default values for this component's properties
UAchromaticaAuraSystem::UAchromaticaAuraSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...

	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("AuraNiagaraComponent"));
	
}


// Called when the game starts
void UAchromaticaAuraSystem::BeginPlay()
{
	Super::BeginPlay();

	// ...
	NiagaraComponent->Deactivate();
	
	
}

void UAchromaticaAuraSystem::SetCharacterReference(AAchromaticaCharacter* Character)
{
	if (!IsValid(AchromaticaCharacter))
	{
		if (IsValid(Character))
		{
			AchromaticaCharacter = Character;
			CharacterMesh = AchromaticaCharacter->GetMesh();
		}
	}
}

void UAchromaticaAuraSystem::ActivateAura(const EAuraType AuraType) const
{
	if(AuraDataTable)
	{
		if (const FAuraDataTableRow* RowData = AuraDataTable->FindRowByAuraType(AuraType))
		{
			VALID(CharacterMesh)
			{
				CharacterMesh->SetOverlayMaterial(RowData->AuraMaterial);
			}
			VALID(NiagaraComponent)
			{
				NiagaraComponent->SetAsset(RowData->AuraNiagaraSystem);
				NiagaraComponent->Activate();
			}
		}
		else
		{
			LOG("No Aura Data Found for the Specified Aura Type");
		}
	}
	else
	{
		LOG("No Aura Data Table Assigned");
	}
}




