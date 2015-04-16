// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstWorldProblems.h"
#include "PaperSpriteComponent.h"
#include "Item.h"


AItem::AItem(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	//initialising the sprite component and setting it as the root component
	RenderComponent = PCIP.CreateDefaultSubobject<UPaperSpriteComponent>(this, TEXT("RenderComponent"));
	RenderComponent->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	RenderComponent->Mobility = EComponentMobility::Movable;

	RootComponent = RenderComponent;


}

void AItem::BeginPlay()
{
	Super::BeginPlay();

}

void AItem::PickedUp()
{
	if (RenderComponent)
	{
		RenderComponent->DestroyComponent(); //item picked up destroy it visual representation
	}
}


