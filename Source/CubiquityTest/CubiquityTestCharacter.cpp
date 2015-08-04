// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "CubiquityTest.h"
#include "CubiquityTestCharacter.h"

ACubiquityTestCharacter::ACubiquityTestCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->AttachTo(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

}


void ACubiquityTestCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
    // Set up gameplay key bindings
    check(InputComponent);

    InputComponent->BindAxis("MoveForward", this, &ACubiquityTestCharacter::OnMoveForward);
    InputComponent->BindAxis("MoveRight", this, &ACubiquityTestCharacter::OnMoveRight);
}


void ACubiquityTestCharacter::OnMoveForward(float value)
{
    if ((Controller != NULL) && (value != 0.0f))
    {
        // find out which way is forward
        const FRotator rotation = Controller->GetControlRotation();
        const FRotator yawRotation(0, rotation.Yaw, 0);

        // get forward vector
        const FVector direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
        AddMovementInput(direction, value);
    }
}

void ACubiquityTestCharacter::OnMoveRight(float value)
{
    if ((Controller != NULL) && (value != 0.0f))
    {
        // find out which way is right
        const FRotator rotation = Controller->GetControlRotation();
        const FRotator yawRotation(0, rotation.Yaw, 0);

        // get right vector 
        const FVector direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);
        // add movement in that direction
        AddMovementInput(direction, value);
    }
}
