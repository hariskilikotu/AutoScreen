// SendKeySequence.cpp: implementation of the SendKeySequence class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SendKeySequence.h"
#include "DirectKeysDlg.h"
#include "Settings.h"
#include "Utils.h"
#include <process.h>

HINSTANCE GetInstance();
HWND GetMainWnd();
void UpdateStatus(WCHAR *pszStatus);
extern HWND hSelectedWindow;
bool bThreadInProgress = false;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SendKeySequence::SendKeySequence(char *pszInputFileName)
{

	m_pszCommandText = NULL;
	m_nNextSendKeyIndex = 0;
	m_bRetryState = false;

	if(pszInputFileName==NULL)
	{

		
	}
}

SendKeySequence::~SendKeySequence()
{
	if(m_pszCommandText)
		delete [] m_pszCommandText;

}
void SendKeySequence::BeginJob(HWND hWnd, HWND hList)
{
	m_nNextSendKeyIndex = 0;

	m_szTranslatedCommands = Utils::Translate(m_pszCommandText);
	
	int nCurSel = SendMessage(hList, LB_GETCURSEL, 0, 0);
	
	
	if( nCurSel < 0 )
	{
		MessageBox(hWnd,_T("You must choose an application from the list(Preferably WinPOS)"),_T("Error"),MB_OK);
		return;
	}
	
	hSelectedWindow = m_hSelectedWindow = (HWND)SendMessage(hList, LB_GETITEMDATA, nCurSel, 0);	

	SetForegroundWindow(hSelectedWindow);

	m_nRepCount = Settings::Instance()->GetRepeatCount();
	m_nIterationsCompleted = 0;

	Sleep(3000);

	SetTimer(hWnd,SENDKEY_SEQUENCE_TIMER,Settings::Instance()->GetDelay(),NULL);

	UpdateStatus(_T("Started"));

}

void __cdecl SendNextCommandProc( LPVOID pParam );
void SendKeySequence::OnNextStep()
{
	if( IsSuspended() == false && bThreadInProgress == false)
	{
		bThreadInProgress = true;
		_beginthread(SendNextCommandProc, 0,(LPVOID)&m_nNextSendKeyIndex);

	}
}

void __cdecl SendNextCommandProc( LPVOID pParam )
{
	int *pnNextSendKeyIndex = (int* )pParam;

	if( *pnNextSendKeyIndex < Utils::GetTokenCount() )
	{
		int nFunction = Utils::GetSpecialFunction(*pnNextSendKeyIndex);
		if( nFunction == FXSUSPEND )
		{
			int nDelay = Utils::GetInterruptDelay(*pnNextSendKeyIndex);
			UpdateStatus(_T("Sleeping"));
			Sleep(nDelay);
			*pnNextSendKeyIndex = *pnNextSendKeyIndex+1;
			
		}
		else if(nFunction == FXCLICK)
		{
			int nX = Utils::GetClickX(*pnNextSendKeyIndex);
			int nY = Utils::GetClickY(*pnNextSendKeyIndex+1);
			*pnNextSendKeyIndex = *pnNextSendKeyIndex+2;
			Utils::ClickMouse(nX,nY);
		}
		else
		{
			UpdateStatus(_T("Procesing"));
			Utils::ProcessToken(*pnNextSendKeyIndex, hSelectedWindow);
			*pnNextSendKeyIndex = *pnNextSendKeyIndex+1;
		}
		
	}
	bThreadInProgress = false;
}


void SendKeySequence::SetCommandText(WCHAR *pszText)
{
	m_pszCommandText = pszText;
}
bool SendKeySequence::IsDone()
{
	if( m_nNextSendKeyIndex >= Utils::GetTokenCount() )
	{
		m_nIterationsCompleted++;

		if( m_nIterationsCompleted >= m_nRepCount)
			return true;
		else
		{
			m_nNextSendKeyIndex =0;
			Sleep(5000);
		}
	}

	return false;
}

void SendKeySequence::EndJob()
{
	UpdateStatus(_T("Job Ended"));

}