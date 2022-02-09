#pragma once

#include "../Common/MyCommon.h"
#include <Framework/Application/NavigationConfig.h>
#include <GameFramework/PlayerInput.h>

// Show Focus Border - Project Settings -> User Interface* and then look for Focus -> "Render Focus Rule"

struct FMyLesson009_NavigationConfig : public FNavigationConfig {
	using Super = FNavigationConfig;

	virtual EUINavigation		GetNavigationDirectionFromKey	(const FKeyEvent& InKeyEvent) const override;
	virtual EUINavigation		GetNavigationDirectionFromAnalog(const FAnalogInputEvent& InAnalogEvent) override;
	virtual EUINavigationAction	GetNavigationActionFromKey		(const FKeyEvent& InKeyEvent) const override;

	virtual void OnNavigationChangedFocus(TSharedPtr<SWidget> OldWidget, TSharedPtr<SWidget> NewWidget, FFocusEvent FocusEvent);

	static void Init(APlayerController* PC);

private:
	struct KeyMap;

	void _InitActionMap(APlayerController* PC);

	static FInputActionKeyMapping*	FindInputAction	(UPlayerInput* Input, FName ActionName);

	TMap<FName, EUINavigationAction>	_KeyToActionMap;
	TMap<FName, EUINavigation>			_KeyToDirectionMap;
	TMap<FName, FName>					_KeyToPlayerControllerMap;
};
