// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "GameplayTagContainer.h"
#include "AchromaticaMain/Private/Data/Structs/FAuraDataTableRow.h"



#include "AchromaticaAuraComponent.generated.h"


class UAuraManagerSubsystem;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ACHROMATICAMAIN_API UAchromaticaAuraComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAchromaticaAuraComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "_GLOBAL|Aura")
	FGameplayTag CurrentAuraTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "_GLOBAL|Aura")
	FAuraDataTableRow CurrentAuraData;



	UFUNCTION(BlueprintCallable, Category= "_GLOBAL|Aura")
	void UpdateAuraDataFromTag();
	
	UFUNCTION(BlueprintCallable, Category= "_GLOBAL|Aura")
	void ClearAura();




private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "_GLOBAL|Aura", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UAuraManagerSubsystem> AuraManagerSubsystem;
};
