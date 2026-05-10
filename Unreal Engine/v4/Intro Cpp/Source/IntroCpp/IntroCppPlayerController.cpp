// Copyright Epic Games, Inc. All Rights Reserved.


#include "IntroCppPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "IntroCppCameraManager.h"

AIntroCppPlayerController::AIntroCppPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = AIntroCppCameraManager::StaticClass();
}

void AIntroCppPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
