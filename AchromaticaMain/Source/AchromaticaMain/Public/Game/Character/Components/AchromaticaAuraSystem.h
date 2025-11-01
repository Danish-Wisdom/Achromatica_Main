// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Data/Enums/EAuraType.h"
#include "Components/ActorComponent.h"
#include "NiagaraSystem.h"
#include "Materials/MaterialInstance.h"
#include "NiagaraComponent.h"
#include  "Data/Tables/AuraDataTable.h"

#include "AchromaticaAuraSystem.generated.h"



class AAchromaticaCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ACHROMATICAMAIN_API UAchromaticaAuraSystem : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAchromaticaAuraSystem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "_Custom Values|Aura One", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMaterialInstance> AuraOneMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "_Custom Values|Aura Ones", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UNiagaraSystem> AuraOneNiagaraSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "_Custom Values|Aura Two", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMaterialInstance> AuraTwoMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "_Custom Values|Aura Two", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UNiagaraSystem> AuraTwoNiagaraSystem;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "_Custom Values|References|Character", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<AAchromaticaCharacter> AchromaticaCharacter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "_Custom Values|References|Character", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> CharacterMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "_Custom Values|References|Niagara", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UNiagaraComponent> NiagaraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "_Custom Values|References|Data", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAuraDataTable> AuraDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "_Custom Values|Aura One", meta = (AllowPrivateAccess = "true"))
	TEnumAsByte<EAuraType> AuraOneType = EAuraType::None;

	
public:
	
	void SetCharacterReference(AAchromaticaCharacter* Character);

	UFUNCTION(BlueprintCallable)
	void ActivateAura(EAuraType AuraType) const;
	

};
