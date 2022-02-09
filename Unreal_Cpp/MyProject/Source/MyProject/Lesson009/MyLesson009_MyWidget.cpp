#include "MyLesson009_MyWidget.h"
#include "../Common/MyCommon.h"
#include "MyLesson009_ListItem.h"

void UMyLesson009_MyWidget::NativeOnInitialized() {
	Super::NativeOnInitialized();
	MyButton->OnPressed.AddDynamic(this, &ThisClass::OnButtonPressed);
}

void UMyLesson009_MyWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime) {
	Super::NativeTick(MyGeometry, InDeltaTime);

	_Count++;

	FString str = MyFormat("TextBlock {}", _Count);
	MyTextBlock->SetText(FText::FromString(str));
}

void UMyLesson009_MyWidget::OnButtonPressed() {
	MY_LOG("OnButtonPressed");

	if (MyListView) {
		UMyLesson009_ListItemData* item = NewObject<UMyLesson009_ListItemData>();
		item->testInt = _Count;

		MyListView->AddItem(item);
	}
}

