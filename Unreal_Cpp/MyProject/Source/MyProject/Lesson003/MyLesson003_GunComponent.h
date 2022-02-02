#pragma once

#include "../Common/MyCommon.h"

#include "MyLesson003_CubeComponent.h"
#include "MyLesson003_GunComponent.generated.h"

UCLASS()
class UMyLesson003_GunComponent : public UMyLesson003_CubeComponent {
	GENERATED_BODY()
public:
	UMyLesson003_GunComponent();
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
};
