// Fill out your copyright notice in the Description page of Project Settings.


#include "MyLesson005_AnimInstance.h"
#include "MyLesson005_Actor.h"

void UMyLesson005_AnimInstance::NativeUpdateAnimation(float DeltaSeconds) {
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto* Mesh = GetSkelMeshComponent();
	if (!Mesh) return;

	auto* Actor = Cast<AMyLesson005_Actor>(Mesh->GetOwner());
	if (!Actor) return;

	TestBlend = Actor->TestBlend;
}
