// AnalysisWnd.cpp : implementation file
//

#include "stdafx.h"
#include "planmaker.h"
#include "AnalysisWnd.h"
#include "AnalysisView3.h"
#include "AnalysisCornerView.h"
#include "AnalysisColumnView.h"
#include "AnalysisRowView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnalysisWnd

IMPLEMENT_DYNCREATE(CAnalysisWnd, CFrameWnd)

CAnalysisWnd::CAnalysisWnd()
{
}

CAnalysisWnd::~CAnalysisWnd()
{
	CMainFrame* pMain = (CMainFrame*)AfxGetMainWnd();
	CMenu* pMenu = pMain->GetMenu();
	pMenu->CheckMenuItem(ID_VIEW_ANALYSIS, MF_UNCHECKED | MF_BYCOMMAND);
}


BEGIN_MESSAGE_MAP(CAnalysisWnd, CFrameWnd)
	//{{AFX_MSG_MAP(CAnalysisWnd)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnalysisWnd message handlers

BOOL CAnalysisWnd::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	AfxGetApp()->WinHelp(0x20000 + IDD_ANALYSISWND);
	return 0;
}

BOOL CAnalysisWnd::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	wndSplitter.CreateStatic(this, 2, 2);

//add the splitter panes
	wndSplitter.CreateView(0, 0,
		RUNTIME_CLASS(CAnalysisCornerView), CSize(0, 0), pContext);

	wndSplitter.CreateView(0, 1,
		RUNTIME_CLASS(CAnalysisRowView), CSize(0, 0), pContext);

	wndSplitter.CreateView(1, 0,
		RUNTIME_CLASS(CAnalysisColumnView), CSize(0, 0), pContext);

	wndSplitter.CreateView(1, 1,
		RUNTIME_CLASS(CAnalysisView), CSize(0, 0), pContext);

	wndSplitter.SetColumnInfo(0, 100, 50); //left column - ideal (default) width; min width
	wndSplitter.SetRowInfo(0, 16, 8); //top row - ideal (default) height; min height

	wndSplitter.SetScrollStyle(WS_HSCROLL | WS_VSCROLL);

	SetActiveView((CView*)wndSplitter.GetPane(1, 1));

	return TRUE;
}
