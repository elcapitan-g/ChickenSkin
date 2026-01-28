// Fill out your copyright notice in the Description page of Project Settings.

#include "SpotlightToggleActor.h"
#include "Components/SpotLightComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerController.h"

ASpotlightToggleActor::ASpotlightToggleActor()
{
	PrimaryActorTick.bCanEverTick = false;

	// create spotlight
	SpotLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotLight"));
	RootComponent = SpotLight;

	SpotLight->Intensity = 5000.f;
	SpotLight->SetVisibility(true);

	bIsLightOn = true;

	// Allow actor to receive input
	AutoReceiveInput = EAutoReceiveInput::Player0;
}

void ASpotlightToggleActor::BeginPlay()
{
	Super::BeginPlay();

	if (InputComponent)
	{
		InputComponent->BindAction("ToggleLight", IE_Pressed, this, &ASpotlightToggleActor::ToggleLight);
	}
}

void ASpotlightToggleActor::ToggleLight()
{
	bIsLightOn = !bIsLightOn;
	SpotLight->SetVisibility(bIsLightOn);
}

void ASpotlightToggleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
