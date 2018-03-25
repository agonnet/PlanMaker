// PrchPrefsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "PrchPrefsDlg.h"
#include "PlanMakerDoc.h"
#include "PlanMakerView.h"
#include "DlgTemplate.h"
#include "afxpriv.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrchPrefsDlg dialog


CPrchPrefsDlg::CPrchPrefsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrchPrefsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrchPrefsDlg)
	m_nLimit = _T("");
	m_slid = 0;
	m_check1 = FALSE;
	m_check2 = FALSE;
	m_check3 = FALSE;
	m_static9 = _T("");
	//}}AFX_DATA_INIT
}


void CPrchPrefsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrchPrefsDlg)
	DDX_Control(pDX, IDC_STATIC9, m_static9ctrl);
	DDX_Control(pDX, IDC_CHECK3, m_check3ctrl);
	DDX_Control(pDX, IDC_CHECK2, m_check2ctrl);
	DDX_Control(pDX, IDC_CHECK1, m_check1ctrl);
	DDX_Control(pDX, IDC_LIST4, m_list4ctrl);
	DDX_Control(pDX, IDC_LIST1, m_list1ctrl);
	DDX_Control(pDX, IDC_SLIDER1, m_slidctrl);
	DDX_Slider(pDX, IDC_SLIDER1, m_slid);
	DDX_Check(pDX, IDC_CHECK1, m_check1);
	DDX_Check(pDX, IDC_CHECK2, m_check2);
	DDX_Check(pDX, IDC_CHECK3, m_check3);
	DDX_Text(pDX, IDC_STATIC9, m_static9);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPrchPrefsDlg, CDialog)
	//{{AFX_MSG_MAP(CPrchPrefsDlg)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, OnReleasedcaptureSlider1)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck3)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnRclickList1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST4, OnItemchangedList4)
	ON_NOTIFY(NM_RCLICK, IDC_LIST4, OnRclickList4)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_KICKIDLE, OnKickIdle)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrchPrefsDlg message handlers

//globals declared in doc.cpp
extern int rows;
extern int cols;
extern int nPreachers;
extern BOOL bNoConsecSame;
extern BOOL bNoDouble;
extern BOOL bFillUnused;
extern BOOL bUseAllAge;
extern PINFO* pPInfoBase;
extern SINFO* pSInfoBase;
extern PINFO* pPInfo1Base;
extern SINFO* pSInfo1Base;
extern PINFO* pPTmpInfoBase;
extern SINFO* pSTmpInfoBase;
extern BOOL bAllocationDone;
extern BOOL bEnableUndo;
extern BOOL bEnableRedo;
extern BOOL bIsAvail[200];
extern BOOL bAllocPending;

BOOL CPrchPrefsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	pDoc = CPlanMakerDoc::GetDoc();

	m_list1ctrl.SetExtendedStyle(LVS_EX_CHECKBOXES);

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

//show the places and times
	SINFO* pSInfo = pSInfo1Base + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		CString strPlace;
		int find1 = pSInfo->place_time.Find(0x0d);
		int find2 = pSInfo->place_time.Find(0x01);
		strPlace = (find1 != -1) ? pSInfo->place_time.Left(find1) : (find2 != -1) ? pSInfo->place_time.Left(find2) : pSInfo->place_time;
		m_list4ctrl.InsertItem(m_list4ctrl.GetItemCount(), strPlace, 1);
		pSInfo += 32;
	}

//set column width for list4
	m_list4ctrl.GetWindowRect(&rect);
	m_list4ctrl.SetColumnWidth(0, rect.Width());

	if (bUseAllAge)
		SetDlgItemText(IDC_CHECK2, "All Age Worship:");
	else
		SetDlgItemText(IDC_CHECK2, "Family Service:");

	nListboxPrch = -1;
	pListboxPrch = pPInfo1Base;
	nSelCount = 0;
	bItemChanged = true;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPrchPrefsDlg::OnReleasedcaptureSlider1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	nListboxRow = (int)m_list4ctrl.GetFirstSelectedItemPosition();
	UpdateData(true);
//don't set slider below insertions for local ordained
	if (pListboxPrch->ordained	&& !pListboxPrch->visitor)
	{
//find insertions in this row
int nInsThisRow = 0;
		SINFO* pSInfo = pSInfo1Base + 32 * nListboxRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (pDoc->PreacherAppears(pListboxPrch, pSInfo)	&& pSInfo->reserved)
				nInsThisRow++;
			pSInfo++;
		}
		if (m_slid < nInsThisRow)
			m_slid = nInsThisRow;
	}
	else
		m_slidctrl.ClearSel(true);
	pListboxPrch->preferences[nListboxRow] = m_slid;
	UpdateData(false);
	bAllocPending = true;
	*pResult = 0;
}

void CPrchPrefsDlg::OnCheck1() 
{
	UpdateData(true);
	m_check1 &= ~2; //don't allow user to set to checked & greyed
	UpdateData(false);

	POSITION pos = m_list4ctrl.GetFirstSelectedItemPosition();
	while (pos)
	{
		pListboxPrch->authorised[(int)pos] = (m_check1 == 1) ? true : false;
		m_list4ctrl.GetNextSelectedItem(pos);
	}
	bAllocPending = true;
}

void CPrchPrefsDlg::OnCheck2() 
{
	UpdateData(true);
	m_check2 &= ~2;
	UpdateData(false);

	POSITION pos = m_list4ctrl.GetFirstSelectedItemPosition();
	while (pos)
	{
		pListboxPrch->family[(int)pos] = (m_check2 == 1) ? true : false;
		m_list4ctrl.GetNextSelectedItem(pos);
	}
	bAllocPending = true;
}

void CPrchPrefsDlg::OnCheck3() 
{
	UpdateData(true);
	m_check3 &= ~2;
	UpdateData(false);

	POSITION pos = m_list4ctrl.GetFirstSelectedItemPosition();
	while (pos)
	{
		pListboxPrch->parade[(int)pos] = (m_check3 == 1) ? true : false;
		m_list4ctrl.GetNextSelectedItem(pos);
	}
	bAllocPending = true;
}

void CPrchPrefsDlg::OnOK() 
{
	bEnableUndo = true;
	bEnableRedo = false;
	pDoc->SetModifiedFlag();

	CDialog::OnOK();
}

CString CPrchPrefsDlg::IntToStr(int value)
{
	char ch[6];
	_itoa(value, ch, 10);
	return ch;
}

int CPrchPrefsDlg::GetSliderRange(int nListboxRow)
{
	pDoc->DoTempInfo(pPInfo1Base, pPTmpInfoBase, pSInfo1Base, pSTmpInfoBase);
	PINFO* pPrch = pPTmpInfoBase + nListboxPrch;
//increment prefs until plan will not compile
	while (pDoc->AllocateOrd(false))
		pPrch->preferences[nListboxRow]++;
	int range = pPrch->preferences[nListboxRow] - 1;
	if (range > 15)
		return 15;  //can't have more than 15 appointments in one row
	else
		return range;
}

void CPrchPrefsDlg::OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
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

void CPrchPrefsDlg::OnRclickList4(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if (m_list4ctrl.GetSelectedCount() > 1)
		return;

	nListboxRow = (int)m_list4ctrl.GetFirstSelectedItemPosition();
	CString strName = "";
	CString strAppt = "";
	CString strPad('.', 50);
	int nNames = 0;
	int nTotal = 0;
	PINFO* pPInfo = pPInfo1Base;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		int nAppt = 0;
		if (pPInfo->ordained && !pPInfo->visitor)
		{
			nAppt += pPInfo->preferences[nListboxRow];
			nTotal += pPInfo->preferences[nListboxRow];
		}
		else
		{
			SINFO* pSInfo = pSInfo1Base + 32 * nListboxRow + 1;
			for (int col = 1; col < cols; col++)
			{
				if (pDoc->PreacherAppears(pPInfo, pSInfo))
				{
					nAppt++;
					nTotal++;
				}
				pSInfo++;
			}
		}
		if (nAppt != 0)
		{
			nNames++;
			strName += pPInfo->first_name + " " + pPInfo->last_name;
			strName += strPad + "\n";
			if (nAppt < 10)
				strAppt += "   ";
			strAppt += IntToStr(nAppt) + "\n";
		}
		pPInfo++;
	}

	if (bAllocationDone)
		strName += "\nTotal Preachers" + strPad;
	else
		strName += "\nTotal Preachers (plan not allocated)" + strPad;
	strAppt += (nTotal < 10) ? "\n   " : "\n";
	strAppt += IntToStr(nTotal);

	SINFO* pRow = pSInfo1Base + 32 * nListboxRow;
	int find1 = pRow->place_time.Find(0x0d);
	int find2 = pRow->place_time.Find(0x01);
	CString strCapt = (find1 != -1) ? pRow->place_time.Left(find1) : (find2 != -1) ? pRow->place_time.Left(find2) : pRow->place_time;
	int h = 8 * (nNames + 2) + 52;
	CDlgTemplate dlgT;
	DLGTEMPLATE* pTemplate = dlgT.MakeTemplate(strCapt, DS_CENTER, 0, 0, 160, h, NULL, 0);
	pTemplate = dlgT.AddStatic(strName, SS_LEFTNOWORDWRAP | WS_CHILD | WS_VISIBLE, 0, 5, 5, 135, h - 50, 0);
	pTemplate = dlgT.AddStatic(strAppt, SS_LEFTNOWORDWRAP | WS_CHILD | WS_VISIBLE, 0, 140, 5, 10, h - 50, 0);
	pTemplate = dlgT.AddButton("OK", BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE, 0, 55, h - 40, 50, 15, IDOK);
		
	CDialog dlg;
	dlg.InitModalIndirect(pTemplate, NULL);
	dlg.DoModal();

	*pResult = 0;
}

void CPrchPrefsDlg::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

//maintain check state if same item
	m_list1ctrl.SetCheck(pNMListView->iItem, bIsAvail[pNMListView->iItem]);

//get listbox preacher
	if (m_list1ctrl.GetSelectedCount() != 1)
	{
		nListboxPrch = -1;
		pListboxPrch = NULL;
	}
	else
	{
		nListboxPrch = pNMListView->iItem;
		pListboxPrch = pPInfo1Base + nListboxPrch;
		UpdateList4();
	}
	bItemChanged = true;
	*pResult = 0;
}

void CPrchPrefsDlg::OnItemchangedList4(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if (nListboxPrch == -1)
		return;
	UpdateList4();
	bItemChanged = true;
	*pResult = 0;
}

LRESULT CPrchPrefsDlg::OnKickIdle(WPARAM, LPARAM)
{
	if (!bItemChanged)
		return 0L;
		
	bItemChanged = false;
//enable/disable slider & checkboxes
	if (m_list1ctrl.GetSelectedCount() == 1	&& m_list4ctrl.GetSelectedCount() != 0 && !pListboxPrch->reserved)
	{
		m_check1ctrl.EnableWindow(true);
		m_check2ctrl.EnableWindow(true);
		m_check3ctrl.EnableWindow(true);
		m_static9ctrl.EnableWindow(true);
		m_static9 = (pListboxPrch->ordained && !pListboxPrch->visitor) ? "Appointments:" : "Weighting:";
		m_slidctrl.EnableWindow(true);
	}
	else
	{
		m_check1ctrl.EnableWindow(false);
		m_check2ctrl.EnableWindow(false);
		m_check3ctrl.EnableWindow(false);
		m_check1 = 0;
		m_check2 = 0;
		m_check3 = 0;
		m_static9ctrl.EnableWindow(false);
		m_static9 = "";
		m_slidctrl.EnableWindow(false);
		m_slid = 0;
	}
	
	UpdateData(false);
	return 0L;
}

void CPrchPrefsDlg::UpdateList4()
{
//do nothing if no selection in list1
	if (m_list1ctrl.GetSelectedCount() == 0)
		return;
//setup dialog controls
	nSelCount = m_list4ctrl.GetSelectedCount();
	if (nSelCount == 0 || pListboxPrch->reserved)
	{
		m_slidctrl.ClearSel();
		m_slidctrl.SetRange(0, 0, true);
		m_slid = m_check1 = m_check2 = m_check3 = 0;
		UpdateData(false);
		return;
	}
//checkboxes 1-3
 	unsigned int nAuth = 0;
 	unsigned int nFamily = 0;
	unsigned int nParade = 0;
 	int nListboxRow;
	POSITION pos = m_list4ctrl.GetFirstSelectedItemPosition();
	while (pos)
 	{
 		nListboxRow = (int)pos;
 		if (pListboxPrch->authorised[nListboxRow])
 			nAuth++;
 		if (pListboxPrch->family[nListboxRow])
			nFamily++;
 		if (pListboxPrch->parade[nListboxRow])
			nParade++;
 		m_list4ctrl.GetNextSelectedItem(pos);
 	}
	m_check1 = (nAuth == 0) ? 0 : (nAuth < nSelCount) ? 2 : 1;
	m_check2 = (nFamily == 0) ? 0 : (nFamily < nSelCount) ? 2 : 1;
	m_check3 = (nParade == 0) ? 0 : (nParade < nSelCount) ? 2 : 1;
//slider
	if (nSelCount == 1)
	{
		int nListboxRow = (int)m_list4ctrl.GetFirstSelectedItemPosition();
		if (pListboxPrch->ordained && !pListboxPrch->visitor)
		{
			int	nInsThisRow = 0;
			SINFO* pSInfo = pSInfo1Base + 32 * nListboxRow + 1;
			for (int col = 1; col < cols; col++)
			{
				if (pSInfo->reserved
					&& pDoc->PreacherAppears(pListboxPrch, pSInfo))
					nInsThisRow++;
				pSInfo++;
			}
			int range = GetSliderRange(nListboxRow);
			m_slidctrl.ClearSel();
			m_slidctrl.SetRange(0, range, true);
			m_slidctrl.SetSelection(nInsThisRow, range);
			m_slidctrl.RedrawWindow(NULL, NULL);
			m_slid = (range > 0) ? pListboxPrch->preferences[nListboxRow] : 0;
		}
		else
		{
			m_slidctrl.ClearSel();
			m_slidctrl.SetRange(0, 4, true);
			m_slid = pListboxPrch->preferences[nListboxRow];
		}
	}
	else
	{
//slider not available if more than 1 selection in listbox4
		m_slidctrl.ClearSel();
		m_slidctrl.SetRange(0, 0, true);
		m_slid = 0;
	}

	UpdateData(false);
}

void CPrchPrefsDlg::OnCancel() 
{
	pDoc->DoTempInfo(pPInfoBase, pPInfo1Base, pSInfoBase, pSInfo1Base); //discard changes	
	CDialog::OnCancel();
}
