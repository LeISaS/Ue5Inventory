// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"
#include "InvenShop/InvenShopCharacter.h"

AFood::AFood()
{
	RemoveFoodValue = 30.0f;
	ItemData.ItemClass = StaticClass();
}

void AFood::Use(AInvenShopCharacter* Character)
{
	if(Character)
	{
		Character->RemoveHunger(RemoveFoodValue);
	}
}
