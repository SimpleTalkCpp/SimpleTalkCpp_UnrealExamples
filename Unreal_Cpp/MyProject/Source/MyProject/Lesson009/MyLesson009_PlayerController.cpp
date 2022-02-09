#include "MyLesson009_PlayerController.h"
#include "MyLesson009_NavigationConfig.h"

#include <UObject/ConstructorHelpers.h>

AMyLesson009_PlayerController::AMyLesson009_PlayerController() {
	static ConstructorHelpers::FClassFinder<UMyLesson009_MyWidget> cls(TEXT("WidgetBlueprint'/Game/SimpleTalkCpp/Lesson009/WBP_Lesson009_MyWidget'"));
	MyWidgetClass = cls.Class;
}

void AMyLesson009_PlayerController::BeginPlay() {
	Super::BeginPlay();

	SetShowMouseCursor(true);

	CreateMyWidget();
	FMyLesson009_NavigationConfig::Init(this);
}

void AMyLesson009_PlayerController::CreateMyWidget() {
	if (!MyWidgetClass) {
		MY_LOG("MyWidgetClass is null");
		return;
	}
	
	MyWidget = CreateWidget<UMyLesson009_MyWidget>(this, MyWidgetClass);
	if (!MyWidget) {
		MY_LOG("Error CreateWidget");
		return;
	}

	MyWidget->AddToViewport();
	MyWidget->SetKeyboardFocus();
}