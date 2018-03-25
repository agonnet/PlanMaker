// EditPreacherDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "EditPreacherDlg.h"
#include "PlanMakerDoc.h"
#include "SortPreachers.h"
#include "afxpriv.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditPreacherDlg dialog


CEditPreacherDlg::CEditPreacherDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditPreacherDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditPreacherDlg)
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
	m_title = _T("");
	m_ordained = FALSE;
	m_stipend = FALSE;
	m_visitor = FALSE;
	m_reserved = FALSE;
	m_onnote = FALSE;
	m_ontrial = FALSE;
	m_additional = _T("");
	m_sacrament = FALSE;
	m_family = FALSE;
	m_parade = FALSE;
	//}}AFX_DATA_INIT
}


void CEditPreacherDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditPreacherDlg)
	DDX_Control(pDX, IDC_CHECK9, m_paradectrl);
	DDX_Control(pDX, IDC_CHECK8, m_familyctrl);
	DDX_Control(pDX, IDC_CHECK7, m_sacramentctrl);
	DDX_Control(pDX, IDC_CHECK6, m_onnotectrl);
	DDX_Control(pDX, IDC_CHECK5, m_reservedctrl);
	DDX_Control(pDX, IDC_CHECK4, m_visitorctrl);
	DDX_Control(pDX, IDC_CHECK3, m_ontrialctrl);
	DDX_Control(pDX, IDC_CHECK1, m_ordainedctrl);
	DDX_Control(pDX, IDC_CHECK2, m_stipendctrl);
	DDX_Control(pDX, IDOK, m_ok);
	DDX_Control(pDX, IDC_BUTTONPREV, m_previous);
	DDX_Control(pDX, IDC_BUTTONNEXT, m_next);
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
	DDX_Text(pDX, IDC_EDIT11, m_title);
	DDX_Check(pDX, IDC_CHECK1, m_ordained);
	DDX_Check(pDX, IDC_CHECK2, m_stipend);
	DDX_Check(pDX, IDC_CHECK4, m_visitor);
	DDX_Check(pDX, IDC_CHECK5, m_reserved);
	DDX_Check(pDX, IDC_CHECK6, m_onnote);
	DDX_Check(pDX, IDC_CHECK3, m_ontrial);
	DDX_Text(pDX, IDC_EDIT12, m_additional);
	DDX_Check(pDX, IDC_CHECK7, m_sacrament);
	DDX_Check(pDX, IDC_CHECK8, m_family);
	DDX_Check(pDX, IDC_CHECK9, m_parade);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditPreacherDlg, CDialog)
	//{{AFX_MSG_MAP(CEditPreacherDlg)
	ON_BN_CLICKED(IDC_BUTTONNEXT, OnNext)
	ON_BN_CLICKED(IDC_BUTTONPREV, OnPrevious)
	ON_BN_CLICKED(IDC_CHECK7, OnCheck7)
	ON_BN_CLICKED(IDC_CHECK8, OnCheck8)
	ON_BN_CLICKED(IDC_CHECK9, OnCheck9)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_KICKIDLE, OnKickIdle)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditPreacherDlg message handlers

extern int nPreachers;
extern int nSelPrch;
extern PINFO* pPInfoBase;
extern SINFO* pSInfoBase;
extern PINFO* pPInfo1Base;
extern SINFO* pSInfo1Base;
extern int rows;
extern int cols;

BOOL CEditPreacherDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	pDoc = CPlanMakerDoc::GetDoc();
	nEditPrch = nSelPrch;
	SetupDlg();
	pDoc = CPlanMakerDoc::GetDoc();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CEditPreacherDlg::ValidateEditedPr()
{
//check preacher name & screen name not already used
	PINFO* pPInfoEdit = pPInfo1Base + nEditPrch;  //prch being edited
	PINFO* pPInfo = pPInfo1Base;  //all preachers
	for (int prch = 0; prch < nPreachers; prch++)
	{
		if (pPInfo != pPInfoEdit)
		{
			if (m_first_name == pPInfo->first_name
				&& m_last_name == pPInfo->last_name)
			{
				MessageBox("The preacher you have entered is already in the Database.", "PlanMaker", MB_OK | MB_ICONINFORMATION);
				return false;
			}
			if (m_screen_name == pPInfo->screen_name)
			{
				MessageBox("The screen name you have chosen is already in use. Please choose different name.", "PlanMaker", MB_OK | MB_ICONINFORMATION);
				return false;
			}
		}
		pPInfo++;
	}

	return true;
}

void CEditPreacherDlg::OnOK() 
{
	GetCurrentData();
	CSortPreachers srt;
	srt.DoSort();
	pDoc->SetModifiedFlag();
	
	CDialog::OnOK();
}

void CEditPreacherDlg::OnPrevious() 
{
	GetCurrentData();
	nEditPrch--;
	SetupDlg();
}

void CEditPreacherDlg::OnNext() 
{
	GetCurrentData();
	nEditPrch++;
	SetupDlg();
}

void CEditPreacherDlg::SetupDlg()
{
	PINFO* pPInfo = pPInfo1Base + nEditPrch;
	m_title = pPInfo->title;
	m_first_name = pPInfo->first_name;
	m_last_name = pPInfo->last_name;
	m_address1 = pPInfo->address1;
	m_address2 = pPInfo->address2;
	m_town = pPInfo->town;
	m_county = pPInfo->county;
	m_postcode = pPInfo->postcode;
	m_phone = pPInfo->phone;
	m_email = pPInfo->email;
	m_screen_name = pPInfo->screen_name;
	m_additional = pPInfo->add_info;
	m_ordained = pPInfo->ordained;
	CheckDlgButton(IDC_CHECK1, m_ordained);
	m_stipend = pPInfo->stipend;
	CheckDlgButton(IDC_CHECK2, m_stipend);
	m_ontrial = pPInfo->on_trial;
	CheckDlgButton(IDC_CHECK3, m_ontrial);
	m_onnote = pPInfo->on_note;
	CheckDlgButton(IDC_CHECK6, m_onnote);
	m_visitor = pPInfo->visitor;
	CheckDlgButton(IDC_CHECK4, m_visitor);
	m_reserved = pPInfo->reserved;
	CheckDlgButton(IDC_CHECK5, m_reserved);
	bool bAuthorised = true;
	bool bFamily = true;
	bool bParade = true;
	for (int row = 1; row < rows - 1; row++)
	{
		if (!pPInfo->authorised[row])
			bAuthorised = false;
		if (!pPInfo->family[row])
			bFamily = false;
		if (!pPInfo->parade[row])
			bParade = false;
	}
	m_sacrament = bAuthorised;
	CheckDlgButton(IDC_CHECK7, m_sacrament);
	m_family = bFamily;
	CheckDlgButton(IDC_CHECK1, m_family);
	m_parade = bParade;
	CheckDlgButton(IDC_CHECK1, m_parade);
	bUserCheck7 = false;
	bUserCheck8 = false;
	bUserCheck9 = false;
	UpdateData(false);
}

void CEditPreacherDlg::GetCurrentData()
{
	UpdateData(true);
	PINFO* pPInfo = pPInfo1Base + nEditPrch;
	if (ValidateEditedPr())
	{
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
		pPInfo->add_info = m_additional;
		pPInfo->on_trial = m_ontrial;
		pPInfo->on_note = m_onnote;
		pPInfo->visitor = m_visitor;
		pPInfo->reserved = m_reserved;
		for (int row = 1; row < rows - 1; row++)
		{
			pPInfo->authorised[row] = m_sacrament;
			pPInfo->family[row] = m_family;
			pPInfo->parade[row] = m_parade;
		}
//if screen name changed
		if (m_screen_name != pPInfo->screen_name)
		{
			SINFO* pRow = pSInfo1Base + 32;
			for (int row = 1; row < rows - 1; row++)
			{
				SINFO* pSInfo = pRow;
				for (int col = 0; col < cols; col++)
				{
					if (pDoc->PreacherAppears(pPInfo, pSInfo))
					{
						int nNamePos = pSInfo->preacher.Find(pPInfo->screen_name);
						CString strBefore = pSInfo->preacher.Left(nNamePos);
						CString strAfter = pSInfo->preacher.Mid(nNamePos + pPInfo->screen_name.GetLength());
						pSInfo->preacher = strBefore + m_screen_name + strAfter;
					}
					pSInfo++;
				}
				pRow += 32;
			}
			pPInfo->screen_name = m_screen_name;
		}
//if changed preacher status from lay to ordained, set prefs according to appearances
		if (m_ordained && !m_visitor
			&& !(pPInfo->ordained && !pPInfo->visitor))
		{
			PINFO* pPInfo0 = pPInfoBase + nEditPrch;
			SINFO* pRow = pSInfo1Base + 32;
			for (int row = 1; row < rows - 1; row++)
			{
				pPInfo->preferences[row] = 0;
				SINFO* pSInfo = pRow + 1;  //look for insertions
				for (int col = 1; col < cols; col++)
				{
					if (pDoc->PreacherAppears(pPInfo0, pSInfo))
						pPInfo->preferences[row]++;
					pSInfo++;
				}
				pRow += 32;
			}
			pPInfo->ordained = true;
			if (!pPInfo->stipend && m_stipend)
				pPInfo->stipend = true;
			return;
		}
//if changed preacher status from ordained to lay, set prefs to 1
		if (pPInfo->ordained && !m_ordained)
		{
			SINFO* pRow = pSInfo1Base + 32;
			for (int row = 1; row < rows - 1; row++)
			{
				pPInfo->preferences[row] = 1;
				pRow += 32;
			}
			pPInfo->ordained = false;
			pPInfo->stipend = false;
			return;
		}
//if changed preacher status to stipendiary
		if (!pPInfo->stipend && m_stipend)
		{
			pPInfo->stipend = true;
			return;
		}
//if changed preacher from stipendiary to non-stipendiary
		if (pPInfo->stipend && !m_stipend)
		{
			pPInfo->stipend = false;
			return;
		}
	}
}

void CEditPreacherDlg::OnCheck7() 
{
	bUserCheck7 = true;
}

void CEditPreacherDlg::OnCheck8() 
{
	bUserCheck8 = true;
}

void CEditPreacherDlg::OnCheck9() 
{
	bUserCheck9 = true;
}

LRESULT CEditPreacherDlg::OnKickIdle(WPARAM, LPARAM)
{
	UpdateData(true);
	BOOL bEnable = (m_first_name != "" && m_last_name != "" && m_screen_name != "") ? true : false;
//buttons
	m_ok.EnableWindow(bEnable);
	m_previous.EnableWindow(bEnable && nEditPrch != 0);
	m_next.EnableWindow(bEnable && nEditPrch != nPreachers - 1);
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
//clear checks if disabled
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

