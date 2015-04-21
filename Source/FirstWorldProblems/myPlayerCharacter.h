// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PaperCharacter.h"
#include "myPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTWORLDPROBLEMS_API AmyPlayerCharacter : public APaperCharacter
{
	GENERATED_UCLASS_BODY()

		virtual void BeginPlay() override;


	//Functions
	UFUNCTION()
		void OnStartJump();
	
	UFUNCTION()
		void OnStopJump();




protected: 
	void MoveRight(float value);
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
};
