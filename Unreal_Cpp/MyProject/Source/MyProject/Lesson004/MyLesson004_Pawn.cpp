#include "MyLesson004_Pawn.h"

#include "../Lesson003/MyLesson003_CubeComponent.h"


AMyLesson004_Pawn::AMyLesson004_Pawn() {
	Cube = CreateDefaultSubobject<UMyLesson003_CubeComponent>(TEXT("Cube"));
	SetRootComponent(Cube);
}

void AMyLesson004_Pawn::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

}

