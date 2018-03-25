// AnalysisRowView.cpp : implementation file
//

#include "stdafx.h"
#include "planmaker.h"
#include "AnalysisRowView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnalysisRowView

IMPLEMENT_DYNCREATE(CAnalysisRowView, CScrollView)

CAnalysisRowView::CAnalysisRowView()
{
}

CAnalysisRowView::~CAnalysisRowView()
{
}


BEGIN_MESSAGE_MAP(CAnalysisRowView, CScrollView)
	//{{AFX_MSG_MAP(CAnalysisRowView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnalysisRowView drawing

void CAnalysisRowView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
}

extern int cols;
extern int nDay[32];
extern int nMonth[32];

void CAnalysisRowView::OnDraw(CDC* pDC)
{
	CPlanMakerDoc* pDoc = (CPlanMakerDoc*)GetDocument();
	CFont* pOldFont = pDC->SelectObject(&anFont);
	CRect rect;
	this->GetClientRect(&rect);
	rect.left = 0;
	rect.right = nColPitch;
//text & background
	for (int col = 1; col < cols; col++)
	{
		pDC->FillSolidRect(rect, 0x00e0e0e0);
		pDC->DrawText(pDoc->IntToStr(nDay[col])	+ "/" + pDoc->IntToStr(nMonth[col]), &rect, DT_CENTER);
		CPoint points[5] =
		{
			CPoint(rect.left, rect.top),
			CPoint(rect.right, rect.top),
			CPoint(rect.right, rect.bottom),
			CPoint(rect.left, rect.bottom),
			CPoint(rect.left, rect.top)
		};
		pDC->Polyline(points, 5);
		rect.OffsetRect(nColPitch, 0);
	}
	pDC->SelectObject(pOldFont);
}

/////////////////////////////////////////////////////////////////////////////
// CAnalysisRowView diagnostics

#ifdef _DEBUG
void CAnalysisRowView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CAnalysisRowView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAnalysisRowView message handlers

void CAnalysisRowView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	nColPitch = 40;

	CSize sizeTotal(nColPitch * (cols - 1), 0);
	CSize sizePage(nColPitch, 0);
	CSize sizeLine(5, 0);
	CScrollView::SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);

	if (lHint == 1)
		InvalidateRect(NULL, true);
	else
		InvalidateRect(NULL, false);
}

void CAnalysisRowView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	if (anFont.m_hObject == NULL)  //font for analysis
		anFont.CreatePointFont(90, "Arial", pDC);
	
	CScrollView::OnPrepareDC(pDC, pInfo);
}
