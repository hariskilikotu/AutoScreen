// Settings.cpp: implementation of the Settings class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Settings.h"
#include "Utils.h"
#include <stdio.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Settings * Settings::m_pInstance = NULL;

Settings::Settings()
{
	memset(m_szConfigFileName,0,100*sizeof(WCHAR));
	wcscpy(m_szConfigFileName, _T("settings.dat"));
}

Settings::~Settings()
{

}
Settings* Settings::Instance()
{
	if(m_pInstance == NULL)
		m_pInstance = new Settings;

	return m_pInstance;
}
int Settings::GetDelay()
{
	int nDelay;

	GetIntValue(KEY_DELAY, nDelay);

	return nDelay;
}
bool Settings::IsRestrictToSelectedWindow()
{
	return false;
}
void Settings::GetIntValue(int nKey,int &nValue)
{
	_settingsdata data;
	
	char *pszFile = NULL;
	FILE * fptr = fopen("settings.dat","r");
	
	if(fptr==NULL) return;

	fread(&data,1,sizeof(data),fptr);
	
	switch(nKey)
	{
	case KEY_DELAY:
		{
			nValue = data.nDelay;
			break;
		}
	case KEY_REPEAT_COUNT:
		{
			nValue = data.nRepeatCount;
			break;
		}
	}
	
	fclose(fptr);
}

void Settings::UpdateDelay(int nDelay)
{
	if(nDelay<0) return;

	UpdateIntValue(KEY_DELAY , nDelay);

}
void Settings::UpdateIntValue(int nKey,int nValue)
{

	_settingsdata data;
	
	char *pszFile = NULL;
	FILE * fptr = fopen("settings.dat","rb");
	
	if(fptr==NULL) return;

	fread(&data,1,sizeof(data),fptr);
	fclose(fptr);

	switch(nKey)
	{
		case KEY_DELAY:
			{
				data.nDelay = nValue;
				break;
			}
		case KEY_REPEAT_COUNT:
			{
				data.nRepeatCount = nValue;
				break;
			}
	}

	fptr = fopen("settings.dat","wb");
	fwrite(&data,1,sizeof(data),fptr);
	fclose(fptr);
}
void Settings::UpdateRepeatCount(int nRepCount)
{
	if(nRepCount<0) return;
	
	UpdateIntValue(KEY_REPEAT_COUNT , nRepCount);
}
int  Settings::GetRepeatCount()
{
	int nCount = 1;
	GetIntValue(KEY_REPEAT_COUNT, nCount);

	return nCount;

}
void Settings::PutScript(WCHAR * pszScript, int nLength)
{
	
	char *pszFile = NULL;
	FILE * fptr = fopen("scriptcache.dat","wb");
	
	if(fptr==NULL) return;

	fwrite(pszScript,sizeof(WCHAR), nLength, fptr);

	fclose(fptr);

	Utils::Trace("\nSettings::PutScript() End");

}
WCHAR* Settings::GetScript()
{
	
	char *pszFile = NULL;
	FILE * fptr = fopen("scriptcache.dat","r+b");
	
	if(fptr==NULL) return NULL;
	
	WCHAR *pszScript = NULL;

	fseek(fptr,0,SEEK_END);
	
	int nLength = ftell(fptr);

	fseek(fptr, 0, SEEK_SET);
	
	if( nLength >0 )
	{
		pszScript = new WCHAR[nLength];
		memset(pszScript,0, sizeof(WCHAR)*nLength);
		fread(pszScript, nLength, 1, fptr);
		Utils::Trace("\nSettings::GetScript() reading completed");
	}
	else
	{
		Utils::Trace("\nSettings::GetScript() nothing was found in cache");
	}

	return pszScript;
}
void Settings::SetQDXPath( std::wstring strPath)
{
	_settingsdata data;
	
	char *pszFile = NULL;
	FILE * fptr = fopen("settings.dat","rb");
	
	if(fptr==NULL) return;
	
	fread(&data,1,sizeof(data),fptr);
	fclose(fptr);

	if( strPath.length()<250 )
		wcscpy(data.szQDXPath,strPath.c_str());
	else
		wcscpy(data.szQDXPath,_T("***file path must be shorter than 250 characters***"));

	
	fptr = fopen("settings.dat","wb");
	fwrite(&data,1,sizeof(data),fptr);
	fclose(fptr);
}
std::wstring Settings::GetQDXPath()
{
	_settingsdata data;
	
	char *pszFile = NULL;
	FILE * fptr = fopen("settings.dat","r");
	
	if(fptr==NULL) return std::wstring(_T(""));
	
	fread(&data,1,sizeof(data),fptr);
	fclose(fptr);
	return std::wstring(data.szQDXPath);
}