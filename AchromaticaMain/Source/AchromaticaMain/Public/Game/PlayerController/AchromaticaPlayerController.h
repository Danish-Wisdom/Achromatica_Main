// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AchromaticaPlayerController.generated.h"

class UInputMappingContext;


/**
 * 
 */
UCLASS()
class ACHROMATICAMAIN_API AAchromaticaPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AAchromaticaPlayerController();

	virtual void BeginPlay() override;


private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom Values|Input|Mapping Context", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> DefaultIMC;

	
	
	
};
