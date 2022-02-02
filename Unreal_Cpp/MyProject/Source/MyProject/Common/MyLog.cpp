#include "MyLog.h"

DECLARE_LOG_CATEGORY_EXTERN(MyLog, Log, All);
DEFINE_LOG_CATEGORY(MyLog)

void MyLogger::Output(int32 key, float timeToDisplay, const FString& msg) {
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(key, timeToDisplay, FColor::Red, msg);
	}
	UE_LOG(MyLog, Warning, TEXT("%s"), *msg);
}
