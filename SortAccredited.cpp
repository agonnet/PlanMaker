// SortAccredited.cpp : implementation file
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "SortAccredited.h"
#include "PlanMakerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSortAccredited

CSortAccredited::CSortAccredited()
{
}

CSortAccredited::~CSortAccredited()
{
}


BEGIN_MESSAGE_MAP(CSortAccredited, CWnd)
	//{{AFX_MSG_MAP(CSortAccredited)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CSortAccredited message handlers
extern int nPreachers;
extern PINFO* pPInfoBase;

void CSortAccredited::DoSort()
{
	qsort(pPInfoBase, nPreachers, sizeof(PINFO), Compare);
}

int CSortAccredited::Compare(const void * p1, const void * p2)
{
//sort according to date of accreditation (anything like 19xx or 20xx)
	PINFO* pPInfo1 = (PINFO*)p1;
	PINFO* pPInfo2 = (PINFO*)p2;
	CString str1, str2;
	if (pPInfo1->add_info != "")
	{
		int yearpos = pPInfo1->add_info.Find("19");
		if (yearpos == -1)
			yearpos = pPInfo1->add_info.Find("20");
		if (yearpos != -1)
			str1 = pPInfo1->add_info.Mid(yearpos, 4);
		else
			str1 = "0";
	}
	else
		str1 = "0";
	if (pPInfo2->add_info != "")
	{
		int yearpos = pPInfo2->add_info.Find("19");
		if (yearpos == -1)
			yearpos = pPInfo2->add_info.Find("20");
		if (yearpos != -1)
			str2 = pPInfo2->add_info.Mid(yearpos, 4);
		else
			str2 = "0";
	}
	else
		str2 = "0";

	if (str1 < str2)
		return -1;
	if (str1 > str2)
		return 1;
	return 0;
}
