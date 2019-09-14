// Settings.h: interface for the Settings class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SETTINGS_H__B01E1BAC_390C_4C57_BE2E_E9C399D5A35E__INCLUDED_)
#define AFX_SETTINGS_H__B01E1BAC_390C_4C57_BE2E_E9C399D5A35E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <string>
#include <map>

struct _settingsdata
{
	_settingsdata()
	{
		nDelay=1000; nScriptLength=0;
		memset(szQDXPath,0,sizeof(szQDXPath)*sizeof(WCHAR));
	}
	int		nDelay;
	int		nScriptLength;
	int		nRepeatCount;
	int		reserved[99];//new requirements can consume them.
	WCHAR	szQDXPath[250];
};

enum{
	KEY_DELAY,
	KEY_REPEAT_COUNT
};
class Settings  
{
	std::map<std::wstring,std::wstring> m_scriptCollection;
	WCHAR  m_szConfigFileName[100];
	static Settings *m_pInstance;
public:
	Settings();
	virtual ~Settings();
	static Settings* Instance();
	void UpdateDelay(int nDelay);
	int GetDelay();
	void UpdateRepeatCount(int nRepCount);
	int  GetRepeatCount();
	bool IsRestrictToSelectedWindow();
	void GetIntValue(int nKey, int &nValue);
	void UpdateIntValue(int nKey,int nValue);
	void PutScript(WCHAR * pszScript, int nLength);
	WCHAR* GetScript();
	void SetQDXPath( std::wstring strPath);
	std::wstring GetQDXPath();
};

#endif // !defined(AFX_SETTINGS_H__B01E1BAC_390C_4C57_BE2E_E9C399D5A35E__INCLUDED_)
