#include "MySpawnPoint.h"
#include "NavigationSystem.h"


AMySpawnPoint::AMySpawnPoint() {
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = TG_PrePhysics;
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
