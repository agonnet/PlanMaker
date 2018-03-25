// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "MainFrm.h"
#include "Splash1.h"
#include "PlanMakerView.h"
#include "ColumnView.h"
#include "RowView.h"
#include "CornerView.h"
#include "htmlhelp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(IDS_STATUS, OnUpdateStatus)
	ON_UPDATE_COMMAND_UI(IDS_SERVICES, OnUpdateServices)
	ON_UPDATE_COMMAND_UI(IDS_ALLOCATED, OnUpdateAllocated)
	ON_UPDATE_COMMAND_UI(IDS_UNALLOCATED, OnUpdateUnallocated)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ANALYSIS, OnUpdateViewAnalysis)
	ON_UPDATE_COMMAND_UI(ID_PREACHERS_CLEARALL, OnUpdatePreachersClearall)
	ON_UPDATE_COMMAND_UI(ID_PREACHERS_RESETOPTIONS, OnUpdatePreachersResetoptions)
	ON_UPDATE_COMMAND_UI(ID_PREACHERS_RESETWEIGHTINGS, OnUpdatePreachersResetweightings)
	ON_UPDATE_COMMAND_UI(ID_PREACHERAVAIL, OnUpdatePreacheravail)
	ON_UPDATE_COMMAND_UI(ID_PREACHERDEL, OnUpdatePreacherdel)
	ON_UPDATE_COMMAND_UI(ID_PREACHEREDIT, OnUpdatePreacheredit)
	ON_UPDATE_COMMAND_UI(ID_ALLOCATE, OnUpdateAllocate)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY_ANALYSIS, OnUpdateEditCopyAnalysis)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY_KEY, OnUpdateEditCopyKey)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY_PLAN, OnUpdateEditCopyPlan)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY_PREACHERS, OnUpdateEditCopyPreachers)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY_VISITORS, OnUpdateEditCopyVisitors)
	ON_UPDATE_COMMAND_UI(ID_EDIT_UNDO, OnUpdateEditUndo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_REDO, OnUpdateEditRedo)
	ON_UPDATE_COMMAND_UI(ID_FILE_CLOSE, OnUpdateFileClose)
	ON_UPDATE_COMMAND_UI(ID_FILE_MAKEDEFAULT, OnUpdateFileMakedefault)
	ON_UPDATE_COMMAND_UI(ID_PREACHERNEW, OnUpdatePreachernew)
	ON_UPDATE_COMMAND_UI(ID_DELPREACHER, OnUpdateDelpreacher)
	ON_UPDATE_COMMAND_UI(ID_PREACHERS_AVAILABLITYFILE_EXPORT, OnUpdatePreachersAvailablityfileExport)
	ON_UPDATE_COMMAND_UI(ID_PREACHERS_AVAILABLITYFILE_IMPORT, OnUpdatePreachersAvailablityfileImport)
	ON_UPDATE_COMMAND_UI(ID_PREACHERS_DEALLOCATE, OnUpdatePreachersDeallocate)
	ON_UPDATE_COMMAND_UI(ID_PREACHERPREFS, OnUpdatePreacherprefs)
	ON_UPDATE_COMMAND_UI(ID_INSPREACHER, OnUpdateInspreacher)
	ON_UPDATE_COMMAND_UI(ID_DELDETAIL, OnUpdateDeldetail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	ON_UPDATE_COMMAND_UI(ID_BAPTISM, OnUpdateBaptism)
	ON_UPDATE_COMMAND_UI(ID_FAMILY, OnUpdateFamily)
	ON_UPDATE_COMMAND_UI(ID_PARADE, OnUpdateParade)
	ON_UPDATE_COMMAND_UI(ID_RESERVED, OnUpdateReserved)
	ON_UPDATE_COMMAND_UI(ID_UNITED, OnUpdateUnited)
	ON_UPDATE_COMMAND_UI(ID_COMMUNION, OnUpdateCommunion)
	ON_UPDATE_COMMAND_UI(ID_VIEW_AVAILABLEPREACHERS, OnUpdateViewAvailablepreachers)
	ON_UPDATE_COMMAND_UI(ID_VIEW_FITWIDTH, OnUpdateViewFitwidth)
	ON_UPDATE_COMMAND_UI(ID_VIEW_PREACHERRECORDS, OnUpdateViewPreacherrecords)
	//}}AFX_MSG_MAP
//help commands
	ON_COMMAND(ID_HELP, CFrameWnd::OnHelp)
	ON_COMMAND(ID_HELP_INDEX, CFrameWnd::OnHelp)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	IDS_STATUS,
	IDS_SERVICES,
	IDS_ALLOCATED,
	IDS_UNALLOCATED,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

extern BOOL bViewingAnalysis;
extern BOOL bAllocationDone;
extern PINFO* pPInfoBase;
extern SINFO* pSInfoBase;
extern BOOL bSelected[100][32];
extern int nSelRow;
extern int nSelCol;
extern BOOL bEnableUndo;
extern BOOL bEnableRedo;
extern int nPreachers;
extern CString filename;
extern int cols;
extern BOOL bFitWidth;
extern BOOL bShowAvailPrchs;
extern int nSelected;
extern int nNoService;

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// CG: The following line was added by the Splash Screen component.
	CSplashWnd::ShowSplashScreen(this);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

CDocument* CMainFrame::GetActiveDocument() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CFrameWnd::GetActiveDocument();
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class

	wndSplitter.CreateStatic(this, 2, 2);

//add the splitter panes
	wndSplitter.CreateView(0, 0,
		RUNTIME_CLASS(CCornerView), CSize(0, 0), pContext);

	wndSplitter.CreateView(0, 1,
		RUNTIME_CLASS(CRowView), CSize(0, 0), pContext);

	wndSplitter.CreateView(1, 0,
		RUNTIME_CLASS(CColumnView), CSize(0, 0), pContext);

	wndSplitter.CreateView(1, 1,
		RUNTIME_CLASS(CPlanMakerView), CSize(0, 0), pContext);

	wndSplitter.SetScrollStyle(WS_HSCROLL | WS_VSCROLL);
//	wndSplitter.SetRowInfo(0, 75, 0);
//	wndSplitter.SetColumnInfo(0, 150, 0);

	SetActiveView((CView*)wndSplitter.GetPane(1, 1));
	pDoc = (CPlanMakerDoc*)GetActiveDocument();

	return TRUE;

//	return CFrameWnd::OnCreateClient(lpcs, pContext);
}

CView* CMainFrame::ResetView()
{
	CView* pView = (CView*)wndSplitter.GetPane(1, 1);
	SetActiveView(pView, false);
	return pView;
}

////////////////status bar

extern int nTotalServices;
extern int nServicesAllocated;
extern int nUnallocReserved;
extern BOOL bAllocPending;

void CMainFrame::OnUpdateStatus(CCmdUI *pCmdUI)
{
	if (!bAllocationDone)
		pCmdUI->SetText("\tPlan is not allocated");
	else if (bAllocPending)
		pCmdUI->SetText("\tAllocation Status: Pending");
	else
		pCmdUI->SetText("\tAllocation Status: OK");
}

void CMainFrame::OnUpdateServices(CCmdUI *pCmdUI)
{
	pCmdUI->Enable();
	CString str = "\tServices: " + pDoc->IntToStr(nTotalServices);
	pCmdUI->SetText(str);
}

void CMainFrame::OnUpdateAllocated(CCmdUI *pCmdUI)
{
	pCmdUI->Enable();
	CString str ="\tAllocated: " + pDoc->IntToStr(nServicesAllocated);
	pCmdUI->SetText(str);
}

void CMainFrame::OnUpdateUnallocated(CCmdUI *pCmdUI)
{
	pCmdUI->Enable();
	CString str = "\tUnallocated: " + pDoc->IntToStr(nTotalServices - nServicesAllocated)
		+ " (Reserved: " + pDoc->IntToStr(nUnallocReserved) + ")";
	pCmdUI->SetText(str);
}

////////////////////////////////

extern int rows;
extern int cols;
extern int nPreachers;

void CMainFrame::OnUpdateViewAnalysis(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(rows != 2 && cols != 1 && nPreachers != 0);
	CMenu* pMenu = this->GetMenu();
	if (bViewingAnalysis)
		pMenu->CheckMenuItem(ID_VIEW_ANALYSIS, MF_CHECKED | MF_BYCOMMAND);
	else
		pMenu->CheckMenuItem(ID_VIEW_ANALYSIS, MF_UNCHECKED | MF_BYCOMMAND);
}

void CMainFrame::OnUpdatePreachersDeallocate(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(bAllocationDone);
}

void CMainFrame::OnUpdatePreachersClearall(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(rows != 2 && cols != 1 && nPreachers != 0);
}

void CMainFrame::OnUpdatePreachersResetoptions(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(nPreachers != 0);
}

void CMainFrame::OnUpdatePreachersResetweightings(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(nPreachers != 0);
}

void CMainFrame::OnUpdatePreacheravail(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(rows != 2 && cols != 1 && nPreachers != 0);
}

void CMainFrame::OnUpdatePreacherdel(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(nPreachers != 0);
}

void CMainFrame::OnUpdatePreacheredit(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(nPreachers != 0);
}

void CMainFrame::OnUpdateAllocate(CCmdUI* pCmdUI) 
{
//enable if plan has been created and if some preacher has hda availability entered
	PINFO* pPInfo = pPInfoBase;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		for (int col = 1; col < cols; col++)
		{
			if (pPInfo->availability[col] != 0)
			{
				pCmdUI->Enable(rows != 2 && cols != 1 && nPreachers != 0);
				return;
			}
		}
		pPInfo++;
	}
	pCmdUI->Enable(false);
}

void CMainFrame::OnUpdateEditCopyAnalysis(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(rows != 2 && cols != 1 && nPreachers != 0);
}

void CMainFrame::OnUpdateEditCopyKey(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(rows != 2 && cols != 1 && nPreachers != 0);
}

void CMainFrame::OnUpdateEditCopyPlan(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(rows != 2 && cols != 1 && nPreachers != 0);
}

void CMainFrame::OnUpdateEditCopyPreachers(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(nPreachers != 0);		
}

void CMainFrame::OnUpdateEditCopyVisitors(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(nPreachers != 0);	
}

void CMainFrame::OnUpdateInspreacher(CCmdUI* pCmdUI) 
{
	SINFO* pSInfo = pSInfoBase + 32 * nSelRow + nSelCol;
	pCmdUI->Enable(nSelected == 1 && !pSInfo->no_service);
}

void CMainFrame::OnUpdateEditUndo(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(bEnableUndo);
}

void CMainFrame::OnUpdateEditRedo(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(bEnableRedo);
}

void CMainFrame::OnUpdateFileClose(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(filename != "");	
}

void CMainFrame::OnUpdatePreachernew(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(nPreachers < 200);		
}

void CMainFrame::OnUpdateFileMakedefault(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(filename != "");	
}

void CMainFrame::OnUpdateDelpreacher(CCmdUI* pCmdUI) 
{
	SINFO* pSInfo = pSInfoBase + 32 * nSelRow + nSelCol;
	pCmdUI->Enable(nSelected == 1 && pSInfo->preacher != "");
}

void CMainFrame::OnUpdatePreachersAvailablityfileExport(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(rows != 2 && cols != 1 && nPreachers != 0);	
}

void CMainFrame::OnUpdatePreachersAvailablityfileImport(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(rows != 2 && cols != 1 && nPreachers != 0);
}

void CMainFrame::OnUpdatePreacherprefs(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(rows != 2 && cols != 1 && nPreachers != 0);
}

void CMainFrame::OnUpdateDeldetail(CCmdUI* pCmdUI) 
{
	SINFO* pSInfo = pSInfoBase + 32 * nSelRow + nSelCol;
	pCmdUI->Enable(pSInfo->detail != "");	
}

void CMainFrame::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(filename != "");	
}

void CMainFrame::SetColumn(int col, int ideal, int min)
{
	wndSplitter.SetColumnInfo(col, ideal, min);
	wndSplitter.RecalcLayout();
}

void CMainFrame::SetRow(int row, int ideal, int min)
{
	wndSplitter.SetRowInfo(row, ideal, min);
	wndSplitter.RecalcLayout();
}

void CMainFrame::OnUpdateBaptism(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(nNoService != nSelected);	
}

void CMainFrame::OnUpdateFamily(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(nNoService != nSelected);
}

void CMainFrame::OnUpdateParade(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(nNoService != nSelected);
}

void CMainFrame::OnUpdateReserved(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(nNoService != nSelected);
}

void CMainFrame::OnUpdateUnited(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(nNoService != nSelected);
}

void CMainFrame::OnUpdateCommunion(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(nNoService != nSelected);
}

void CMainFrame::WinHelp(DWORD dwData, UINT nCmd) 
{
 	CString helpFilePath = AfxGetApp()->m_pszHelpFilePath;
 	HtmlHelp(m_hWnd, helpFilePath, HH_HELP_CONTEXT, dwData);
}

void CMainFrame::OnUpdateViewAvailablepreachers(CCmdUI* pCmdUI) 
{
	CMenu* pMenu = this->GetMenu();
	if (bShowAvailPrchs)
		pMenu->CheckMenuItem(ID_VIEW_AVAILABLEPREACHERS, MF_CHECKED | MF_BYCOMMAND);
	else
		pMenu->CheckMenuItem(ID_VIEW_AVAILABLEPREACHERS, MF_UNCHECKED | MF_BYCOMMAND);
}

void CMainFrame::OnUpdateViewFitwidth(CCmdUI* pCmdUI) 
{
	CMenu* pMenu = this->GetMenu();
	if (bFitWidth)
		pMenu->CheckMenuItem(ID_VIEW_FITWIDTH, MF_CHECKED | MF_BYCOMMAND);
	else
		pMenu->CheckMenuItem(ID_VIEW_FITWIDTH, MF_UNCHECKED | MF_BYCOMMAND);
}

void CMainFrame::OnUpdateViewPreacherrecords(CCmdUI* pCmdUI) 
{
//get path to executable
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	CString strPath = CString(buffer);
	strPath.Replace("PlanMaker.exe", "pmr.exe");
	if (GetFileAttributes(strPath) == -1) //if pmr.exe not installed
	{
		pCmdUI->Enable(false);
		return;
	}

	CMenu* pMenu = this->GetMenu();
	ITEMIDLIST idl;
	LPITEMIDLIST pidl = &idl;
	SHGetSpecialFolderLocation(NULL, CSIDL_PERSONAL, &pidl);
	SHGetPathFromIDList(pidl, buffer);
	strPath = CString(buffer) + "\\Planmaker";
	CFile file;
	if (file.Open(strPath + "\\pmr.ini", CFile::modeRead)) //if pmr.ini opens, check for "run=1"
	{
		char buf[1024];
		file.Read(&buf, file.GetLength());
		file.Close();
		CString str = CString(buf);
		if (str.Find("run=1") != -1) //if pmr.ini contains "run=1", pmr.exe isn't running
		{
			pMenu->CheckMenuItem(ID_VIEW_PREACHERRECORDS, MF_UNCHECKED | MF_BYCOMMAND);
			pCmdUI->Enable(true); //pmr not running - menu item unchecked & enabled
		}
		else //else pmr.exe is running - disable menu item
		{
			pMenu->CheckMenuItem(ID_VIEW_PREACHERRECORDS, MF_CHECKED | MF_BYCOMMAND);
			pCmdUI->Enable(false); //pmr running - menu item checked & disabled
		}
	}
}
