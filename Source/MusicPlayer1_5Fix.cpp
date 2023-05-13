//#include <windows.h>
//
//#include "Names.h"
//
//struct PROCESS_INFO {
//	DWORD dwThreadId;
//	HWND hwnd;
//};
//
//BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
//	PROCESS_INFO *pProcessInfo = (PROCESS_INFO *)lParam;
//	DWORD dwThreadId;
//	GetWindowThreadProcessId(hwnd, &dwThreadId);
//	if (pProcessInfo->dwThreadId == dwThreadId) {
//		pProcessInfo->hwnd = hwnd;
//		return FALSE;
//	}
//	return TRUE;
//}
//
//int WINAPI main() {
//	STARTUPINFO si = { sizeof(si) };
//	PROCESS_INFORMATION pi;
//	if (CreateProcessA(NULL, "\"MusicPlayer\\OLD\\BETA1.5\\Player.exe\"", NULL, NULL, FALSE, 0, NULL, "MusicPlayer\\OLD\\BETA1.5", &si, &pi) == FALSE) {
//		MessageBoxA(NULL, "Невозможно создать процесс", "Фатальная ошибка", MB_ICONERROR);
//		return 1;
//	}
//
//	PROCESS_INFO ProcessInfo = { pi.dwThreadId };
//	EnumWindows(EnumWindowsProc, (LPARAM)&ProcessInfo);
//
//	WNDPROC lpfnWndProc = (WNDPROC)GetWindowLongPtr(ProcessInfo.hwnd, GWLP_WNDPROC);
//	SetWindowLongPtr(ProcessInfo.hwnd, GWLP_WNDPROC, (LONG_PTR)&[lpfnWndProc](HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) -> LRESULT CALLBACK {
//
//		switch (message) {
//			case WM_COMMAND:
//				if (LOWORD(wParam) == ID_BUTTON) {
//					CallWindowProc(lpfnWndProc, hwnd, message, wParam, lParam);
//					SetClassLongPtr(hwnd, GCL_STYLE, 0);
//				}
//				break;
//		}
//
//		return CallWindowProc(lpfnWndProc, hwnd, message, wParam, lParam);
//		});
//
//	WaitForSingleObject(pi.hProcess, INFINITE);
//	CloseHandle(pi.hThread);
//	CloseHandle(pi.hProcess);
//	return 0;
//}