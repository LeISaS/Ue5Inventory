// Fill out your copyright notice in the Description page of Project Settings.


#include "Gold.h"
#include "InvenShop/InvenShopCharacter.h"


AGold::AGold()
{
	ItemData.ItemClass = StaticClass();
}

void AGold::Use(AInvenShopCharacter* Character)
{
	Super::Use(Character);
}
