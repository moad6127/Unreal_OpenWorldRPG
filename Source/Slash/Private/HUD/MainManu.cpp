// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/MainManu.h"
#include "Character/SlashCharacter.h"

void UMainManu::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UMainManu::NativeConstruct()
{
	Super::NativeConstruct();

	PlayerCharacter = Cast<ASlashCharacter>(GetOwningPlayerPawn());
}

bool UMainManu::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation)
{
	return Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);

	//TODO cast operation item drag, drop player call drop Item 
}
