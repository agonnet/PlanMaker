// CornerView.cpp : implementation file
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "CornerView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCornerView

IMPLEMENT_DYNCREATE(CCornerView, CView)

CCornerView::CCornerView()
{
}

CCornerView::~CCornerView()
{
}


BEGIN_MESSAGE_MAP(CCornerView, CView)
	//{{AFX_MSG_MAP(CCornerView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCornerView drawing

void CCornerView::OnDraw(CDC* pDC)
{
	CRect rect;
	this->GetClientRect(&rect);
	pDC->FillSolidRect(rect, 0x00d0d0d0);
}

/////////////////////////////////////////////////////////////////////////////
// CCornerView diagnostics

#ifdef _DEBUG
void CCornerView::AssertValid() const
{
	CView::AssertValid();
}

void CCornerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCornerView message handlers

void CCornerView::OnLButtonDown(UINT nFlags, CPoint point) 
{
//do nothing - reset the view to CPlanMakerView
	ResetView();	
	CView::OnLButtonDown(nFlags, point);
}

void CCornerView::OnRButtonDown(UINT nFlags, CPoint point) 
{
//do nothing - reset the view to CPlanMakerView
	ResetView();	
	CView::OnRButtonDown(nFlags, point);
}

void CCornerView::ResetView()
{
	CMainFrame* pMain = (CMainFrame*)AfxGetMainWnd();
	pMain->ResetView();
}

