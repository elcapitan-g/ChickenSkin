#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpotlightToggleActor.generated.h"

UCLASS()
class CHICKENSKIN_API ASpotlightToggleActor : public AActor
{
    GENERATED_BODY()

public:
    ASpotlightToggleActor();

protected:
    virtual void BeginPlay() override;

    // Spotlight component
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
    class USpotLightComponent* SpotLight;

    // Tracks light state
    bool bIsLightOn;

    // Function to toggle light
    void ToggleLight();

public:
    virtual void Tick(float DeltaTime) override;
};

