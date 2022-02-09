#pragma once

#include "../Common/MyCommon.h"
#include <GameFramework/PlayerController.h>

#include "MyLesson009_MyWidget.h"
#include "MyLesson009_PlayerController.generated.h"

UCLASS()
class AMyLesson009_PlayerController : public APlayerController {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UMyLesson009_MyWidget> MyWidgetClass;

	UPROPERTY(EditAnywhere)
	UMyLesson009_MyWidget* MyWidget = nullptr;

	AMyLesson009_PlayerController();
	virtual void BeginPlay() override;

	void CreateMyWidget();
	void SetCustomNavigationConfig();
};