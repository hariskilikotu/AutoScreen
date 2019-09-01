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
	
	fseek(fptr,0,SEEK_END);
	int nSize = ftell(fptr);
	
	if(nSize>0)
	{
		fseek(fptr,0,SEEK_SET);
		fread(&data,1,sizeof(data),fptr);
	}
	switch(nKey)
	{
	case KEY_DELAY:
		{
			nValue = data.nDelay;
			break;
		}
	}
	
	fclose(fptr);
}
void Settings::GetTextValue(int nKey, char *szValue)
{

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
	FILE * fptr = fopen("settings.dat","ab");
	
	if(fptr==NULL) return;
	
	fseek(fptr,0,SEEK_END);
	int nSize = ftell(fptr);
	
	if(nSize>0)
	{
		fseek(fptr,0,SEEK_SET);
		fread(&data,1,sizeof(data),fptr);
	}
	
	switch(nKey)
	{
		case KEY_DELAY:
			{
					data.nDelay = nValue;
					break;
			}
	}

	fwrite(&data,1,sizeof(data),fptr);
	fclose(fptr);
}
void Settings::UpdateTextValue(int nKey,char szValue[30])
{

}
void Settings::PutScript(WCHAR * pszScript, int nLength)
{
	_settingsdata data;
	
	char *pszFile = NULL;
	FILE * fptr = fopen("settings.dat","wb");
	
	if(fptr==NULL) return;

	fread(&data,1,sizeof(data),fptr);
	data.nScriptLength = nLength;

	fseek(fptr,0,SEEK_SET);

	fwrite(&data,1,sizeof(data),fptr);

	fwrite(pszScript,sizeof(WCHAR), nLength, fptr);

	fclose(fptr);

	Utils::Trace("\nSettings::PutScript() End");

}
WCHAR* Settings::GetScript()
{
	_settingsdata data;
	
	char *pszFile = NULL;
	FILE * fptr = fopen("settings.dat","r+b");
	
	if(fptr==NULL) return NULL;
	
	fread(&data,1,sizeof(data),fptr);

	WCHAR *pszScript = NULL;

	int nLength = data.nScriptLength;
	
	if( nLength >0 )
	{
		pszScript = new WCHAR[nLength];
		memset(pszScript,0, sizeof(WCHAR)*nLength);
		fread(pszScript, nLength, sizeof(WCHAR), fptr);
		Utils::Trace("\nSettings::GetScript() reading completed");
	}
	else
	{
		Utils::Trace("\nSettings::GetScript() nothing was found in cache");
	}

	return pszScript;
}

void AddScript(std::wstring name, std::wstring script)
{

}
void GetScript(std::wstring name, std::wstring script)
{

}
void LoadScripts()
{

}
void SaveScripts()
{

}