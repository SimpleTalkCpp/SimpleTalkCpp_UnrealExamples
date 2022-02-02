#include "MyLesson003_Actor.h"
#include "MyLesson003_GunComponent.h"
#include "MyLesson003_RotateComponent.h"
#include "Components/BillboardComponent.h"

AMyLesson003_Actor::AMyLesson003_Actor() {
	BillboardComponent = CreateDefaultSubobject<UBillboardComponent>(UBillboardComponent::StaticClass()->GetFName());
	RootComponent = BillboardComponent;

	RotateComponent = CreateDefaultSubobject<UMyLesson003_RotateComponent>(TEXT("Rotate"));
}

void AMyLesson003_Actor::BeginPlay() {
	Super::BeginPlay();

	GunComponent = NewObject<UMyLesson003_GunComponent>(this);
	GunComponent->RegisterComponent();	
	GunComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

