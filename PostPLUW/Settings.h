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
	_settingsdata(){nDelay=1000; nScriptLength=0;}
	int		nDelay;
	int		nScriptLength;
	int		reserved[100];//new requirements can consume them.
};

enum{
	KEY_DELAY
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
	bool IsRestrictToSelectedWindow();
	void GetIntValue(int nKey, int &nValue);
	void GetTextValue(int nKey, char *pszValue);
	void UpdateIntValue(int nKey,int nValue);
	void UpdateTextValue(int nKey,char szValue[30]);
	void AddScript(std::wstring name, std::wstring script);
	void GetScript(std::wstring name, std::wstring script);
	void LoadScripts();
	void SaveScripts();
	void PutScript(WCHAR * pszScript, int nLength);
	WCHAR* GetScript();


};

#endif // !defined(AFX_SETTINGS_H__B01E1BAC_390C_4C57_BE2E_E9C399D5A35E__INCLUDED_)
