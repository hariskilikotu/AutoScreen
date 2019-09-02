// FileUtils.h: interface for the FileUtils class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILEUTILS_H__A64B257C_FFFB_4022_A9D2_18DDBAAEF3A9__INCLUDED_)
#define AFX_FILEUTILS_H__A64B257C_FFFB_4022_A9D2_18DDBAAEF3A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class FileUtils  
{
	WCHAR m_szFile[260];     // if using TCHAR macros
public:
	FileUtils();
	virtual ~FileUtils();
	static FileUtils* Instance();
	void OpenFile(HWND hWnd);
	WCHAR *GetFileName();
	void GetScript( HWND hDlg, int nCtrlId);

	void SaveToFile(HWND hWnd, WCHAR *pszTxt);
	void SaveToFile(WCHAR *pszTxt);


};

#endif // !defined(AFX_FILEUTILS_H__A64B257C_FFFB_4022_A9D2_18DDBAAEF3A9__INCLUDED_)
