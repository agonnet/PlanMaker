// ServiceDayDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "ServiceDayDlg.h"
#include "PlanMakerDoc.h"
#include "PlanMakerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServiceDayDlg dialog


CServiceDayDlg::CServiceDayDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CServiceDayDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CServiceDayDlg)
	m_date = 0;
	m_note = _T("");
	//}}AFX_DATA_INIT
}


void CServiceDayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CServiceDayDlg)
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_DELETE, m_delete);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
	DDX_Control(pDX, IDC_MONTHCALENDAR, m_datectrl);
	DDX_MonthCalCtrl(pDX, IDC_MONTHCALENDAR, m_date);
	DDX_Text(pDX, IDC_EDIT1, m_note);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CServiceDayDlg, CDialog)
	//{{AFX_MSG_MAP(CServiceDayDlg)
	ON_NOTIFY(MCN_SELECT, IDC_MONTHCALENDAR, OnSelectMonthcalendar)
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	ON_BN_CLICKED(IDC_ADDNOTE, OnAddNote)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServiceDayDlg message handlers

extern int nDay[32];
extern int nMonth[32];
extern int nYear[32];
extern int rows;
extern int cols;
extern int nPreachers;
extern BOOL bAllocationDone;
extern PINFO* pPInfoBase;
extern SINFO* pSInfoBase;
extern PINFO* pPInfo1Base;
extern SINFO* pSInfo1Base;
extern BOOL bEnableUndo;
extern BOOL bEnableRedo;
extern BOOL bPlanResized;
extern BOOL bAllocPending;

BOOL CServiceDayDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	pDoc = CPlanMakerDoc::GetDoc();
//store nDay, nMonth & nYear in row 0 of each col
	SINFO* pCol = pSInfo1Base + 1;
	for (int col = 1; col < cols; col++)
	{
		pCol->nDay = nDay[col];
		pCol->nMonth = nMonth[col];
		pCol->nYear = nYear[col];
		pCol++;
	}

	m_datectrl.GetToday(&date);
	m_datectrl.SetCurSel(&date);

//get date info from cols in row 0 (remove crlf)
	SINFO* pSInfo = pSInfo1Base + 1;
	for (col = 1; col < cols; col++)
	{
		CString str = pSInfo->date;
		str.Replace(0x0d, ' ');
		str.Replace(0x0a, ' ');
		m_listctrl.AddString(str);
		pSInfo++;
	}
	nOldCols = cols;
	pDoc = CPlanMakerDoc::GetDoc();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CServiceDayDlg::OnSelectMonthcalendar(NMHDR* pNMHDR, LRESULT* pResult) 
{
	nItems = m_listctrl.GetCount();
	if (nItems == 32)
	{
		MessageBox("You have reached the maximum number of dates allowable and no more can be added. If you really need more dates, contact the program author to see if PlanMaker can be customised for you.", "PlanMaker", MB_OK | MB_ICONINFORMATION);
		return;
	}
//add new item at end of list
	nItems++;
	m_datectrl.GetCurSel(&date);
	SINFO* pSInfo = pSInfo1Base + nItems;
	pSInfo->nDay = date.wDay;
	pSInfo->nMonth = date.wMonth;
	pSInfo->nYear = date.wYear;
	char ch[8];
	_itoa(date.wDay, ch, 10);
	pSInfo->date = ch;
	pSInfo->date += " ";
	switch (date.wMonth)
	{
	case  1:	pSInfo->date += "January";
		break;
	case  2:	pSInfo->date += "February";
		break;
	case  3:	pSInfo->date += "March";
		break;
	case  4:	pSInfo->date += "April";
		break;
	case  5:	pSInfo->date += "May";
		break;
	case  6:	pSInfo->date += "June";
		break;
	case  7:	pSInfo->date += "July";
		break;
	case  8:	pSInfo->date += "August";
		break;
	case  9:	pSInfo->date += "September";
		break;
	case 10:	pSInfo->date += "October";
		break;
	case 11:	pSInfo->date += "November";
		break;
	case 12:	pSInfo->date += "December";
		break;
	}
	pSInfo->date += " ";
	_itoa(date.wYear, ch, 10);
	pSInfo->date += ch;
//copy info into CALENDAR
	CALENDAR* pCalBase = new CALENDAR[nItems];
	CALENDAR* pCal = pCalBase;
	pSInfo = pSInfo1Base + 1; //row0, col1
	for (int col = 1; col <= nItems; col++)
	{
		pCal->row0Info = *pSInfo;
		pCal->nCol = col;
		pCal++;
		pSInfo++;
	}
	qsort(pCalBase, nItems, sizeof(CALENDAR), Compare);
//find the new col
	int nCol = 0;
	SINFO newColInfo;
	pCal = pCalBase;
	for (col = 1; col <= nItems; col++)
	{
		if (pCal->nCol == nItems)
		{
			newColInfo = pCal->row0Info;
			nCol = col;
		}
		pCal++;
	}
	delete [] pCalBase;
//move service info & preacher availability right if new col not at end
	if (nCol != nItems)
	{
		SINFO* pRow = pSInfo1Base + nItems; //row0, last col
		for (int row = 0; row < rows - 1; row++)
		{
			SINFO* pSInfo = pRow;
			for (int col = nItems; col > nCol; col--)
			{
				*pSInfo = *(pSInfo - 1);
				pSInfo--;
			}
			pRow += 32;
		}
		*(pSInfo1Base + nCol) = newColInfo;
		for (int col = nItems; col > nCol; col--)
		{
			PINFO* pPInfo = pPInfo1Base;
			for (int prch = 0; prch < nPreachers; prch++)
			{
				pPInfo->availability[col] = pPInfo->availability[col - 1];
				pPInfo++;
			}
		}
	}
//initialise SINFO for new col
	pSInfo = pSInfo1Base + 32 + nCol;
	for (int row = 1; row < rows - 1; row++)
	{
		pSInfo->communion = false;
		pSInfo->family = false;
		pSInfo->parade = false;
		pSInfo->baptism = false;
		pSInfo->united = false;
		pSInfo->no_service = false;
		pSInfo->reserved = false;
		pSInfo->group = 0;
		pSInfo->detail = "";
		pSInfo->code = "";
		pSInfo->date = "";
		pSInfo->place_time = "";
		pSInfo->preacher = "";
		pSInfo += 32;
	}
//initialise preacher availability for new col
	PINFO* pPInfo = pPInfo1Base;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		pPInfo->availability[nCol] = 0;
		pPInfo++;
	}
	
//display in listbox
	m_listctrl.ResetContent();
	pSInfo = pSInfo1Base + 1;
	for (col = 1; col <= nItems; col++)
	{
		CString str;
		int find = pSInfo->date.Find(0x0d, 0);
		if (find != -1)
		{
			str = pSInfo->date.Left(find);
			str += " ";
			str += pSInfo->date.Mid(find + 2);
		}
		else
			str = pSInfo->date;
		m_listctrl.AddString(str);
		pSInfo++;
	}
	*pResult = 0;
}

void CServiceDayDlg::OnSelchangeList1() 
{
	m_edit1.EnableWindow(true);
	m_edit1.SetFocus();
	m_delete.EnableWindow(true);
//extract any note and copy to edit box
	SINFO* pSInfo = pSInfo1Base + m_listctrl.GetCurSel() + 1;
	CString str = pSInfo->date;
//find the return 0x0d before note (there isn't one if no note present)
	int nNote = str.Find(0x0d);
	if (nNote != -1)
		SetDlgItemText(IDC_EDIT1, str.Mid(nNote + 2));
	else
		SetDlgItemText(IDC_EDIT1, "");
}

void CServiceDayDlg::OnAddNote() 
{
	int nItems = m_listctrl.GetCount();
//add note
CString newnote;
	UpdateData(true);
	if (m_note != "")
	{
		newnote = (char)13;
		newnote += (char)10;
		newnote += m_note;
	}
	else newnote = "";
//remove any existing note
	SINFO* pSInfo = pSInfo1Base + m_listctrl.GetCurSel() + 1;
	int nNote = pSInfo->date.Find(0x0d);  //if exists, already a note
	if (nNote != -1)
		pSInfo->date = pSInfo->date.Left(nNote);
//add the new note
	pSInfo->date += newnote;
//display in list box
//clear the box first
	m_listctrl.ResetContent();
//then add the strings
	pSInfo = pSInfo1Base + 1;
	for (int col = 1; col <= nItems; col++)
	{
		CString str = pSInfo->date;
		str.Replace(0x0d, ' ');
		str.Replace(0x0a, ' ');
		m_listctrl.AddString(str);
		pSInfo++;
	}
//clear the edit box and disable
	SetDlgItemText(IDC_EDIT1, "");
	m_edit1.EnableWindow(false);
}

void CServiceDayDlg::OnDelete() 
{
//delete a date
	nItems = m_listctrl.GetCount();
	int nSelCol = m_listctrl.GetCurSel() + 1;
	m_listctrl.DeleteString(m_listctrl.GetCurSel());
//reduce prefs in rows where local ords appear in this col
	SINFO* pSInfo = pSInfo1Base + 32 + nSelCol;
	for (int row = 1; row < rows - 1; row++)
	{
		PINFO* pPInfo = pPInfo1Base;
		for (int prch = 0; prch < nPreachers; prch++)
		{
			if (pDoc->PreacherAppears(pPInfo, pSInfo) && pPInfo->ordained && !pPInfo->visitor)
				pPInfo->preferences[row]--;
			pPInfo++;
		}
		pSInfo += 32;
	}
//move later plan entries left
	SINFO* pRow = pSInfo1Base;; //row0, col0
	for (row = 0; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + nSelCol;
		for (int col = nSelCol; col < nItems; col++)
		{
			*pSInfo = *(pSInfo + 1);
			pSInfo++;
		}
		pRow += 32;
	}
//move availability left
	for (int col = nSelCol; col < nItems; col++)
	{
		PINFO* pPInfo = pPInfo1Base;
		for (int prch = 0; prch < nPreachers; prch++)
		{
			pPInfo->availability[col] = pPInfo->availability[col + 1];
			pPInfo++;
		}
	}
	m_delete.EnableWindow(false);
}

void CServiceDayDlg::OnOK() 
{
	cols = m_listctrl.GetCount() + 1;
	SINFO* pSInfo = pSInfo1Base + 1; //row0 col1
	for (int col = 1; col < cols; col++)
	{
		nDay[col] = pSInfo->nDay;
		nMonth[col] = pSInfo->nMonth;
		nYear[col] = pSInfo->nYear;
		pSInfo++;
	}
	if (cols != nOldCols)
	{
		bAllocPending = true;
		bPlanResized = true;
	}
	pDoc->SetModifiedFlag();
	bEnableUndo = true;
	bEnableRedo = false;
	CDialog::OnOK();
}

int CServiceDayDlg::Compare(const void *p1, const void *p2)
{
	CALENDAR* pCal1 = (CALENDAR*)p1;
	CALENDAR* pCal2 = (CALENDAR*)p2;

	if (pCal1->row0Info.nYear < pCal2->row0Info.nYear)
		return -1;
	if (pCal1->row0Info.nYear > pCal2->row0Info.nYear)
		return 1;
	if (pCal1->row0Info.nMonth < pCal2->row0Info.nMonth)
		return -1;
	if (pCal1->row0Info.nMonth > pCal2->row0Info.nMonth)
		return 1;
	if (pCal1->row0Info.nDay < pCal2->row0Info.nDay)
		return -1;
	if (pCal1->row0Info.nDay > pCal2->row0Info.nDay)
		return 1;

	return 0;
}


