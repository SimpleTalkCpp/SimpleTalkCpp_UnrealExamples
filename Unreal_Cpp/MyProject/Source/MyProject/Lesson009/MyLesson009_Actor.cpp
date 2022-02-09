#include "MyLesson009_Actor.h"

#include <Components/StaticMeshComponent.h>
#include <Components/WidgetComponent.h>

#include <UObject/ConstructorHelpers.h>

AMyLesson009_Actor::AMyLesson009_Actor() {
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(MeshComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube'"));
	MeshComponent->SetStaticMesh(MeshObj.Object);


	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));

	static ConstructorHelpers::FClassFinder<UUserWidget> WidgetClass(TEXT("WidgetBlueprint'/Game/SimpleTalkCpp/Lesson009/WBP_Lesson009_WorldSpaceWidget'"));
	WidgetComponent->SetWidgetClass(WidgetClass.Class);
	WidgetComponent->SetRelativeLocation(FVector(0, 0, 50));
}

