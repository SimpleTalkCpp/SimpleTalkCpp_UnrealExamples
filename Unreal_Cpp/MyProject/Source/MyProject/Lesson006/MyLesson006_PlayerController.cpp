#include "MyLesson006_PlayerController.h"
#include "MyLesson006_Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <Kismet/GameplayStatics.h>

void AMyLesson006_PlayerController::BeginPlay() {
	Super::BeginPlay();

	{
		static FName MyCameraTag(TEXT("MyCamera"));
		TArray<AActor*> CameraList;
		UGameplayStatics::GetAllActorsWithTag(GetWorld(), MyCameraTag, CameraList);
		if (CameraList.Num() > 0) {
			SetViewTargetWithBlend(CameraList[0]);
		}
	}
}

void AMyLesson006_PlayerController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	auto* ch = Cast<AMyLesson006_Character>(GetPawn());
	if (!ch) return;

	ch->GetMovementComponent()->AddInputVector(InputDirection);
}

void AMyLesson006_PlayerController::OnPossess(APawn* aPawn) {
	Super::OnPossess(aPawn);
	MyCharacter = Cast<AMyLesson006_Character>(aPawn);
}

void AMyLesson006_PlayerController::OnUnPossess() {
	MyCharacter = nullptr;
	Super::OnUnPossess();
}

void AMyLesson006_PlayerController::SetupInputComponent() {
	Super::SetupInputComponent();

	SetShowMouseCursor(true);

	// Axis
	InputComponent->BindAxis("MoveForward",		this, &ThisClass::OnInputAxis_MoveForward);
	InputComponent->BindAxis("MoveRight",		this, &ThisClass::OnInputAxis_MoveRight);

	// Action
	InputComponent->BindAction("Crouch",		IE_Pressed,	this, &ThisClass::OnInputAction_Crouch_Pressed);
	InputComponent->BindAction("Fire",			IE_Pressed,	this, &ThisClass::OnInputAction_Fire_Pressed);
	InputComponent->BindAction("Jump",			IE_Pressed,	this, &ThisClass::OnInputAction_Jump_Pressed);
}

void AMyLesson006_PlayerController::OnInputAxis_MoveForward(float value) {
	InputDirection.X = value;
}

void AMyLesson006_PlayerController::OnInputAxis_MoveRight(float value) {
	InputDirection.Y = value;
}

void AMyLesson006_PlayerController::OnInputAction_Crouch_Pressed() {
	if (!MyCharacter) return;
	MyCharacter->MyCrouch = !MyCharacter->MyCrouch;
}

void AMyLesson006_PlayerController::OnInputAction_Fire_Pressed() {
	if (!MyCharacter) return;
	MyCharacter->MyFire();
}

void AMyLesson006_PlayerController::OnInputAction_Jump_Pressed() {
	if (!MyCharacter) return;
	MyCharacter->Jump();
}
