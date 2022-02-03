#include "MyLesson004_GameMode.h"

#include "MyLesson004_PlayerController.h"
#include "MyLesson004_Pawn.h"

AMyLesson004_GameMode::AMyLesson004_GameMode() {
	PlayerStateClass = nullptr;
	GameStateClass = nullptr;
	SpectatorClass = nullptr;
	HUDClass = nullptr;

//	PlayerControllerClass = nullptr;
	PlayerControllerClass = AMyLesson004_PlayerController::StaticClass();

//	DefaultPawnClass = nullptr;
	DefaultPawnClass = AMyLesson004_Pawn::StaticClass();
}

void AMyLesson004_GameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) {
	Super::InitGame(MapName, Options, ErrorMessage);
	MY_LOG("AMyLesson004_GameMode::InitGame()");
}

void AMyLesson004_GameMode::InitGameState() {
	Super::InitGameState();
	MY_LOG("AMyLesson004_GameMode::InitGameState()");
}

void AMyLesson004_GameMode::StartPlay() {
	Super::StartPlay();
	MY_LOG("AMyLesson004_GameMode::StartPlay()");
}

