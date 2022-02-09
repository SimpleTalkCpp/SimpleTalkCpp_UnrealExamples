#pragma once

#include <GameFramework/HUD.h>
#include "MyLesson009_MyWidget.h"
#include "MyLesson009_HUD.generated.h"

UCLASS()
class AMyLesson009_HUD : public AHUD {
	GENERATED_BODY()
public:
	AMyLesson009_HUD();

	UPROPERTY(EditAnywhere)
	TSubclassOf<UMyLesson009_MyWidget> MyWidgetClass;

	UPROPERTY(EditAnywhere)
	UMyLesson009_MyWidget* MyWidget = nullptr;

	virtual void BeginPlay() override;

	void CreateMyWidget();
};