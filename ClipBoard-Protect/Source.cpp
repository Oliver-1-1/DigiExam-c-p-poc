#include <Windows.h>

int main() {
	while (1) {
		OpenClipboard(0);
		EmptyClipboard();
		CloseClipboard();
		Sleep(5);
	}
}