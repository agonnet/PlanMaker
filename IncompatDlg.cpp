// IncompatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "planmaker.h"
#include "IncompatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIncompatDlg dialog

extern int rows;
extern SINFO* pSInfo1Base;
extern BOOL bSelected[100][32];

CIncompatDlg::CIncompatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIncompatDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CIncompatDlg)
	m_clicklist1 = _T("");
	m_clicklist2 = _T("");
	//}}AFX_DATA_INIT
}


void CIncompatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIncompatDlg)
	DDX_Control(pDX, IDC_LIST2, m_list2ctrl);
	DDX_Control(pDX, IDC_LIST1, m_list1ctrl);
	DDX_LBString(pDX, IDC_LIST1, m_clicklist1);
	DDX_LBString(pDX, IDC_LIST2, m_clicklist2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CIncompatDlg, CDialog)
	//{{AFX_MSG_MAP(CIncompatDlg)
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	ON_LBN_SELCHANGE(IDC_LIST2, OnSelchangeList2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIncompatDlg message handlers

BOOL CIncompatDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
//find selected church
	CString strIncompatSel = "";
	SINFO* pRow = pSInfo1Base + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		if (bSelected[row][0])
		{
			pSelRow = pRow;
			char grp = pSelRow->group + (char)0x30;
			strIncompatSel = (char)0x01 + pSelRow->strChurchCode + grp;
		}
		pRow += 32;
	}
//show incompatibles in listbox2
//show others in listbox1
	CString strList2;
	int find;
	pRow = pSInfo1Base + 32;
	for (row = 1; row < rows - 1; row++)
	{
		if (pRow->group != pSelRow->group)
		{
			if (pRow->place_time.Find(strIncompatSel) == -1)
			{
				find = pRow->place_time.Find(0x01);
				if (find != -1)
					m_list1ctrl.AddString(pRow->place_time.Left(find));
				else
					m_list1ctrl.AddString(pRow->place_time);
			}
			else
			{
				find = pRow->place_time.Find(0x01);
				if (find != -1)
					m_list2ctrl.AddString(pRow->place_time.Left(find));
				else
					m_list2ctrl.AddString(pRow->place_time);
			}
		}
		pRow += 32;
	}

	CString str = "Click Churches in the left hand box to prevent ";
	str += "Preachers being allocated to them on the same day as ";
	CString strPlaceTime = pSelRow->place_time;
	find = strPlaceTime.Find(0x01);
	if (find != -1)
		strPlaceTime = strPlaceTime.Left(find);
	find = strPlaceTime.Find(0x0d);
	if (find != -1)
	{
		strPlaceTime = strPlaceTime.Left(find)
			+ " " + strPlaceTime.Mid(find + 2);
	}
	str += strPlaceTime;
	str += ". The Churches you click will appear in the right hand box. ";
	str += "Click a Church in the right hand box to move it back.";
	SetDlgItemText(IDC_STATIC1, str);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CIncompatDlg::OnSelchangeList1() 
{
	UpdateData(true);
	m_list2ctrl.AddString(m_clicklist1);
	m_list1ctrl.DeleteString(m_list1ctrl.GetCurSel());
}

void CIncompatDlg::OnSelchangeList2() 
{
	UpdateData(true);
	m_list1ctrl.AddString(m_clicklist2);
	m_list2ctrl.DeleteString(m_list2ctrl.GetCurSel());
}

void CIncompatDlg::OnOK() 
{
//strIncompat for selected has to appear in all in listbox2
//strIncompats for all in listbox2 have to appear in selected
	char grp = pSelRow->group + (char)0x30;
	CString strIncompatSel = (char)0x01 + pSelRow->strChurchCode + grp;

//remove all strIncompats from selected if any exist
	int find = pSelRow->place_time.Find(0x01);
	if (find != -1)
		pSelRow->place_time = pSelRow->place_time.Left(find);

//remove strIncompatSel from all where it exists
	SINFO* pRow = pSInfo1Base + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		int find = pRow->place_time.Find(strIncompatSel);
		if (find != -1)
		{
			pRow->place_time = pRow->place_time.Left(find)
				+ pRow->place_time.Mid(find + 6);
		}
		pRow += 32;
	}

//add strIncompats according to content of listbox2
	CString strList2;
	for (int i = 0; i < m_list2ctrl.GetCount(); i++)
	{
		m_list2ctrl.GetText(i, strList2);
//identify the items in listbox2
		SINFO* pRow = pSInfo1Base + 32;
		for (int row = 1; row < rows - 1; row++)
		{
			if (pRow->place_time.Find(strList2) != -1)
			{
//add strIncompatSel to each in listbox2
				pRow->place_time += strIncompatSel;
				char grp = pRow->group + (char)0x30;
				CString strIncompatList = (char)0x01 + pRow->strChurchCode + grp;
//add strIncompat for each in listbox2 to selected
				pSelRow->place_time += strIncompatList;
			}
			pRow += 32;
		}
	}

	CDialog::OnOK();
}
