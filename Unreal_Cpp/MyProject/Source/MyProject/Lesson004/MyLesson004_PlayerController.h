#pragma once

#include "../Common/MyCommon.h"

#include "MyLesson004_PlayerController.generated.h"

UCLASS()
class AMyLesson004_PlayerController : public APlayerController {
	GENERATED_BODY()
public:

	AMyLesson004_PlayerController();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupInputComponent() override;

	UPROPERTY(VisibleAnywhere, Transient)
	FVector InputDirection;

	int CurrentCameraIndex = 0;

	void OnInputAxis_MoveForward(float value);
	void OnInputAxis_MoveRight	(float value);

	void OnInputAction_Jump_Pressed();
	void OnInputAction_Jump_Released();
	void OnInputAction_Jump_Axis();
	void OnInputAction_Jump_Repeat();
	void OnInputAction_Jump_DoubleClick();

	void OnInputAction_MyChangeCamera();
	void UpdateCameraTarget();
};