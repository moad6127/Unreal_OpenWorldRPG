// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SlashHUD.generated.h"

struct FInteractableData;
class USlashOverlay;
class UMainManu;
class UInteractionWidget;

UCLASS()
class SLASH_API ASlashHUD : public AHUD
{
	GENERATED_BODY()
public:

	ASlashHUD();
	void DisplayMenu();
	void HideMenu();

	void ShowInteractionWidget();
	void HideInteractionWidget();
	void UpdateInteractionWIdget(const FInteractableData* InteractableData);

protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditDefaultsOnly, Category = Slash)
	TSubclassOf<USlashOverlay> SlashOverlayClass;

	UPROPERTY(EditDefaultsOnly, Category = Widget)
	TSubclassOf<UMainManu> MainMenuClass;

	UPROPERTY(EditDefaultsOnly, Category = Widget)
	TSubclassOf<UInteractionWidget> InteractionWidgetClass;

	UPROPERTY()
	USlashOverlay* SlashOverlay;

	UPROPERTY()
	UMainManu* MainMenuWidget;

	UPROPERTY()
	UInteractionWidget* InteractionWidget;

	bool bIsMenuVisible;


public:
	FORCEINLINE USlashOverlay* GetSlashOverlay() const { return SlashOverlay; }
};
