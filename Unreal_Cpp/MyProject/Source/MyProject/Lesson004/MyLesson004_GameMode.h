#pragma once

#include "../Common/MyCommon.h"
#include "GameFramework/GameModeBase.h"

#include "MyLesson004_GameMode.generated.h"

UCLASS()
class AMyLesson004_GameMode : public AGameModeBase {
	GENERATED_BODY()
public:

	AMyLesson004_GameMode();
	
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	virtual void InitGameState() override;

	virtual void StartPlay() override;

};