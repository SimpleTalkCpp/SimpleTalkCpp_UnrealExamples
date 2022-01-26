#pragma once

#include "CoreMinimal.h"
#include "MyActor.generated.h"

UCLASS()
class AMyActor : public AActor {
	GENERATED_BODY()
public:
	AMyActor();

	void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, Category="My Settings")
	bool EnableTest;

	UPROPERTY(EditAnywhere, Category="My Settings", meta = (DisplayName = "Int for Testing", ClampMin = "5", ClampMax = "100", EditCondition="EnableTest"))
	int TestInt = 10;
};