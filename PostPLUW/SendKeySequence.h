// SendKeySequence.h: interface for the SendKeySequence class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SENDKEYSEQUENCE_H__BC8EC213_7F6F_43E9_B40F_7845963CED63__INCLUDED_)
#define AFX_SENDKEYSEQUENCE_H__BC8EC213_7F6F_43E9_B40F_7845963CED63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <string>
#include <map>
#include "IJob.h"

#define SENDKEY_SEQUENCE_TIMER 200


class SendKeySequence : public IJob  
{
	HWND	m_hSelectedWindow;
	std::wstring m_szTranslatedCommands;
	int		 m_nNextSendKeyIndex;
	bool	 m_bRetryState;
	WCHAR	*m_pszCommandText;
	WCHAR	*m_pCurrentCommandCursor;
	WCHAR	 m_szLastReadCommand[100];

	int m_nRepCount;
	int m_nIterationsCompleted;

public:
	SendKeySequence(char *pszInputFileName);
	virtual ~SendKeySequence();

	virtual void BeginJob(HWND hWnd, HWND hList);
	virtual void OnNextStep();
	virtual void EndJob();
	virtual bool IsDone();


	int GetInterruptDelay(int nIndex);
	void SetCommandText(WCHAR *pszText);

	

};

#endif // !defined(AFX_SENDKEYSEQUENCE_H__BC8EC213_7F6F_43E9_B40F_7845963CED63__INCLUDED_)
