// SortPreachers.cpp : implementation file
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "SortPreachers.h"
#include "PlanMakerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSortPreachers

extern int nPreachers;
extern PINFO* pPInfo1Base;

CSortPreachers::CSortPreachers()
{
}

CSortPreachers::~CSortPreachers()
{
}


BEGIN_MESSAGE_MAP(CSortPreachers, CWnd)
	//{{AFX_MSG_MAP(CSortPreachers)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CSortPreachers message handlers

void CSortPreachers::DoSort()
{
	qsort(pPInfo1Base, nPreachers, sizeof(PINFO), Compare);
}

int CSortPreachers::Compare(const void * p1, const void * p2)
{
	PINFO* pPInfo1 = (PINFO*)p1;
	PINFO* pPInfo2 = (PINFO*)p2;
	
	if (pPInfo1->last_name < pPInfo2->last_name)
		return -1;
	if (pPInfo1->last_name > pPInfo2->last_name)
		return 1;
	if (pPInfo1->first_name < pPInfo2->first_name)
		return -1;
	if (pPInfo1->first_name > pPInfo2->first_name)
		return 1;
	return 0;
}
