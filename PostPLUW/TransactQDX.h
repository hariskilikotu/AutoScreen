// TransactQDX.h: interface for the TransactQDX class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSACTQDX_H__282B2BE2_0120_46E4_9F89_68C9F531A685__INCLUDED_)
#define AFX_TRANSACTQDX_H__282B2BE2_0120_46E4_9F89_68C9F531A685__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <map>

#include "Ticket.h"

class TransactQDX  
{

	std::map<int , Ticket*> m_mTickets;// ticket_no: ticket*
	std::map<int , Ticket*>::iterator m_it;
public:
	static TransactQDX* Instance()
	{
		static TransactQDX obj;

		return &obj;
	}

	void Refresh()
	{

		m_mTickets.clear();

	}

public:
	TransactQDX();
	virtual ~TransactQDX();


	void AddTicket(int ticket_no, Ticket *pTicket);

	Ticket* GetCreateTicket(int ticket_no);

	Ticket* GetFirstTicket();
	Ticket* GetNextTicket();

};

#endif // !defined(AFX_TRANSACTQDX_H__282B2BE2_0120_46E4_9F89_68C9F531A685__INCLUDED_)
