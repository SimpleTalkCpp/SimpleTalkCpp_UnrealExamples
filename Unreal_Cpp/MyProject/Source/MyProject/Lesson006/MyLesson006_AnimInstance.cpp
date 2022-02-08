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
}

void UMyLesson006_AnimInstance::_UpdateMove() {
	auto vel = MyCharacter->GetCharacterMovement()->Velocity;

	vel = MyCharacter->GetTransform().InverseTransformVector(vel);

	MoveForward = vel.X;
	MoveRight   = vel.Y;

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
