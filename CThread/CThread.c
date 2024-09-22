#include "CThread.h"

typedef struct ThreadFunctionParameter {
	void(*vParam)();

	Thread th;

} ThreadFunctionParameter;

DWORD WINAPI thread_function(LPVOID param) {
	ThreadFunctionParameter* tfp = (ThreadFunctionParameter*)param;
	tfp->vParam();
	free(tfp);
}

void _runThread(Thread th, void(*vParam), DWORD rParam) {
	ThreadFunctionParameter* tfp = (ThreadFunctionParameter*)malloc(sizeof(tfp));
	tfp->vParam = vParam;
	if (rParam & THREAD_RUN_WITH_DEFAULT_VALUES) {
		th = _createThread();
	}
	th.cThread = CreateThread(th.lpAttributes,th.stackSize,thread_function,tfp,th.creationFlags,th.threadID);
	if (th.cThread == NULL) {
		return NULL;
	}
	
	if (rParam & THREAD_JOIN) {
		WaitForSingleObject(th.cThread, INFINITE);
	}
	else if (rParam & THREAD_DETACH) {
		return;
	}
}

Thread _createThread() {
	Thread thread;
	thread.creationFlags = DEFAULT_CREATIONFLAGS;
	thread.stackSize = DEFAULT_STACKSIZE;

	thread.lpAttributes = NULL;

	thread.threadID = NULL;

	return thread;
}