// FileUtils.cpp: implementation of the FileUtils class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FileUtils.h"
#include <commdlg.h>
#include <stdio.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FileUtils::FileUtils()
{

}

FileUtils::~FileUtils()
{

}
FileUtils* FileUtils::Instance()
{
	static FileUtils obj;

	return &obj;


}
void FileUtils::OpenFile(HWND hWnd)
{
	OPENFILENAME ofn;       // common dialog box structure


	// Initialize OPENFILENAME
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFile = m_szFile;
	ofn.nMaxFile = sizeof(m_szFile);
	ofn.lpstrFilter = _T("*.TXT");
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (GetOpenFileName(&ofn) == TRUE)
	{
		
	}
};

WCHAR *FileUtils::GetFileName()
{
	return m_szFile;
}

void FileUtils::GetScript( HWND hDlg, int nCtrlId)
{
	char *pszFile = NULL;
	FILE * fptr = _wfopen(m_szFile,_T("r+b"));
	
	if(fptr==NULL) return ;

	fseek (fptr,0,SEEK_END);
	int nSize = ftell(fptr);
	
	if(nSize>0)
	{
		char *tempBuffPtr = new char[nSize+2];
		memset((void*)tempBuffPtr,0,nSize+2);
		fseek (fptr,0,SEEK_SET);
		fread(tempBuffPtr,nSize,1,fptr);
		SetDlgItemText(hDlg, nCtrlId, (WCHAR*)tempBuffPtr);
		//m_pPLUBufStart = Utils::ConvertToW(tempBuffPtr, m_nBuffSize);
		delete []tempBuffPtr;
	}

	fclose(fptr);
	
}

void FileUtils::SaveToFile(HWND hWnd, WCHAR *pszTxt)
{
	OPENFILENAME ofn;
	
	// Initialize OPENFILENAME
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFile = m_szFile;
	ofn.nMaxFile = sizeof(m_szFile);
	ofn.lpstrFilter = _T("*.TXT");
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = 0;//OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	
	if (GetSaveFileName(&ofn) == TRUE)
	{
		SaveToFile(pszTxt);
	}
}

void FileUtils::SaveToFile(WCHAR *pszTxt)
{
	char *pszFile = NULL;
	FILE * fptr = _wfopen( m_szFile,_T("wb"));
	
	if(fptr==NULL) return;
	
	int nLen = wcslen(pszTxt);
	fwrite(pszTxt,sizeof(WCHAR),nLen,fptr);
		
	fclose(fptr);
}