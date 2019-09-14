// TicketListCtrl.h: interface for the TicketListCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TICKETLISTCTRL_H__C41DEFA9_1901_4367_AEC0_2BF9E8B7E54A__INCLUDED_)
#define AFX_TICKETLISTCTRL_H__C41DEFA9_1901_4367_AEC0_2BF9E8B7E54A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <string>
#include<commctrl.h>
class TransactQDX;

class TicketListCtrl  
{
	HWND		m_hWnd;
	HIMAGELIST	m_hImageList;
	HBITMAP m_hBitMap;

public:
	TicketListCtrl();
	virtual ~TicketListCtrl();

	void Bind(HWND hWnd);

	void InitControl();

	void ResetControl();
	void PopulateControl(TransactQDX *pQDX);
	HTREEITEM InsertItem(std::wstring pluCode, HTREEITEM Parent);
	HTREEITEM InsertTicket(std::wstring pluCode,HTREEITEM Parent);

};

#endif // !defined(AFX_TICKETLISTCTRL_H__C41DEFA9_1901_4367_AEC0_2BF9E8B7E54A__INCLUDED_)
