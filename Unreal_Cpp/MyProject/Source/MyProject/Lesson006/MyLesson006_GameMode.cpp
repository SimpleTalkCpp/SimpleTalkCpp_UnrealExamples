#include "MyLesson006_GameMode.h"
#include "MyLesson006_PlayerController.h"
#include "MyLesson006_Character.h"

AMyLesson006_GameMode::AMyLesson006_GameMode() {
	PlayerControllerClass = AMyLesson006_PlayerController::StaticClass();
	DefaultPawnClass      = AMyLesson006_Character::StaticClass();
}