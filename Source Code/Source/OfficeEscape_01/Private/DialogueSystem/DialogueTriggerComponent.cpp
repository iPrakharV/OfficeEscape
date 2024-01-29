// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueSystem/DialogueTriggerComponent.h"


#include "DialogueSystem/DialogueManagerSubsystem.h"
#include "Kismet/GameplayStatics.h"



void UDialogueTriggerComponent::GetDialogueManager()
{
	if (!DialogueManager)
	{
		DialogueManager = GetWorld()->GetSubsystem<UDialogueManagerSubsystem>();
		if(DialogueManager) UE_LOG(LogTemp, Warning, TEXT("DiologueManager found!"))
	}
}

// Sets default values for this component's properties
UDialogueTriggerComponent::UDialogueTriggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	/// ~Dialogue Controls
	bEnabled = false;
	
	DialogueManager = nullptr;
	
}


// Called when the game starts
void UDialogueTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
	// Get Reference to the DialogueManager
	GetDialogueManager();
	// ...
	
}


// Called every frame
void UDialogueTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                              FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDialogueTriggerComponent::TriggerDialogue()
{
	if(DialogueManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("Asking DialogueManager to start dialogue"))
		DialogueManager->StartDialogue(DialogueNodes);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("DialogueManager not found in the world."));
		UE_LOG(LogTemp, Warning, TEXT("Searching for a Dialogue Manager in the world..."));
		GetDialogueManager();
	}
}

