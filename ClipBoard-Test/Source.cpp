#include <Windows.h>
#include <string.h>
#include <direct.h>

int main() {
	const char* output = "Test";

	while (1) {
		OpenClipboard(0);
		HLOCAL hMem = LocalAlloc(LHND, 1024);
		char* cptr = (char*)LocalLock(hMem);
		memcpy(cptr, output, 500);
		SetClipboardData(CF_TEXT, hMem);
		LocalUnlock(hMem);
		LocalFree(hMem);
		Sleep(3); 
		CloseClipboard();
	}

}


BOOL __stdcall DllMain(HINSTANCE Dll, DWORD Reason, LPVOID Reserved) {

	if (Reason == DLL_PROCESS_ATTACH) {
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)main, 0, 0, 0);
	}
	return TRUE;
}