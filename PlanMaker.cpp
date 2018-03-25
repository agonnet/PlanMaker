// PlanMaker.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "WinSpool.h"
#include "MainFrm.h"
#include "PlanMakerView.h"
#include "Splash1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern PINFO* pPInfoBase;
extern SINFO* pSInfoBase;
extern PINFO* pPInfo1Base;
extern SINFO* pSInfo1Base;
extern PINFO* pPTmpInfoBase;
extern SINFO* pSTmpInfoBase;
extern int nPreachers;
extern int rows;
extern int cols;
extern BOOL bAllocationDone;
extern BOOL bNoConsecSame;
extern BOOL bFillUnused;
extern CString filename;
extern CString strDisplay[100][32];
extern BOOL bPrintNoService;
extern BOOL bUseSforComm;
extern BOOL bUseAllAge;
extern BOOL bPlanResized;

/////////////////////////////////////////////////////////////////////////////
// CPlanMakerApp

BEGIN_MESSAGE_MAP(CPlanMakerApp, CWinApp)
	//{{AFX_MSG_MAP(CPlanMakerApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINTSETUP_PRINTER, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlanMakerApp construction

CPlanMakerApp::CPlanMakerApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPlanMakerApp object

CPlanMakerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CPlanMakerApp initialization

BOOL CPlanMakerApp::InitInstance()
{
// CG: The following block was added by the Splash Screen component.
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	CSplashWnd::EnableSplashScreen(cmdInfo.m_bShowSplash);

	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CPlanMakerDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CPlanMakerView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	else
	{
		filename = cmdInfo.m_strFileName;
		pDoc = CPlanMakerDoc::GetDoc();
	}

	EnableShellOpen();
	RegisterShellFileTypes(false);

//set to HTML help
	free((void*)m_pszHelpFilePath);
//get path to executable
	char buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, MAX_PATH);
	CString strPath = CString(buffer);
	strPath.Replace(".exe", ".chm");
	m_pszHelpFilePath = _tcsdup(strPath);

// The one and only window has been initialized, so show and update it.

	m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CPlanMakerApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CPlanMakerApp message handlers

BOOL CPlanMakerApp::PreTranslateMessage(MSG* pMsg)
{
	// CG: The following lines were added by the Splash Screen component.
	if (CSplashWnd::PreTranslateAppMessage(pMsg))
		return TRUE;

	return CWinApp::PreTranslateMessage(pMsg);
}

void CPlanMakerApp::SetLandscape()
{
	PRINTDLG pd;
	pd.lStructSize = (DWORD)sizeof(PRINTDLG);
	BOOL bRet = GetPrinterDeviceDefaults(&pd);
	if (bRet)
	{
// protect memory handle with ::GlobalLock and ::GlobalUnlock
		DEVMODE FAR *pDevMode = (DEVMODE FAR *)::GlobalLock(m_hDevMode);
// set orientation to landscape & paper size to A4
		pDevMode->dmOrientation = DMORIENT_LANDSCAPE;
		pDevMode->dmPaperSize = DMPAPER_A4;
		::GlobalUnlock(m_hDevMode);
	}
}

void CPlanMakerApp::SetPortrait()
{
	PRINTDLG pd;
	pd.lStructSize = (DWORD)sizeof(PRINTDLG);
	BOOL bRet = GetPrinterDeviceDefaults(&pd);
	if (bRet)
	{
// protect memory handle with ::GlobalLock and ::GlobalUnlock
		DEVMODE FAR *pDevMode = (DEVMODE FAR *)::GlobalLock(m_hDevMode);
// set orientation to landscape & paper size to A4
		pDevMode->dmOrientation = DMORIENT_PORTRAIT;
		pDevMode->dmPaperSize = DMPAPER_A4;
		::GlobalUnlock(m_hDevMode);
	}
}

extern BOOL bFitWidth;
extern BOOL bShowAvailPrchs;

BOOL CPlanMakerApp::OnIdle(LONG lCount) 
{
	CWinApp::OnIdle(lCount);

	if (filename != "")
		AfxGetMainWnd()->SetWindowText("PlanMaker - " + filename);
	else
		AfxGetMainWnd()->SetWindowText("PlanMaker");

    pDoc = CPlanMakerDoc::GetDoc();
	if (pDoc->IsModified())
	{
		pDoc->DoTempInfo(pPInfo1Base, pPTmpInfoBase, pSInfo1Base, pSTmpInfoBase);
		if (pDoc->AllocateOrd(false))
			pDoc->DoTempInfo(pPInfo1Base, pPInfoBase, pSInfo1Base, pSInfoBase); //last changes ok - info1 to info
		else
			Resync(); //resync prefs with displayed plan
		pDoc->Store();
		if (bShowAvailPrchs)
			pDoc->UpdatePlan(true);
		else
			pDoc->UpdatePlan(false);
		if (bPlanResized)
		{
			bPlanResized = false;
			pDoc->UpdateAllViews(NULL, 1L, NULL);
		}
		else
			pDoc->UpdateAllViews(NULL, 0L, NULL);
		pDoc->SetModifiedFlag(false);
	}

	return CWinApp::OnIdle(lCount);
}

void CPlanMakerApp::Resync()
{
	MessageBox(NULL, "The operation you attempted was not successful, and PlanMaker needs to rebuild its data structures. Click OK and then try the operation again; it should then succeed, but your Plan will not otherwise be affected.", "PlanMaker", MB_OK | MB_ICONEXCLAMATION);
	PINFO* pPInfo = pPInfoBase;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		SINFO* pRow = pSInfoBase + 32;
		for (int row = 1; row < rows - 1; row++)
		{
			if (pPInfo->ordained && !pPInfo->visitor)
			{
				pPInfo->preferences[row] = 0;
				SINFO* pSInfo = pRow + 1;
				for (int col = 1; col < cols; col++)
				{
					if (pDoc->PreacherAppears(pPInfo, pSInfo))
						pPInfo->preferences[row]++;
					pSInfo++;
				}
			}
			pRow += 32;
		}
		pPInfo++;
	}
	pDoc->DoTempInfo(pPInfoBase, pPInfo1Base, pSInfoBase, pSInfo1Base);
}
