// OptionsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "OptionsDlg.h"
#include "PlanMakerDoc.h"
#include "PrchAvailDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg dialog


COptionsDlg::COptionsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COptionsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COptionsDlg)
	m_use_all_lay = FALSE;
	m_no_print_year = FALSE;
	m_print_accredited = FALSE;
	m_use_s_for_comm = FALSE;
	m_print_no_service = FALSE;
	m_no_consec_plan = FALSE;
	m_fill_unused = FALSE;
	m_use_all_age = FALSE;
	m_only_once = FALSE;
	m_no_double = FALSE;
	m_no_consec_same = FALSE;
	m_print_no_service_excl = FALSE;
	//}}AFX_DATA_INIT
}


void COptionsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptionsDlg)
	DDX_Control(pDX, IDC_CHECK12, m_check12ctrl);
	DDX_Control(pDX, IDC_CHECK6, m_check6ctrl);
	DDX_Control(pDX, IDC_CHECK8, m_no_consec_same_ctrl);
	DDX_Control(pDX, IDC_CHECK11, m_no_double_ctrl);
	DDX_Check(pDX, IDC_CHECK1, m_use_all_lay);
	DDX_Check(pDX, IDC_CHECK3, m_no_print_year);
	DDX_Check(pDX, IDC_CHECK4, m_print_accredited);
	DDX_Check(pDX, IDC_CHECK5, m_use_s_for_comm);
	DDX_Check(pDX, IDC_CHECK6, m_print_no_service);
	DDX_Check(pDX, IDC_CHECK7, m_no_consec_plan);
	DDX_Check(pDX, IDC_CHECK9, m_fill_unused);
	DDX_Check(pDX, IDC_CHECK10, m_use_all_age);
	DDX_Check(pDX, IDC_CHECK2, m_only_once);
	DDX_Check(pDX, IDC_CHECK11, m_no_double);
	DDX_Check(pDX, IDC_CHECK8, m_no_consec_same);
	DDX_Check(pDX, IDC_CHECK12, m_print_no_service_excl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptionsDlg, CDialog)
	//{{AFX_MSG_MAP(COptionsDlg)
	ON_BN_CLICKED(IDC_CHECK12, OnCheck12)
	ON_BN_CLICKED(IDC_CHECK6, OnCheck6)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg message handlers

extern PINFO* pPInfo1Base;
extern PINFO* pPTmpInfoBase;
extern SINFO* pSInfo1Base;
extern SINFO* pSTmpInfoBase;
extern BOOL bUseAllLay;
extern BOOL bNoConsecPlan;
extern BOOL bNoPrintYear;
extern BOOL bPrintAccredited;
extern BOOL bUseSforComm;
extern BOOL bPrintNoService;
extern BOOL bPrintNoServiceExcl;
extern BOOL bFillUnused;
extern BOOL bUseAllAge;
extern BOOL bOnlyOnce;
extern BOOL bNoConsecSame;
extern BOOL bNoDouble;
extern BOOL bAllocPending;

BOOL COptionsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	pDoc = CPlanMakerDoc::GetDoc();
	m_use_all_lay = bUseAllLay;
	m_no_consec_plan = bNoConsecPlan;
	m_no_print_year = bNoPrintYear;
	m_print_accredited = bPrintAccredited;
	m_use_s_for_comm = bUseSforComm;
	m_print_no_service = bPrintNoService;
	m_print_no_service_excl = bPrintNoServiceExcl;
	m_fill_unused = bFillUnused;
	m_use_all_age = bUseAllAge;
	m_only_once = bOnlyOnce;
	m_no_consec_same = bNoConsecSame;
	m_no_double = bNoDouble;
//enable/disable options
	if (!bNoConsecSame)
	{
		bNoConsecSame = true;
		pDoc->DoTempInfo(pPInfo1Base, pPTmpInfoBase, pSInfo1Base, pSTmpInfoBase);
		m_no_consec_same_ctrl.EnableWindow(pDoc->AllocateOrd(false));
		bNoConsecSame = false;
	}
	else
		m_no_consec_same_ctrl.EnableWindow(true);
	if (!bNoDouble)
	{
		bNoDouble = true;
		pDoc->DoTempInfo(pPInfo1Base, pPTmpInfoBase, pSInfo1Base, pSTmpInfoBase);
		m_no_double_ctrl.EnableWindow(pDoc->AllocateOrd(false));
		bNoDouble = false;
	}
	else
		m_no_double_ctrl.EnableWindow(true);

	m_check6ctrl.EnableWindow(true);
	m_check12ctrl.EnableWindow(true);
	
	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void COptionsDlg::OnOK() 
{
	UpdateData(true);
	bUseAllLay = m_use_all_lay;
	if (bNoConsecPlan != m_no_consec_plan)
	{
		bNoConsecPlan = m_no_consec_plan;
		bAllocPending = true;
	}
	bNoPrintYear = m_no_print_year;
	bPrintAccredited = m_print_accredited;
	bUseSforComm = m_use_s_for_comm;
	bPrintNoService = m_print_no_service;
	bPrintNoServiceExcl = m_print_no_service_excl;
	if (bFillUnused != m_fill_unused)
	{
		bFillUnused = m_fill_unused;
		bAllocPending = true;
	}
	bUseAllAge = m_use_all_age;
	if (bOnlyOnce != m_only_once)
	{
		bOnlyOnce = m_only_once;
		bAllocPending = true;
	}
	if (bNoConsecSame != m_no_consec_same)
	{
		bNoConsecSame = m_no_consec_same;
		bAllocPending = true;
	}
	if (bNoDouble != m_no_double)
	{
		bNoDouble = m_no_double;
		bAllocPending = true;
	}
	CDialog::OnOK();
}

//checkboxes to control printing of "No Service"
void COptionsDlg::OnCheck12() //print_no_service_excl checkbox - doesn't print it if there's a note
{
	m_print_no_service = false; //clear the other
	m_print_no_service_excl ^= 1; //toggle this
	m_check6ctrl.EnableWindow(!m_print_no_service_excl); //enable the other if this not checked
	UpdateData(false);
}

void COptionsDlg::OnCheck6() //print_no_service checkbox - always prints it
{
	m_print_no_service_excl = false;
	m_print_no_service ^= 1;
	m_check12ctrl.EnableWindow(!m_print_no_service);
	UpdateData(false);
}
