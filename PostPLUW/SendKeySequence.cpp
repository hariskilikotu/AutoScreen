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
	//SendNextCommand();
}
void SendKeySequence::SendNextCommand()
{
	if( m_nNextSendKeyIndex < Utils::GetTokenCount() 
			/*&& GetForegroundWindow() ==  m_hSelectedWindow*/
			&& IsSuspended() == false )
	{
		int nFunction = Utils::GetSpecialFunction(m_nNextSendKeyIndex);
		if( nFunction == FXSUSPEND) //Utils::HasInterrupt(m_nNextSendKeyIndex) )
		{
			int nDelay = Utils::GetInterruptDelay(m_nNextSendKeyIndex);
			UpdateStatus(_T("Sleeping"));
			Sleep(nDelay);
			m_nNextSendKeyIndex++;
			
		}
		else if (nFunction == FXCLICK)
		{
			int nDelay = Utils::GetInterruptDelay(m_nNextSendKeyIndex);
			UpdateStatus(_T("Sleeping"));
			Sleep(nDelay);
			m_nNextSendKeyIndex++;
		}
		else
		{
			UpdateStatus(_T("Procesing"));
			Utils::ProcessToken(m_nNextSendKeyIndex, m_hSelectedWindow);
			m_nNextSendKeyIndex++;
		}

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
			Sleep(1000);//just pause to have the click processed before sending more
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
		return true;
	}

	return false;
}

void SendKeySequence::EndJob()
{
	UpdateStatus(_T("Job Ended"));

}