// TransactQDXReader.h: interface for the TransactQDXReader class.
//
//////////////////////////////////////////////////////////////////////
#pragma warning(disable:4786) 

#include<map>
#include<string>

class TransactQDX;
class TransactQDXReader  
{
	FILE *m_fpTransQDX;
	std::wstring m_strFileName;
	TransactQDX *m_pTransQDX;
 
public:
	void Bind(TransactQDX *pTransQDX);
	bool QdxReadStart(void *pBuf);
	bool QdxReadNextRecord(void *pBuf);
	void QdxCloseFile();

	void FetchTickets();
	void unpak ( unsigned char *u_str, unsigned char *p_str, short n );

	TransactQDXReader(std::wstring strFileName);
	virtual ~TransactQDXReader();
	std::wstring m_szQDXFilePath;

};