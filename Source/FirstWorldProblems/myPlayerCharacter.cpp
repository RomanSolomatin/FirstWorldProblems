// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstWorldProblems.h"
#include "myPlayerCharacter.h"
#include "PaperFlipbookComponent.h"
#include "Item.h"


AmyPlayerCharacter::AmyPlayerCharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	CharacterMovement->bOrientRotationToMovement = false;

	//Collision Capsule
	CapsuleComponent->SetCapsuleHalfHeight(96);
	CapsuleComponent->SetCapsuleRadius(40);
}

void::AmyPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AmyPlayerCharacter::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	InputComponent->BindAxis("MoveRight", this, &AmyPlayerCharacter::MoveRight);

	//jumping
	InputComponent->BindAction("Jump", IE_Pressed, this, &AmyPlayerCharacter::OnStartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &AmyPlayerCharacter::OnStopJump);
}


void AmyPlayerCharacter::MoveRight(float Value)
{
	if (Controller != nullptr)
	{
		if (Value > 0)
		{
			Controller->SetControlRotation(FRotator(0, 0, 0));
			AddMovementInput(FVector(1, 0, 0), Value);
		}
		else if (Value < 0)
		{
			Controller->SetControlRotation(FRotator(0, 180, 0));

			AddMovementInput(FVector(1, 0, 0), Value);
		}
	}
}

void AmyPlayerCharacter::OnStartJump()
{
	bPressedJump = true;
}

void AmyPlayerCharacter::OnStopJump()
{
	bPressedJump = false;
}


