// LabelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "LabelDlg.h"
#include "PlanMakerDoc.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLabelDlg dialog


CLabelDlg::CLabelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLabelDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLabelDlg)
	m_across = _T("");
	m_down = _T("");
	m_left = _T("");
	m_top = _T("");
	m_hoff = _T("");
	m_voff = _T("");
	m_startrow = _T("");
	m_font = _T("");
	m_no_label = FALSE;
	//}}AFX_DATA_INIT
}


void CLabelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLabelDlg)
	DDX_CBString(pDX, IDC_COMBO1, m_across);
	DDX_CBString(pDX, IDC_COMBO2, m_down);
	DDX_CBString(pDX, IDC_COMBO3, m_left);
	DDX_CBString(pDX, IDC_COMBO4, m_top);
	DDX_CBString(pDX, IDC_COMBO5, m_hoff);
	DDX_CBString(pDX, IDC_COMBO6, m_voff);
	DDX_CBString(pDX, IDC_COMBO7, m_startrow);
	DDX_CBString(pDX, IDC_COMBO8, m_font);
	DDX_Check(pDX, IDC_CHECK1, m_no_label);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLabelDlg, CDialog)
	//{{AFX_MSG_MAP(CLabelDlg)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnSelchangeCombo2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLabelDlg message handlers

//globals
CString _across;
CString _down;
CString _left;
CString _top;
CString _hoff;
CString _voff;
CString _font;
BOOL bNoLabel;
int nAcross;
int nDown;
int nTopMargin;
int nLeftMargin;
float fPageHeight;
float fPageWidth;
int nVOffset;
int nHOffset;
int nStartRow;
int nFont;
int nLocalLabel;
int nVisitorLabel;

BOOL CLabelDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_across = (_across != "") ? _across : "2"; //no of labels across sheet
	m_down = (_down != "") ? _down : "7"; //no of labels down sheet
	m_hoff = (_hoff != "") ? _hoff : "5"; //distance (mm) from left edge of sheet to first label
	m_voff = (_voff != "") ? _voff : "15"; //distance (mm) from top of sheet to first label
	m_left = (_left != "") ? _left : "20"; //left print margin (mm)
	m_top = (_top != "") ? _top : "20"; //top print margin (mm)
	m_font = (_font != "") ? m_font = _font : "12"; //default font
	m_startrow = "1";
	m_no_label = bNoLabel;
	UpdateData(false);

	switch (nLocalLabel)
	{
	case 1: CheckRadioButton(IDC_RADIO5, IDC_RADIO8, IDC_RADIO6); //all
		break;
	case 2: CheckRadioButton(IDC_RADIO5, IDC_RADIO8, IDC_RADIO7); //planned
		break;
	case 3: CheckRadioButton(IDC_RADIO5, IDC_RADIO8, IDC_RADIO8); //available
		break;
	default: CheckRadioButton(IDC_RADIO5, IDC_RADIO8, IDC_RADIO5); //none
	}

	switch (nVisitorLabel)
	{
	case 1: CheckRadioButton(IDC_RADIO9, IDC_RADIO12, IDC_RADIO10);
		break;
	case 2: CheckRadioButton(IDC_RADIO9, IDC_RADIO12, IDC_RADIO11);
		break;
	case 3: CheckRadioButton(IDC_RADIO9, IDC_RADIO12, IDC_RADIO12);
		break;
	default: CheckRadioButton(IDC_RADIO9, IDC_RADIO12, IDC_RADIO9);
	}

//init start row combo box
	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO7);
	CString str;
	for (int i = 1; i <= StrToInt(m_down); i++)
	{
		str.Format(_T("%d"), i);
		pCombo->AddString(str);
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLabelDlg::OnCheck1() 
{
	UpdateData(true);
	bNoLabel = m_no_label;
}

int CLabelDlg::StrToInt(CString str)
{
	int nMultiplier = 1;
	int nInt = 0;
	for (int i = str.GetLength() - 1; i >= 0; i--)
	{
		nInt += (str.GetAt(i) - 48) * nMultiplier;
		nMultiplier *= 10;
	}
	return nInt;
}

void CLabelDlg::OnOK() 
{
	UpdateData(true);
	nAcross = StrToInt(m_across);
	nDown = StrToInt(m_down);
	nLeftMargin = StrToInt(m_left);
	nTopMargin = StrToInt(m_top);
	nHOffset = StrToInt(m_hoff);
	nVOffset = StrToInt(m_voff);
	nStartRow = StrToInt(m_startrow) - 1;
	nFont = StrToInt(m_font);
	_across = m_across;
	_down = m_down;
	_left = m_left;
	_top = m_top;
	_hoff = m_hoff;
	_voff = m_voff;
	_font = m_font;

//get preacher label choices
	switch(GetCheckedRadioButton(IDC_RADIO5, IDC_RADIO8))
	{
		case IDC_RADIO5: nLocalLabel = 0; //none
			break;
		case IDC_RADIO6: nLocalLabel = 1; //all
			break;
		case IDC_RADIO7: nLocalLabel = 2; //planned
			break;
		case IDC_RADIO8: nLocalLabel = 3; //available
			break;
		default: nLocalLabel = 0;
	}
	switch(GetCheckedRadioButton(IDC_RADIO9, IDC_RADIO12))
	{
		case IDC_RADIO9: nVisitorLabel = 0;
			break;
		case IDC_RADIO10: nVisitorLabel = 1;
			break;
		case IDC_RADIO11: nVisitorLabel = 2;
			break;
		case IDC_RADIO12: nVisitorLabel = 3;
			break;
		default: nVisitorLabel = 0;
	}

	pDoc = CPlanMakerDoc::GetDoc();
	pDoc->Store();

	CDialog::OnOK();
}

void CLabelDlg::OnSelchangeCombo2() 
{
	CComboBox* pCombo2 = (CComboBox*)GetDlgItem(IDC_COMBO2);
	pCombo2->GetLBText(pCombo2->GetCurSel(), m_down);

	CComboBox* pCombo7 = (CComboBox*)GetDlgItem(IDC_COMBO7);
	pCombo7->ResetContent();

	CString str;
	for (int i = 1; i <= StrToInt(m_down); i++)
	{
		str.Format(_T("%d"), i);
		pCombo7->AddString(str);
	}
	m_startrow = "1";
	UpdateData(false);
}

