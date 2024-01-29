// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DialogueRenderer.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class OFFICEESCAPE_01_API UDialogueRenderer : public UWorldSubsystem
{
	GENERATED_BODY()
protected:
	

	
public:
	UDialogueRenderer();

	void DisplayDialogue(const FString& Speaker, const FString& Message);
	void DisplayChoices(const TArray<FString>& Choices);
	void ClearScreen();
};
