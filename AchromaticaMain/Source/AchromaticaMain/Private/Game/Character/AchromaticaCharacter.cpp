// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/Character/AchromaticaCharacter.h"


#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

#define LOG(x) UE_LOG(LogTemp, Warning, TEXT(x))
#define VALID(x) if(IsValid(x))

// Sets default values
AAchromaticaCharacter::AAchromaticaCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
	

	FollowCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCameraComponent"));
	FollowCameraComponent->SetupAttachment(SpringArmComponent);

	AuraSystem = CreateDefaultSubobject<UAchromaticaAuraSystem>(TEXT("AuraSystemComponent"));
	AuraSystem->SetCharacterReference(this);
	
}

// Called when the game starts or when spawned
void AAchromaticaCharacter::BeginPlay()
{
	Super::BeginPlay();

	InitializeSpringArmSettings();
	
}

// Called to bind functionality to input
void AAchromaticaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (PlayerInputComponent)
	{
		if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
		{
			EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAchromaticaCharacter::Move);
			EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &AAchromaticaCharacter::Look);
			EIC->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
			EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
			// Additional action bindings (Attack, Aim) can be added here
			EIC->BindAction(AttackAction, ETriggerEvent::Started, this, &AAchromaticaCharacter::Attack);
			EIC->BindAction(AimAction, ETriggerEvent::Triggered, this, &AAchromaticaCharacter::StartAim);
			EIC->BindAction(AimAction, ETriggerEvent::Completed, this, &AAchromaticaCharacter::StopAim);
			
		}
	}
	
}

void AAchromaticaCharacter::Move(const FInputActionValue& Value)
{
	//LOG("Moving");

	VALID(Controller)
	{
		// Get current rotation of controller, separate yaw rotation
		const FRotator CurrentRotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, CurrentRotation.Yaw, 0.f);

		// Get forward and right directions based off controller
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// Add movement input
		const FVector2D MovementVector = Value.Get<FVector2D>();
		const float SpeedValue = bIsAiming ? AimSpeed : MoveSpeed;

		AddMovementInput(ForwardDirection, MovementVector.Y * SpeedValue * GetWorld()->GetDeltaSeconds());
		AddMovementInput(RightDirection, MovementVector.X * SpeedValue * GetWorld()->GetDeltaSeconds());
		
		
	}
	
}

void AAchromaticaCharacter::Look(const FInputActionValue& Value)
{
	//LOG("Looking");

	VALID(Controller)
	{
		const FVector2D LookAxis = Value.Get<FVector2D>();
		const float RotationSpeedX = bIsAiming ? AimingHorizontalRotationRate : HorizontalRotationRate;
		const float RotationSpeedY = bIsAiming ? AimingVerticalRotationRate : VerticalRotationRate;
		
		AddControllerYawInput(LookAxis.X * RotationSpeedX * GetWorld()->GetDeltaSeconds());
		AddControllerPitchInput(LookAxis.Y * RotationSpeedY * GetWorld()->GetDeltaSeconds());
	}
}

void AAchromaticaCharacter::Attack()
{
	LOG("Attacking");
	
}

void AAchromaticaCharacter::StartAim()
{
	LOG("Starting Aim");
	bIsAiming = true;

	SpringArmComponent->TargetArmLength = 250.f;
}

void AAchromaticaCharacter::StopAim()
{
	LOG("Stoping Aim");
	bIsAiming = false;

	SpringArmComponent->TargetArmLength = SpringArmTargetArmLength;
}

void AAchromaticaCharacter::InitializeSpringArmSettings()
{
	SpringArmComponent->TargetArmLength = SpringArmTargetArmLength;
	SpringArmComponent->bUsePawnControlRotation = true;
	
	FollowCameraComponent->bUsePawnControlRotation = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, YawRotationRate, 0.f);
	GetCharacterMovement()->JumpZVelocity = JumpVelocityValue;
	GetCharacterMovement()->AirControl = AirControlValue;
}

