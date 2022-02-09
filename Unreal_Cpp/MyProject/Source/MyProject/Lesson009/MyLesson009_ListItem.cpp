#include "MyLesson009_ListItem.h"

void UMyLesson009_ListItemWidget::NativeOnListItemObjectSet(UObject* ListItemObject) {
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	auto* item = Cast<UMyLesson009_ListItemData>(ListItemObject);
	if (!item) {
		MY_LOG("Error UMyLesson009_ListItemData");
		return;
	}

	FString str = MyFormat("ListItem {}", item->testInt);
	MyItemText->SetText(FText::FromString(str));
}

