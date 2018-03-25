// PreacherDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "PreacherDlg.h"
#include "PlanMakerDoc.h"
#include "SortPreachers.h"
#include "Mmsystem.h"
#include "afxpriv.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPreacherDlg dialog


CPreacherDlg::CPreacherDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPreacherDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPreacherDlg)
	m_title = _T("");
	m_first_name = _T("");
	m_last_name = _T("");
	m_address1 = _T("");
	m_address2 = _T("");
	m_town = _T("");
	m_county = _T("");
	m_postcode = _T("");
	m_phone = _T("");
	m_email = _T("");
	m_screen_name = _T("");
	m_ordained = FALSE;
	m_stipend = FALSE;
	m_visitor = FALSE;
	m_reserved = FALSE;
	m_ontrial = FALSE;
	m_onnote = FALSE;
	m_additional = _T("");
	m_sacrament = FALSE;
	m_family = FALSE;
	m_parade = FALSE;
	//}}AFX_DATA_INIT
}


void CPreacherDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPreacherDlg)
	DDX_Control(pDX, IDC_CHECK5, m_reservedctrl);
	DDX_Control(pDX, IDC_CHECK4, m_visitorctrl);
	DDX_Control(pDX, IDC_CHECK1, m_ordainedctrl);
	DDX_Control(pDX, IDC_CHECK2, m_stipendctrl);
	DDX_Control(pDX, IDC_CHECK6, m_onnotectrl);
	DDX_Control(pDX, IDC_CHECK3, m_ontrialctrl);
	DDX_Control(pDX, IDC_CHECK9, m_paradectrl);
	DDX_Control(pDX, IDC_CHECK8, m_familyctrl);
	DDX_Control(pDX, IDC_CHECK7, m_sacramentctrl);
	DDX_Control(pDX, IDC_EDIT11, m_edit11);
	DDX_Control(pDX, IDOK, m_ok);
	DDX_Control(pDX, IDC_BUTTONMORE, m_more);
	DDX_Text(pDX, IDC_EDIT11, m_title);
	DDX_Text(pDX, IDC_EDIT1, m_first_name);
	DDX_Text(pDX, IDC_EDIT2, m_last_name);
	DDX_Text(pDX, IDC_EDIT3, m_address1);
	DDX_Text(pDX, IDC_EDIT4, m_address2);
	DDX_Text(pDX, IDC_EDIT5, m_town);
	DDX_Text(pDX, IDC_EDIT6, m_county);
	DDX_Text(pDX, IDC_EDIT7, m_postcode);
	DDX_Text(pDX, IDC_EDIT8, m_phone);
	DDX_Text(pDX, IDC_EDIT9, m_email);
	DDX_Text(pDX, IDC_EDIT10, m_screen_name);
	DDX_Check(pDX, IDC_CHECK1, m_ordained);
	DDX_Check(pDX, IDC_CHECK2, m_stipend);
	DDX_Check(pDX, IDC_CHECK4, m_visitor);
	DDX_Check(pDX, IDC_CHECK5, m_reserved);
	DDX_Check(pDX, IDC_CHECK3, m_ontrial);
	DDX_Check(pDX, IDC_CHECK6, m_onnote);
	DDX_Text(pDX, IDC_EDIT12, m_additional);
	DDX_Check(pDX, IDC_CHECK7, m_sacrament);
	DDX_Check(pDX, IDC_CHECK8, m_family);
	DDX_Check(pDX, IDC_CHECK9, m_parade);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPreacherDlg, CDialog)
	//{{AFX_MSG_MAP(CPreacherDlg)
	ON_BN_CLICKED(IDC_BUTTONMORE, OnButtonMore)
	ON_BN_CLICKED(IDC_CHECK7, OnCheck7)
	ON_BN_CLICKED(IDC_CHECK8, OnCheck8)
	ON_BN_CLICKED(IDC_CHECK9, OnCheck9)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck4)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_KICKIDLE, OnKickIdle)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPreacherDlg message handlers

extern int nPreachers;
extern int rows;
extern int cols;
extern PINFO* pPInfo1Base;
extern BOOL bEnableUndo;
extern BOOL bEnableRedo;

BOOL CPreacherDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	pDoc = CPlanMakerDoc::GetDoc();
	bUserCheck7 = false;
	bUserCheck8 = false;
	bUserCheck9 = false;
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPreacherDlg::OnButtonMore() 
{
//add preacher previously entered
	UpdateData(true);
	if (ValidateNewPreacher())
		AddNewPreacher();
	else
		return;
	m_title = "";
	m_first_name = "";
	m_last_name = "";
	m_address1 = "";
	m_address2 = "";
	m_town = "";
	m_county = "";
	m_postcode = "";
	m_phone = "";
	m_email = "";
	m_screen_name = "";
	m_additional = "";
	m_ordained = false;
	m_stipend = false;
	m_ontrial = false;
	m_onnote = false;
	m_visitor = false;
	m_reserved = false;
	UpdateData(false);
	m_edit11.SetFocus();
}

BOOL CPreacherDlg::ValidateNewPreacher()
{
//check preacher does not already exist and screen name not in use
	PINFO* pPInfo = pPInfo1Base;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		if (m_first_name == pPInfo->first_name
			&& m_last_name == pPInfo->last_name)
		{
			MessageBox("The preacher you have entered is already in the Database. A second entry will not be created.", "PlanMaker", MB_OK | MB_ICONINFORMATION);
			return false;
		}
		if (m_screen_name == pPInfo->screen_name)
		{
			MessageBox("The screen name you have entered is already in use. Please choose another name.", "PlanMaker", MB_OK | MB_ICONINFORMATION);
			return false;
		}
		pPInfo++;
	}
	return true;
}


void CPreacherDlg::AddNewPreacher()
{
	PINFO* pPInfo = pPInfo1Base + nPreachers;
	pPInfo->title = m_title;
	pPInfo->first_name = m_first_name;
	pPInfo->last_name = m_last_name;
	pPInfo->address1 = m_address1;
	pPInfo->address2 = m_address2;
	pPInfo->town = m_town;
	pPInfo->county = m_county;
	pPInfo->postcode = m_postcode;
	pPInfo->phone = m_phone;
	pPInfo->email = m_email;
	pPInfo->screen_name = m_screen_name;
	pPInfo->add_info = m_additional;
	pPInfo->ordained = m_ordained;
	pPInfo->stipend = m_stipend;
	pPInfo->on_trial = m_ontrial;
	pPInfo->on_note = m_onnote;
	pPInfo->visitor = m_visitor;
	pPInfo->reserved = m_reserved;
	pPInfo->no_consec = false;
	pPInfo->one_service = false;
	pPInfo->nLimit = -1;
	for (int row = 1; row < rows - 1; row++)
	{
		pPInfo->authorised[row] = m_sacrament;
		pPInfo->family[row] = m_family;
		pPInfo->parade[row] = m_parade;
		pPInfo->preferences[row] = (pPInfo->ordained && !pPInfo->visitor) ? 0 : 1;
	}
	for (int col = 1; col < cols; col++)
	{
		pPInfo->availability[col] = 0;
	}
	bUserCheck7 = false;
	bUserCheck8 = false;
	bUserCheck9 = false;
	nPreachers++;
	CSortPreachers srt;
	srt.DoSort();
}

void CPreacherDlg::OnOK() 
{
	UpdateData(true);
	if (ValidateNewPreacher())
		AddNewPreacher();
	else
		return;
	bEnableUndo = true;
	bEnableRedo = false;
	pDoc->SetModifiedFlag();
	CDialog::OnOK();
}

void CPreacherDlg::OnCheck1() 
{
	bUserCheck7 = bUserCheck8 = bUserCheck9 = false;	
}

void CPreacherDlg::OnCheck4() 
{
	bUserCheck7 = bUserCheck8 = bUserCheck9 = false;
}

void CPreacherDlg::OnCheck7() 
{
	bUserCheck7 = true;	
}

void CPreacherDlg::OnCheck8() 
{
	bUserCheck8 = true;
}

void CPreacherDlg::OnCheck9() 
{
	bUserCheck9 = true;
}

LRESULT CPreacherDlg::OnKickIdle(WPARAM, LPARAM)
{
	UpdateData(true);
	BOOL bEnable = (m_first_name != "" && m_last_name != "" && m_screen_name != "") ? true : false;
//buttons
	m_ok.EnableWindow(bEnable);
	m_more.EnableWindow(bEnable);
//enable/disable checkboxes
	m_ordainedctrl.EnableWindow(!m_onnote && !m_ontrial && !m_reserved);
	m_stipendctrl.EnableWindow(m_ordained && !m_visitor && !m_reserved);
	m_ontrialctrl.EnableWindow(!m_ordained && !m_visitor && !m_onnote && !m_reserved);
	m_onnotectrl.EnableWindow(!m_ordained && !m_visitor && !m_ontrial && !m_reserved);
	m_visitorctrl.EnableWindow(!m_stipend && !m_ontrial && !m_onnote && !m_reserved);
	m_sacramentctrl.EnableWindow(!m_reserved);
	m_familyctrl.EnableWindow(!m_reserved);
	m_paradectrl.EnableWindow(!m_reserved);
	m_reservedctrl.EnableWindow(!m_ordained && !m_stipend && !m_visitor && !m_onnote && ! m_ontrial);
//check sacrament, family & parade if local ord
//if user changes setting, don't change it here
	if (!bUserCheck7) m_sacrament = (m_ordained && !m_visitor);// ? true : false;
	if (!bUserCheck8) m_family = (m_ordained && !m_visitor);// ? true : false;
	if (!bUserCheck9) m_parade = (m_ordained && !m_visitor);// ? true : false;
//clear check if disabled
	if (!m_ordainedctrl.IsWindowEnabled()) m_ordained = false;
	if (!m_stipendctrl.IsWindowEnabled()) m_stipend = false;
	if (!m_ontrialctrl.IsWindowEnabled()) m_ontrial = false;
	if (!m_onnotectrl.IsWindowEnabled()) m_onnote = false;
	if (!m_visitorctrl.IsWindowEnabled()) m_visitor = false;
	if (!m_reservedctrl.IsWindowEnabled()) m_reserved = false;
	if (!m_sacramentctrl.IsWindowEnabled()) m_sacrament = false;
	if (!m_familyctrl.IsWindowEnabled()) m_family = false;
	if (!m_paradectrl.IsWindowEnabled()) m_parade = false;
	UpdateData(false);

	return 0L;
}
