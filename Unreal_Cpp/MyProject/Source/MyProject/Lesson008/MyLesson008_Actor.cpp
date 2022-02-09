#include "MyLesson008_Actor.h"

void MyLesson008_C_Static_Function(int testInt, float testFloat) {
	MY_LOG("C_Static_Function");
}

void AMyLesson008_Actor::OnStaticMemberFunction(int testInt, float testFloat) {
	MY_LOG("OnStaticMemberFunction");
}

void AMyLesson008_Actor::OnTestFunction(int testInt, float testFloat) {
	MY_LOG("OnTestFunction({}, {})", testInt, testFloat);
}

void AMyLesson008_Actor::OnTestUFunction(int testInt, float testFloat) {
	MY_LOG("OnTestUFunction({}, {})", testInt, testFloat);
}

void AMyLesson008_Actor::OnTestDynamicFunction(int testInt, float testFloat) {
	MY_LOG("OnTestDynamicFunction({}, {})", testInt, testFloat);
}

AMyLesson008_Actor::AMyLesson008_Actor() {
	TestEvent.AddStatic(&MyLesson008_C_Static_Function);
	TestEvent.AddStatic(&ThisClass::OnStaticMemberFunction);

	TestEvent.AddUObject(this, &ThisClass::OnTestFunction);
//	TestEvent.AddSP();

	TestEvent.AddUFunction(this, TEXT("OnTestUFunction"));
	TestEvent.AddUFunction(this, TEXT("OnTestBlueprintImplentableEvent"));

	TestEvent.AddLambda([](int testInt, int testFloat) {
		MY_LOG("OnTest Lambda");
	});
	TestEvent.AddWeakLambda(this, [](int testInt, int testFloat) {
		MY_LOG("OnTest Weak Lambda");
	});

	TestDynamicEvent.AddDynamic(this, &ThisClass::OnTestDynamicFunction);
}

void AMyLesson008_Actor::BeginPlay() {
	Super::BeginPlay();

	MY_LOG("BeginPlay()");

	TestDelegate.ExecuteIfBound(0, 1);
	TestEvent.Broadcast(1, 2);

	TestDynamicDelegate.ExecuteIfBound(3, 4);
	TestDynamicEvent.Broadcast(5, 6);
}

