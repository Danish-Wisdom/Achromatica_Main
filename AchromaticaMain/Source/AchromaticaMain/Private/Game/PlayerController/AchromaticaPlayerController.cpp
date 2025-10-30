// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/PlayerController/AchromaticaPlayerController.h"

#include  "EnhancedInputSubsystems.h"

AAchromaticaPlayerController::AAchromaticaPlayerController()
{
	
}

void AAchromaticaPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// Clear out existing mappings
		Subsystem->ClearAllMappings();

		// Add each mapping context, along with their priority values
		Subsystem->AddMappingContext(DefaultIMC, 0);
	}
}


