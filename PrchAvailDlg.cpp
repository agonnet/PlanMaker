// PrchAvailDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "PrchAvailDlg.h"
#include "PlanMakerDoc.h"
#include "PlanMakerView.h"
#include "DlgTemplate.h"
#include "Afxpriv.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrchAvailDlg dialog


CPrchAvailDlg::CPrchAvailDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrchAvailDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrchAvailDlg)
	m_nLimit = _T("");
	m_check4 = FALSE;
	m_check5 = FALSE;
	m_check6 = FALSE;
	m_check7 = FALSE;
	m_check8 = FALSE;
	m_check9 = FALSE;
	//}}AFX_DATA_INIT
}


void CPrchAvailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrchAvailDlg)
	DDX_Control(pDX, IDC_CHECK9, m_check9ctrl);
	DDX_Control(pDX, IDC_CHECK8, m_check8ctrl);
	DDX_Control(pDX, IDC_CHECK7, m_check7ctrl);
	DDX_Control(pDX, IDC_CHECK6, m_check6ctrl);
	DDX_Control(pDX, IDC_STATIC7, m_static7ctrl);
	DDX_Control(pDX, IDC_CHECK5, m_check5ctrl);
	DDX_Control(pDX, IDC_CHECK4, m_check4ctrl);
	DDX_Control(pDX, IDC_LIST1, m_list1ctrl);
	DDX_Control(pDX, IDC_LIST2, m_list2ctrl);
	DDX_Control(pDX, IDC_COMBO1, m_comboctrl);
	DDX_CBString(pDX, IDC_COMBO1, m_nLimit);
	DDX_Check(pDX, IDC_CHECK4, m_check4);
	DDX_Check(pDX, IDC_CHECK5, m_check5);
	DDX_Check(pDX, IDC_CHECK6, m_check6);
	DDX_Check(pDX, IDC_CHECK7, m_check7);
	DDX_Check(pDX, IDC_CHECK8, m_check8);
	DDX_Check(pDX, IDC_CHECK9, m_check9);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPrchAvailDlg, CDialog)
	//{{AFX_MSG_MAP(CPrchAvailDlg)
	ON_BN_CLICKED(IDC_CHECK6, OnCheck6)
	ON_BN_CLICKED(IDC_CHECK7, OnCheck7)
	ON_BN_CLICKED(IDC_CHECK8, OnCheck8)
	ON_BN_CLICKED(IDC_CHECK9, OnCheck9)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnRclickList1)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck4)
	ON_BN_CLICKED(IDC_CHECK5, OnCheck5)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, OnItemchangedList2)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_KICKIDLE, OnKickIdle)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrchAvailDlg message handlers

BOOL bIsAvail[200];

//globals declared in doc.cpp
extern int rows;
extern int cols;
extern int nPreachers;
extern BOOL bNoConsecSame;
extern BOOL bNoDouble;
extern BOOL bFillUnused;
extern BOOL bUseAllAge;
extern BOOL bAllocationDone;
extern PINFO* pPInfoBase;
extern SINFO* pSInfoBase;
extern PINFO* pPInfo1Base;
extern SINFO* pSInfo1Base;
extern PINFO* pPTmpInfoBase;
extern SINFO* pSTmpInfoBase;
extern BOOL bEnableUndo;
extern BOOL bEnableRedo;
extern BOOL bSelected[100][32];
extern BOOL bAllocPending;

BOOL CPrchAvailDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	pDoc = CPlanMakerDoc::GetDoc();

	m_list1ctrl.SetExtendedStyle(LVS_EX_CHECKBOXES);
	m_list2ctrl.SetExtendedStyle(LVS_EX_CHECKBOXES);

//show the preachers; tick the available ones
	PINFO* pPInfo = pPInfo1Base;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		bIsAvail[prch] = false;
		SINFO* pRow = pSInfo1Base + 1;
		for (int col = 1; col < cols; col++)
		{
			if (pPInfo->availability[col] != 0)
			{
				bIsAvail[prch] = true;
				break;
			}
			pRow++;
		}
		CString str = pPInfo->first_name + " " + pPInfo->last_name;
		if (pPInfo->reserved)
			str += " (R)";
		m_list1ctrl.InsertItem(m_list1ctrl.GetItemCount(), str);
		m_list1ctrl.SetCheck(prch, bIsAvail[prch]);
		pPInfo++;
	}

//set column widths for list1
	CRect rect;
	m_list1ctrl.GetWindowRect(&rect);
	m_list1ctrl.SetColumnWidth(0, rect.Width());

//show the service days
	SINFO* pSInfo = pSInfo1Base + 1;  //row 0 col 1
	for (int i = 1; i < cols; i++)
	{
		CString str = pSInfo->date;
		int find  = str.Find(0x0d);
		if (find != -1)
			str = str.Left(find);
		m_list2ctrl.InsertItem(m_list2ctrl.GetItemCount(), str);
		pSInfo++;
	}

//set column widths for list2
	m_list2ctrl.GetWindowRect(&rect);
	m_list2ctrl.SetColumnWidth(0, rect.Width());

	nListboxPrch = -1;
	pListboxPrch = NULL;
	nSelCount = 0;
	bItemChanged = true;
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPrchAvailDlg::OnSelchangeCombo1() 
{
	CString str;
	m_comboctrl.GetLBText(m_comboctrl.GetCurSel(), str);
	pListboxPrch->nLimit = (str == "(none)") ? -1 : str.GetAt(0) - 48;
	m_nLimit = str;
	bAllocPending = true;
}

void CPrchAvailDlg::OnOK() 
{
//remove allocated or inserted preachers if not now available
	PINFO* pPInfo = pPInfo1Base;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		SINFO* pRow = pSInfo1Base + 32;
		for (int row = 1; row < rows - 1; row++)
		{
			SINFO* pSInfo = pRow + 1;
			for (int col = 1; col < cols; col++)
			{
				if (pDoc->PreacherAppears(pPInfo, pSInfo)
					&& (pPInfo->availability[col] & pRow->group) == 0)
				{
					if (pSInfo->preacher.Find(" / ") != -1) //if multiple preachers
						pDoc->RemoveNamedPreacher(pPInfo, pSInfo);
					else
					{
						if (pSInfo->reserved && pPInfo->ordained && !pPInfo->visitor && pPInfo->preferences[row] > 0) 
							pPInfo->preferences[row]--; //if local ord in reserved service, reduce prefs
						pSInfo->preacher = "";
						pSInfo->reserved = false;
					}
					bSelected[row][col] = true; //highlight affected cells
				}
				pSInfo++;
			}
			pRow += 32;
		}
		pPInfo++;
	}
	if (!bAllocationDone) 
	{
		pDoc->DoTempInfo(pPInfo1Base, pPTmpInfoBase, pSInfo1Base, pSTmpInfoBase);
		if (!pDoc->AllocateOrd(false)) //do trial allocation if plan not allocated
		{
			MessageBox("You have tried to make one or more Preachers unavailable when they are required on the Plan. To resolve this, allocate your Plan, repeat the procedure and the Preacher(s) will be removed and made unavailable. ", NULL, MB_OK | MB_ICONEXCLAMATION);
			pDoc->DoTempInfo(pPInfoBase, pPInfo1Base, pSInfoBase, pSInfo1Base); //undo changes
		}
	}
	bEnableUndo = true;
	bEnableRedo = false;
	pDoc->SetModifiedFlag();
	CDialog::OnOK();
}

CString CPrchAvailDlg::IntToStr(int value)
{
	char ch[6];
	_itoa(value, ch, 10);
	return ch;
}

void CPrchAvailDlg::OnCheck6() 
{
	UpdateData(true);
	m_check6 &= ~2;
	UpdateData(false);
	DoAvailability(IDC_CHECK6, m_check6);
}

void CPrchAvailDlg::OnCheck7() 
{
	UpdateData(true);
	m_check7 &= ~2;
	UpdateData(false);
	DoAvailability(IDC_CHECK7, m_check7);
}

void CPrchAvailDlg::OnCheck8() 
{
	UpdateData(true);
	m_check8 &= ~2;
	UpdateData(false);
	DoAvailability(IDC_CHECK8, m_check8);
}

void CPrchAvailDlg::OnCheck9() 
{
	UpdateData(true);
	m_check9 &= ~2;
	UpdateData(false);
	DoAvailability(IDC_CHECK9, m_check9);
}

void CPrchAvailDlg::OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	nListboxPrch = (int)m_list1ctrl.GetFirstSelectedItemPosition() - 1;
	pListboxPrch = pPInfo1Base + nListboxPrch;

//preacher status pop-up
	CString strPlace = "";
	CString strAlloc = "";
	CString strPad('.', 50);
	int nTotal = 0;
	int nPlaces = 0;
	SINFO* pRow = pSInfo1Base + 32;
	int nAllocs;
	for (int row = 1; row < rows - 1; row++)
	{
		nAllocs = 0;
		if (pListboxPrch->ordained && !pListboxPrch->visitor)
		{
			nAllocs += pListboxPrch->preferences[row];
			nTotal += pListboxPrch->preferences[row];
		}
		else
		{
			SINFO* pSInfo = pRow + 1;
			for (int col = 1; col < cols; col++)
			{
				if (pDoc->PreacherAppears(pListboxPrch, pSInfo))
				{
					nAllocs++;
					nTotal++;
				}
				pSInfo++;
			}
		}
		if (nAllocs != 0)
		{
			int find1 = pRow->place_time.Find(0x0d);
			int find2 = pRow->place_time.Find(0x01);
			strPlace += (find1 != -1) ? pRow->place_time.Left(find1) : (find2 != -1) ? pRow->place_time.Left(find2) : pRow->place_time;
			strPlace += strPad + "\n";
			nPlaces++;
			if (nAllocs < 10)
				strAlloc += "   ";
			strAlloc += IntToStr(nAllocs) + "\n";
		}
		pRow += 32;
	}
	if (bAllocationDone)
		strPlace += "\nTotal appointments" + strPad;
	else
		strPlace += "\nTotal appointments (plan not allocated)" + strPad;
	strAlloc += (nTotal < 10) ? "\n   " : "\n";
	strAlloc += IntToStr(nTotal);

	int h = 8 * (nPlaces + 2) + 52;
	CString strCapt = pListboxPrch->first_name + " " + pListboxPrch->last_name;
	CDlgTemplate dlgT;
	DLGTEMPLATE* pTemplate = dlgT.MakeTemplate(strCapt, DS_CENTER, 0, 0, 160, h, NULL, 0);
	pTemplate = dlgT.AddStatic(strPlace, SS_LEFTNOWORDWRAP | WS_CHILD | WS_VISIBLE, 0, 5, 5, 135, h - 50, 0);
	pTemplate = dlgT.AddStatic(strAlloc, SS_LEFTNOWORDWRAP | WS_CHILD | WS_VISIBLE, 0, 140, 5, 10, h - 50, 0);
	pTemplate = dlgT.AddButton("OK", BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 0, 55, h - 40, 50, 15, IDOK);
		
	CDialog dlg;
	dlg.InitModalIndirect(pTemplate, NULL);
	dlg.DoModal();

	*pResult = 0;
}

void CPrchAvailDlg::DoAvailability(int nID, BOOL bMakeAvailable)
{
	int nGrp;
	switch (nID)
	{
		case IDC_CHECK6: nGrp = 1;
			break;
		case IDC_CHECK7: nGrp = 2;
			break;
		case IDC_CHECK8: nGrp = 4;
			break;
		case IDC_CHECK9: nGrp = 8;
	}

	POSITION pos = m_list2ctrl.GetFirstSelectedItemPosition();
	while (pos)
	{
		if (bMakeAvailable) //make available for all selected
		{
			pListboxPrch->availability[(int)pos] |= nGrp; //pos starts at 1
			m_list2ctrl.SetCheck(nListboxPrch, true);  //listctrl item indexes start at 0
		}
		else
		{
			pListboxPrch->availability[(int)pos] &= ~nGrp; //make unavailable for all selected
			if (pListboxPrch->availability[(int)pos] == 0)
				m_list2ctrl.SetCheck(nListboxPrch, false);
		}
		m_list2ctrl.GetNextSelectedItem(pos);
	}

//if still available in any col, must be ticked in list1
	int col = 1;
	while (col < cols)
	{
		if (pListboxPrch->availability[col] != 0)
		{
			bIsAvail[nListboxPrch] = true;
			m_list1ctrl.SetCheck(nListboxPrch, true);
			break;
		}
		col++;
	};
	if (col == cols)
	{
		bIsAvail[nListboxPrch] = false;
		m_list1ctrl.SetCheck(nListboxPrch, false);
	}
	bAllocPending = true;
}

void CPrchAvailDlg::OnCheck4() 
{
	UpdateData(true);
	pListboxPrch->one_service = m_check4;
	bAllocPending = true;
}

void CPrchAvailDlg::OnCheck5() 
{
	UpdateData(true);
	pListboxPrch->no_consec = m_check5;
	bAllocPending = true;
}

void CPrchAvailDlg::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

//maintain check state
	m_list1ctrl.SetCheck(pNMListView->iItem, bIsAvail[pNMListView->iItem]);

//get selected preacher
	if (m_list1ctrl.GetSelectedCount() == 1)
	{
		nListboxPrch = pNMListView->iItem;
		pListboxPrch = pPInfo1Base + nListboxPrch;
		UpdateList2();
		bItemChanged = true;
	}
	else
	{
		nListboxPrch = -1;
		pListboxPrch = NULL;
	}
	*pResult = 0;
}

void CPrchAvailDlg::OnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

//maintain check state
	if (m_list1ctrl.GetSelectedCount() != 0)
		m_list2ctrl.SetCheck(pNMListView->iItem, pListboxPrch->availability[pNMListView->iItem + 1]);
	else
		m_list2ctrl.SetCheck(pNMListView->iItem, 0);
	UpdateList2();
	
	*pResult = 0;
}

LRESULT CPrchAvailDlg::OnKickIdle(WPARAM, LPARAM)
{
	if (!bItemChanged)
		return 0L;

	bItemChanged = false;
	if (nListboxPrch == -1)
		return 0L;

//option ctrls
	if (pListboxPrch->reserved)
	{
//disable if reserved prch
		m_check4ctrl.EnableWindow(false);
		m_check5ctrl.EnableWindow(false);
		m_comboctrl.EnableWindow(false);
		m_static7ctrl.EnableWindow(false);
		return 0L;
	}
//enable if plan can be allocated with option set
//enable anyway if option set
	if (pListboxPrch->one_service)
		m_check4ctrl.EnableWindow(true);
	else
	{
		pListboxPrch->one_service = true;
		pDoc->DoTempInfo(pPInfo1Base, pPTmpInfoBase, pSInfo1Base, pSTmpInfoBase);
		m_check4ctrl.EnableWindow(pDoc->AllocateOrd(false));
		pListboxPrch->one_service = false;
	}
	if (pListboxPrch->no_consec)
		m_check5ctrl.EnableWindow(true);
	else
	{
		pListboxPrch->no_consec = true;
		pDoc->DoTempInfo(pPInfo1Base, pPTmpInfoBase, pSInfo1Base, pSTmpInfoBase);
		m_check5ctrl.EnableWindow(pDoc->AllocateOrd(false));
		pListboxPrch->no_consec = false;
	}
	m_comboctrl.EnableWindow(true);
	m_static7ctrl.EnableWindow(true);

//update
	m_check4 = pListboxPrch->one_service;
	m_check5 = pListboxPrch->no_consec;
	m_nLimit = (pListboxPrch->nLimit == -1) ? "(none)" : IntToStr(pListboxPrch->nLimit);

//list2 checkboxes
	if (m_list1ctrl.GetSelectedCount() != 0 && m_list2ctrl.GetSelectedCount() != 0)
	{
//enable if preacher & date selected
		m_check6ctrl.EnableWindow(true);
		m_check7ctrl.EnableWindow(true);
		m_check8ctrl.EnableWindow(true);
		m_check9ctrl.EnableWindow(true);
	}
	else
	{
//disable & clear
		m_check6ctrl.EnableWindow(false);
		m_check7ctrl.EnableWindow(false);
		m_check8ctrl.EnableWindow(false);
		m_check9ctrl.EnableWindow(false);
		m_check6 = 0;
		m_check7 = 0;
		m_check8 = 0;
		m_check9 = 0;
	}
	UpdateData(false);
	return 0L;
}

void CPrchAvailDlg::UpdateList2()
{
	if (m_list1ctrl.GetSelectedCount() != 1)
		return;

//update checks
	for (int col = 1; col < cols; col++)
		m_list2ctrl.SetCheck(col - 1, pListboxPrch->availability[col]);
//update checkboxes
//unchecked if none available - 0
//checked if all selected available - 1
//checked & greyed if some selected available - 2
	unsigned int nIsAvailable[4] = {0}; //4 groups
	POSITION pos = m_list2ctrl.GetFirstSelectedItemPosition();
	while (pos)
	{		
		int col = (int)pos;
		if ((pListboxPrch->availability[col] & 1) != 0)
			nIsAvailable[0]++;
		if ((pListboxPrch->availability[col] & 2) != 0)
			nIsAvailable[1]++;
		if ((pListboxPrch->availability[col] & 4) != 0)
			nIsAvailable[2]++;
		if ((pListboxPrch->availability[col] & 8) != 0)
			nIsAvailable[3]++;
		m_list2ctrl.GetNextSelectedItem(pos);
	}
	nSelCount = m_list2ctrl.GetSelectedCount();
	m_check6 = (nIsAvailable[0] == 0) ? 0 : (nIsAvailable[0] < nSelCount) ? 2 : 1;
	m_check7 = (nIsAvailable[1] == 0) ? 0 : (nIsAvailable[1] < nSelCount) ? 2 : 1;
	m_check8 = (nIsAvailable[2] == 0) ? 0 : (nIsAvailable[2] < nSelCount) ? 2 : 1;
	m_check9 = (nIsAvailable[3] == 0) ? 0 : (nIsAvailable[3] < nSelCount) ? 2 : 1;
	UpdateData(false);

	bItemChanged = true;
}

void CPrchAvailDlg::OnCancel() 
{
	pDoc->DoTempInfo(pPInfoBase, pPInfo1Base, pSInfoBase, pSInfo1Base); //discard changes
	CDialog::OnCancel();
}
