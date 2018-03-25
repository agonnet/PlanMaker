// InsertDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "InsertDlg.h"
#include "PrchAvailDlg.h"
#include "PlanMakerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInsertDlg dialog

CInsertDlg::CInsertDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInsertDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInsertDlg)

	//}}AFX_DATA_INIT
}


void CInsertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInsertDlg)
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInsertDlg, CDialog)
	//{{AFX_MSG_MAP(CInsertDlg)
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInsertDlg message handlers

extern int nPreachers;
extern PINFO* pPInfoBase;
extern SINFO* pSInfoBase;
extern PINFO* pPInfo1Base;
extern SINFO* pSInfo1Base;
extern int nSelRow;
extern int nSelCol;
extern int rows;
extern int cols;
extern BOOL bAllocationDone;
extern int nAvailPrchIndex[64];

BOOL CInsertDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	pDoc = CPlanMakerDoc::GetDoc();
	int prchs = pDoc->GetAvailablePrchs(nSelRow, nSelCol, false);
	for (int prch = 0; prch < prchs; prch++)
	{
		PINFO* pPInfo = pPInfo1Base + nAvailPrchIndex[prch];
		CString str = pPInfo->first_name + " " + pPInfo->last_name;
		str += " (" + IntToStr(pDoc->GetPreacherAppearances(pPInfo, -1, false));
		if (pPInfo->nLimit != -1)
			str += "/" + IntToStr(pPInfo->nLimit);
		str += ")";
		if (pPInfo->reserved)
			str += " (R)";
		m_listctrl.AddString(str);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
}

void CInsertDlg::OnSelchangeList1() 
{
	GetDlgItem(IDOK)->EnableWindow(true);
}

CString CInsertDlg::IntToStr(int value)
{
	char ch[6];
	_itoa(value, ch, 10);
	return ch;
}

void CInsertDlg::OnOK() 
{
	nSelPrch = nAvailPrchIndex[m_listctrl.GetCurSel()];
	CDialog::OnOK();
}
