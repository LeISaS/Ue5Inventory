// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "Medpack.generated.h"

class AInvenShopCharacter;

UCLASS()
class INVENSHOP_API AMedpack : public AItem
{
	GENERATED_BODY()
public:
	AMedpack();
protected:
	UPROPERTY(EditAnywhere)
	float HealthValue;
	
public:
	
	virtual void Use(AInvenShopCharacter* Character) override;
	
};
