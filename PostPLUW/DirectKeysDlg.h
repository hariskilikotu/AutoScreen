// DirectKeysDlg.h: interface for the DirectKeysDlg class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIRECTKEYSDLG_H__AB794C50_8534_4265_A955_6C0227748117__INCLUDED_)
#define AFX_DIRECTKEYSDLG_H__AB794C50_8534_4265_A955_6C0227748117__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



int CALLBACK DirectKeysDialogBoxProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

class DirectKeysDlg  
{
public:	
	static bool m_bOK;
	static WCHAR *m_pszCommandText;
public:
	DirectKeysDlg();
	virtual ~DirectKeysDlg();
	void Open(HWND hParent, HINSTANCE hInst);
	WCHAR * GetCommandText();
	bool IsOK();

};

#endif // !defined(AFX_DIRECTKEYSDLG_H__AB794C50_8534_4265_A955_6C0227748117__INCLUDED_)
