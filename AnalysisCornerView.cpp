// AnalysisCornerView.cpp : implementation file
//

#include "stdafx.h"
#include "AnalysisCornerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnalysisCornerView

IMPLEMENT_DYNCREATE(CAnalysisCornerView, CScrollView)

CAnalysisCornerView::CAnalysisCornerView()
{
}

CAnalysisCornerView::~CAnalysisCornerView()
{
}


BEGIN_MESSAGE_MAP(CAnalysisCornerView, CScrollView)
	//{{AFX_MSG_MAP(CAnalysisCornerView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnalysisCornerView drawing

void CAnalysisCornerView::OnInitialUpdate()
{
	CSize sizeTotal;
	sizeTotal.cx = 0;
	sizeTotal.cy = 0;
	SetScrollSizes(MM_TEXT, sizeTotal);

	CScrollView::OnInitialUpdate();
}

void CAnalysisCornerView::OnDraw(CDC* pDC)
{
	CRect rect;
	this->GetClientRect(&rect);
	pDC->FillSolidRect(rect, 0x00e0e0e0);
}

/////////////////////////////////////////////////////////////////////////////
// CAnalysisCornerView diagnostics

#ifdef _DEBUG
void CAnalysisCornerView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CAnalysisCornerView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAnalysisCornerView message handlers
