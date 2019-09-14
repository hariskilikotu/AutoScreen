// TicketListCtrl.cpp: implementation of the TicketListCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TicketListCtrl.h"
#include "TransactQDX.h"
#include "resource.h"
#include <commctrl.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
extern HINSTANCE hInst;

TicketListCtrl::TicketListCtrl()
{

}

TicketListCtrl::~TicketListCtrl()
{

}

void TicketListCtrl::Bind(HWND hWnd)
{
	m_hWnd = hWnd;
	m_hImageList=ImageList_Create(16,16,ILC_COLOR16,2,1);
	m_hBitMap=LoadBitmap(hInst,MAKEINTRESOURCE(IDB_TREE));
	ImageList_Add(m_hImageList,m_hBitMap,NULL);
	SendMessage(m_hWnd,TVM_SETIMAGELIST,0,(LPARAM)m_hImageList);
	//SendDlgItemMessage(hWnd,IDC_TREE1,TVM_SETIMAGELIST,0,
                  //(LPARAM)hImageList);
}

void TicketListCtrl::InitControl()
{

	ResetControl();

	TransactQDX *pTQ = TransactQDX::Instance();

	Ticket *pTicket = pTQ->GetFirstTicket();

	while(pTicket)
	{

		WCHAR ticket_row_text[100]={0};
		//std::wstring strTicket = std::wstring("");
		
		wsprintf(ticket_row_text,_T("Ticket : %d (%d items)"),pTicket->TicketNumber(),pTicket->GetPLUCount());

		HTREEITEM hTicket = InsertTicket(ticket_row_text, NULL);
		int nCount = pTicket->GetPLUCount();
		for(int i=0;i<nCount;i++)
		{
			std::wstring strPLU;
			pTicket->GetPLUAt_W(i, strPLU);
			InsertItem(strPLU, hTicket);
		}

		pTicket = pTQ->GetNextTicket();
	}


}

void TicketListCtrl::ResetControl()
{

}
void TicketListCtrl::PopulateControl(TransactQDX *pQDX)
{

}
HTREEITEM TicketListCtrl::InsertTicket(std::wstring pluCode,HTREEITEM Parent)
{
	TV_INSERTSTRUCT tvinsert={0};    // struct to config out the
	// tree control
	// Now, we need to intialize this struct:
	// Global Vars:
	//HTREEITEM Parent;    // Tree item handle
	//HTREEITEM Before;    // .......
	//HTREEITEM Root;      // .......
	// .....
	// .....
	// Code:
	tvinsert.hParent=Parent;               // top-most level Item
	tvinsert.hInsertAfter=TVI_ROOT;      // root level item attribute
	tvinsert.item.mask=TVIF_TEXT|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	// attributes
	tvinsert.item.pszText = (WCHAR*)pluCode.c_str();      // item text
	tvinsert.item.iImage=0;              // not pressed pic
	tvinsert.item.iSelectedImage=0;      // pressed pic
	//Parent=(HTREEITEM)SendDlgItemMessage
	//(hWnd,IDC_TREE1,TVM_INSERTITEM,0,(LPARAM)&tvinsert);
	HTREEITEM hItem=(HTREEITEM)SendMessage(m_hWnd, TVM_INSERTITEM, (WPARAM)0, (LPARAM)&tvinsert);
	
	return hItem;
}
HTREEITEM TicketListCtrl::InsertItem(std::wstring pluCode,HTREEITEM Parent)
{
	TV_INSERTSTRUCT tvinsert={0};    // struct to config out the
	// tree control
	// Now, we need to intialize this struct:
	// Global Vars:
	//HTREEITEM Parent;    // Tree item handle
	//HTREEITEM Before;    // .......
	//HTREEITEM Root;      // .......
	// .....
	// .....
	// Code:
	tvinsert.hParent=Parent;               // top-most level Item
	tvinsert.hInsertAfter=TVI_LAST;      // root level item attribute
	tvinsert.item.mask=TVIF_TEXT|TVIF_IMAGE|TVIF_SELECTEDIMAGE;
	// attributes
	tvinsert.item.pszText = (WCHAR*)pluCode.c_str();      // item text
	tvinsert.item.iImage=1;              // not pressed pic
	tvinsert.item.iSelectedImage=1;      // pressed pic
	//Parent=(HTREEITEM)SendDlgItemMessage
       //(hWnd,IDC_TREE1,TVM_INSERTITEM,0,(LPARAM)&tvinsert);
	HTREEITEM hItem=(HTREEITEM)SendMessage(m_hWnd, TVM_INSERTITEM, (WPARAM)0, (LPARAM)&tvinsert);

	return hItem;
}
