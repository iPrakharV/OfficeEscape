// Created By Hollow Game Studios

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RenderComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class OFFICEESCAPE_01_API URenderComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	URenderComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	// Reference to the dialogue widget class
	UPROPERTY(EditDefaultsOnly, Category = "Dialogue")
	TSubclassOf<UUserWidget> DialogueWidgetClass;

	// Reference to the created dialogue widget
	UUserWidget* DialogueWidget;
	
	struct FDialogueMessage
	{
		FString Speaker;
		FString Message;
	};

	TArray<FDialogueMessage> DialogueQueue;
	
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	// Function to display dialogue
	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	void DisplayDialogue(const FString& Speaker, const FString& Message);

	UFUNCTION(BlueprintCallable, Category= "Dialogue")
	void ClearScreen();
};
