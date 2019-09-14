// TransactQDX.cpp: implementation of the TransactQDX class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TransactQDX.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TransactQDX::TransactQDX()
{

}

TransactQDX::~TransactQDX()
{

}
void TransactQDX::AddTicket(int ticket_no, Ticket *pTicket)
{	
	m_mTickets.insert( std::make_pair(ticket_no , pTicket) );	
}

Ticket* TransactQDX::GetCreateTicket(int ticket_no)
{
	Ticket *pTicket = NULL;

	std::map<int , Ticket*>::iterator it;

	it = m_mTickets.find(ticket_no);

	if(it == m_mTickets.end())
	{
		pTicket = new Ticket(ticket_no);
		
		m_mTickets.insert( std::make_pair(ticket_no , pTicket) );
	}
	else
	{
		pTicket = it->second;
	}

	return pTicket;

}

Ticket* TransactQDX::GetFirstTicket()
{

	m_it = m_mTickets.begin();

	if(m_it == m_mTickets.end()) return NULL;

	return m_it->second;

}
Ticket* TransactQDX::GetNextTicket()
{

	m_it++;

	if(m_it == m_mTickets.end()) 
		return NULL;	
	
	return m_it->second;
}