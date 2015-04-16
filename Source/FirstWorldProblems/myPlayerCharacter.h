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


	//Properties
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		TSubobjectPtr<class USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		TSubobjectPtr<class UCameraComponent> SideViewCameraComponent;

	UPROPERTY(EditAnywhere, Category = Inventory)
		TArray<class AItem*> ItemInventory;		//Our inventory


	//Functions
	UFUNCTION()
		void OnStartJump();
	
	UFUNCTION()
		void OnStopJump();

	void PickUpItem(AItem* Item);



protected: 
	void MoveRight(float value);
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	
};
