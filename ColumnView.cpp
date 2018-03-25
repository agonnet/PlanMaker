// ColumnView.cpp : implementation file
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "ColumnView.h"
#include "PlaceTimeDlg.h"
#include "PlanMakerDoc.h"
#include "PlanMakerView.h"
#include "IncompatDlg.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CColumnView

IMPLEMENT_DYNCREATE(CColumnView, CScrollView)

CColumnView::CColumnView()
{
}

CColumnView::~CColumnView()
{
}


BEGIN_MESSAGE_MAP(CColumnView, CScrollView)
	//{{AFX_MSG_MAP(CColumnView)
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColumnView drawing

extern int rows;
extern int cols;
extern int nSelRow;
extern BOOL bSelected[100][32];
extern BOOL bEnableUndo;
extern BOOL bEnableRedo;
extern SINFO* pSInfo1Base;
extern PINFO* pPInfo1Base;
extern int nPreachers;

void CColumnView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
}

void CColumnView::OnDraw(CDC* pDC)
{
	pDoc = (CPlanMakerDoc*)GetDocument();
	CFont *pOldFont = pDC->SelectObject(&font);

//text and colours
	CRect rect;
	this->GetClientRect(&rect);
	rect.top = 0;
	rect.bottom = 50;
	for (int row = 1; row < rows; row++)
	{
		if (bSelected[row][0])
			pDC->FillSolidRect(rect, 0x00ff6060);
		else
			pDC->FillSolidRect(rect, 0x00d0d0d0);
		CString str;
		if (row < rows - 1)
			str = pDoc->GetCellInfo(row, 0);
		else
			str = "";
		rect.DeflateRect(2, 2);
		pDC->DrawText(str, rect, DT_CENTER | DT_WORDBREAK);
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
		rect.OffsetRect(0, 50);
	}

	pDC->SelectObject(pOldFont);
}

/////////////////////////////////////////////////////////////////////////////
// CColumnView diagnostics

#ifdef _DEBUG
void CColumnView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CColumnView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CColumnView message handlers

extern BOOL bPlanResized;

void CColumnView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	int nOldRows = rows;
	int y = point.y + CScrollView::GetScrollPosition().y;
	nSelRow = y / 50 + 1;
	if (nSelRow >= rows)
		return;
	for (int row = 1; row < rows; row++) //clear any selections
		bSelected[row][0] = false;
	bSelected[nSelRow][0] = true; //select clicked
	CRect rect;
	this->GetClientRect(&rect);
	InvalidateRect(&rect, false);
	CPlaceTimeDlg dlg;
	if (dlg.DoModal() == IDCANCEL)
		bSelected[nSelRow][0] = false;
	if (rows != nOldRows)
	{
		bSelected[nSelRow][0] = false;
		bPlanResized = true;
	}
	CMainFrame* pMain = (CMainFrame*)AfxGetMainWnd();
	pMain->ResetView();
	bEnableUndo = true;
	bEnableRedo = false;
	pDoc->SetModifiedFlag();

	CScrollView::OnRButtonDown(nFlags, point);
}

void CColumnView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	BOOL bIsModified = false;
	if (nFlags & MK_CONTROL)  //making incompatible churches
	{
		int y = point.y + CScrollView::GetScrollPosition().y;
		nSelRow = y / 50 + 1;
		if (nSelRow == rows - 1)
			return;
		for (int row = 1; row < rows; row++) //clear any selections
		{
			if (bSelected[row][0])
				bSelected[row][0] = false;
		}
		bSelected[nSelRow][0] = true; //select clicked
		CRect rect;
		this->GetClientRect(&rect);
		InvalidateRect(&rect, false);
		CIncompatDlg dlg;
		if (IDOK == dlg.DoModal())
		{
			RemoveIncompatiblePreachers();
			bIsModified = true;
		}
		else
			bSelected[nSelRow][0] = false;
	}
	else
	{
		for (int row = 1; row < rows; row++) //clear all selections
		{
			if (bSelected[row][0])
				bSelected[row][0] = false;
		}
	}

//reset the view to CPlanMakerView
	CMainFrame* pMain = (CMainFrame*)AfxGetMainWnd();
	pMain->ResetView();
	bEnableUndo = true;
	bEnableRedo = false;
	if (bIsModified)
		pDoc->SetModifiedFlag();
	else
		pDoc->UpdateAllViews(NULL, 0L, NULL);

	CScrollView::OnLButtonDown(nFlags, point);
}

extern BOOL bFitWidth;

void CColumnView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	if (font.m_hObject != NULL)
		font.DeleteObject();

	CString face = "Arial";
	int size;
	bFitWidth ? size = 85 : size = 90;
	font.CreatePointFont(size, face, pDC);
	
	CScrollView::OnPrepareDC(pDC, pInfo);
}

void CColumnView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
//y scrolling as main view; no x scrolling
	CSize sizeTotal(0, 50 * (rows - 1));
	CSize sizePage(0, 50);
	CSize sizeLine(0, 5);
	CScrollView::SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);

	if (lHint == 1)
		InvalidateRect(NULL, true);
	else
		InvalidateRect(NULL, false);
}

void CColumnView::RemoveIncompatiblePreachers()
{
//removes preachers from services in incompatible churches, except selected church
//deselect all
	for (int row = 1; row < rows - 1; row++)
	{
		for (int col = 1; col < cols; col++)
			bSelected[row][col] = false;
	}
	SINFO* pRow = pSInfo1Base + 32;
	SINFO* pSelRow = pSInfo1Base + 32 * nSelRow;
	for (row = 1; row < rows - 1; row++)
	{
		char grp = pRow->group + (char)0x30;
		CString strIncompat = (char)0x01 + pRow->strChurchCode + grp;
		if (pSelRow->place_time.Find(strIncompat) != -1)
		{
			SINFO* pSInfo = pRow + 1;
			SINFO* pSInfoSel = pSelRow + 1;
			for (int col = 1; col < cols; col++)
			{
				PINFO* pPInfo = pPInfo1Base;
				for (int prch = 0; prch < nPreachers; prch++)
				{
					if (pDoc->PreacherAppears(pPInfo, pSInfo) && pDoc->PreacherAppears(pPInfo, pSInfoSel))
					{
						pSInfo->preacher = "";
						pSInfo->reserved = false; //make not reserved
						bSelected[row][col] = true; //select cells where preachers removed - to warn user
					}
					pPInfo++;
				}
				pSInfo++;
				pSInfoSel++;
			}
		}
		pRow += 32;
	}
}
