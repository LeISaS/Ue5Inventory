// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InvenShop/InteractableInterface.h"
#include "InvenShop/Structs.h"

#include "Item.generated.h"

UCLASS()
class INVENSHOP_API AItem : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly,Category = "TUTORIAL")
	class UStaticMeshComponent* ItemMesh;
	UPROPERTY(EditAnywhere,Category = "TUTORIAL")
	FItemData ItemData;
	

public:
	virtual void Interact(class AInvenShopCharacter* Character) override;
	
	FItemData GetItemData() const {return ItemData;}
	virtual void Use(AInvenShopCharacter* Character) override;
};
