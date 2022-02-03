#pragma once

#include "../Common/MyCommon.h"
#include "Engine/GameInstance.h"

#include "MyLesson004_GameInstance.generated.h"

UCLASS()
class UMyLesson004_GameInstance : public UGameInstance {
	GENERATED_BODY()
public:
	virtual void OnStart() override;
};