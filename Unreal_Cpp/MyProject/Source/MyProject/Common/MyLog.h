#pragma once

#include "MyFormat.h"
#include "Logging/LogMacros.h"

struct MYPROJECT_API MyLogger {
	static void Output(int32 key, float timeToDisplay, const FString& msg);

	template<class... ARGS> inline
	static void _LogInternal(int32 key, float timeToDisplay, const char* format_str, const ARGS& ... args) {
		FString tmp;
		fmt::format_to(MyFormat_FStringBackInserter(tmp), format_str, args...);
		Output(key, timeToDisplay, tmp);
	}
};

#define MY_LOG(...)  do { MyLogger::_LogInternal(INDEX_NONE, 3,  __VA_ARGS__); } while(false)


#define  MY_ASSERT(X) check(X)