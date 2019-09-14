// TransactQDXDlg.h: interface for the TransactQDXDlg class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSACTQDXDLG_H__57C2F128_E840_49C4_9AC9_C21799DB0BA9__INCLUDED_)
#define AFX_TRANSACTQDXDLG_H__57C2F128_E840_49C4_9AC9_C21799DB0BA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "TicketListCtrl.h"
class TransactQDXDlg  
{



public:	static bool m_bRunTickets;
public:
	TransactQDXDlg();
	virtual ~TransactQDXDlg();
	void Open(HWND hParent, HINSTANCE hInst);
	bool ShouldRun();

};

#endif // !defined(AFX_TRANSACTQDXDLG_H__57C2F128_E840_49C4_9AC9_C21799DB0BA9__INCLUDED_)
