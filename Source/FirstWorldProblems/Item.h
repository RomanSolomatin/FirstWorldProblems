// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <string>
#include "GameFramework/Actor.h"
#include "Item.generated.h"



/**
 * 
 */
UCLASS()
class FIRSTWORLDPROBLEMS_API AItem : public AActor
{
	GENERATED_UCLASS_BODY()


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Item)
		FString ItemName;

	//declaring sprite component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Sprite)
		TSubobjectPtr<class UPaperSpriteComponent> RenderComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Item)
		int32 Value; 

	UFUNCTION(BlueprintImplementableEvent, meta = (FriendlyName = "Item: Used"))
		virtual void Used();


	virtual void BeginPlay() override; 
	void PickedUp();


	
};
