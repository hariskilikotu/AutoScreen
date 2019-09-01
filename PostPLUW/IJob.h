// IJob.h: interface for the IJob class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IJOB_H__C27EE4D9_0B01_49A2_8CD7_7C50094C8A59__INCLUDED_)
#define AFX_IJOB_H__C27EE4D9_0B01_49A2_8CD7_7C50094C8A59__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class IJob  
{
public:
	IJob();
	virtual ~IJob();

	virtual void BeginJob(HWND hWnd, HWND hList);
	virtual void OnNextStep();
	virtual void EndJob();
	virtual void SetCommandText(WCHAR *pszText);
	virtual bool IsDone() = 0;
	void SuspendJob();
	void ResumeJob();
	bool IsSuspended();
	bool m_bSuspended;

};

#endif // !defined(AFX_IJOB_H__C27EE4D9_0B01_49A2_8CD7_7C50094C8A59__INCLUDED_)
