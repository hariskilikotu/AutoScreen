// SettingsDlg.h: interface for the SettingsDlg class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SETTINGSDLG_H__33E290A9_28F3_469A_8CBA_83ADBFD27B6A__INCLUDED_)
#define AFX_SETTINGSDLG_H__33E290A9_28F3_469A_8CBA_83ADBFD27B6A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

int CALLBACK SettingsDialogBoxProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

class SettingsDlg  
{
public:
	SettingsDlg();
	virtual ~SettingsDlg();

	void Open(HWND hParent, HINSTANCE hInst);

};

#endif // !defined(AFX_SETTINGSDLG_H__33E290A9_28F3_469A_8CBA_83ADBFD27B6A__INCLUDED_)
