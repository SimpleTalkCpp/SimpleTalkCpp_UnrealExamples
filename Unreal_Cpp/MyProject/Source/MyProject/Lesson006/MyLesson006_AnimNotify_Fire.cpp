#include "MyLesson006_AnimNotify_Fire.h"
#include "MyLesson006_Character.h"

void UMyLesson006_AnimNotify_Fire::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) {
	Super::Notify(MeshComp, Animation);
	if (!MeshComp) return;
	auto* ch = Cast<AMyLesson006_Character>(MeshComp->GetOwner());
	if (!ch) return;
	ch->AnimNotify_Fire();
}

