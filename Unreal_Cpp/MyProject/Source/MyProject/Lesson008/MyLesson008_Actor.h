#pragma once

#include "../Common/MyCommon.h"
#include "MyLesson008_Actor.generated.h"

// C to C++  -  shared_ptr, safe bool idiom, weak_ptr
//    https://www.youtube.com/watch?v=XFj5vjgug_0&list=PLeGk08zVu4566pxRefXH0zr1FDL4BGUUG&index=17

// C Sharp 22 - Garbage Collection, StringBuilder 
//    https://www.youtube.com/watch?v=upv14CVxsCk&list=PLeGk08zVu454pKsrnLJCEZbEJD5vszSbI&index=23&t=1s

DECLARE_DELEGATE_TwoParams(          FMyLesson008_TestDelegate, int, float);
DECLARE_MULTICAST_DELEGATE_TwoParams(FMyLesson008_TestEvent,    int, float);

DECLARE_DYNAMIC_DELEGATE_TwoParams(          FMyLesson008_TestDynamicDelegate, int, testInt, float, testFloat);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMyLesson008_TestDynamicEvent,    int, testInt, float, testFloat);

UCLASS()
class AMyLesson008_Actor : public AActor {
	GENERATED_BODY()
public:

	FMyLesson008_TestDelegate	TestDelegate;
	FMyLesson008_TestEvent		TestEvent;

	// Dynamic delegates can be serialized, their functions can be found by name, and they are slower than regular delegates.
	// https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/Delegates/Dynamic/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMyLesson008_TestDynamicDelegate TestDynamicDelegate;

	UPROPERTY(EditAnywhere, BlueprintAssignable)
	FMyLesson008_TestDynamicEvent TestDynamicEvent;

	static void OnStaticMemberFunction(int testInt, float testFloat);

	void OnTestFunction(int testInt, float testFloat);

	UFUNCTION(BlueprintCallable)
	void OnTestUFunction(int testInt, float testFloat); // Blueprint call C++

	UFUNCTION(BlueprintImplementableEvent)
	void OnTestBlueprintImplentableEvent(int testInt, float testFloat); // C++ call Blueprint Event

	UFUNCTION()
	void OnTestDynamicFunction(int testInt, float testFloat);

	AMyLesson008_Actor();
	virtual void BeginPlay() override;
};
