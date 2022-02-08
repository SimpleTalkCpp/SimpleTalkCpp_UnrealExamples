#include "MyLesson006_PlayerController.h"
#include "MyLesson006_Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <Kismet/GameplayStatics.h>

void AMyLesson006_PlayerController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	BaseTurnRate   = 45.f;
	BaseLookUpRate = 45.f;

	auto* ch = Cast<AMyLesson006_Character>(GetPawn());
	if (!ch) return;

	auto v = ch->GetTransform().TransformVector(InputDirection);
	
	v *= FMath::Clamp(1 - ch->BlockMoveCurveValue, 0.0f, 1.0f);

	ch->GetMovementComponent()->AddInputVector(v);
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

	InputComponent->BindAxis("Turn",			this, &ThisClass::OnInputAxis_Turn);
	InputComponent->BindAxis("TurnRate",		this, &ThisClass::OnInputAxis_TurnRate);
	InputComponent->BindAxis("LookUp",			this, &ThisClass::OnInputAxis_Lookup);
	InputComponent->BindAxis("LookUpRate",		this, &ThisClass::OnInputAxis_LookupRate);

	// Action
	InputComponent->BindAction("Crouch",		IE_Pressed,	this, &ThisClass::OnInputAction_Crouch_Pressed);
	InputComponent->BindAction("Equip",			IE_Pressed,	this, &ThisClass::OnInputAction_Equip_Pressed);
	InputComponent->BindAction("Fire",			IE_Pressed,	this, &ThisClass::OnInputAction_Fire_Pressed);
	InputComponent->BindAction("Jump",			IE_Pressed,	this, &ThisClass::OnInputAction_Jump_Pressed);
}

void AMyLesson006_PlayerController::OnInputAxis_MoveForward(float value) {
	InputDirection.X = value;
}

void AMyLesson006_PlayerController::OnInputAxis_MoveRight(float value) {
	InputDirection.Y = value;
}

void AMyLesson006_PlayerController::OnInputAxis_Turn(float value) {
	AddYawInput(value);
}

void AMyLesson006_PlayerController::OnInputAxis_TurnRate(float value) {
	AddYawInput(value * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMyLesson006_PlayerController::OnInputAxis_Lookup(float value) {
	AddPitchInput(value);
}

void AMyLesson006_PlayerController::OnInputAxis_LookupRate(float value) {
	AddPitchInput(value * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AMyLesson006_PlayerController::OnInputAction_Crouch_Pressed() {
	if (!MyCharacter) return;
	MyCharacter->MyCrouch = !MyCharacter->MyCrouch;
}

void AMyLesson006_PlayerController::OnInputAction_Equip_Pressed() {
	if (!MyCharacter) return;
	MyCharacter->MyEquip();
}

void AMyLesson006_PlayerController::OnInputAction_Fire_Pressed() {
	if (!MyCharacter) return;
	MyCharacter->MyFire();
}

void AMyLesson006_PlayerController::OnInputAction_Jump_Pressed() {
	if (!MyCharacter) return;
	MyCharacter->Jump();
}
