// TransactQDXDlg.cpp: implementation of the TransactQDXDlg class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TransactQDXDlg.h"
#include "resource.h"
#include "Settings.h"
#include "TransactQDX.h"
#include "TransactQDXReader.h"
#include <string>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
bool TransactQDXDlg::m_bRunTickets = false;

//CONTROL_MAP_OBJECTS
static 	TicketListCtrl ctrl_TicketList;

TransactQDXDlg::TransactQDXDlg()
{

}

TransactQDXDlg::~TransactQDXDlg()
{

}
bool TransactQDXDlg::ShouldRun()
{
	return m_bRunTickets;

}
//declare-open - and window procedure-keep in a sequence
int CALLBACK TicketsFromTransactQDXDialogBoxProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
void TransactQDXDlg::Open(HWND hParent, HINSTANCE hInst)
{
	DialogBox(hInst,MAKEINTRESOURCE(IDD_DIALOG_TRANSACTQDX),hParent,TicketsFromTransactQDXDialogBoxProc);
}

int CALLBACK TicketsFromTransactQDXDialogBoxProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_INITDIALOG:
		{
			ctrl_TicketList.Bind(GetDlgItem(hDlg,IDC_TREE_QDX_TICKET_LIST));
			ctrl_TicketList.InitControl();
			break;
		}
	case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{
			case IDOK:
			case IDCANCEL:
				{
					EndDialog(hDlg, 0);
					break;
				}
			case IDC_BUTTON_QDX_BROWSE:
				{
					std::wstring szQDXPath = _T("C:\\NCR\\Kishor\\BugFiles\\QDX\\transact.qdx");
					TransactQDXReader Reader(szQDXPath);
					Reader.Bind(TransactQDX::Instance());
					Reader.FetchTickets();
					ctrl_TicketList.InitControl();
					break;
				}
			case IDC_BUTTON_RUN_QDX_TICKETS:
				{

					TransactQDXDlg::m_bRunTickets = true;
					EndDialog(hDlg, 0);
					break;
				}			
			}
			break;
		}
	case WM_CLOSE:
		{
			EndDialog(hDlg, 0);
			return TRUE;
		}		
	}
	
	return FALSE;
}
