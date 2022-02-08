#pragma once

#include "GameFramework/PlayerController.h"
#include "MyLesson006_PlayerController.generated.h"

UCLASS()
class AMyLesson006_PlayerController : public APlayerController {
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, Transient)
	FVector InputDirection;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;

	virtual void SetupInputComponent() override;

	void OnInputAxis_MoveForward(float value);
	void OnInputAxis_MoveRight	(float value);

	void OnInputAction_Crouch_Pressed();
	void OnInputAction_Fire_Pressed();
	void OnInputAction_Jump_Pressed();

	UPROPERTY(VisibleAnywhere)
	class AMyLesson006_Character*	MyCharacter = nullptr;
};