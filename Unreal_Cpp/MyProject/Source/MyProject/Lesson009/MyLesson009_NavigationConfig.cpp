#include "MyLesson009_NavigationConfig.h"

struct FMyLesson009_NavigationConfig::KeyMap {
	TMap<FName, EUINavigationAction>	ActionMap;
	TMap<FName, EUINavigation>			DirectionMap;

	KeyMap() {
		DirectionMap.Add("UI_Up",		EUINavigation::Up);
		DirectionMap.Add("UI_Down",		EUINavigation::Down);
		DirectionMap.Add("UI_Left",		EUINavigation::Left);
		DirectionMap.Add("UI_Right",	EUINavigation::Right);
		DirectionMap.Add("UI_Prev",		EUINavigation::Previous);
		DirectionMap.Add("UI_Next",		EUINavigation::Next);

		ActionMap.Add("UI_Accept",	EUINavigationAction::Accept);
		ActionMap.Add("UI_Back",	EUINavigationAction::Back);
	}
};

void FMyLesson009_NavigationConfig::Init(APlayerController* PC) {
	TSharedRef<FMyLesson009_NavigationConfig> NavConfig = MakeShareable(new FMyLesson009_NavigationConfig());
	NavConfig->_InitActionMap(PC);

	auto& app = FSlateApplication::Get();
	app.SetNavigationConfig(MoveTemp(NavConfig));
}

void FMyLesson009_NavigationConfig::_InitActionMap(APlayerController* PC) {
	static KeyMap _KeyMap;

	if (!PC || !PC->PlayerInput) return;

	for (auto& It : PC->PlayerInput->ActionMappings) {
		if (EUINavigationAction* action = _KeyMap.ActionMap.Find(It.ActionName)) {
			_KeyToActionMap.Add(It.Key.GetFName(), *action);
		}

		if (EUINavigation* Dir = _KeyMap.DirectionMap.Find(It.ActionName)) {
			_KeyToDirectionMap.Add(It.Key.GetFName(), *Dir);
		}

		if (It.ActionName.ToString().StartsWith("UI_")) {
			_KeyToPlayerControllerMap.Add(It.Key.GetFName(), It.ActionName);
		}
	}
#if WITH_EDITOR
	for (auto& It : _KeyMap.ActionMap) {
		if (!FindInputAction(PC->PlayerInput, It.Key)) {
			MY_LOG("UINavigation missing Action {}", It.Key);
		}
	}

	for (auto& It : _KeyMap.DirectionMap) {
		if (!FindInputAxis(PC->PlayerInput, It.Key)) {
			MY_LOG("UINavigation missing Action {}", It.Key);
		}
	}

#endif
}

FInputAxisKeyMapping* FMyLesson009_NavigationConfig::FindInputAxis(UPlayerInput* Input, FName AxisName) {
	if (!Input) return nullptr;
	for (auto& E : Input->AxisMappings) {
		if (E.AxisName == AxisName)
			return &E;
	}
	return nullptr;
}

FInputActionKeyMapping* FMyLesson009_NavigationConfig::FindInputAction(UPlayerInput* Input, FName ActionName) {
	if (!Input) return nullptr;
	for (auto& E : Input->ActionMappings) {
		if (E.ActionName == ActionName)
			return &E;
	}
	return nullptr;
}

EUINavigation FMyLesson009_NavigationConfig::GetNavigationDirectionFromKey(const FKeyEvent& InKeyEvent) const {
	auto key = InKeyEvent.GetKey().GetFName();
	if (auto* dir = _KeyToDirectionMap.Find(key)) {
		MY_LOG("GetNavigationDirectionFromKey {} -> {}", key, MyEnumToFName(*dir));
		return *dir;
	}
	return EUINavigation::Invalid;
}

EUINavigation FMyLesson009_NavigationConfig::GetNavigationDirectionFromAnalog(const FAnalogInputEvent& InAnalogEvent) {
	return Super::GetNavigationDirectionFromAnalog(InAnalogEvent);
}

EUINavigationAction FMyLesson009_NavigationConfig::GetNavigationActionFromKey(const FKeyEvent& InKeyEvent) const {
	auto key = InKeyEvent.GetKey().GetFName();
	if (auto* act = _KeyToActionMap.Find(key)) {
		MY_LOG("GetNavigationActionFromKey {} -> {}", key, MyEnumToFName(*act));
		return *act;
	}

	return EUINavigationAction::Invalid;
}

void FMyLesson009_NavigationConfig::OnNavigationChangedFocus(TSharedPtr<SWidget> OldWidget, TSharedPtr<SWidget> NewWidget, FFocusEvent FocusEvent) {
	Super::OnNavigationChangedFocus(OldWidget, NewWidget, FocusEvent);
}
