#pragma once

#include <Blueprint/UserWidget.h>
#include <Components/Button.h>
#include <Components/TextBlock.h>
#include <Components/ListView.h>
#include "MyLesson009_MyWidget.generated.h"

UCLASS()
class UMyLesson009_MyWidget : public UUserWidget {
	GENERATED_BODY()
public:

	UMyLesson009_MyWidget(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, Transient, meta=(BindWidget)) UTextBlock*	MyTextBlock	= nullptr;
	UPROPERTY(EditAnywhere, Transient, meta=(BindWidget)) UButton*		MyButton	= nullptr;
	UPROPERTY(EditAnywhere, Transient, meta=(BindWidget)) UListView*	MyListView	= nullptr;

	virtual void NativeOnInitialized() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UFUNCTION()
	void OnButtonPressed();

	int _Count = 0;
};