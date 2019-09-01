// SettingsDlg.cpp: implementation of the SettingsDlg class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SettingsDlg.h"
#include "resource.h"
#include "Settings.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



SettingsDlg::SettingsDlg()
{

}

SettingsDlg::~SettingsDlg()
{

}
void SettingsDlg::Open(HWND hParent, HINSTANCE hInst)
{
	DialogBox(hInst,MAKEINTRESOURCE(IDD_DIALOG_SETTINGS),hParent,SettingsDialogBoxProc);
}
int CALLBACK SettingsDialogBoxProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_INITDIALOG:
		{
			int nDelay = Settings::Instance()->GetDelay();
			SetDlgItemInt(hDlg,IDC_EDIT_DELAY,nDelay,FALSE);
			break;
		}
	case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{
				case IDCANCEL:
				{
					EndDialog(hDlg, 0);
					break;
				}
				case IDOK:
				{
					int nDelay = GetDlgItemInt(hDlg,IDC_EDIT_DELAY,NULL,FALSE);
					Settings::Instance()->UpdateDelay(nDelay);
					EndDialog(hDlg, 0);
					break;
				}
				break;
			}
			break;
		}
		case WM_CLOSE:
		{
			//EndDialog(hDlg, 0);
		}

	}
	
	return FALSE;
}
