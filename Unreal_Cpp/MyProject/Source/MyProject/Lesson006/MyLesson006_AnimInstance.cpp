#include "MyLesson006_AnimInstance.h"
#include "MyLesson006_Character.h"

UMyLesson006_AnimInstance::UMyLesson006_AnimInstance() {
}

void UMyLesson006_AnimInstance::NativeUpdateAnimation(float DeltaSeconds) {
	auto* Mesh = GetSkelMeshComponent();
	if (!Mesh) return;

	MyCharacter = Cast<AMyLesson006_Character>(Mesh->GetOwner());
	if (!MyCharacter) return;


	_UpdateAim();
}

void UMyLesson006_AnimInstance::_UpdateAim() {
	FVector aim = MyCharacter->AimLocator->GetRelativeLocation();
	auto rot = aim.Rotation();
	AimUp    = rot.Pitch;
	AimRight = rot.Yaw;
}
