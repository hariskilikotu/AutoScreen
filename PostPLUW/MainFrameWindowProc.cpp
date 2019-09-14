// MainFrameWindowProc.cpp: implementation of the MainFrameWindowProc class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainFrameWindowProc.h"
#include "IJob.h"
#include "resource.h"
#include "SettingsDlg.h"
#include "SendPLUList.h"
#include "SendKeySequence.h"
#include "TransactQDXJob.h"
#include "TransactQDX.h"
#include "TransactQDXDlg.h"
#include "Utils.h"
#include "DirectKeysDlg.h"


HINSTANCE hInst = NULL;
HWND hwndMain = NULL;
IJob *pCurrentJob = NULL;
HWND hList = NULL;

HWND hFilterWnd = NULL;
HWND hStatusWnd = NULL;
HWND hSelectedWindow = NULL;

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
int nCounter = 0;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);

	switch (message) 
	{
	case WM_TIMER:
		{
			if(pCurrentJob && pCurrentJob->IsDone() )
			{
				pCurrentJob->EndJob();
				delete pCurrentJob;
				pCurrentJob = NULL;
			}

			if(pCurrentJob)
				pCurrentJob->OnNextStep();
			
			if(pCurrentJob == NULL)
			{
				KillTimer(hWnd,wParam);
			}
			break;
		}
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
			case IDC_APPLY_BUTTON:
				{
					SendMessage((HWND)hList, LB_RESETCONTENT, (WPARAM)0, (LPARAM)0);
					EnumDesktopWindows(GetThreadDesktop(GetCurrentThreadId()),Utils::enumWindowsProc,(LPARAM)hList);
					break;
				}
			case ID_JOB_SUSPEND:
				{
					if(pCurrentJob!=NULL)
						pCurrentJob->SuspendJob();
					break;
				}
			case ID_JOB_RESUME:
				{
					if(pCurrentJob!=NULL)
						pCurrentJob->ResumeJob();
					break;
				}
			case ID_JOB_END:
				{
					if(pCurrentJob!=NULL)
					{
						pCurrentJob->EndJob();
						delete pCurrentJob;
						pCurrentJob = NULL;
					}

					break;
				}
			case ID_CONFIGURE_SETTINGS:
				{
					SettingsDlg dlg;
					dlg.Open(hWnd,hInst);
					break;
				}
			case ID_PLU_BROWSEPLUFILE:
				{
					break;
				}
			case ID_PLU_SENDPLUTOPOS:
				{
					if(pCurrentJob==NULL) 
					{
						pCurrentJob = new SendPLUList();
						pCurrentJob->BeginJob(hWnd,hList);
					}
					break;
				}
			case ID_PLU_STOPSENDINGPLU:
				{
					if(pCurrentJob)
					{
						pCurrentJob->EndJob();
						delete pCurrentJob;
						pCurrentJob = NULL;
					}
					break;
				}
			case ID_SENDKEYS_DIRECT:
				{
					if( pCurrentJob==NULL ) 
					{
						DirectKeysDlg dlg;
						dlg.Open(GetMainWnd(),GetInstance());
						if(dlg.IsOK())
						{
							pCurrentJob = new SendKeySequence(NULL);
							pCurrentJob->SetCommandText(dlg.GetCommandText());
							ShowWindow(GetMainWnd(), SW_MINIMIZE);
							pCurrentJob->BeginJob(hWnd,hList);
						}

					}
					break;
				}
			case ID_TRANSACTQDX_RUNTICKETS:
				{
					if(pCurrentJob == NULL)
					{
						TransactQDXDlg dlg;
						dlg.Open(hWnd,GetInstance());

						if(true == dlg.ShouldRun())
						{
							pCurrentJob = new TransactQDXJob();
							pCurrentJob->BeginJob(hWnd,hList);
						}
					}
					break;

				}
			case ID_HELP_CONTENT:
				{
					break;
				}
			case IDM_EXIT:
				 DestroyWindow(hWnd);
				break;
			default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_CREATE:
			{
				RECT rt;
				GetClientRect(hWnd, &rt);
				CreateWindow(_T("STATIC"),_T("Filter"),WS_CHILD|WS_VISIBLE|SS_CENTER,
					50,20,200,30,hWnd,
					(HMENU)100,hInst,0);
				hFilterWnd = CreateWindow(_T("EDIT"),_T("Notepad"),WS_CHILD|WS_VISIBLE|WS_BORDER,
					300,20,200,30,hWnd,
					(HMENU)101,hInst,0);
				CreateWindow(_T("BUTTON"),_T("Apply"),WS_CHILD|WS_VISIBLE|WS_BORDER,
					520,20,100,30,hWnd,
					(HMENU)IDC_APPLY_BUTTON,hInst,0);
				hStatusWnd = CreateWindow(_T("STATIC"),_T(""),WS_CHILD|WS_VISIBLE|WS_BORDER,
					630,20,200,30,hWnd,
					(HMENU)132,hInst,0);
				
				
				hList = CreateWindow(_T("LISTBOX"),_T(""),WS_CHILD|WS_VISIBLE|LBS_HASSTRINGS|WS_BORDER|WS_VSCROLL,0,70,rt.right-rt.left,rt.bottom-rt.top,hWnd,(HMENU)103,hInst,0);
				EnumDesktopWindows(GetThreadDesktop(GetCurrentThreadId()),Utils::enumWindowsProc,(LPARAM)hList);
				break;
			}
		case WM_DESTROY:
			if(pCurrentJob) delete pCurrentJob;
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}


HINSTANCE GetInstance(){return hInst;}
HWND GetMainWnd() { return hwndMain;}

void GetFilterText(WCHAR *pBuff)
{
	memset(pBuff,0,100*sizeof(WCHAR));
	GetWindowText( hFilterWnd, pBuff , 100);
}

void UpdateStatus(WCHAR *pszStatus)
{
	SetWindowText(hStatusWnd, pszStatus);
}
