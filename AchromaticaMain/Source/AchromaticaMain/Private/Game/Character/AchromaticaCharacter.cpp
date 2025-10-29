// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/Character/AchromaticaCharacter.h"

// Sets default values
AAchromaticaCharacter::AAchromaticaCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAchromaticaCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAchromaticaCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAchromaticaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

