// Ticket.h: interface for the Ticket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TICKET_H__BF1F5058_FE82_41A9_B180_52C98EB5235E__INCLUDED_)
#define AFX_TICKET_H__BF1F5058_FE82_41A9_B180_52C98EB5235E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include<vector>
#include<string>

typedef  std::string PLUCODE;  
   
class Ticket  
{
	int m_nticketNumber;

	std::vector<PLUCODE> m_pluList;
public:
	Ticket(int nticketNumber);
	virtual ~Ticket();

	void SetTicketNumber(int nTicketNumber);
	void AddPLU( PLUCODE strPLU);
	int GetPLUCount();
	PLUCODE GetPLUAt(int nIndex);
	void GetPLUAt_W(int nIndex, std::wstring &strPLUCodeW);
	void StringToWString(std::wstring &ws, const std::string &s);
	int TicketNumber(){return m_nticketNumber;}

};

#endif // !defined(AFX_TICKET_H__BF1F5058_FE82_41A9_B180_52C98EB5235E__INCLUDED_)
