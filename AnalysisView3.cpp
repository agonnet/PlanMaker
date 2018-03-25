// AnalysisView3.cpp : implementation file
//

#include "stdafx.h"
#include "planmaker.h"
#include "AnalysisView3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnalysisView

extern PINFO* pPInfoBase;
extern SINFO* pSInfoBase;
extern int nPreachers;
extern int rows;
extern int cols;
extern CString filename;
extern int nDay[32];
extern int nMonth[32];
extern BOOL bViewingAnalysis;
extern BOOL bAllocationDone;

IMPLEMENT_DYNCREATE(CAnalysisView, CScrollView)

CAnalysisView::CAnalysisView()
{
	nRowPitch = 16;
	nColPitch = 40;
}

CAnalysisView::~CAnalysisView()
{
	bViewingAnalysis = false;
}

BEGIN_MESSAGE_MAP(CAnalysisView, CScrollView)
	//{{AFX_MSG_MAP(CAnalysisView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnalysisView drawing

void CAnalysisView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
}

void CAnalysisView::OnDraw(CDC* pDC)
{
	pDoc = (CPlanMakerDoc*)GetDocument();
	CFont* pOldFont = pDC->SelectObject(&anFont);

//show where preachers appear
	CRect rect(0, 0, nColPitch, nRowPitch);
	for (int i = 0; i < nPrchsUsed; i++)
	{
		PINFO* pPInfo = pPrchList[i];
		for (int grp = 1; grp < 9; grp <<= 1)
		{
			if (bGroupUsed[grp])
			{
				for (int col = 1; col < cols; col++) //cols of plan and of analysis
				{
					switch (grp)
					{
					case 1: pDC->FillSolidRect(rect, 0x00c0ffff);
						break;
					case 2: pDC->FillSolidRect(rect, 0x00ffffc0);
						break;
					case 4: pDC->FillSolidRect(rect, 0x00ffc0c0);
						break;
					case 8: pDC->FillSolidRect(rect, 0x00c0c0ff);
					}
					if (!(pPInfo->availability[col] & grp))
						pDC->DrawText("N/A", rect, DT_CENTER);
					SINFO* pRow = pSInfoBase + 32;
					for (int row = 1; row < rows - 1; row ++) //rows of plan
					{
						SINFO* pSInfo = pRow + col;
						if (pDoc->PreacherAppears(pPInfo, pSInfo))
						{
							if (pRow->group == grp)
							{
								if (pSInfo->reserved)
									pDC->SetBkColor(0x0000ff00);//FillSolidRect(rect, 0x0000ff00);
								else
									pDC->SetBkColor(0x0000ffff);//FillSolidRect(rect, 0x0000ffff);
								pDC->DrawText(pRow->strChurchCode, rect, DT_CENTER);
								break;
							}
						}
						pRow += 32;
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
					rect.OffsetRect(nColPitch, 0);
				}
				rect.OffsetRect(-rect.left, nRowPitch);
			}
		}
	}
	pDC->SelectObject(pOldFont);
}

/////////////////////////////////////////////////////////////////////////////
// CAnalysisView diagnostics

#ifdef _DEBUG
void CAnalysisView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CAnalysisView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAnalysisView message handlers

void CAnalysisView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	if (anFont.m_hObject == NULL)  //font for analysis
		anFont.CreatePointFont(90, "Arial", pDC);
	if (anFontB.m_hObject == NULL)  //font for analysis
		anFontB.CreatePointFont(90, "Arial Bold", pDC);
	
	CScrollView::OnPrepareDC(pDC, pInfo);
}

void CAnalysisView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
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

	nRowPitch = 16;
	nColPitch = 40;

	CSize sizeTotal(nColPitch * (cols - 1), nRowPitch * nGroupsUsed * nPrchsUsed);
	CSize sizePage(nColPitch, nRowPitch * nGroupsUsed);
	CSize sizeLine(5, nRowPitch);
	CScrollView::SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);

	if (lHint == 1)
		InvalidateRect(NULL, true);
	else
		InvalidateRect(NULL, false);
}

CString CAnalysisView::IntToStr(int value)
{
	char ch[6];
	_itoa(value, ch, 10);
	return ch;
}


