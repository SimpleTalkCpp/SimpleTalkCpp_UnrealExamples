#include "MyLesson006_AnimInstance.h"
#include "MyLesson006_Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UMyLesson006_AnimInstance::UMyLesson006_AnimInstance() {
}

void UMyLesson006_AnimInstance::NativeUpdateAnimation(float DeltaSeconds) {
	auto* Mesh = GetSkelMeshComponent();
	if (!Mesh) return;

	MyCharacter = Cast<AMyLesson006_Character>(Mesh->GetOwner());
	if (!MyCharacter) return;

	_UpdateMove();
	_UpdateAim();
	_UpdateSlotWeight();
}

void UMyLesson006_AnimInstance::_UpdateMove() {
	auto* charMove = MyCharacter->GetCharacterMovement();

	auto vel = charMove->Velocity;
	vel = MyCharacter->GetTransform().InverseTransformVector(vel);

	vel /= charMove->MaxWalkSpeed;

	MoveForward = vel.X;
	MoveRight   = vel.Y;

	MyCrouch = MyCharacter->MyCrouch;

	IsMovingGround = charMove->IsMovingOnGround();
}

void UMyLesson006_AnimInstance::_UpdateAim() {
	if (auto* t = MyCharacter->Target.Get()) {
		FVector targetLoc = t->GetActorLocation();
		FVector aim = MyCharacter->GetTransform().InverseTransformPosition(targetLoc);
		auto rot = aim.Rotation();
		AimUp    = rot.Pitch;
		AimRight = rot.Yaw;
	} else {
		AimUp    = 0;
		AimRight = 0;
	}
}

void UMyLesson006_AnimInstance::_UpdateSlotWeight() {
	static FName UpperName(TEXT("Upper"));
	UpperSlotWeight = GetMontageSlotWeight(UpperName);
}

float UMyLesson006_AnimInstance::GetMontageSlotWeight(FName slot) {
	float outWeight = 0;

	int32 const NumInstances = MontageInstances.Num();
	for (int32 InstanceIndex = NumInstances - 1; InstanceIndex >= 0; InstanceIndex--) {
		const FAnimMontageInstance* MontageInstance = MontageInstances[InstanceIndex];
		if (!MontageInstance || !MontageInstance->IsActive()) continue;
		if (!MontageInstance->Montage->IsValidSlot(slot)) continue;
		outWeight += MontageInstance->GetWeight();
	}

	outWeight = FMath::Clamp(outWeight, 0.0f, 1.0f);
	return outWeight;
}
