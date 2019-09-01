// Utils.h: interface for the Utils class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UTILS_H__45FE2788_EC4C_4FE0_92B7_D4F75D790DFB__INCLUDED_)
#define AFX_UTILS_H__45FE2788_EC4C_4FE0_92B7_D4F75D790DFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#pragma warning(disable: 4786)
#include <string>
#include <map>
#include <vector>

#define FXSUSPEND 1
#define FXCLICK	2

	class _KEY_MAP{
		std::map<std::wstring,WCHAR> m_keyValues;
	public:
		_KEY_MAP();
		WCHAR GetKey(std::wstring strKeyName);

	};

namespace Utils  
{	
	int GetTokenCount();
	//bool HasInterrupt(int nIndex);
	int GetSpecialFunction(int nIndex);
	int GetInterruptDelay(int nIndex);
	int GetClickX(int nIndex);
	int GetClickY(int nIndex);
	wchar_t * ConvertToW(char *ansiString, int &nBuffSize);
	void ProcessToken(int nTokenIndex, HWND hSelectedWindow);
	void SendInputKey(WCHAR ch);
	BOOL CALLBACK enumWindowsProc(HWND hWnd,  LPARAM lParam);
	std::wstring Translate(WCHAR szCommand[100]);
	WCHAR GetActualKey(std::wstring szKeyName);
	void ClickMouse(int nX, int nY);
	void Trace(char *pszTxt);
	void Trace(DWORD num1, int num2, int num3);
};

#endif // !defined(AFX_UTILS_H__45FE2788_EC4C_4FE0_92B7_D4F75D790DFB__INCLUDED_)
