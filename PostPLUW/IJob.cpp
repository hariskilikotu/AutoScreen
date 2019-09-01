// IJob.cpp: implementation of the IJob class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IJob.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IJob::IJob()
{

	m_bSuspended = false;
}

IJob::~IJob()
{

}

void IJob::OnNextStep()
{
//Dont implement anything here. This is a default empty implementation
}
void IJob::BeginJob(HWND hWnd, HWND hList)
{
//Dont implement anything here. This is a default empty implementation
}

void IJob::SuspendJob()
{
	m_bSuspended = true;
}
void IJob::EndJob()
{
	//Dont implement anything here. This is a default empty implementation

}
void IJob::SetCommandText(WCHAR *pszText)
{
	//Dont implement anything here. This is a default empty implementation
}


bool IJob::IsSuspended()
{
	return m_bSuspended;
}
void IJob::ResumeJob()
{
	m_bSuspended = false;
}


