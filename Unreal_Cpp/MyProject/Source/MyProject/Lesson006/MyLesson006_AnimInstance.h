#pragma once

#include <Animation/AnimInstance.h>
#include "MyLesson006_AnimInstance.generated.h"

UCLASS()
class UMyLesson006_AnimInstance : public UAnimInstance {
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Transient, BlueprintReadOnly)
	float MoveForward = 0;

	UPROPERTY(EditAnywhere, Transient, BlueprintReadOnly)
	float MoveRight = 0;

	UPROPERTY(EditAnywhere, Transient, BlueprintReadOnly)
	float AimUp = 0;

	UPROPERTY(EditAnywhere, Transient, BlueprintReadOnly)
	float AimRight = 0;

	UPROPERTY(VisibleAnywhere, Transient)
	class AMyLesson006_Character* MyCharacter = nullptr;


	UMyLesson006_AnimInstance();

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	void _UpdateMove();
	void _UpdateAim();

};