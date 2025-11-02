// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/*
 *====================================================
 *													 \|
 *	  		   ACHROMATICA GLOBAL MACROS		     \|
 *													 \|
 *====================================================
 */

// Simple UE_LOG
#define LOG(x) UE_LOG(LogTemp, Warning, TEXT(x))

// Check if is Valid
#define VALID(x) if(IsValid(x))

// Formatted log (use like: LOGF("HP: %d", Health))
#define LOGF(fmt, ...) UE_LOG(LogTemp, Warning, TEXT(fmt), __VA_ARGS__)

// Screen log (prints to screen in yellow for 3s)
#define SCREEN_LOG(x) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, x)

// Screen log formatted
#define SCREEN_LOGF(fmt, ...) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT(fmt), __VA_ARGS__))