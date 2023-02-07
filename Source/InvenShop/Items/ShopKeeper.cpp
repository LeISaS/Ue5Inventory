// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopKeeper.h"
#include "Components/SkeletalMeshComponent.h"
#include "InvenShop/InvenShopCharacter.h"
#include "Net/UnrealNetwork.h"

AShopKeeper::AShopKeeper()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShopKeeperMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	RootComponent = ShopKeeperMesh;

	bReplicates =true;
}


void AShopKeeper::BeginPlay()
{
	Super::BeginPlay();
	
}

void AShopKeeper::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AShopKeeper, Items);
}

void AShopKeeper::Interact(AInvenShopCharacter* Character)
{
	if(Character)
	{
		Character->OpenShop(Items);
	}
	
}


