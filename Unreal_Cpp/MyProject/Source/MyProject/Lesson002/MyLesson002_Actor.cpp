#include "MyLesson002_Actor.h"

void AMyLesson002_Actor::BeginPlay() {
	Super::BeginPlay();

	{
		FString str = FString::Printf(TEXT("FString Printf %d %d %f %s"), 1, 2, 1.23f, TEXT("Hi!"));
		UE_LOG(LogTemp, Warning, TEXT("%s"), *str);
	}

	{
		FString str = FString::Printf(TEXT("FString Printf is unsafe %s"), "Hi!");
		UE_LOG(LogTemp, Warning, TEXT("%s"), *str);
	}

	{
		FStringFormatOrderedArguments Args;
		Args.Add(123);
		Args.Add(2);
		Args.Add(1.23f);
		Args.Add(TEXT("Hi!"));
		FString str = FString::Format(TEXT("FString Format Ordered {0} {1} {2} {3}"), Args);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *str);
	}

	{
		FStringFormatNamedArguments Args;
		Args.Add("A", 123);
		Args.Add("B", 2);
		Args.Add("C", 1.23f);
		Args.Add("D", TEXT("Hi!"));
		FString str = FString::Format(TEXT("FString Format Named {A} {B} {C} {D}"), Args);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *str);
	}

	MY_LOG("MYLOG Test {}", 123);
}

