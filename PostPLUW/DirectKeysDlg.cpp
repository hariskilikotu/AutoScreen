// DirectKeysDlg.cpp: implementation of the DirectKeysDlg class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DirectKeysDlg.h"
#include "resource.h"
#include "FileUtils.h"
#include "Settings.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
WCHAR * DirectKeysDlg::m_pszCommandText = NULL;
bool DirectKeysDlg::m_bOK = false;

DirectKeysDlg::DirectKeysDlg()
{
	m_bOK = false;
	m_pszCommandText = NULL;
}

DirectKeysDlg::~DirectKeysDlg()
{


}
WCHAR * DirectKeysDlg::GetCommandText()
{
	return m_pszCommandText;

}
bool DirectKeysDlg::IsOK()
{
	return m_bOK;
}
void DirectKeysDlg::Open(HWND hParent, HINSTANCE hInst)
{
	DialogBox(hInst,MAKEINTRESOURCE(IDD_DIALOG_DIRECT_KEYS),hParent,DirectKeysDialogBoxProc);
}

int CALLBACK DirectKeysDialogBoxProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_INITDIALOG:
		{
		
			WCHAR *pszScript = Settings::Instance()->GetScript();
			if(pszScript)
			{
				SetDlgItemText(hDlg,IDC_EDIT_INPUT_KEYS,pszScript);
			}

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
			case IDC_BUTTON_SAVE_SCRIPT:
				{
					//IDC_STATIC_CURRENT_FILE
					int nSize = SendDlgItemMessage(hDlg,IDC_EDIT_INPUT_KEYS,WM_GETTEXTLENGTH,0,0);
					
					if(nSize>0)
					{
						nSize++;
						WCHAR * pszText = new WCHAR[nSize];
						memset(pszText,0,nSize*sizeof(WCHAR));
						GetDlgItemText(hDlg,IDC_EDIT_INPUT_KEYS,pszText,nSize);
						DirectKeysDlg::m_bOK = true;
						FileUtils::Instance()->SaveToFile(hDlg , pszText);
						SetDlgItemText(hDlg, IDC_STATIC_CURRENT_FILE, FileUtils::Instance()->GetFileName());
					}
					break;

				}
			case IDC_BUTTON_OPEN_SCRIPT_FILE:
				{
					FileUtils::Instance()->OpenFile(hDlg);

					FileUtils::Instance()->GetScript(hDlg,IDC_EDIT_INPUT_KEYS);

					SetDlgItemText(hDlg, IDC_STATIC_CURRENT_FILE, FileUtils::Instance()->GetFileName());
					break;
				}
			case IDC_BUTTON_CLEAR:
				{
					SetDlgItemText(hDlg,IDC_EDIT_INPUT_KEYS,_T(""));
					break;
				}
			case IDOK:
				{
					int nSize = SendDlgItemMessage(hDlg,IDC_EDIT_INPUT_KEYS,WM_GETTEXTLENGTH,0,0);
					
					if(nSize>0)
					{
						nSize++;
						WCHAR * pszText = new WCHAR[nSize];
						memset(pszText,0,nSize*sizeof(WCHAR));
						GetDlgItemText(hDlg,IDC_EDIT_INPUT_KEYS,pszText,nSize);
						DirectKeysDlg::m_pszCommandText = pszText;
						DirectKeysDlg::m_bOK = true;

						//let us save the script to settings file
						Settings::Instance()->PutScript(pszText, nSize);
					}
					
					EndDialog(hDlg, 0);
					break;
				}
				break;
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
