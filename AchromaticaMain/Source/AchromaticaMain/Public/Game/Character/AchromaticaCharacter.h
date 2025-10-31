// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Components/AchromaticaAuraSystem.h"
#include "AchromaticaCharacter.generated.h"

class UInputAction;





UCLASS()
class ACHROMATICAMAIN_API AAchromaticaCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Values|Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Values|Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> FollowCameraComponent;
	
public:
	// Sets default values for this character's properties
	AAchromaticaCharacter();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	
protected:

	void InitializeSpringArmSettings();
	
	
private:
	void Move(const FInputActionValue& Value);
	
	void Look(const FInputActionValue& Value);

	void Attack();
	void StartAim();
	void StopAim();


	/* --- Gameplay Values --- */

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Values|Gameplay|States", meta = (AllowPrivateAccess = "true"))
	bool bIsAiming = false;
	


	/* --- Input Actions --- */

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom Values|Input|Actions", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom Values|Input|Actions", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom Values|Input|Actions", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom Values|Input|Actions", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> AttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Custom Values|Input|Actions", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> AimAction;

	

	/* --- Settings Values --- */
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Values|Settings|Camera", meta = (AllowPrivateAccess = "true"))
	float SpringArmTargetArmLength = 300.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Values|Settings|Character|Movement", meta = (AllowPrivateAccess = "true"))
	float YawRotationRate = 540.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Values|Settings|Character|Movement", meta = (AllowPrivateAccess = "true"))
	float AimingYawRotationRate = 300.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Values|Settings|Character|Movement", meta = (AllowPrivateAccess = "true"))
	float JumpVelocityValue = 600.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Values|Settings|Character|Movement", meta = (AllowPrivateAccess = "true"))
	float AirControlValue = 0.2f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Values|Settings|Controller|Base", meta = (AllowPrivateAccess = "true"))
	float MoveSpeed = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Values|Settings|Controller|Aim", meta = (AllowPrivateAccess = "true"))
	float AimSpeed = 300.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Values|Settings|Controller|Base", meta = (AllowPrivateAccess = "true"))
	float HorizontalRotationRate = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Values|Settings|Controller|Base", meta = (AllowPrivateAccess = "true"))
	float VerticalRotationRate = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Values|Settings|Controller|Aim", meta = (AllowPrivateAccess = "true"))
	float AimingHorizontalRotationRate = 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Values|Settings|Controller|Aim", meta = (AllowPrivateAccess = "true"))
	float AimingVerticalRotationRate = 50.f;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Values|Settings|Character|Aura", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMaterialInstance> AuraOneMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Custom Values|Settings|Character|Aura", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UMaterialInstance> AuraTwoMaterial;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Values|Settings|Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAchromaticaAuraSystem> AuraSystem;
public:

	/* --- Getters --- */
	FORCEINLINE USpringArmComponent* GetSpringArmComponent() const { return SpringArmComponent; }
	FORCEINLINE UCameraComponent* GetFollowCameraComponent() const { return FollowCameraComponent; }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool IsAiming() const { return bIsAiming; }

	
	
	
};
