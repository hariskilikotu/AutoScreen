// Ticket.cpp: implementation of the Ticket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Ticket.h"
#include <AtlBase.h>
#include <atlconv.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Ticket::Ticket(int nticketNumber)
{

	m_nticketNumber = nticketNumber;

}

Ticket::~Ticket()
{

}

void Ticket::AddPLU( PLUCODE strPLU)
{
	m_pluList.push_back(strPLU);
}

void Ticket::SetTicketNumber(int nTicketNumber)
{
	m_nticketNumber = nTicketNumber;
}

int Ticket::GetPLUCount()
{
	return m_pluList.size();

}
PLUCODE Ticket::GetPLUAt(int nIndex)
{
	std::string strPLUCode;
	
	if( m_pluList.size() >nIndex )
	{
		strPLUCode = m_pluList[nIndex];
	}
	
	return strPLUCode;
}
void Ticket::GetPLUAt_W(int nIndex, std::wstring & strPLUCodeW)
{
	std::string strPLUCode;
	
	if( m_pluList.size() >nIndex )
	{
		strPLUCode = m_pluList[nIndex];
		StringToWString(strPLUCodeW, strPLUCode);
	}
	
}
void Ticket::StringToWString(std::wstring &ws, const std::string &s)
{
	int nLength = s.length();
    std::wstring wsTmp;
	wsTmp.resize(nLength);
	for(int i=0;i<nLength;i++) wsTmp[i] = s[i];

    ws = wsTmp;

	
}