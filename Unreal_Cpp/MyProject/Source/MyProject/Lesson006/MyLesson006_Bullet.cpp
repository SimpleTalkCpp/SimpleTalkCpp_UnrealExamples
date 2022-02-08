#include "MyLesson006_Bullet.h"
#include "../Common/MyCommon.h"


AMyLesson006_Bullet::AMyLesson006_Bullet() 
	: Speed(100)
	, SimPhysicTime(3)
	, Lifespan(5)
{
	PrimaryActorTick.bCanEverTick = true;

	static FName MeshComponentName("Mesh");
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(MeshComponentName);
	SetRootComponent(MeshComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	MeshComponent->SetStaticMesh(MeshObj.Object);
	MeshComponent->SetRelativeScale3D(FVector::OneVector * 0.25f);

	MeshComponent->SetMobility(EComponentMobility::Movable);
}

void AMyLesson006_Bullet::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
	_lifeTime += DeltaSeconds;

	if (_lifeTime > Lifespan) {
		Destroy();
		return;
	}

	if (_lifeTime > SimPhysicTime) {
		MeshComponent->SetSimulatePhysics(true);
		return;
	}

	auto Loc = GetActorLocation();
	Loc += GetActorForwardVector() * (Speed * DeltaSeconds);
	SetActorLocation(Loc);
}
