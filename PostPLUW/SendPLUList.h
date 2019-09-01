// SendPLUList.h: interface for the SendPLUList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SENDPLULIST_H__F63E7D13_55C8_45B7_B995_897817A16D61__INCLUDED_)
#define AFX_SENDPLULIST_H__F63E7D13_55C8_45B7_B995_897817A16D61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IJob.h"

class SendPLUList  : public IJob
{

	int m_nBuffSize;
	FILE *gblPLUfptr;
	HWND m_hWnd;
	HWND m_hSelectedWindow;
	WCHAR * m_pCurrentPLUCursor;
	WCHAR * m_pPLUBufStart;
	bool m_bRetryState;
	WCHAR m_lastReadPLU[20];

public:
	SendPLUList();
	virtual ~SendPLUList();

	void SendNextPLU();
	void SendPLU(WCHAR pszPLU[20]);
	void OnSendPLUFROMFile( HWND hList);

	virtual void OnNextStep();
	virtual void BeginJob(HWND hWnd, HWND hList);
	virtual void EndJob();
	virtual bool IsDone();

};

#endif // !defined(AFX_SENDPLULIST_H__F63E7D13_55C8_45B7_B995_897817A16D61__INCLUDED_)
