#pragma once

#include "../Common/MyCommon.h"
#include <Animation/AnimNotifies/AnimNotify.h>
#include <Animation/AnimNotifies/AnimNotifyState.h>

#include "MyLesson006_AnimNotify_Fire.generated.h"

UCLASS()
class UMyLesson006_AnimNotify_Fire : public UAnimNotify {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	int testInt = 1;

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};

UCLASS()
class UMyLesson006_AnimNotifyState_Example : public UAnimNotifyState {
	GENERATED_BODY()
public:

	virtual void NotifyBegin(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, float TotalDuration) { 
		MY_LOG("AnimNotifyState_Example Begin"); 
	}
	
	virtual void NotifyTick(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, float FrameDeltaTime) {
//		MY_LOG("AnimNotifyState_Example Tick"); 
	}
	
	virtual void NotifyEnd(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation) {
		MY_LOG("AnimNotifyState_Example End");
	}
};