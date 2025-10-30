// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/Character/Components/AchromaticaAuraSystem.h"

#include "Game/Character/AchromaticaCharacter.h"
#include "NiagaraFunctionLibrary.h"


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
	NiagaraComponent->SetAsset(AuraOneNiagaraSystem);
	NiagaraComponent->Activate();
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

void UAchromaticaAuraSystem::ActivateAura(const int AuraIndex) const
{
	switch (AuraIndex)
	{
		case 0:
			CharacterMesh->SetOverlayMaterial(AuraOneMaterial);
			NiagaraComponent->SetAsset(AuraOneNiagaraSystem);
			NiagaraComponent->Activate();
			break;
		case 1:
			CharacterMesh->SetOverlayMaterial(AuraTwoMaterial);
			NiagaraComponent->SetAsset(AuraTwoNiagaraSystem);
			NiagaraComponent->Activate();
			break;
		default:
			CharacterMesh->SetOverlayMaterial(nullptr);
			NiagaraComponent->SetAsset(nullptr);
			NiagaraComponent->Deactivate();
			break;
	}
}




