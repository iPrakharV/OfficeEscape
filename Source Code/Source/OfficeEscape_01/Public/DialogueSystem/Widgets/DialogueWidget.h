// Created By Hollow Game Studios

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"

#include "DialogueWidget.generated.h"

/**
 * 
 */
UCLASS()
class OFFICEESCAPE_01_API UDialogueWidget : public UUserWidget
{
	GENERATED_BODY()
	

public:
	// Function to set the dialogue text
	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	void SetDialogueText(const FText& NewText);
	UFUNCTION(Blueprintable, Category = "Dialogue")
	FString GetDialogueText();
	// Text block to display dialogue text
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* DialogueTextBlock;
protected:
	// Called when the widget is created
	virtual void NativeConstruct() override;
	
	
};



inline void UDialogueWidget::SetDialogueText(const FText& NewText)
{
	if (DialogueTextBlock)
	{
		// Set the text in the TextBlock
		DialogueTextBlock->SetText(NewText);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("DialogueTextBlock not found!"));
	}
}

inline FString UDialogueWidget::GetDialogueText()
{
	return DialogueTextBlock->GetText().ToString();
}

inline void UDialogueWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Bind the TextBlock widget
	DialogueTextBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("DialogueTextBlock")));
}