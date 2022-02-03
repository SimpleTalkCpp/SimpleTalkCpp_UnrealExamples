#pragma once

#include "../Common/MyCommon.h"

#include "MyLesson004_Pawn.generated.h"

UCLASS()
class AMyLesson004_Pawn : public APawn {
	GENERATED_BODY()
public:

	UPROPERTY(VisibleAnywhere)
	class UMyLesson003_CubeComponent* Cube;

	AMyLesson004_Pawn();

	virtual void Tick(float DeltaSeconds) override;
};