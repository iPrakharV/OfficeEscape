// Created By Hollow Game Studios


#include "DialogueSystem/RenderComponent.h"

#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
URenderComponent::URenderComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	// Set default class for the dialogue widget
	static ConstructorHelpers::FClassFinder<UUserWidget> WidgetClassFinder(TEXT("/Game/YourPath/To/DialogueWidget"));
	DialogueWidgetClass = WidgetClassFinder.Class;
}


// Called when the game starts
void URenderComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URenderComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void URenderComponent::DisplayDialogue(const FString& Speaker, const FString& Message)
{
	FDialogueMessage NewDialogueMessage;
	NewDialogueMessage.Speaker = Speaker;
	NewDialogueMessage.Message = Message;

	DialogueQueue.Add(NewDialogueMessage);
	
	if (DialogueWidgetClass)
	{
		// Remove the previously displayed widget
		if (DialogueWidget)
		{
			DialogueWidget->RemoveFromParent();
			DialogueWidget = nullptr;
		}
		// Create an instance of the dialogue widget
		DialogueWidget = CreateWidget<UUserWidget>(GetWorld(), DialogueWidgetClass);

		if (DialogueWidget)
		{
			// Set the text in the widget
			UTextBlock* TextBlock = Cast<UTextBlock>(DialogueWidget->GetWidgetFromName(TEXT("DialogueTextBlock")));
			if (TextBlock)
			{
				TextBlock->SetText(FText::FromString(FString::Printf(TEXT("%s: %s"), *Speaker, *Message)));
			}

			// Add the widget to the viewport
			DialogueWidget->AddToViewport();

			// Remove the displayed message from the queue
			DialogueQueue.RemoveAt(0);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to create DialogueWidget!"));
		}
	}
}

void URenderComponent::ClearScreen()
{
	// Remove the previously displayed widget
	if (DialogueWidget)
	{
		DialogueWidget->RemoveFromParent();
		DialogueWidget = nullptr;
	}
	DialogueQueue.Empty();
}

