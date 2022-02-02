#pragma once

#include "../Common/MyCommon.h"
#include "MyLesson003_RotateComponent.generated.h"

UCLASS(ClassGroup=MyProject, meta=(BlueprintSpawnableComponent))
class UMyLesson003_RotateComponent : public UActorComponent {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float RotateSpeed = 100;

	UMyLesson003_RotateComponent();
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
};

