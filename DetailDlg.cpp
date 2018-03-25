// DetailDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "DetailDlg.h"
#include "PlanMakerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDetailDlg dialog


CDetailDlg::CDetailDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDetailDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDetailDlg)
	m_detail = _T("");
	m_code = _T("");
	//}}AFX_DATA_INIT
}


void CDetailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDetailDlg)
	DDX_Text(pDX, IDC_EDIT1, m_detail);
	DDX_Text(pDX, IDC_EDIT2, m_code);
	DDV_MaxChars(pDX, m_code, 4);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDetailDlg, CDialog)
	//{{AFX_MSG_MAP(CDetailDlg)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDetailDlg message handlers

extern SINFO* pSInfo1Base;
extern int nSelCol;
extern int nSelRow;

BOOL CDetailDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SINFO* pSInfo = pSInfo1Base + 32 * nSelRow + nSelCol;
	if (pSInfo->detail != "")
		m_detail = pSInfo->detail;
	if (pSInfo->code != "")
	{
		m_code = pSInfo->code;
		GetDlgItem(IDC_EDIT2)->EnableWindow(true);
	}
	UpdateData(false);

	GetDlgItem(IDC_EDIT1)->SetFocus();
	
	return FALSE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDetailDlg::OnChangeEdit1() 
{
	UpdateData(true);
	GetDlgItem(IDC_EDIT2)->EnableWindow(m_detail != "");
}
