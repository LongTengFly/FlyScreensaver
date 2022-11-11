#include <windows.h>

#pragma comment(lib,"scrnsave.lib") //使用库文件

#include "resource.h"


LRESULT CALLBACK ScreenSaverProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)

{

	switch (message)
	{

	case WM_PAINT:

	{

		PAINTSTRUCT ps;

		HDC hDC = BeginPaint(hWnd, &ps);

		SetBkMode(hDC, TRANSPARENT);

		SetTextColor(hDC, RGB(0x33, 0xcc, 0));

		TextOut(hDC, 150, 150, TEXT("WWW.VCKBASE.COM"), 15);

		EndPaint(hWnd, &ps);

	}

	break;

	case WM_DESTROY:

		PostQuitMessage(0);

		break;

	default:

		// 缺省的消息处理函数

		return DefScreenSaverProc(hWnd, message, wParam, lParam);

	}



	return 0;

}


BOOL WINAPI ScreenSaverConfigureDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)

{

	switch (message) {

	case WM_COMMAND:

		//处理 确定 按钮

		if (LOWORD(wParam) == IDOK) {

			EndDialog(hDlg, LOWORD(wParam));

			return TRUE;

		}

		else

		{

			//系统的处理退出命令

			EndDialog(hDlg, LOWORD(wParam));

			return TRUE;

		}

		break;

	}

	return FALSE;

}

BOOL WINAPI RegisterDialogClasses(HANDLE hInst)

{

	return TRUE;

}
