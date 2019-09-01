// SendPLUList.cpp: implementation of the SendPLUList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SendPLUList.h"
#include "Utils.h"
#include "Settings.h"
#include <stdio.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

extern IJob *pCurrentJob;
extern HWND hSelectedWindow; 
void UpdateStatus(WCHAR *pszStatus);


SendPLUList::SendPLUList()
{

}

SendPLUList::~SendPLUList()
{

}
void SendPLUList::OnSendPLUFROMFile( HWND hList)
{

	int nCurSel = SendMessage(hList, LB_GETCURSEL, 0, 0);


	if( nCurSel < 0 )
	{
		MessageBox(m_hWnd,_T("You must choose an application from the list(Preferably WinPOS)"),_T("Error"),MB_OK);
		return;
	}

	hSelectedWindow = m_hSelectedWindow = (HWND)SendMessage(hList, LB_GETITEMDATA, nCurSel, 0);


	gblPLUfptr = fopen("PLULIST.TXT","r");

	if(!gblPLUfptr)
		
	{
		MessageBox(m_hWnd,_T("PLULIST.TXT is not found. Please have it in the same directory,where the PostPLU application is. There should be a single PLU code on each line without any seperators"),_T("Error"),MB_OK);
		return;
	}

	fseek (gblPLUfptr,0,SEEK_END);
	int nSize = ftell(gblPLUfptr);

	if(nSize>0)
	{
		char *tempBuffPtr = new char[nSize+2];
		memset((void*)tempBuffPtr,0,nSize+2);
		fseek (gblPLUfptr,0,SEEK_SET);
		fread(tempBuffPtr,nSize,1,gblPLUfptr);
		m_pPLUBufStart = Utils::ConvertToW(tempBuffPtr, m_nBuffSize);
		m_pCurrentPLUCursor = m_pPLUBufStart;
		delete []tempBuffPtr;
	}

	if( gblPLUfptr ) 
	{
		fclose(gblPLUfptr);
		m_bRetryState = false;
		int nDelay = Settings::Instance()->GetDelay();
		SetTimer(m_hWnd,101,nDelay,NULL);
	}

}

void SendPLUList::SendNextPLU()
{

	if(m_bRetryState)
	{
		if( GetForegroundWindow()==hSelectedWindow )
		{
				SendPLU(m_lastReadPLU);
				m_bRetryState = false;
		}
	}
	else if( m_pCurrentPLUCursor && (m_pCurrentPLUCursor-m_pPLUBufStart) < m_nBuffSize )
	{
		WCHAR * pstrFound = NULL;

		pstrFound = wcstok(m_pCurrentPLUCursor,_T("\n\r"));


		if(pstrFound && wcslen(pstrFound)>0)
		{
			m_pCurrentPLUCursor = m_pCurrentPLUCursor + wcslen(pstrFound) +1;

			if( GetForegroundWindow()!=hSelectedWindow )
			{
				memset(m_lastReadPLU,0,40);
				wcscpy(m_lastReadPLU, pstrFound);
				m_bRetryState = true;
			}
			else
			{
				SendPLU(pstrFound);
				m_bRetryState = false;
			}

		}
		else
		{
			m_pCurrentPLUCursor = NULL;
			EndJob();
		}

	}
	else
	{
		EndJob();
	}

}

void SendPLUList::SendPLU(WCHAR pszPLU[20])
{
	if(pszPLU)
	{
		while(*pszPLU)
		{
			Utils::SendInputKey(*pszPLU++);
		}

		Utils::SendInputKey(13);//ENTER
	}

	
	UpdateStatus(pszPLU);

}

void SendPLUList::OnNextStep()
{
	SendNextPLU();
}
void SendPLUList::BeginJob(HWND hWnd, HWND hList)
{
	m_hWnd = hWnd;
	OnSendPLUFROMFile(hList);
	UpdateStatus(_T("Started"));
}


void SendPLUList::EndJob()
{

	KillTimer(m_hWnd,101);
	delete pCurrentJob;

	pCurrentJob = NULL;
	m_pCurrentPLUCursor = NULL;
	UpdateStatus(_T("EndJob: Completed."));
}
bool SendPLUList::IsDone()
{

	if(m_pCurrentPLUCursor == NULL)
		return true;

	return false;

}