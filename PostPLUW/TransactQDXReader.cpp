// TransactQDXReader.cpp: implementation of the TransactQDXReader class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TransactQDXReader.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include "postrans.h"
#include "Utils.h"
#include "TransactQDX.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TransactQDXReader::TransactQDXReader(std::wstring strFileName)
{
	m_fpTransQDX = NULL;
	m_strFileName = strFileName;
	m_pTransQDX = NULL;
}

TransactQDXReader::~TransactQDXReader()
{

}
void TransactQDXReader::Bind(TransactQDX *pTransQDX)
{
	m_pTransQDX = pTransQDX;
}
void TransactQDXReader::FetchTickets()
{
	if( m_pTransQDX == NULL ) return;

	trans_  trs;
	bool bRead = false;
	//Read First Record
	bRead = QdxReadStart((void *)&trs );

	while( bRead == true )
	{
		//add to trace file

		switch( trs.general.opcode )
		{
		case TRANS_TICKET_FRAME:
			{
				break;
			}
		case TRANS_DEP_SALE:
			{
				//trs.dep_sale.dept;
				//trs.dep_sale.
				break;
			}
		case TRANS_PLU_SALE:
			{
				//Item sale can be a [Return], [Void] or an [Actual Sale]
				if(trs.plu_sale.return_type)
				{
				}
				else if(trs.plu_sale.opt_subtract)
				{
				}
				else
				{
					unsigned char chPLU[15]={0};
					unpak((unsigned char*)chPLU, trs.plu_sale.code, 14);
					if(strlen((char*)chPLU)>0)
					{
						Utils::Trace("\n");
						Utils::Trace((char*)chPLU);
						Ticket *pTicket = m_pTransQDX->GetCreateTicket(trs.plu_sale.tail.ticket_no);
						pTicket->AddPLU( PLUCODE((char*)chPLU) );

					}
				}

				break;
			}
			case TRANS_DISCOUNT:
			{
				break;
			}
			case TRANS_MEDIA:
			{
				//A payment has been made
				break;
			}
			case TRANS_TICKET_TOTAL:
				{
					//Found [Void Ticket]?
					if( trs.ticket_total.opt_void_ticket )
					{
					}

					//Found [Return Ticket]?
					if(trs.ticket_total.return_type)
					{
					}

					break;
				}
		}

		bRead = QdxReadNextRecord((void *)&trs );

	}

	QdxCloseFile();

	
}
void TransactQDXReader::unpak ( unsigned char *u_str, unsigned char *p_str, short n )
{
	short i;
	
	for (i=0; i < n ;i++,u_str++)
	{
		*u_str = (i & 1) ? (((*p_str++) & 0xf) | 0x30)
			: (((*p_str >> 4 ) & 0xf) | 0x30) ;
		if (*u_str >= 0x3a )
			*u_str  += 7;   /* convert leters to asci */
	}
}

bool TransactQDXReader::QdxReadStart(void *pBuf)
{
	m_fpTransQDX = _wfopen(m_strFileName.c_str(), _T("rb"));

	bool bReadStatus = QdxReadNextRecord(pBuf);
	
	return bReadStatus;
	
}
bool TransactQDXReader::QdxReadNextRecord(void *pBuf)
{
	int nRecordSize = sizeof(trans_);

	if(m_fpTransQDX)
	{
		size_t nReadCount = fread(pBuf, nRecordSize, 1, m_fpTransQDX);

		if(  nReadCount == 1 )
			return true;
	}
	
	return false;

}
void TransactQDXReader::QdxCloseFile()
{
	if(m_fpTransQDX != NULL)
		fclose(m_fpTransQDX);
}





