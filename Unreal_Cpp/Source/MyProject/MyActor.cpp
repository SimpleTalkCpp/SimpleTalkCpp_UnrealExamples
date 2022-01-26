#include "MyActor.h"

AMyActor::AMyActor() {
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = TG_PrePhysics;
}

void AMyActor::Tick( float DeltaSeconds ) {
	Super::Tick(DeltaSeconds);
	UE_LOG(LogTemp, Warning, TEXT("Hello %d"), TestInt);
}