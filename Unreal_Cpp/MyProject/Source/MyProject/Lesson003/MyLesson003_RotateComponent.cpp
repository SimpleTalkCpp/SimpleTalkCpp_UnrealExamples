#include "MyLesson003_RotateComponent.h"

UMyLesson003_RotateComponent::UMyLesson003_RotateComponent() {
	PrimaryComponentTick.bCanEverTick = true;
//	PrimaryComponentTick.bTickEvenWhenPaused = true;
//	PrimaryComponentTick.TickGroup = TG_PrePhysics;
}

void UMyLesson003_RotateComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

//	MY_LOG("UMyLesson003_RotateComponent Tick");

	auto* Actor = GetOwner();
	auto Rot = Actor->GetActorRotation();
	Rot.Yaw += RotateSpeed * DeltaTime;
	Actor->SetActorRotation(Rot);
}
