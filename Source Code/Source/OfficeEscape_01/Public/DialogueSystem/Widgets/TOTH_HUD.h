// Created By Hollow Game Studios

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TOTH_HUD.generated.h"

/**
 * 
 */
UCLASS()
class OFFICEESCAPE_01_API ATOTH_HUD : public AHUD
{
	GENERATED_BODY()

public:
	// Function to draw HUD elements
	virtual void DrawHUD() override;
	// Function to display dialogue
	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	void DisplayDialogue(const FString& Speaker, const FString& Message);
};
