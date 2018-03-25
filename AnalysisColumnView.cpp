// AnalysisColumnView.cpp : implementation file
//

#include "stdafx.h"
#include "planmaker.h"
#include "AnalysisColumnView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnalysisColumnView

IMPLEMENT_DYNCREATE(CAnalysisColumnView, CScrollView)

CAnalysisColumnView::CAnalysisColumnView()
{
}

CAnalysisColumnView::~CAnalysisColumnView()
{
}


BEGIN_MESSAGE_MAP(CAnalysisColumnView, CScrollView)
	//{{AFX_MSG_MAP(CAnalysisColumnView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////

extern PINFO* pPInfoBase;
extern SINFO* pSInfoBase;
extern int nPreachers;
extern int rows;
extern int cols;
extern BOOL bAllocationDone;

// CAnalysisColumnView drawing

void CAnalysisColumnView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
}

void CAnalysisColumnView::OnDraw(CDC* pDC)
{
	CPlanMakerDoc* pDoc = (CPlanMakerDoc*)GetDocument();
	CFont* pOldFont = pDC->SelectObject(&anFont);
	CRect rect;
	this->GetClientRect(&rect);
	rect.top = 0;
	rect.bottom = nRowPitch;
//text & background
	for (int prch = 0; prch < nPrchsUsed; prch++)
	{
		PINFO* pPInfo = pPrchList[prch];
		CString str = "  " + pPInfo->screen_name;
		str += (pPInfo->reserved) ? " (R) " : " ";
		str += pDoc->IntToStr(nOnPlan[prch]);
		if (pPInfo->nLimit != -1)
		{
			str += "/";
			str += pDoc->IntToStr(pPInfo->nLimit);
		}
		pDC->FillSolidRect(rect, 0x00e0e0e0);
		if (pPInfo->ordained && !pPInfo->visitor)
		{
			CFont* pOldFont = pDC->SelectObject(&anFontB);
			pDC->DrawText(str, rect, DT_SINGLELINE | DT_LEFT);
			pDC->SelectObject(pOldFont);
		}
		else
		{
			CFont* pOldFont = pDC->SelectObject(&anFont);
			pDC->DrawText(str, rect, DT_SINGLELINE | DT_LEFT);
			pDC->SelectObject(pOldFont);
		}
		CPoint points[5] =
		{
			CPoint(rect.left, rect.top),
			CPoint(rect.right, rect.top),
			CPoint(rect.right, rect.bottom),
			CPoint(rect.left, rect.bottom),
			CPoint(rect.left, rect.top)
		};
		pDC->Polyline(points, 5);
		rect.OffsetRect(0, nRowPitch);
	}
	pDC->SelectObject(pOldFont);
}

/////////////////////////////////////////////////////////////////////////////
// CAnalysisColumnView diagnostics

#ifdef _DEBUG
void CAnalysisColumnView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CAnalysisColumnView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAnalysisColumnView message handlers

void CAnalysisColumnView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	CPlanMakerDoc* pDoc = (CPlanMakerDoc*)GetDocument();
//find which preachers are available and number of times used
	nPrchsUsed = 0;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		PINFO* pPInfo = pPInfoBase + prch;
		int nAppears = 0;
		BOOL bIsAvail = false;
		SINFO* pRow = pSInfoBase + 32;
		for (int row = 1; row < rows - 1; row++)
		{
			SINFO* pSInfo = pRow + 1;
			for (int col = 1; col < cols; col++)
			{
				if (pPInfo->availability[col] & pRow->group)
				{
					bIsAvail = true;
					if (pDoc->PreacherAppears(pPInfo, pSInfo)
						&& (bAllocationDone || pSInfo->reserved))
						nAppears++;
				}
				pSInfo++;
			}
			pRow += 32;
		}
		if (bIsAvail)
		{
			pPrchList[nPrchsUsed] = pPInfo;
			nOnPlan[nPrchsUsed] = nAppears;
			nPrchsUsed++;
		}
	}
//find which service groups are present
	nGroupsUsed = 0;
	for (int grp = 1; grp < 9; grp <<= 1)
	{
		bGroupUsed[grp] = false;
		SINFO* pRow = pSInfoBase + 32;
		for (int row = 1; row < rows - 1; row++)
		{
			if (pRow->group == grp)
			{
				bGroupUsed[grp] = true;
				nGroupsUsed++;
				break;
			}
			pRow += 32;
		}
	}

	nRowPitch = 16 * nGroupsUsed;

	CSize sizeTotal(0, nRowPitch * nPrchsUsed);
	CSize sizePage(0, nRowPitch);
	CSize sizeLine(0, 16);
	CScrollView::SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);

	if (lHint == 1)
		InvalidateRect(NULL, true);
	else
		InvalidateRect(NULL, false);

}

void CAnalysisColumnView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	if (anFont.m_hObject == NULL)  //font for analysis
		anFont.CreatePointFont(90, "Arial", pDC);
	if (anFontB.m_hObject == NULL)  //bold font for analysis
		anFontB.CreatePointFont(90, "Arial Bold", pDC);

	CScrollView::OnPrepareDC(pDC, pInfo);
}
