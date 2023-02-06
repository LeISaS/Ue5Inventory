// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "InvenShop/InvenShopCharacter.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	RootComponent = ItemMesh;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItem::Interact(class AInvenShopCharacter* Character)
{
	if(Character)
	{
		Character->AddItemToInventoryWidget(ItemData);
	}
	Destroy();
}

void AItem::Use(AInvenShopCharacter* Character)
{
	UE_LOG(LogTemp,Warning,TEXT("USING ITEM: %s"), *GetName());
}

