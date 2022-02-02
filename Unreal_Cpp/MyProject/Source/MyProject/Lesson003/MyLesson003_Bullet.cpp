#include "MyLesson003_Bullet.h"
#include "MyLesson003_CubeComponent.h"

AMyLesson003_Bullet2::AMyLesson003_Bullet2() {
	PrimaryActorTick.bCanEverTick = true;

	CubeComponent = CreateDefaultSubobject<UMyLesson003_CubeComponent>(TEXT("CubeComponent"));
	RootComponent = CubeComponent;
	CubeComponent->SetRelativeScale3D(FVector(0.5f, 0.25f, 0.25f));
}

void AMyLesson003_Bullet2::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	auto Loc = GetActorLocation();
	Loc += GetActorForwardVector() * (MoveSpeed * DeltaSeconds);
	SetActorLocation(Loc);
}

