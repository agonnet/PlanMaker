// PlaceTimeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "PlaceTimeDlg.h"
#include "PlanMakerDoc.h"
#include "mmsystem.h"
#include "afxpriv.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlaceTimeDlg dialog


CPlaceTimeDlg::CPlaceTimeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPlaceTimeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPlaceTimeDlg)
	m_text = _T("");
	//}}AFX_DATA_INIT
}


void CPlaceTimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlaceTimeDlg)
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_MODIFY, m_modify);
	DDX_Control(pDX, IDC_INSERT, m_insert);
	DDX_Control(pDX, IDC_DELETE, m_delete);
	DDX_Text(pDX, IDC_EDIT1, m_text);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPlaceTimeDlg, CDialog)
	//{{AFX_MSG_MAP(CPlaceTimeDlg)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_INSERT, OnInsert)
	ON_BN_CLICKED(IDC_MODIFY, OnModify)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_KICKIDLE, OnKickIdle)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlaceTimeDlg message handlers

extern int rows;
extern int cols;
extern int nSelRow;
extern int nPreachers;
extern BOOL bAllocationDone;
extern BOOL bAllocPending;
extern BOOL bEnableUndo;
extern BOOL bEnableRedo;

extern PINFO* pPInfo1Base;
extern SINFO* pSInfo1Base;

BOOL CPlaceTimeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	pDoc = CPlanMakerDoc::GetDoc();
	if (nSelRow != rows - 1)
	{
		SINFO* pSInfo = pSInfo1Base + 32 * nSelRow;
		switch (pSInfo->group)
		{
			case 1:	CheckRadioButton(IDC_RADIO1, IDC_RADIO4, IDC_RADIO1);
					break;
			case 2:	CheckRadioButton(IDC_RADIO1, IDC_RADIO4, IDC_RADIO2);
					break;
			case 4:	CheckRadioButton(IDC_RADIO1, IDC_RADIO4, IDC_RADIO3);
					break;
			case 8:	CheckRadioButton(IDC_RADIO1, IDC_RADIO4, IDC_RADIO4);
		}
		m_check = GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO4);
		strPlaceTime = pSInfo->place_time;
		int find = strPlaceTime.Find(0x01); //incompats follow 0x01, if applicable
		if (find != -1)
			strPlaceTime = strPlaceTime.Left(find);
		m_text = strPlaceTime;
		UpdateData(false);
	}
	m_edit1.SetFocus();
	return FALSE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/////////////////////////////////////////////////////////////

void CPlaceTimeDlg::OnChangeEdit1() 
{
	UpdateData(true);
}

void CPlaceTimeDlg::OnDelete() 
{
//remove any incompats relevant to this church from other churches
	SINFO* pRow = pSInfo1Base + 32 * nSelRow;
	char grp = pRow->group + (char)0x30;
	CString strIncompatSel = (char)0x01 + pRow->strChurchCode + grp;
	pRow = pSInfo1Base + 32;
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
//move the data in the table up
	pRow = pSInfo1Base + 32 * nSelRow;
	for (row = nSelRow; row < rows; row++)
	{
		SINFO* pSInfo = pRow;
		for (int col = 0; col < cols; col++)
		{
			*pSInfo = *(pSInfo + 32);
			pSInfo++;
		}
//move church-specific preacher info up
		PINFO* pPInfo = pPInfo1Base;
		for (int prch = 0; prch < nPreachers; prch++)
		{
			pPInfo->preferences[row] = pPInfo->preferences[row + 1];
			pPInfo->authorised[row] = pPInfo->authorised[row + 1];
			pPInfo->family[row] = pPInfo->family[row + 1];
			pPInfo->parade[row] = pPInfo->parade[row + 1];
			pPInfo++;
		}
		pRow += 32;
	}
	rows--;
	bAllocPending = true;
	bEnableUndo = true;
	bEnableRedo = false;
	pDoc->SetModifiedFlag();
	CDialog::OnOK();
}

void CPlaceTimeDlg::OnInsert() 
{
//not to be more than 100 churches
	if (rows >= 100)
	{
		MessageBox("You have reached the maximum allowable number of churches and no more can be added. If you really need more chuches, contact the program author to see if PlanMaker can be customised for you.", "PlanMaker", MB_OK | MB_ICONINFORMATION);
		return;
	}
	if (nSelRow != rows - 1)
//not the empty row at the end so make space
	{
		SINFO* pRow = pSInfo1Base + 32 * (rows - 1);
		for (int row = rows - 1; row > nSelRow; row--)
		{
			SINFO* pSInfo = pRow;
			for (int col = 0; col < cols; col++)
			{
				*pSInfo = *(pSInfo - 32);
				pSInfo++;
			}
			PINFO* pPInfo = pPInfo1Base;
			for (int prch = 0; prch < nPreachers; prch++)
			{
				pPInfo->preferences[row] = pPInfo->preferences[row - 1];
				pPInfo->authorised[row] = pPInfo->authorised[row - 1];
				pPInfo->family[row] = pPInfo->family[row - 1];
				pPInfo->parade[row] = pPInfo->parade[row - 1];
				pPInfo++;
			}
			pRow -= 32;
		}
	}
//see which radio button is checked
	SINFO* pSInfo = pSInfo1Base + 32 * nSelRow;
	switch (GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO4))
	{
		case IDC_RADIO1: pSInfo->group = 1;
			break;
		case IDC_RADIO2: pSInfo->group = 2;
			break;
		case IDC_RADIO3: pSInfo->group = 4;
			break;
		case IDC_RADIO4: pSInfo->group = 8;
	}
//now insert the new row
//default service info
	for (int col = 0; col < cols; col++)
	{
		pSInfo->place_time = m_text;
		pSInfo->communion = false;
		pSInfo->family = false;
		pSInfo->parade = false;
		pSInfo->baptism = false;
		pSInfo->united = false;
		pSInfo->no_service = false;
		pSInfo->reserved = false;
		pSInfo->detail = "";
		pSInfo->code = "";
		pSInfo->preacher = "";
		pSInfo++;
	}	
//and preachers preferences & not authorised etc.
	PINFO* pPInfo = pPInfo1Base;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		if (pPInfo->ordained && !pPInfo->visitor)
		{
			pPInfo->preferences[nSelRow] = 0;
			pPInfo->authorised[nSelRow] = true;
			pPInfo->family[nSelRow] = true;
			pPInfo->parade[nSelRow] = true;
		}
		else
		{
			pPInfo->preferences[nSelRow] = 1;
			pPInfo->authorised[nSelRow] = false;
			pPInfo->family[nSelRow] = false;
			pPInfo->parade[nSelRow] = false;
		}
		pPInfo++;
	}
	rows++;
	bAllocPending = true;
	bEnableUndo = true;
	bEnableRedo = false;
	pDoc->SetModifiedFlag();
	CDialog::OnOK();
}

void CPlaceTimeDlg::OnModify() 
{
	UpdateData(true);
	SINFO* pSInfo = pSInfo1Base + 32 * nSelRow;
	pSInfo->place_time = m_text;
	bAllocPending = true;
	bEnableUndo = true;
	bEnableRedo = false;
	pDoc->SetModifiedFlag();
	CDialog::OnOK();
}

LRESULT CPlaceTimeDlg::OnKickIdle(WPARAM, LPARAM)
{
	m_insert.EnableWindow(m_text != "" && m_text != strPlaceTime && GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO4) != 0);
	m_modify.EnableWindow(m_text != "" && m_text != strPlaceTime && GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO4) == m_check && nSelRow != rows - 1);
	m_delete.EnableWindow(nSelRow != rows - 1);
	return 0L;
}
