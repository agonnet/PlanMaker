// PlanMakerView.cpp : implementation of the CPlanMakerView class
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "PlanMakerDoc.h"
#include "PlanMakerView.h"
#include "WinSpool.h"
#include "AnalysisView3.h"
#include "MainFrm.h"
#include "AnalysisWnd.h"
#include "LabelDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlanMakerView

IMPLEMENT_DYNCREATE(CPlanMakerView, CScrollView)

BEGIN_MESSAGE_MAP(CPlanMakerView, CScrollView)
	//{{AFX_MSG_MAP(CPlanMakerView)
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_FILE_PRINT_LABELS, OnFilePrintLabels)
	ON_COMMAND(ID_FILE_PRINT_PLAN, OnFilePrintPlan)
	ON_COMMAND(ID_FILE_PRINTPREVIEW_LABELS, OnFilePrintpreviewLabels)
	ON_COMMAND(ID_FILE_PRINTPREVIEW_PLAN, OnFilePrintpreviewPlan)
	ON_COMMAND(ID_FILE_PRINTPREVIEW_ANALYSIS, OnFilePrintpreviewAnalysis)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_FILE_PRINTSETUP_FONT, OnFilePrintsetupFont)
	ON_COMMAND(ID_FILE_PRINT_ANALYSIS, OnFilePrintAnalysis)
	ON_COMMAND(ID_VIEW_ANALYSIS, OnViewAnalysis)
	ON_COMMAND(ID_VIEW_FITWIDTH, OnViewFitwidth)
	ON_COMMAND(ID_VIEW_AVAILABLEPREACHERS, OnViewAvaliablepreachers)
	ON_COMMAND(ID_VIEW_PREACHERRECORDS, OnViewPreacherrecords)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

///////////////////////////////////////////
//globals declared in doc.cpp
extern int rows;
extern int cols;
extern int nPreachers;
extern PINFO* pPInfoBase;
extern SINFO* pSInfoBase;
extern PINFO* pPInfo1Base;
extern SINFO* pSInfo1Base;
extern BOOL bSelected[100][32];
extern int nDay[32];
extern int nMonth[32];
extern int nYear[32];
extern CString filename;
extern int nSelRow;
extern int nSelCol;
extern int nSelPrch;
extern CString strDetails[100][32];
extern CString strAvailPrchs[100][32];
extern int left, top, right, bottom;
extern BOOL bAllocationDone;
extern LPLOGFONT lpFont;
extern BOOL bPrintPlan;
extern BOOL bNoPrintYear;
extern COLORREF crPlanFontColor;
extern BOOL bUseSforComm;
extern BOOL bUseAllAge;
extern CString strPathDat;

//globals declared in labeldlg.cpp
extern int nAcross;
extern int nDown;
extern int nFont;
extern int nHOffset;
extern int nVOffset;
extern int nTopMargin;
extern int nLeftMargin;
extern int nStartRow;
extern BOOL bNoLabel;
extern int nLocalLabel;
extern int nVisitorLabel;

/////////////////////////////////////////////////////////////////////////////
// CPlanMakerView construction/destruction

CPlanMakerView::CPlanMakerView()
{
}

CPlanMakerView::~CPlanMakerView()
{
}

BOOL CPlanMakerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

void CPlanMakerView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
}

/////////////////////////////////////////////////////////////////////////////
// CPlanMakerView drawing

extern BOOL bFitWidth;

void CPlanMakerView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	if (pInfo != NULL) //do nothing if printing
		return;

//create display fonts if not already done
	if (font.m_hObject != NULL) //for non-ministers in plan
		font.DeleteObject();
	if (fontb.m_hObject != NULL) //for ministers in plan
		fontb.DeleteObject();
	if (fonti.m_hObject != NULL) //for details in plan
		fonti.DeleteObject();

	int size;
	bFitWidth ? size = 85 : size = 90;
	font.CreatePointFont(size, "Arial", pDC);
	fontb.CreatePointFont(size, "Arial Bold", pDC);
	fonti.CreatePointFont(size, "Arial Italic", pDC);

//set column pitch
	if (bFitWidth && cols > 1)
	{
		CRect rect;
		this->GetClientRect(&rect);
		col_pitch = rect.Width() / (cols - 1);
	}
	else
		col_pitch = 100;

//set pane sizes
	if (bFitWidth)
	{
		CMainFrame* pMain = (CMainFrame*)AfxGetMainWnd();
		pMain->SetRow(0, 50, 0);
		pMain->SetColumn(0, 100, 0);
	}
	else
	{
		CMainFrame* pMain = (CMainFrame*)AfxGetMainWnd();
		pMain->SetRow(0, 75, 0);
		pMain->SetColumn(0, 150, 0);
	}

	CScrollView::OnPrepareDC(pDC, pInfo);
}

extern BOOL bShowAvailPrchs;

void CPlanMakerView::OnDraw(CDC* pDC)
{
	pDoc = (CPlanMakerDoc*)GetDocument();
	CRect rect(0, 0, col_pitch, 50);
	SINFO* pRow = pSInfoBase + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			BOOL bHasBorder = false;
			if (bShowAvailPrchs && !pSInfo->no_service && pSInfo->preacher == "")
			{
//borders
				if (pSInfo->nAvailPrchs < 2)
					pDC->FillSolidRect(rect, 0x000000ff); //red border
				else if (pSInfo->nAvailPrchs < 4)
					pDC->FillSolidRect(rect, 0x0054b9ff); //orange border
				else if (pSInfo->nAvailPrchs < 8)
					pDC->FillSolidRect(rect, 0x0037f7f5); //yellow border
				else
					pDC->FillSolidRect(rect, 0x0000ff00); //green border
//fill
				rect.DeflateRect(5, 5);
				if (bSelected[row][col])
					pDC->FillSolidRect(rect, 0x00ff6060); //fill blue
				else if (pSInfo->reserved)
					pDC->FillSolidRect(rect, 0x00d0d0d0); //fill grey
				else if (bAllocationDone)
					pDC->FillSolidRect(rect, 0x00ffffff); //fill white
				
				else
				{
					switch (pRow->group) //fill according to service group
					{
					case 1: pDC->FillSolidRect(rect, 0x00c0ffff);
						break;
					case 2:	pDC->FillSolidRect(rect, 0x00ffffa0);
						break;
					case 4:	pDC->FillSolidRect(rect, 0x00ffa0a0);
						break;
					case 8:	pDC->FillSolidRect(rect, 0x008080ff);
					}
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
				rect.InflateRect(5, 5);
				bHasBorder = true;
			}
			else //not showing available preachers
			{
				if (bSelected[row][col])
					pDC->FillSolidRect(rect, 0x00ff6060); //fill blue
				else if (pSInfo->reserved)
					pDC->FillSolidRect(rect, 0x00d0d0d0); //fill grey
				else if (bAllocationDone && pSInfo->preacher == "" & !pSInfo->no_service)
					pDC->FillSolidRect(rect, 0x00ffffff); //fill white
				else
				{
					switch (pRow->group)
					{
					case 1: pDC->FillSolidRect(rect, 0x00c0ffff);
						break;
					case 2:	pDC->FillSolidRect(rect, 0x00ffffa0);
						break;
					case 4:	pDC->FillSolidRect(rect, 0x00ffa0a0);
						break;
					case 8:	pDC->FillSolidRect(rect, 0x008080ff);
					}
				}
			}
//show no_service if applicable
			if (pSInfo->no_service)
			{
				pDC->MoveTo(rect.left, rect.top);
				pDC->LineTo(rect.right, rect.bottom);
				pDC->MoveTo(rect.left, rect.bottom);
				pDC->LineTo(rect.right, rect.top);
			}
//add text
			CFont* pOldFont;
			if (bHasBorder) //no preacher
			{
				rect.DeflateRect(7, 7);
				CRect rectDraw = rect;
				pOldFont = pDC->SelectObject(&fonti);
				pDC->DrawText(strDetails[row][col], rectDraw, DT_CENTER | DT_MODIFYSTRING | DT_WORD_ELLIPSIS);
				pDC->SelectObject(pOldFont);
				CSize size = pDC->GetTextExtent(strDetails[row][col]);
				rectDraw.OffsetRect(0, size.cy);
				pOldFont = pDC->SelectObject(&font);
				pDC->DrawText(strAvailPrchs[row][col], rectDraw, DT_CENTER);
				pDC->SelectObject(pOldFont);
				rect.InflateRect(7, 7);
			}
			else //has preacher(s)
			{
//find how many preachers there are
				int nSlashes = 0;
				int i = 0;
				while (i < pSInfo->preacher.GetLength())
				{
					if (pSInfo->preacher.GetAt(i++) == '/')
						nSlashes++;
				}
//look for local ords first
				CRect rectDraw = rect;
				rectDraw.DeflateRect(2, 2);
				PINFO* pPInfo = pPInfoBase;
				for (int prch = 0; prch < nPreachers; prch++)
				{
					if (pPInfo->ordained && !pPInfo->visitor)
					{
						if (pDoc->PreacherAppears(pPInfo, pSInfo))
						{
							pOldFont = pDC->SelectObject(&fontb);
							CString str = pPInfo->screen_name + " (" + IntToStr(pPInfo->nInRow[row]) + ")";
							if (nSlashes-- > 0)
								str += " / ";
							pDC->DrawText(str, rectDraw, DT_CENTER | DT_WORDBREAK);
							CSize size = pDC->GetTextExtent(pPInfo->screen_name);
							rectDraw.OffsetRect(0, size.cy);
							pDC->SelectObject(pOldFont);
						}
					}
					pPInfo++;
				}
//then lays, visitors & reserved
				pPInfo = pPInfoBase;
				for (prch = 0; prch < nPreachers; prch++)
				{
					if (!pPInfo->ordained || pPInfo->visitor || pPInfo->reserved)
					{
						if (pDoc->PreacherAppears(pPInfo, pSInfo))
						{
							pOldFont = pDC->SelectObject(&font);
							CString str = pPInfo->screen_name + " (" + IntToStr(pPInfo->nOnPlan) + ")";
							if (nSlashes-- > 0)
								str += " / ";
							pDC->DrawText(str, rectDraw, DT_CENTER | DT_WORDBREAK);
							CSize size = pDC->GetTextExtent(pPInfo->screen_name);
							rectDraw.OffsetRect(0, size.cy);
							pDC->SelectObject(pOldFont);
						}
					}
					pPInfo++;
				}
//service types and details
				pOldFont = pDC->SelectObject(&fonti);
				pDC->DrawText(strDetails[row][col], rectDraw, DT_CENTER | DT_WORDBREAK);
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
			rect.OffsetRect(col_pitch, 0);
			pSInfo++;
		}
		rect.OffsetRect(-rect.left, 50);
		pRow += 32;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPlanMakerView printing

int nFirstLabel;

void CPlanMakerView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
//print labels
	if (bPrintLabels)
	{
		DoPrintLabels(pDC, pInfo);
	}
//print analysis
	if (bPrintAnalysis)
	{
		DoPrintAnalysis(pDC, pInfo);
	}
//print plan
	if (bPrintPlan)
	{
		DoPrintPlan(pDC, pInfo);
	}
}

BOOL CPlanMakerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	pInfo->m_bDirect = true;  //don't show print dialog

	CPlanMakerApp* pApp = (CPlanMakerApp*)AfxGetApp();
	if (bPrintPlan)
		pApp->SetLandscape();
	else
		pApp->SetPortrait();

	return DoPreparePrinting(pInfo);
}

void CPlanMakerView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	pLabelsListBase = NULL;
//print labels
	if (bPrintLabels)
	{
		if (labFont.m_hObject == NULL)  //font for labels
			labFont.CreatePointFont(nFont * 10, "Arial", pDC);

//nXXXLabel = 0 - none
//nXXXLabel = 1 - all
//nXXXLabel = 2 - planned
//nXXXLabel = 3 - available
		pLabelsListBase = new PINFO[200];
		PINFO* pLabelsList = pLabelsListBase;
		nToPrint = 0;
		PINFO* pPInfo = pPInfoBase;
		for (int prch = 0; prch < nPreachers; prch++)
		{
			if (pPInfo->email == ""	|| (pPInfo->email != ""	&& !bNoLabel))
			{
				if ((nLocalLabel == 1 && !pPInfo->visitor)
					|| (nVisitorLabel == 1 && pPInfo->visitor))
				{
					*pLabelsList = *pPInfo;
					pLabelsList++;
					nToPrint++;
				}
				if ((nLocalLabel >= 2 && !pPInfo->visitor)
					|| (nVisitorLabel >= 2 && pPInfo->visitor))
				{
					pPInfo->bDoLabel = false;  //avoid duplicates
					SINFO* pRow = pSInfoBase + 32;
					for (int row = 1; row < rows - 1; row++)
					{
						SINFO* pSInfo = pRow + 1;
						for (int col = 1; col < cols; col++)
						{
							if (!pPInfo->bDoLabel)
							{
								if ((pDoc->PreacherAppears(pPInfo, pSInfo)
										&& (nLocalLabel == 2 || nVisitorLabel == 2))
									|| (pPInfo->availability[col] != 0
										&& (nLocalLabel == 3 || nVisitorLabel == 3)))
								{
									pPInfo->bDoLabel = true;
									*pLabelsList = *pPInfo;
									pLabelsList++;
									nToPrint++;
								}
							}
							pSInfo++;
						}
						pRow += 32;
					}
				}
			}
			pPInfo++;
		}

		int scale = pDC->GetDeviceCaps(LOGPIXELSX) / 25; //pixels to mm
		nLabelRectLeft = nHOffset * scale - pDC->GetDeviceCaps(PHYSICALOFFSETX);
		nPrintRectLeft = nLabelRectLeft + nLeftMargin * scale;
		col_pitch = (pDC->GetDeviceCaps(PHYSICALWIDTH) - 2 * nHOffset * scale) / nAcross;
		nColsPerPage = nAcross;
		nHorzPages = 1;

		scale = pDC->GetDeviceCaps(LOGPIXELSY) / 25; //pixels to mm
		nLabelRectTop = nVOffset * scale - pDC->GetDeviceCaps(PHYSICALOFFSETY);
		nPrintRectTop = nLabelRectTop + nTopMargin * scale;
		row_pitch = (pDC->GetDeviceCaps(PHYSICALHEIGHT) - 2 * nVOffset * scale) / nDown;

//see if bottom label can be fully printed
		if (labFont.m_hObject == NULL)  //font for labels
			labFont.CreatePointFont(nFont * 10, "Arial", pDC);
		CFont* pOldFont = pDC->SelectObject(&labFont);
		TEXTMETRIC txtMetrics;
		LPTEXTMETRIC lpMetrics = &txtMetrics;
		pDC->GetTextMetrics(lpMetrics);
		int textheight = 6 * lpMetrics->tmHeight;
		int viewportextent = pDC->GetDeviceCaps(VERTRES);
		int textextent = (nDown - 1) * row_pitch + nPrintRectTop + textheight;
		nRowsPerPage = nDown;
		if (textextent > viewportextent)
			nRowsPerPage--;
		pDC->SelectObject(pOldFont);

		nVertPages = (nToPrint + nStartRow) / nAcross / nRowsPerPage;
		if ((nToPrint / nAcross) % nRowsPerPage)
			nVertPages++;
		nPages = nHorzPages * nVertPages;
	}

//print analysis
	else if (bPrintAnalysis)
	{
		if (anFont.m_hObject == NULL)  //font for analysis
			anFont.CreatePointFont(100, "Arial Narrow", pDC);
//find which preachers are available and number of times used
		nPrchsUsed = 0;
		for (int prch = 0; prch < nPreachers; prch++)
		{
			PINFO* pPInfo = pPInfoBase + prch;
			BOOL bIsAvail = false;
			int nAppears = 0;
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
		col_pitch = pDC->GetDeviceCaps(LOGPIXELSX) * 4 / 10; //0.4 inch wide
		row_pitch = pDC->GetDeviceCaps(LOGPIXELSY) * 2 / 10; //0.2 inch high
//cols (dates) per page
		nColsPerPage = pDC->GetDeviceCaps(HORZRES) / col_pitch - 3; //left col = 3 cols
//rows (preachers) per page
		nRowsPerPage = (pDC->GetDeviceCaps(VERTRES) / row_pitch - 2) / nGroupsUsed; //1 row_pitch for header, 1 for cols headers
//pages
		nVertPages = nPrchsUsed / nRowsPerPage;
		if (nPrchsUsed % nRowsPerPage)
			nVertPages++;
		nHorzPages = (cols - 1) / nColsPerPage; //plan has (cols-1) dates
		if ((cols - 1) % nColsPerPage)
			nHorzPages++;
		nPages = nHorzPages * nVertPages;
	}

//print plan
	else if (bPrintPlan)
	{
		if (planFont.m_hObject == NULL)  //font for plan
			planFont.CreatePointFontIndirect(lpFont, pDC);

		col_pitch = pDC->GetDeviceCaps(LOGPIXELSX) * 3 / 4; // 0.75 inch
		nColsPerPage = pDC->GetDeviceCaps(HORZRES) / col_pitch;
		nHorzPages = (cols) / nColsPerPage;
		if (cols % nColsPerPage)
			nHorzPages++;
		nColsPerPage--; //allow 1 for churches column

		CSize size = pDC->GetTextExtent("H", 1); //get height of text
		row_pitch = pDC->GetDeviceCaps(LOGPIXELSY) / 2; //0.5 inch
		nRowsPerPage = (pDC->GetDeviceCaps(VERTRES) - 2 * size.cy) / row_pitch; //allow for file header
		nVertPages = (rows - 1) / nRowsPerPage;
		if ((rows - 1) % nRowsPerPage)
			nVertPages++;
		nRowsPerPage--; //allow 1 for dates row

		nPages = nHorzPages * nVertPages;
	}

	pInfo->SetMinPage(1);
	pInfo->SetMaxPage(nPages);
}

void CPlanMakerView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: add cleanup after printing
	if (planFont.m_hObject != NULL)
		planFont.DeleteObject();
	if (labFont.m_hObject != NULL)
		labFont.DeleteObject();
	if (anFont.m_hObject != NULL)
		anFont.DeleteObject();
	if (pLabelsListBase != NULL)
		delete [] pLabelsListBase;
	bPrintPlan = false;
	bPrintAnalysis = false;
	bPrintLabels = false;
}


/////////////////////////////////////////////////////////////////////////////
// CPlanMakerView diagnostics

#ifdef _DEBUG
void CPlanMakerView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CPlanMakerView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDocument* CPlanMakerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlanMakerDoc)));
	return (CDocument*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPlanMakerView message handlers

void CPlanMakerView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	if (bFitWidth)
	{
//no horizontal scrolling
		CSize sizeTotal(0, 50 * (rows - 1));
		CSize sizePage(0, 50);
		CSize sizeLine(0, 5);
		CScrollView::SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);
	}
	else
	{
		CSize sizeTotal(100 * (cols - 1), 50 * (rows - 1));
		CSize sizePage(100, 50);
		CSize sizeLine(5, 5);
		CScrollView::SetScrollSizes(MM_TEXT, sizeTotal, sizePage, sizeLine);
	}

	if (lHint == 0)
		InvalidateRect(NULL, false); //update
	else
		InvalidateRect(NULL, true); //erase & update
}

void CPlanMakerView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	nColDown0 = nColDown; //remember previous click
	nRowDown0 = nRowDown;
	CRect rect = GetRectFromMouse(point); //also gets new values for nRowDown & nColDown
	switch (nFlags - 1)
	{
	case MK_CONTROL:
		{
			bSelected[nRowDown][nColDown] = true; //select clicked cell
			InvalidateRect(&rect, false);
			return;
		}
	case MK_CONTROL | MK_SHIFT:
		{
			if (nColDown0 < 1 || nColDown0 >= cols || nRowDown0 < 1 || nRowDown0 >= rows - 1)
				return;
			int nStartCol = nColDown0; //start at previous click
			for (int row = nRowDown0; row < rows - 1; row++)
			{
				for (int col = nStartCol; col < cols; col++)
				{
					CRect rect = GetRectFromCell(row, col);
					bSelected[row][col] = true;
					InvalidateRect(&rect, false);
					if (row == nRowDown && col == nColDown) //select until current click reached
						return;
				}
				nStartCol = 1; //start subsequent rows at first col
			}
		}
	default:
		{
			BOOL bClickedSelected = false; 
			if (bSelected[nRowDown][nColDown]) //if clicked cell already selected
				bClickedSelected = true;
			for (int row = 1; row < rows - 1; row++) //clear all selected
			{
				for (int col = 1; col < cols; col++)
				{
					if (bSelected[row][col])
					{
						CRect rect = GetRectFromCell(row, col);
						bSelected[row][col] = false;
						InvalidateRect(&rect, false);
					}
				}
			}
			if (!bClickedSelected) //if clicked cell wasn't selected, select it
			{
				CRect rect = GetRectFromCell(nRowDown, nColDown);
				bSelected[nRowDown][nColDown] = true;
				InvalidateRect(&rect, false);
			}
		}
	}
}

void CPlanMakerView::OnMouseMove(UINT nFlags, CPoint point) 
{
	if ((nFlags & MK_LBUTTON) != 0)
	{
		CRect rect = GetRectFromMouse(point);
		SINFO* pSInfo = pSInfo1Base + 32 * nRowDown + nColDown;
		if (!bSelected[nRowDown][nColDown])
		{
			bSelected[nRowDown][nColDown] = true;
			InvalidateRect(&rect, false);
		}
	}
}

void CPlanMakerView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	CRect rect = GetRectFromMouse(point);
	nSelRow = nRowDown;
	nSelCol = nColDown;
	if (!bSelected[nRowDown][nColDown]) //if clicked cell not selected, deselect all
	{
		for (int row = 1; row < rows; row++)
		{
			for (int col = 1; col < cols; col++)
			{
				if (bSelected[row][col])
				{
					CRect rect = GetRectFromCell(row, col);
					bSelected[row][col] = false;
					InvalidateRect(&rect, false);
				}
			}
		}
	}
	bSelected[nRowDown][nColDown] = true; //select clicked
	InvalidateRect(&rect, false);

	pDoc->DoServicesPopup(point);
}

CString CPlanMakerView::IntToStr(int value)
{
	char ch[6];
	_itoa(value, ch, 10);
	return ch;
}

void CPlanMakerView::OnFilePrintLabels() 
{
	CLabelDlg dlg;
	if (IDOK != dlg.DoModal())
		return;
	bPrintAnalysis = false;
 	bPrintLabels = true;
	bPrintPlan = false;
	pDoc->Store();
 	OnFilePrint();
}

void CPlanMakerView::OnFilePrintPlan() 
{
	bPrintLabels = false;
	bPrintAnalysis = false;
	bPrintPlan = true;
	OnFilePrint();
}

void CPlanMakerView::OnFilePrintAnalysis() 
{
 	bPrintLabels = false;
  	bPrintAnalysis = true;
	bPrintPlan = false;
  	OnFilePrint();
}

void CPlanMakerView::OnFilePrintpreviewLabels() 
{
	CLabelDlg dlg;
	if (IDOK != dlg.DoModal())
		return;
	bPrintAnalysis = false;
 	bPrintLabels = true;
	bPrintPlan = false;
 	OnFilePrintPreview();
}

void CPlanMakerView::OnFilePrintpreviewPlan() 
{
	bPrintAnalysis = false;
	bPrintLabels = false;
	bPrintPlan = true;
	OnFilePrintPreview();	
}

void CPlanMakerView::OnFilePrintpreviewAnalysis() 
{
 	bPrintLabels = false;
  	bPrintAnalysis = true;
	bPrintPlan = false;
  	OnFilePrintPreview();
}

void CPlanMakerView::OnFilePrintsetupFont() 
{
//lfHeight is used by CreatePointFontIndirect(), which interprets it in tenths of a point
//dlg Create() interprets it as a number of pixels on the screen
	LONG nOldHeight = lpFont->lfHeight; //remember the unconverted value
	CClientDC dc(this);
//convert lpHeight to number of pixels on the screen
	lpFont->lfHeight = -MulDiv(lpFont->lfHeight, dc.GetDeviceCaps(LOGPIXELSY), 720);
	CFontDialog dlg(lpFont);
	if (IDOK != dlg.DoModal())
	{
		lpFont->lfHeight = nOldHeight;
		return;
	}
	crPlanFontColor = dlg.GetColor();
	dlg.GetCurrentFont(lpFont);
//GetSize() returns the font size in tenths of a point
	lpFont->lfHeight = dlg.GetSize();
	pDoc->Store();
}

BOOL bViewingAnalysis;

void CPlanMakerView::OnViewAnalysis() 
{
	bViewingAnalysis ^= 1;
	if (bViewingAnalysis)
	{
		CRect rect = CRect(100, 100, 40 * cols + 205, 400);
		CCreateContext createContext;
		createContext.m_pCurrentDoc = pDoc;
		pWndAnalysis = (CFrameWnd*)new CAnalysisWnd;
		pWndAnalysis->Create(
			NULL,
			"Analysis",
			WS_OVERLAPPEDWINDOW | WS_EX_TOPMOST,
			rect,
			this,
			NULL,
			0,
			&createContext);
		pWndAnalysis->InitialUpdateFrame(pDoc, true);
	}
	else
		pWndAnalysis->DestroyWindow();
}

void CPlanMakerView::DoPrintPlan(CDC *pDC, CPrintInfo *pInfo)
{
	CFont* pOldFont = pDC->SelectObject(&planFont);
	pDC->SetTextColor(crPlanFontColor);

//print file date & time
	CString str = "File: ";
	CFileStatus status;
	if (filename == "")
	{
		str += strPathDat + " - ";
		if (CFile::GetStatus(strPathDat, status))
			str += status.m_mtime.Format("%A, %d %B, %Y; %H:%M");
	}
	else
	{
		str += filename + " - ";
		if (CFile::GetStatus(filename, status))
			str += status.m_mtime.Format("%A, %d %B, %Y; %H:%M");
	}
	str += " Page ";
	str += IntToStr(pInfo->m_nCurPage);
	pDC->TextOut(0, 0, str);

//example 9 page layout numbered by pInfo->m_nCurPage - 1
// | 0 | 1 | 2 |
// | 3 | 4 | 5 |
// | 6 | 7 | 8 |

	int startcol = ((pInfo->m_nCurPage - 1) % nHorzPages) * nColsPerPage + 1; //start printing at col 1
	int startrow = ((pInfo->m_nCurPage - 1) / nHorzPages) * nRowsPerPage + 1; //start printing at row 1

	CSize size = pDC->GetTextExtent("H", 1); //get height of header
	pDC->SetViewportOrg(0, 2 * size.cy);

//print dates
	CRect rectCols(col_pitch, 0, 2 * col_pitch, row_pitch);
	for (int col = startcol; col < startcol + nColsPerPage && col < cols; col++)
	{
		CString str = pDoc->GetCellInfo(0, col);
		int nYear = str.Find(" 20");
		if (bNoPrintYear && nYear != -1)
			str = str.Left(nYear) + str.Mid(nYear + 5);
		pDC->DrawText(str, rectCols, DT_CENTER | DT_WORDBREAK | DT_NOPREFIX);
		CPoint points[5] =
		{
			CPoint(rectCols.left, rectCols.top),
			CPoint(rectCols.right, rectCols.top),
			CPoint(rectCols.right, rectCols.bottom),
			CPoint(rectCols.left, rectCols.bottom),
			CPoint(rectCols.left, rectCols.top)
		};
		pDC->Polyline(points, 5);
		rectCols.OffsetRect(col_pitch, 0);
	}

//print churches
	CRect rectRows(0, row_pitch, col_pitch, 2 * row_pitch);
	for (int row = startrow; row < startrow + nRowsPerPage && row < rows - 1; row++)
	{
		CString str = pDoc->GetCellInfo(row, 0);
		pDC->DrawText(str, rectRows, DT_CENTER | DT_WORDBREAK | DT_NOPREFIX);
		CPoint points[5] =
		{
			CPoint(rectRows.left, rectRows.top),
			CPoint(rectRows.right, rectRows.top),
			CPoint(rectRows.right, rectRows.bottom),
			CPoint(rectRows.left, rectRows.bottom),
			CPoint(rectRows.left, rectRows.top)
		};
		pDC->Polyline(points, 5);
		rectRows.OffsetRect(0, row_pitch);
	}

//print plan
	CRect rectPlan(col_pitch, row_pitch, 2 * col_pitch, 2 * row_pitch);
	for (row = startrow; row < startrow + nRowsPerPage && row < rows - 1; row++)
	{
		for (int col = startcol; col < startcol + nColsPerPage && col < cols; col++)
		{
			CString str = pDoc->GetCellInfo(row, col);
			pDC->DrawText(str, rectPlan, DT_CENTER | DT_WORDBREAK | DT_NOPREFIX);
			CPoint points[5] =
			{
				CPoint(rectPlan.left, rectPlan.top),
				CPoint(rectPlan.right, rectPlan.top),
				CPoint(rectPlan.right, rectPlan.bottom),
				CPoint(rectPlan.left, rectPlan.bottom),
				CPoint(rectPlan.left, rectPlan.top)
			};
			pDC->Polyline(points, 5);
			rectPlan.OffsetRect(col_pitch, 0);
		}
		rectPlan.OffsetRect(-rectPlan.left + col_pitch, row_pitch);
	}

//line round top left cell
	CPoint points[5] =
	{
		CPoint(0, 0),
		CPoint(col_pitch, 0),
		CPoint(col_pitch, row_pitch),
		CPoint(0, row_pitch),
		CPoint(0, 0)
	};
	pDC->Polyline(points, 5);

	pDC->SelectObject(pOldFont);
	pDC->SetTextColor(0x00000000);
}

void CPlanMakerView::DoPrintAnalysis(CDC *pDC, CPrintInfo *pInfo)
{
	pDC->SetBkMode(TRANSPARENT);
	CFont* pOldFont = pDC->SelectObject(&anFont);

//print file date & time
	CString str = "File: ";
	CFileStatus status;
	if (filename == "")
	{
		str += strPathDat + " - ";
		if (CFile::GetStatus(strPathDat, status))
			str += status.m_mtime.Format("%A, %d %B, %Y; %H:%M");
	}
	else
	{
		str += filename + " - ";
		if (CFile::GetStatus(filename, status))
			str += status.m_mtime.Format("%A, %d %B, %Y; %H:%M");
	}
	str += " Page ";
	str += IntToStr(pInfo->m_nCurPage);
	pDC->TextOut(0, 0, str);

	int startcol = ((pInfo->m_nCurPage - 1) % nHorzPages) * nColsPerPage + 1; //cols start at 1
	int startrow = ((pInfo->m_nCurPage - 1) / nHorzPages) * nRowsPerPage; //prchs start at 0

//colours
//column headers
	pDC->SetViewportOrg(3 * col_pitch, row_pitch);
	CRect rect(0, 0, col_pitch, row_pitch);
	for (int col = startcol; col < startcol + nColsPerPage && col < cols; col++)
	{
		pDC->FillSolidRect(rect, 0x00e0e0e0);
		pDC->DrawText(pDoc->IntToStr(nDay[col])	+ "/" + pDoc->IntToStr(nMonth[col]), rect,
			DT_SINGLELINE | DT_CENTER | DT_VCENTER);
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

//preachers
	pDC->SetViewportOrg(0, 2 * row_pitch);
	rect.SetRect(0, 0, 3 * col_pitch, nGroupsUsed * row_pitch);
	for (int prch = startrow; prch < startrow + nRowsPerPage && prch < nPrchsUsed; prch++)
	{
		pDC->FillSolidRect(rect, 0x00e0e0e0);
		rect.DeflateRect(col_pitch / 8, 0, 0, 0);
		PINFO* pPInfo = pPrchList[prch];
		CString str = pPInfo->screen_name;
		str += (pPInfo->reserved) ? " (R) " : " ";
		str += pDoc->IntToStr(nOnPlan[prch]);
		if (pPInfo->nLimit != -1)
		{
			str += "/";
			str += pDoc->IntToStr(pPInfo->nLimit);
		}
		pDC->DrawText(str, rect, DT_NOPREFIX);
		rect.InflateRect(col_pitch / 8, 0, 0, 0);
		CPoint points[5] =
		{
			CPoint(rect.left, rect.top),
			CPoint(rect.right, rect.top),
			CPoint(rect.right, rect.bottom),
			CPoint(rect.left, rect.bottom),
			CPoint(rect.left, rect.top)
		};
		pDC->Polyline(points, 5);
		rect.OffsetRect(0, nGroupsUsed * row_pitch);
	}

//main body of table
	pDC->SetViewportOrg(3 * col_pitch, 2 * row_pitch);
	rect.SetRect(0, 0, col_pitch, row_pitch);
	for (prch = startrow; prch < startrow + nRowsPerPage && prch < nPrchsUsed; prch++)
	{
		PINFO* pPInfo = pPrchList[prch];
		for (int grp = 1; grp < 9; grp <<= 1)
		{
			if (bGroupUsed[grp])
			{
				for (int col = startcol; col < startcol + nColsPerPage && col < cols; col++)
				{
					COLORREF crColor;
					switch (grp)
					{
					case 1: crColor = 0x00c0ffff;
						break;
					case 2: crColor = 0x00ffffc0;
						break;
					case 4: crColor = 0x00ffc0c0;
						break;
					case 8: crColor = 0x00c0c0ff;
					}
					pDC->FillSolidRect(rect, crColor);
					if (!(pPInfo->availability[col] & grp))
						pDC->DrawText("N/A", rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
					SINFO* pRow = pSInfoBase + 32;
					for (int row = 1; row < rows - 1; row ++) //rows of plan
					{
						SINFO* pSInfo = pRow + col;
						if (pDoc->PreacherAppears(pPInfo, pSInfo))
						{
							if (pRow->group == grp)
							{
								pDC->SetBkMode(OPAQUE);
								if (pSInfo->reserved)
									pDC->SetBkColor(0x0000ff00);//FillSolidRect(rect, 0x0000ff00);
								else
									pDC->SetBkColor(0x0000ffff);//FillSolidRect(rect, 0x0000ffff);
								pDC->DrawText(pRow->strChurchCode, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
								pDC->SetBkMode(TRANSPARENT);
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
					rect.OffsetRect(col_pitch, 0);
				}
				rect.OffsetRect(-rect.left, row_pitch);
			}
		}
	}

	pDC->SelectObject(pOldFont);
}

void CPlanMakerView::DoPrintLabels(CDC *pDC, CPrintInfo *pInfo)
{
	CFont* pOldFont = pDC->SelectObject(&labFont);

	int startrow = (pInfo->m_nCurPage - 1) * nRowsPerPage;

	CRect rect (nPrintRectLeft, nPrintRectTop, col_pitch + nPrintRectLeft, row_pitch + nPrintRectTop);
	CRect rectLine(nLabelRectLeft, nLabelRectTop, col_pitch + nLabelRectLeft, row_pitch + nLabelRectTop);

//advance rects to allow for nStartRow
	if (pInfo->m_nCurPage == 1)
	{
		for (int i = 0; i < nStartRow; i++)
		{
			rect.OffsetRect(0, row_pitch);
			rectLine.OffsetRect(0, row_pitch);
		}
	}
	else
		startrow -= nStartRow;

//do the labels
	PINFO* pPInfo = pLabelsListBase + startrow * nAcross;
	for (int row = startrow; row < startrow + nRowsPerPage && row * nAcross < nToPrint; row++)
	{
		if (pInfo->m_nCurPage == 1 && row == startrow + nRowsPerPage - nStartRow)
			break;
		for (int col = 0; col < nAcross; col++)
		{
			CString str = "";
			if (pPInfo->title != "")
				str += pPInfo->title + " ";
			if (pPInfo->first_name != "")
				str += pPInfo->first_name + " ";
			if (pPInfo->last_name != "")
				str += pPInfo->last_name + "\n";
			if (pPInfo->address1 != "")
				str += pPInfo->address1 + "\n";
			if (pPInfo->address2 != "")
				str += pPInfo->address2 + "\n";
			if (pPInfo->town != "")
				str += pPInfo->town + "\n";
			if (pPInfo->county != "")
				str += pPInfo->county + "\n";
			if (pPInfo->postcode != "")
				str += pPInfo->postcode;
			pDC->DrawText(str, rect, DT_NOPREFIX);
			if (pInfo->m_bPreview)
			{
				CPoint points[5] =
				{
					CPoint(rectLine.left, rectLine.top),
					CPoint(rectLine.right, rectLine.top),
					CPoint(rectLine.right, rectLine.bottom),
					CPoint(rectLine.left, rectLine.bottom),
					CPoint(rectLine.left, rectLine.top)
				};
				pDC->Polyline(points, 5);
			}
			rect.OffsetRect(col_pitch, 0);
			rectLine.OffsetRect(col_pitch, 0);
			pPInfo++;
			if (pPInfo == pPInfoBase + nToPrint)
				break;
		}
		rect.OffsetRect(-rect.left + nPrintRectLeft, row_pitch);
		rectLine.OffsetRect(-rectLine.left + nLabelRectLeft, row_pitch);
	}

	pDC->SelectObject(pOldFont);
}

CRect CPlanMakerView::GetRectFromMouse(CPoint point)
{
//get row, col & rect from click
	CSize size(col_pitch, 50);
	CPoint pt = point + CScrollView::GetScrollPosition();
	nColDown = pt.x / col_pitch + 1;
	nRowDown = pt.y / 50 + 1;
	CPoint ptTopleft(point.x - pt.x % col_pitch, point.y - pt.y % 50);
	return CRect(ptTopleft, size);
}

CRect CPlanMakerView::GetRectFromCell(int row, int col)
{
//get rect from row & col
	CSize size(col_pitch, 50);
	CPoint ptScroll = CScrollView::GetScrollPosition();
	CPoint ptTopleft((col - 1) * col_pitch - ptScroll.x, (row - 1) * 50 - ptScroll.y);
	return CRect(ptTopleft, size);
}

void CPlanMakerView::OnViewFitwidth() 
{
	CMainFrame* pMain = (CMainFrame*)AfxGetMainWnd();
	bFitWidth ^= 1;	
	CRect rect;
	pMain->GetWindowRect(&rect);
	if (bFitWidth)
	{
		pMain->SetColumn(0, rect.Width() / cols, 0);
		pMain->SetRow(0, 50, 0);
	}
	else
	{
		pMain->SetColumn(0, 150, 0);
		pMain->SetRow(0, 75, 0);
	}
	InvalidateRect(NULL, true);
}

void CPlanMakerView::OnViewAvaliablepreachers() 
{
	bShowAvailPrchs ^= 1;
	if (bShowAvailPrchs)
		pDoc->UpdatePlan(true);
	else
		pDoc->UpdatePlan(false);
	InvalidateRect(NULL, false);
}

void CPlanMakerView::OnViewPreacherrecords() 
{
//get path to executable
//pmr.exe is in same folder as PlanMaker.exe
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	CString strPath = CString(buffer);
	strPath.Replace("PlanMaker.exe", "pmr.exe");
	ShellExecute(NULL, "open", strPath, NULL, NULL, SW_SHOWNORMAL);
}
