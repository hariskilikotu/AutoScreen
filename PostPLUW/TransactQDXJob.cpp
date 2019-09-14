// TransactQDXJob.cpp: implementation of the TransactQDXJob class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TransactQDXJob.h"
#include "TransactQDX.h"
#include "Ticket.h"
#include "Utils.h"
#include <process.h>

void UpdateStatus(WCHAR *pszStatus);

int TransactQDXJob::TimerId = 200;

TransactQDXJob::TransactQDXJob()
{
	m_pTicket = NULL;
}
TransactQDXJob::~TransactQDXJob()
{

}
void TransactQDXJob::BeginJob(HWND hWnd, HWND hList)
{
	m_bTicketInProgress = false;
	m_bJobDone = false;
	UpdateStatus(_T("Job Started"));

	m_pTicket = TransactQDX::Instance()->GetFirstTicket();

	SetTimer(hWnd,TransactQDXJob::TimerId,2000,NULL);

}
void TransactQDXJob::OnNextStep()
{
	if( m_bTicketInProgress ) return;

	if( IsSuspended() ) return;

	if( m_pTicket )
	{
		m_bTicketInProgress = true;
		DispatchTicket( m_pTicket );

		m_pTicket = TransactQDX::Instance()->GetNextTicket();
	}
	else
	{
		m_bJobDone = true;
	}

}
void TransactQDXJob::EndJob()
{
	UpdateStatus(_T("Job Ended"));
}
bool TransactQDXJob::IsDone()
{
	return m_bJobDone;
}

Ticket *pCurrentTicket		= NULL;
int		nPLUCurrentIndex	= 0;

void __cdecl DispatchTicketProc( LPVOID pParam );

void TransactQDXJob::DispatchTicket(Ticket* pTicket )
{
	pCurrentTicket = pTicket;
	_beginthread(DispatchTicketProc,0,(LPVOID)&m_bTicketInProgress);
}

void __cdecl DispatchTicketProc( LPVOID pParam )
{
	bool *pbThreadInProgress = (bool* )pParam;
	*pbThreadInProgress = true;

	if( pCurrentTicket != NULL )
	{
		int nCount = pCurrentTicket->GetPLUCount();
		int nIndex = 0;
		
		while(nIndex<nCount)
		{
			std::string strPLU =pCurrentTicket->GetPLUAt(nIndex);
			Utils::SendPLU(strPLU);
			Utils::SendENTER();
			Sleep(3000);
			nIndex++;
		}
		if(nCount>0)
		{
			Utils::SendENTER();
			Sleep(3000);
		}

	}
	
	*pbThreadInProgress = false;
}





