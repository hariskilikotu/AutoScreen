// TransactQDXJob.h: interface for the TransactQDXJob class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSACTQDXJOB_H__183ECB29_8C7E_400B_9C5F_A149A3B07FBA__INCLUDED_)
#define AFX_TRANSACTQDXJOB_H__183ECB29_8C7E_400B_9C5F_A149A3B07FBA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IJob.h"
class Ticket;
class TransactQDXJob : public IJob  
{

	Ticket *m_pTicket;
	bool	m_bTicketInProgress;
	bool	m_bJobDone;
	static int TimerId;
public:
	TransactQDXJob();
	virtual ~TransactQDXJob();

	virtual void BeginJob(HWND hWnd, HWND hList);
	virtual void OnNextStep();
	virtual void EndJob();
	virtual bool IsDone();

	void DispatchTicket(Ticket* pTicket );

};

#endif // !defined(AFX_TRANSACTQDXJOB_H__183ECB29_8C7E_400B_9C5F_A149A3B07FBA__INCLUDED_)
