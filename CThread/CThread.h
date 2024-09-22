#ifndef WL_VIRTUAL_THREAD

#define WL_VIRTUAL_THREAD

#include <Windows.h>
#include <malloc.h>

#define DEFAULT_CREATIONFLAGS 0
#define DEFAULT_STACKSIZE 0

DWORD THREAD_JOIN = 0001;
DWORD THREAD_DETACH = 0010;
DWORD THREAD_RUN_WITH_DEFAULT_VALUES = 0100;

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct Thread {
		HANDLE cThread;

		LPSECURITY_ATTRIBUTES lpAttributes;

		DWORD creationFlags;
		size_t stackSize;

		LPWORD threadID;

	} Thread;

	void _runThread(Thread th, void(*vParam), DWORD rParam);

	void _forceExit(Thread th);

	Thread _createThread();

#ifdef __cplusplus
}
#endif

#endif WL_VIRTUAL_THREAD