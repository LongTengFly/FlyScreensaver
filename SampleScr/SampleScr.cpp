#include <windows.h>
#include "resource.h"
#pragma comment(lib,"scrnsave.lib") //使用库文件

#pragma comment(lib,"comctl32.lib") 

// Timer ID
#define TIMER_ID_FLUSH	101

// Timer Elapse time
#define TIMER_ELAPSE_500MS	500

// Timer callback
static void CALLBACK TimerProc(HWND hWnd, UINT nMsg, UINT nTimerid, DWORD dwTime);

LRESULT CALLBACK ScreenSaverProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	static BOOL bFlushTimerFlag = TRUE;

	switch (message)
	{

	case WM_PAINT:
	{

		PAINTSTRUCT ps;

		HDC hDC;
		hDC = BeginPaint(hWnd, &ps);

		SetBkMode(hDC, TRANSPARENT);

		SetTextColor(hDC, RGB(0x33, 0xcc, 0));

		TCHAR sztext[128];
		SYSTEMTIME mCurrentTime;

		GetLocalTime(&mCurrentTime);

		wsprintf(sztext, TEXT("%d-%02d-%02d %02d:%02d:%02d"),
			mCurrentTime.wYear, mCurrentTime.wMonth, mCurrentTime.wDay,
			mCurrentTime.wHour, mCurrentTime.wMinute, mCurrentTime.wSecond);

		TextOut(hDC, 150, 150, sztext, 128);

		if (bFlushTimerFlag)
		{
			bFlushTimerFlag = FALSE;
			SetTimer(hWnd, TIMER_ID_FLUSH, TIMER_ELAPSE_500MS, (TIMERPROC)TimerProc);
		}
		
		EndPaint(hWnd, &ps);

	}

	break;

	case WM_DESTROY:
		KillTimer(hWnd, TIMER_ID_FLUSH);
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



static void CALLBACK TimerProc(HWND hWnd, UINT nMsg, UINT nTimerid, DWORD dwTime)
{
	switch (nTimerid)
	{
	case TIMER_ID_FLUSH:
		//KillTimer(hWnd, TIMER_ID_FLUSH);
		InvalidateRect(hWnd, NULL, FALSE);
		break;
	default:
		break;
	}
}
