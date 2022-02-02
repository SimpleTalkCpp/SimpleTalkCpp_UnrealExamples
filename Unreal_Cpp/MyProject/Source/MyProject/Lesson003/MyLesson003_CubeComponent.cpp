#include "MyLesson003_CubeComponent.h"

UMyLesson003_CubeComponent::UMyLesson003_CubeComponent() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("StaticMesh'/Game/Geometry/Meshes/1M_Cube.1M_Cube'"));
	SetStaticMesh(MeshObj.Object);
}

