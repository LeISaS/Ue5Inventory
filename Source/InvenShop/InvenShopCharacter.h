// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InvenShop/Structs.h"
#include "InvenShopCharacter.generated.h"

struct FItemData;
class AItem;

UCLASS(config=Game)
class AInvenShopCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	AInvenShopCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input)
	float TurnRateGamepad;

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	void Interact();

	void Interact(FVector Start, FVector End);
	
	UFUNCTION(Server,Reliable,WithValidation)
	void Server_Interact(FVector Start, FVector End);

	UPROPERTY(ReplicatedUsing=OnRep_Stats,BlueprintReadWrite, Category= "TUTORIAL")
	float Health;

	UPROPERTY(ReplicatedUsing=OnRep_Stats,BlueprintReadWrite, Category= "TUTORIAL")
	float Hunger;

	UFUNCTION()
	void OnRep_Stats();
	
	UFUNCTION(BlueprintCallable,Category="TUTORIAL")
	void UseItem(TSubclassOf<AItem> ItemSubclass);

	UFUNCTION(Server, Reliable,WithValidation)
	void Server_UseItem(TSubclassOf<AItem> ItemSubclass);
	
	UPROPERTY(ReplicatedUsing=OnRep_InventoryItems,BlueprintReadWrite,Category="TUTORIAL")
	TArray<FItemData> InventoryItems;

	UFUNCTION()
	void OnRep_InventoryItems();

	UFUNCTION(BlueprintImplementableEvent,Category="TUTORIAL")
	void AddItemAndUpdateInventoryWidget(FItemData ItemData,const TArray<FItemData>& CurrentInventory = TArray<FItemData>());

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	
	UFUNCTION(BlueprintNativeEvent,Category="TUTORIAL")
	void UpdateStats(float _Hunger, float _Health);
	
	void AddHealth(float Value);
	void RemoveHunger(float Value);
	void AddInventoryItem(FItemData ItemData);

	UFUNCTION(BlueprintImplementableEvent)
	void OpenShop(const TArray<FItemData>& Items);
};

