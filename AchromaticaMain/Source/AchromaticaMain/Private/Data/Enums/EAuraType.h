// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EAuraType.generated.h"


UENUM(BlueprintType)
enum EAuraType : uint8
{
	None = 0,
	Aura_Fire = 1,
	Aura_Ice = 2,
	Aura_Nature = 3,
	Aura_Psychic = 4,
	Aura_Elemental = 5
};