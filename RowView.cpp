// RowView.cpp : implementation file
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "RowView.h"
#include "ServiceDayDlg.h"
#include "PlanMakerDoc.h"
#include "PlanMakerView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRowView

IMPLEMENT_DYNCREATE(CRowView, CScrollView)

CRowView::CRowView()
{
}

CRowView::~CRowView()
{
}


BEGIN_MESSAGE_MAP(CRowView, CScrollView)
	//{{AFX_MSG_MAP(CRowView)
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRowView drawing
extern int rows;
extern int cols;
extern BOOL bNoPrintYear;
extern BOOL bEnableUndo;
extern BOOL bEnableRedo;

void CRowView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
}

void CRowView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
//x scrolling as main view; no y scrolling
	CSize sizeTotal(100 * (cols - 1), 0);
	CSize sizePage(100, 0);
	CSize sizeLine(5, 0);
	CScrollView::SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);

	if (lHint == 1)
		InvalidateRect(NULL, true);
	else
		InvalidateRect(NULL, false);
}

void CRowView::OnDraw(CDC* pDC)
{
	pDoc = (CPlanMakerDoc*)GetDocument();
	CFont *pOldFont = pDC->SelectObject(&font);

	CRect rect;
	this->GetClientRect(&rect);
	rect.left = 0;
	rect.right = col_pitch;
//shading and text
	for (int col = 1; col < cols; col++)
	{
		CString str = pDoc->GetCellInfo(0, col);
		CString str1;
		if (bNoPrintYear && str.Find(" 20") != -1)
		{
			int year = str.Find(" 20");
			str1 = str.Left(year) + str.Mid(year + 5);
		}
		else
			str1 = str;
		pDC->FillSolidRect(rect, 0x00d0d0d0);
		rect.DeflateRect(2, 2);
		pDC->DrawText(str1, rect, DT_CENTER | DT_WORDBREAK | DT_NOPREFIX);
		rect.InflateRect(2, 2);
		CPoint points[5] =
		{
			CPoint(rect.left, rect.top),
			CPoint(rect.right, rect.top),
			CPoint(rect.right, rect.bottom),
			CPoint(rect.left, rect.bottom),
			CPoint(rect.left, rect.top)
		};
		pDC->Polyline(points, 5);
		rect.OffsetRect(col_pitch, 0);
	}

	pDC->SelectObject(pOldFont);
}

/////////////////////////////////////////////////////////////////////////////
// CRowView diagnostics

#ifdef _DEBUG
void CRowView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CRowView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRowView message handlers

void CRowView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	CServiceDayDlg dlg;
	dlg.DoModal(); //show service day dlg
	CMainFrame* pMain = (CMainFrame*)AfxGetMainWnd(); //reset the view to CPlanMakerView
	pMain->ResetView();
	CScrollView::OnRButtonDown(nFlags, point);
}

extern BOOL bFitWidth;

void CRowView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	if (bFitWidth && cols > 1)
	{
		CRect rect;
		this->GetClientRect(&rect);
		col_pitch = rect.Width() / (cols - 1);
	}
	else
		col_pitch = 100;

	if (font.m_hObject != NULL)
		font.DeleteObject();

	CString face = "Arial";
	int size;
	bFitWidth ? size = 85 : size = 90;
	font.CreatePointFont(size, face, pDC);

	CScrollView::OnPrepareDC(pDC, pInfo);
}

void CRowView::OnLButtonDown(UINT nFlags, CPoint point) 
{
//do nothing - reset the view to CPlanMakerView
	CMainFrame* pMain = (CMainFrame*)AfxGetMainWnd();
	pMain->ResetView();

	CScrollView::OnLButtonDown(nFlags, point);
}


