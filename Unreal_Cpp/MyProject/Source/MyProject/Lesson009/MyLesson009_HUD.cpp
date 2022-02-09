#include "MyLesson009_HUD.h"
#include "../Common/MyCommon.h"
#include <UObject/ConstructorHelpers.h>

AMyLesson009_HUD::AMyLesson009_HUD() {
	static ConstructorHelpers::FClassFinder<UMyLesson009_MyWidget> cls(TEXT("WidgetBlueprint'/Game/SimpleTalkCpp/Lesson009/WBP_Lesson009_MyWidget'"));
	MyWidgetClass = cls.Class;
}

void AMyLesson009_HUD::BeginPlay() {
	Super::BeginPlay();
	CreateMyWidget();
}

void AMyLesson009_HUD::CreateMyWidget() {
	if (!MyWidgetClass) {
		MY_LOG("MyWidgetClass is null");
		return;
	}
	
	// HUD cannot be the owner
	// from CreateWidget()
	//		static_assert(TIsDerivedFrom<OwnerT, UWidget>::IsDerived
	//			|| TIsDerivedFrom<OwnerT, UWidgetTree>::IsDerived
	//			|| TIsDerivedFrom<OwnerT, APlayerController>::IsDerived
	//			|| TIsDerivedFrom<OwnerT, UGameInstance>::IsDerived
	//			|| TIsDerivedFrom<OwnerT, UWorld>::IsDerived, "The given OwningObject is not of a supported type for use with CreateWidget.");

	MyWidget = CreateWidget<UMyLesson009_MyWidget>(GetWorld(), MyWidgetClass);
	if (!MyWidget) {
		MY_LOG("Error CreateWidget");
		return;
	}

	MyWidget->AddToViewport();
}
