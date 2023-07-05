// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemDataStruct.h"
#include "Interfaces/InteractionInterface.h"
#include "Item.generated.h"

class USphereComponent;
class UNiagaraSystem;
class UNiagaraComponent;

enum class EItemState : uint8
{
	EIS_Hovering,
	EIS_Equipped
};


UCLASS()
class SLASH_API AItem : public AActor , public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	AItem();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(Category = Item)
	AItem* CreateItemCopy();

	UFUNCTION(Category = Item)
	void SetQuantity(const int32 NewQuantity);

	UFUNCTION(Category = Item)
	virtual void Use(class ABaseCharacter* Character);

	/**
	* Item Data
	*/
	//UPROPERTY()
	//UInventoryComponent* OwningInventory;
	
	UPROPERTY(VisibleAnywhere, Category = "Item Data")
	int32 Quantity;

	UPROPERTY(VisibleAnywhere, Category = "Item Data")
	FName ID;

	UPROPERTY(VisibleAnywhere, Category = "Item Data")
	EItemType ItemType;

	UPROPERTY(VisibleAnywhere, Category = "Item Data")
	EItemQuality ItemQuality;

	UPROPERTY(VisibleAnywhere, Category = "Item Data")
	FItemStatistics ItemStatistics;

	UPROPERTY(VisibleAnywhere, Category = "Item Data")
	FItemTextData TextData;

	UPROPERTY(VisibleAnywhere, Category = "Item Data")
	FItemNumericData NumericData;

	UPROPERTY(VisibleAnywhere, Category = "Item Data")
	FItemAssetData AssetData;
	/**
	* Item Data
	*/
protected:
	virtual void BeginPlay() override;

	/**
	* InteractionInterface
	*/

	UPROPERTY(EditInstanceOnly,Category = "Test")
	FInteractableData InstanceItneractableData;

	virtual void BeginFocus() override;
	virtual void EndFocus() override;
	virtual void BeginInteract() override;
	virtual void EndInteract() override;
	virtual void Interact(class ASlashCharacter* PlayerCharacter) override;
	/*** InteractionInterface*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float Amplitude = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float TimeConstant = 5.f;

	UFUNCTION(BlueprintPure)
	float TransformedSin();

	UFUNCTION(BlueprintPure)
	float TransformedCos();

	template<typename T>
	T Avg(T First, T Second);

	UFUNCTION()
	virtual void OnSphereOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnSphereEndOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

	virtual void SpawnPickupSystem();
	virtual void SpawnPickupSound();

	bool operator==(const FName& OtherID) const
	{
		return ID == OtherID;
	}

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* ItemMesh;


	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;

	EItemState ItemState = EItemState::EIS_Hovering;


	UPROPERTY(EditAnywhere)
	UNiagaraComponent* ItemEffect;

	UPROPERTY(EditAnywhere)
	USoundBase* PickupSound;
private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;

	UPROPERTY(EditAnywhere)
	UNiagaraSystem* PickupEffect;

public:

	UFUNCTION(Category = Item)
	FORCEINLINE float GetItemStackWeight() const { return Quantity * NumericData.Weight; }

	UFUNCTION(Category = Item)
	FORCEINLINE float GetItemSingleWeight() const { return NumericData.Weight; }

	UFUNCTION(Category = Item)
	FORCEINLINE bool IsFullItemStack() const { return Quantity == NumericData.MaxStackSize; }
	
	
};

template<typename T>
inline T AItem::Avg(T First, T Second)
{
	return (First + Second) / 2;
}
