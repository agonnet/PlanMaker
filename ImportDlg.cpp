// ImportDlg.cpp : implementation file
//

#include "stdafx.h"
#include "planmaker.h"
#include "ImportDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImportDlg dialog

extern PINFO* pPInfo1Base;
extern int nPreachers;

CImportDlg::CImportDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImportDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImportDlg)
	m_nSelprch = -1;
	m_check = FALSE;
	//}}AFX_DATA_INIT
}


void CImportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImportDlg)
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
	DDX_LBIndex(pDX, IDC_LIST1, m_nSelprch);
	DDX_Check(pDX, IDC_CHECK1, m_check);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CImportDlg, CDialog)
	//{{AFX_MSG_MAP(CImportDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImportDlg message handlers

BOOL CImportDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	PINFO* pPInfo = pPInfo1Base;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		m_listctrl.AddString(pPInfo->first_name + " " + pPInfo->last_name);
		pPInfo++;
	}
	m_listctrl.SetCurSel(0);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
