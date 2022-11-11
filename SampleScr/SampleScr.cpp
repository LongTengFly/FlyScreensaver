#include <windows.h>

#pragma comment(lib,"scrnsave.lib") //ʹ�ÿ��ļ�

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

		// ȱʡ����Ϣ������

		return DefScreenSaverProc(hWnd, message, wParam, lParam);

	}



	return 0;

}


BOOL WINAPI ScreenSaverConfigureDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)

{

	switch (message) {

	case WM_COMMAND:

		//���� ȷ�� ��ť

		if (LOWORD(wParam) == IDOK) {

			EndDialog(hDlg, LOWORD(wParam));

			return TRUE;

		}

		else

		{

			//ϵͳ�Ĵ����˳�����

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
