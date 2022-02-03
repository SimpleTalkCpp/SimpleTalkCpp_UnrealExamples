#include "MyLesson004_PlayerController.h"

#include <Kismet/GameplayStatics.h>

AMyLesson004_PlayerController::AMyLesson004_PlayerController() {
	InputDirection = FVector::ZeroVector;
}

void AMyLesson004_PlayerController::BeginPlay() {
	UpdateCameraTarget();
}

void AMyLesson004_PlayerController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	if (GEngine) {
		FString msg = MyFormat("InputDirection {}", InputDirection);
		GEngine->AddOnScreenDebugMessage(1, 2, FColor::Purple, msg);
	}

	if (auto* p = GetPawn()) {
		// p->AddMovementInput(InputDirection, 1);
		auto Loc = p->GetActorLocation();
		Loc += InputDirection * 100 * DeltaSeconds;
		p->SetActorLocation(Loc);
	}
}

void AMyLesson004_PlayerController::SetupInputComponent() {
	Super::SetupInputComponent();

	SetShowMouseCursor(true);

	// Axis
	InputComponent->BindAxis("MoveForward",		this, &ThisClass::OnInputAxis_MoveForward);
	InputComponent->BindAxis("MoveRight",		this, &ThisClass::OnInputAxis_MoveRight);

	// Action
	InputComponent->BindAction("Jump",				IE_Pressed,		this, &ThisClass::OnInputAction_Jump_Pressed);
	InputComponent->BindAction("Jump",				IE_Released,	this, &ThisClass::OnInputAction_Jump_Released);
	InputComponent->BindAction("Jump",				IE_Axis,		this, &ThisClass::OnInputAction_Jump_Axis);
	InputComponent->BindAction("Jump",				IE_Repeat,		this, &ThisClass::OnInputAction_Jump_Repeat);
	InputComponent->BindAction("Jump",				IE_DoubleClick, this, &ThisClass::OnInputAction_Jump_DoubleClick);

	InputComponent->BindAction("MyChangeCamera",	IE_Pressed,		this, &ThisClass::OnInputAction_MyChangeCamera);
}

void AMyLesson004_PlayerController::OnInputAxis_MoveForward(float value) { InputDirection.X = value; }
void AMyLesson004_PlayerController::OnInputAxis_MoveRight  (float value) { InputDirection.Y = value; }

void AMyLesson004_PlayerController::OnInputAction_Jump_Pressed()		{ MY_LOG("Jump_Pressed"); }
void AMyLesson004_PlayerController::OnInputAction_Jump_Released()		{ MY_LOG("Jump_Released"); }
void AMyLesson004_PlayerController::OnInputAction_Jump_Axis()			{ MY_LOG("Jump_Axis"); }
void AMyLesson004_PlayerController::OnInputAction_Jump_Repeat()			{ MY_LOG("Jump_Repeat"); }
void AMyLesson004_PlayerController::OnInputAction_Jump_DoubleClick()	{ MY_LOG("Jump_DoubleClick"); }

void AMyLesson004_PlayerController::OnInputAction_MyChangeCamera() {
	MY_LOG("MyChangeCamera");
	CurrentCameraIndex++;

	UpdateCameraTarget();
}

void AMyLesson004_PlayerController::UpdateCameraTarget() {
	static FName MyCameraTag(TEXT("MyCamera"));

	TArray<AActor*> CameraList;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), MyCameraTag, CameraList);

	int N = CameraList.Num();
	if (N <= 0) return;

	auto* Cam = CameraList[CurrentCameraIndex % N];
	SetViewTargetWithBlend(Cam);
}
