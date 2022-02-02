#include "MySpawnPoint.h"
#include "MyActor.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/BillboardComponent.h"
#include "MySceneComponent.h"
#include "NavigationSystem.h"

AMySpawnPoint::AMySpawnPoint() {
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = TG_PrePhysics;

	static ConstructorHelpers::FClassFinder<AActor> SpawnActorFinder(TEXT("Blueprint'/Game/MyProject/MyBox'"));
	SpawnActorClass = SpawnActorFinder.Class;

	BillboardComponent = CreateDefaultSubobject<UBillboardComponent>(UBillboardComponent::StaticClass()->GetFName());
	SetRootComponent(BillboardComponent);

	static ConstructorHelpers::FObjectFinder<UTexture2D> Texture(TEXT("Texture2D'/Engine/EditorResources/EmptyActor'"));
	BillboardComponent->Sprite = Texture.Object;

	static FName BoxName(TEXT("Box Test"));
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(BoxName);

	SphereComponent = CreateDefaultSubobject<USphereComponent>(USphereComponent::StaticClass()->GetFName());

	static FName Shpere2(TEXT("Sphere2"));
	SphereComponent2 = CreateDefaultSubobject<USphereComponent>(Shpere2);

	SphereComponent2->SetupAttachment(SphereComponent);

	MySceneComponent = CreateDefaultSubobject<UMySceneComponent>(UMySceneComponent::StaticClass()->GetFName());
}

FVector AMySpawnPoint::GetRandomLocation() {
	FVector Loc = GetActorLocation();

	if (auto* Nav = UNavigationSystemV1::GetCurrent(GetWorld())) {
		FNavLocation ResultLoc;
		if (Nav->GetRandomPointInNavigableRadius(Loc, Radius, ResultLoc)) {
			return ResultLoc.Location;
		} else {
			UE_LOG(LogTemp, Warning, TEXT("Error GetRandomPointInNavigableRadius !!"));
		}
	}
	
	FVector2D R = FMath::RandPointInCircle(Radius);
	Loc += FVector(R.X, R.Y, 0);
	return Loc;
}

void AMySpawnPoint::SpawnActor() {

	UE_LOG(LogTemp, Warning, TEXT("SpawnActor !!"));

	if (!SpawnActorClass.Get()) return;

	FVector Loc  = GetRandomLocation();
	FRotator Rot = GetActorRotation();

	AActor* NewActor = GetWorld()->SpawnActor<AActor>(SpawnActorClass.Get(), Loc, Rot);
	if (!NewActor) return;

#if WITH_EDITOR
	NewActor->SetFolderPath(TEXT("__SpawnedActors__/ABC"));

	FString Name = NewActor->GetActorLabel();
	Name.Append(" (Spawned)");
	NewActor->SetActorLabel(Name);
#endif
}

void AMySpawnPoint::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	_RemainTime -= DeltaSeconds;

	if (_RemainTime > 0) {
		_RemainTime -= DeltaSeconds;
		return;
	}

	SpawnActor();
	_RemainTime = SpawnInterval;
}
