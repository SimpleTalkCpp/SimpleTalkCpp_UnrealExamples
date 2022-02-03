// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyLesson005_AnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UMyLesson005_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float TestBlend = 0.5f;
	
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
