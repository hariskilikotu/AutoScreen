// Utils.cpp: implementation of the Utils class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Utils.h"
#include "Settings.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
void GetFilterText(WCHAR *pBuff);

extern HWND hSelectedWindow;

namespace Utils
{
	std::vector<std::wstring> strTokens;
	std::map<int, int> m_specialFunctions;//1-{SUSPEND(XXXXX)}  2-{CLICK(XXXX,XXXX)}


	int GetTokenCount()
	{
		return strTokens.size();

	}
	wchar_t * ConvertToW(char *ansiString, int &nSize)
	{
		int output_size = MultiByteToWideChar(CP_ACP,0,ansiString,-1,NULL,0);
		wchar_t *converted_buf = new wchar_t[output_size];
		nSize = MultiByteToWideChar(CP_ACP,0,ansiString,-1,converted_buf,output_size);
		
		return converted_buf;
	}
	void Trace(DWORD num1, int num2, int num3)
	{
		char Buff[100]={0};
		sprintf(Buff,"\nIn(Key:Shift)=>%d(%d:%d)", num1, num2, num3);
		FILE *fptr = fopen("tracing.txt","a");
		fwrite(Buff,strlen(Buff),1,fptr);
		fclose(fptr);

	}
	void Trace(char *pszTxt)
	{
//		sprintf(Buff,"\nIn(Key:Shift)=>%d(%d:%d)", num1, num2, num3);
		FILE *fptr = fopen("tracing.txt","a");
		fwrite(pszTxt,strlen(pszTxt),sizeof(char),fptr);
		fclose(fptr);
		
	}

void ProcessToken(int nTokenIndex, HWND hSelectedWindow)
{
	std::wstring strKeys = strTokens.at(nTokenIndex);
	int nLength = strKeys.length();
	int i = 0;
	while( i<nLength )
	{
		
		WCHAR key = strKeys.at(i);
		
		if( Settings::Instance()->IsRestrictToSelectedWindow() && GetForegroundWindow() !=hSelectedWindow )
		{
			Sleep(2000);
		}
		else
		{
			SendInputKey(key);
			i++;
		}

	}

}
void SendInputKey(WCHAR ch)
{

	if(ch==10) return; // guarding from unnecessary ENTER

		// This structure will be used to create the keyboard
		// input event.

		//if OemKeyScan() doesn't work, we should try VkKeyScan() function
		//DWORD dwScanCodeAndShiftState =  OemKeyScan(ch);

		//WORD wVKeyCode		= LOWORD(dwScanCodeAndShiftState);
		//WORD wShiftKey	= HIWORD(dwScanCodeAndShiftState);

		//Trace(ch,wVKeyCode,wShiftKey);

		SHORT shKeyAndShift = VkKeyScan(ch);
		
		BYTE  byteKey = LOBYTE(shKeyAndShift);
		BYTE  byteShift = HIBYTE(shKeyAndShift);
		
		Trace(ch, byteKey, byteShift);

			
		INPUT ip={0};
		
		// Pause for 1/5 seconds.
		Sleep(100);
		
		// Set up a generic keyboard event.
		ip.type = INPUT_KEYBOARD;
		ip.ki.wScan = 0; // hardware scan code for key
		ip.ki.time = 0;
		ip.ki.dwExtraInfo = 0;

		bool bShiftON = byteShift & 0x01;

		if( bShiftON )
		{
			// Press the "A" key
			ip.ki.wVk = 0x10;//SHIFT KEY
			ip.ki.dwFlags = 0; // 0 for key press
			SendInput(1, &ip, sizeof(INPUT));			
		}
		
		// Press the "A" key
		ip.ki.wVk = byteKey; // virtual-key code for the "a" key
		ip.ki.dwFlags = 0; // 0 for key press
		SendInput(1, &ip, sizeof(INPUT));
		
		if( bShiftON )
		{
			// Press the "A" key
			ip.ki.wVk = 0x10;//SHIFT KEY
			ip.ki.dwFlags = KEYEVENTF_KEYUP; // 0 for key press
			SendInput(1, &ip, sizeof(INPUT));			
		}
		// Release the "A" key
		ip.ki.wVk = byteKey; // virtual-key code for the "a" key
		ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
		SendInput(1, &ip, sizeof(INPUT));
		
}
// #define MOUSEEVENTF_MOVE        0x0001 /* mouse move */
// #define MOUSEEVENTF_LEFTDOWN    0x0002 /* left button down */
// #define MOUSEEVENTF_LEFTUP      0x0004 /* left button up */
// #define MOUSEEVENTF_RIGHTDOWN   0x0008 /* right button down */
// #define MOUSEEVENTF_RIGHTUP     0x0010 /* right button up */
// #define MOUSEEVENTF_MIDDLEDOWN  0x0020 /* middle button down */
// #define MOUSEEVENTF_MIDDLEUP    0x0040 /* middle button up */
// #define MOUSEEVENTF_WHEEL       0x0800 /* wheel button rolled */
// #define MOUSEEVENTF_ABSOLUTE    0x8000 /* absolute move */
void ClickMouse(int nX, int nY)
{
	INPUT ip={0};
	
	int maxX = GetSystemMetrics(SM_CXSCREEN), maxY = GetSystemMetrics(SM_CYSCREEN);
	int x = maxX/2, y = maxY/2;
	double factorX = 65536.0 / maxX,factorY = 65536.0 / maxY;

	// Pause for 1/5 seconds.
	Sleep(100);
	
	// Set up a generic keyboard event.
	ip.type = INPUT_MOUSE;
	ip.mi.dx = factorX*nX;
	ip.mi.dy = factorY*nY;
	ip.mi.mouseData = 0;
	ip.mi.dwFlags = 0x8003;
	//MOUSEEVENTF_ABSOLUTE 0x8000
	//MOUSEEVENTF_LEFTDOWN 0x0002
	
	SendInput(1, &ip, sizeof(INPUT));

	ip.mi.dwFlags = 0x8004;
	SendInput(1, &ip, sizeof(INPUT));
}

BOOL CALLBACK enumWindowsProc(	HWND hWnd, LPARAM lParam ) 
{
		WCHAR BuffTitle[100] = {0};
		WCHAR BuffClsName[100] = {0};
		WCHAR Buff[200]={0};
		GetWindowText(hWnd,BuffTitle,100);
		
		if(wcslen(BuffTitle)==0) return TRUE;
		
		
		GetClassName(hWnd,BuffClsName,100);
		wcscpy(Buff,BuffTitle);
		Buff[wcslen(BuffTitle)]=' ';
		Buff[wcslen(BuffTitle)+1]='[';
		wcscpy(Buff+wcslen(BuffTitle)+2,BuffClsName);
		Buff[wcslen(Buff)]=']';

		WCHAR FilterBuff[100]={0};
		GetFilterText(FilterBuff);

		if( FilterBuff[0]==0 || wcsstr(BuffClsName,FilterBuff)!=NULL )
		{		
			int nItem = SendMessage((HWND)lParam, LB_ADDSTRING, 0, (LPARAM)Buff);
			SendMessage((HWND)lParam, LB_SETITEMDATA, (WPARAM)nItem, (LPARAM)hWnd);
		}
		return TRUE;
}


std::wstring Translate(WCHAR *pInputString)
{
	strTokens.clear();
	std::wstring strTranslatedString;
	
	WCHAR chKey = 0;
	wchar_t * pStart = pInputString;
	int nScanCursor = 0;
	while(pStart[nScanCursor] != 0)
	{
		int nTempFillIndex = 0;
		WCHAR tmpKeyChunk[100]={0};
		while( pStart[nScanCursor] != 0 && pStart[nScanCursor] != '{' )
		{

			tmpKeyChunk[nTempFillIndex++] = pStart[nScanCursor];

			if(nTempFillIndex==99)
			{
				strTokens.push_back( std::wstring(tmpKeyChunk) );
				memset( tmpKeyChunk, 0, 99*sizeof(WCHAR) );
				nTempFillIndex =0;
			}

			nScanCursor++;
		}

		//add to strToken if anything found so far?

		if(nTempFillIndex>0)
				strTokens.push_back(std::wstring(tmpKeyChunk));
		
		//Control arrive here with two possible states
		//1) reached end of input string[LASTDOOR] 
		//or 2) found a start brace [GOOD]


		//Block:GOOD
		if( pStart[nScanCursor] == '{' )
		{
			//need to look for '}'
			WCHAR tmpKeyName[101] = {0};
			int ntmpKeyFillIndex = 0;
			while( pStart[nScanCursor]!= 0 && pStart[nScanCursor]!= '}' && ntmpKeyFillIndex <100)
			{
				tmpKeyName[ntmpKeyFillIndex++] = pStart[nScanCursor];
				nScanCursor++;
			}
			//Control arrive here with either of 3 states
			//1- reached end of input string or 2) found a close brace 3) ran out of max key size
			if(pStart[nScanCursor]== '}')
			{
				//MessageBox(NULL,tmpKeyName,_T("Key"),MB_OK);
				//need to replace the key name with actual key code
				tmpKeyName[ntmpKeyFillIndex] = '}';
				wchar_t chKey = GetActualKey(std::wstring(tmpKeyName));
				if(chKey)
				{
					WCHAR keyStr[2] = {0};
					keyStr[0] = chKey;
					strTokens.push_back( std::wstring(keyStr) );
				}
				else if( wcslen(tmpKeyName)==16 && 
					wcsncmp(tmpKeyName,_T("{SUSPEND("),9)==0 && 
					tmpKeyName[14] == ')' &&
					tmpKeyName[15] == '}')
				{
					wchar_t digits[6] = {0};
					wchar_t num[2] = {0};

					
					digits[0] = tmpKeyName[9];
					digits[1] = tmpKeyName[10];
					digits[2] = tmpKeyName[11];
					digits[3] = tmpKeyName[12];
					digits[4] = tmpKeyName[13];

					num[0] = _wtoi(digits);

					//MessageBox(NULL,digits,"",MB_OK);
					//MessageBox(NULL,num,"",MB_OK);
					
					strTokens.push_back( std::wstring(num) );
					int nSize = strTokens.size();
					m_specialFunctions.insert(std::make_pair(nSize-1,FXSUSPEND));
					
				}//{CLICK(0000,0000)}
				else if( wcslen(tmpKeyName)==18 && 
					wcsncmp(tmpKeyName,_T("{CLICK("),7)==0 && 
					tmpKeyName[16] == ')' &&
					tmpKeyName[17] == '}')
				{
					wchar_t xDigits[5] = {0};
					wchar_t yDigits[5] = {0};
					wchar_t numX[2] = {0};
					wchar_t numY[2] = {0};
					
					
					xDigits[0] = tmpKeyName[7];
					xDigits[1] = tmpKeyName[8];
					xDigits[2] = tmpKeyName[9];
					xDigits[3] = tmpKeyName[10];

					yDigits[0] = tmpKeyName[12];
					yDigits[1] = tmpKeyName[13];
					yDigits[2] = tmpKeyName[14];
					yDigits[3] = tmpKeyName[15];
					
					numX[0] = _wtoi(xDigits);
					numY[0] = _wtoi(yDigits);
										
					strTokens.push_back( std::wstring(numX) );
					strTokens.push_back( std::wstring(numY) );

					int nSize = strTokens.size();
					m_specialFunctions.insert(std::make_pair(nSize-2,FXCLICK));
					
				}
				else
				{
				//if no key code found, have the key name unchanged added to token array
					strTokens.push_back( std::wstring(tmpKeyName) );
				}
				nScanCursor++;

			}
			else
			{
				strTokens.push_back( std::wstring(tmpKeyName) );
			}

		}
		else //Block:LASTDOOR
		{

			break;
		}
		
	}
	
	int nSize = strTokens.size();
	for(int i=0; i<nSize; i++)
	{
		strTranslatedString = strTranslatedString + strTokens[i];
	}
	return strTranslatedString;

}
int GetIntVal(int nIndex)
{
	std::wstring strTok = strTokens.at(nIndex);
	WCHAR wcVal = strTok.at(0);
	return wcVal;
}
int GetInterruptDelay(int nIndex)
{
	return GetIntVal(nIndex);
}
int GetClickX(int nIndex)
{
	return GetIntVal(nIndex);
}
int GetClickY(int nIndex)
{
	return GetIntVal(nIndex);
}

int GetSpecialFunction(int nIndex)
{
	return m_specialFunctions[nIndex];
}

_KEY_MAP key_name_map;

WCHAR GetActualKey(std::wstring strKeyName)
{
	WCHAR chKey = key_name_map.GetKey(strKeyName);
	return chKey;
}

}//Utils namespace end bracket



_KEY_MAP::_KEY_MAP()
{
	m_keyValues.insert(std::make_pair(std::wstring(_T("{ENTER}")),(WCHAR)0xD));
	m_keyValues.insert(std::make_pair(std::wstring(_T("{TAB}")),(WCHAR)0x9));
	m_keyValues.insert(std::make_pair(std::wstring(_T("{MENU}")),(WCHAR)0x12));
	m_keyValues.insert(std::make_pair(std::wstring(_T("{ALT}")),(WCHAR)0x12));
	m_keyValues.insert(std::make_pair(std::wstring(_T("{BACKSPACE}")),(WCHAR)0x8));
}
WCHAR _KEY_MAP::GetKey(std::wstring strKeyName)
{
	WCHAR chKey = m_keyValues[strKeyName];
	return chKey;
}

