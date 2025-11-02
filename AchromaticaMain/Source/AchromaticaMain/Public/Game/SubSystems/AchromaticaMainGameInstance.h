// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AchromaticaMainGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ACHROMATICAMAIN_API UAchromaticaMainGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Aura")
	TSoftObjectPtr<UDataTable> AuraDataTable;
};
