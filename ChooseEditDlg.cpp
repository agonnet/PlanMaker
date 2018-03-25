// ChooseEditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "ChooseEditDlg.h"
#include "PlanMakerDoc.h"
#include "EditPreacherDlg.h"
#include "SortPreachers.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChooseEditDlg dialog


CChooseEditDlg::CChooseEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChooseEditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChooseEditDlg)
	//}}AFX_DATA_INIT
}


void CChooseEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChooseEditDlg)
	DDX_Control(pDX, IDC_EDIT, m_editctrl);
	DDX_Control(pDX, IDC_LIST1, m_list1ctrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChooseEditDlg, CDialog)
	//{{AFX_MSG_MAP(CChooseEditDlg)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	ON_BN_CLICKED(IDC_EDIT, OnEdit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChooseEditDlg message handlers

extern int nPreachers;
extern PINFO* pPInfo1Base;
extern int nSelPrch;
extern int rows;
extern int cols;

BOOL CChooseEditDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
//set column width
	CRect rect;
	m_list1ctrl.GetWindowRect(&rect);
	m_list1ctrl.SetColumnWidth(0, rect.Width());

	PINFO* pPInfo = pPInfo1Base;	
	for (int prch = 0; prch < nPreachers; prch++)
	{
		if (pPInfo->reserved)
			m_list1ctrl.InsertItem(m_list1ctrl.GetItemCount(), pPInfo->first_name + " " + pPInfo->last_name + " (R)");
		else
			m_list1ctrl.InsertItem(m_list1ctrl.GetItemCount(), pPInfo->first_name + " " + pPInfo->last_name);
		pPInfo++;
	}
	return TRUE;  // return TRUE unless you set the focus to a control
}


void CChooseEditDlg::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	if (!(m_list1ctrl.GetItemState(pNMListView->iItem, LVIS_SELECTED)))
		return; //only deal with selected item
	
	nSelPrch = pNMListView->iItem;
	m_editctrl.EnableWindow(true);

	*pResult = 0;
}

void CChooseEditDlg::OnEdit() 
{
	CDialog::OnOK();	
}
