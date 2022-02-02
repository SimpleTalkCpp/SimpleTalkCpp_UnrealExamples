#include "MyLesson003_GunComponent.h"
#include "MyLesson003_Actor.h"

UMyLesson003_GunComponent::UMyLesson003_GunComponent() {
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickInterval = 0.5f;

	SetRelativeScale3D(FVector(0.2f, 0.2f, 0.2f));
}

void UMyLesson003_GunComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

//	MY_LOG("Gun Tick");

	AActor* Actor = GetOwner();
	auto Loc = Actor->GetActorLocation();
	auto Rot = Actor->GetActorRotation();

	UClass* Cls = nullptr;
//	Cls = AMyLesson003_Bullet2::StaticClass();

	if (auto* Lesson003_Actor = Cast<AMyLesson003_Actor>(Actor)) {
		Cls = Lesson003_Actor->BulletClass.Get();
	}

	if (Cls) {
		GetWorld()->SpawnActor(Cls, &Loc, &Rot);
	}
}
