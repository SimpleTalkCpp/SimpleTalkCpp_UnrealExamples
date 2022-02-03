#pragma once

#include "Animation/SkeletalMeshActor.h"
#include "MyLesson005_Actor.generated.h"

UCLASS()
class AMyLesson005_Actor : public ASkeletalMeshActor {
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	float TestBlend = 0.5f;

};
