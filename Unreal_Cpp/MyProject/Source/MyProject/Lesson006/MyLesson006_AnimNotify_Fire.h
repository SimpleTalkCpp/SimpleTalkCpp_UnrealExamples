#pragma once

#include <Animation/AnimNotifies/AnimNotify.h>
#include "MyLesson006_AnimNotify_Fire.generated.h"

UCLASS()
class UMyLesson006_AnimNotify_Fire : public UAnimNotify {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	int testInt = 1;

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};