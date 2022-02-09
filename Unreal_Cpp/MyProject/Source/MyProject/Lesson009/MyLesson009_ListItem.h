#pragma once

#include "../Common/MyCommon.h"

#include <Blueprint/UserWidget.h>
#include <Blueprint/IUserObjectListEntry.h>
#include <Components/TextBlock.h>

#include "MyLesson009_ListItem.generated.h"

UCLASS()
class UMyLesson009_ListItemData : public UObject {
	GENERATED_BODY()
public:
	int testInt = 0;
};

UCLASS()
class UMyLesson009_ListItemWidget : public UUserWidget, public IUserObjectListEntry {
	GENERATED_BODY()
public:	
	UPROPERTY(EditAnywhere) UTextBlock*	MyItemText = nullptr;

	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
};