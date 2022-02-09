#pragma once

#include <GameFramework/Actor.h>
#include "MyLesson009_Actor.generated.h"

UCLASS()
class AMyLesson009_Actor : public AActor {
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent*	MeshComponent = nullptr;

	UPROPERTY(VisibleAnywhere)
	class UWidgetComponent* WidgetComponent = nullptr;

	AMyLesson009_Actor();
};