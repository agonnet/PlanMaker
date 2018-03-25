// ChoosePrDel.cpp : implementation file
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "ChoosePrDel.h"
#include "PreacherDlg.h"
#include "MainFrm.h"
#include "PlanMakerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChoosePrDel dialog
CChoosePrDel::CChoosePrDel(CWnd* pParent /*=NULL*/)
	: CDialog(CChoosePrDel::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChoosePrDel)
	//}}AFX_DATA_INIT
}

extern PINFO* pPInfo1Base;
extern SINFO* pSInfo1Base;
extern int rows;
extern int cols;
extern int nPreachers;
extern BOOL bEnableUndo;
extern BOOL bEnableRedo;

void CChoosePrDel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChoosePrDel)
	DDX_Control(pDX, IDC_LIST1, m_list1ctrl);
	DDX_Control(pDX, IDC_DELETE, m_delete);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChoosePrDel, CDialog)
	//{{AFX_MSG_MAP(CChoosePrDel)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChoosePrDel message handlers

BOOL CChoosePrDel::OnInitDialog() 
{
	CDialog::OnInitDialog();
	pDoc = CPlanMakerDoc::GetDoc();

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
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CChoosePrDel::OnDelete() 
{
	m_list1ctrl.SetItemState(nSelPrch, 0, LVIS_SELECTED | LVIS_FOCUSED); //deselect item
	m_list1ctrl.DeleteItem(nSelPrch); //delete item from list
	PINFO* pPInfo = pPInfo1Base + nSelPrch;
	for (int prch = nSelPrch; prch < nPreachers - 1; prch++) //item index = prch
	{
		*pPInfo = *(pPInfo + 1); //move up list
		pPInfo++;
	}
	nPreachers--;
	m_list1ctrl.SetItemState(nSelPrch, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED); //select item now at this position
	bEnableUndo = true;
	bEnableRedo = false;
	pDoc->SetModifiedFlag();
}

void CChoosePrDel::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	if (!m_list1ctrl.GetItemState(pNMListView->iItem, LVIS_SELECTED | LVIS_FOCUSED))
		return; //only deal with selected item
	BOOL bAppears = false;
	PINFO* pPInfo = pPInfo1Base + pNMListView->iItem;	
	SINFO* pRow = pSInfo1Base + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (pDoc->PreacherAppears(pPInfo, pSInfo))
			{
				bAppears = true;
				break;
			}
			pSInfo++;
		}
		if (bAppears)
			break;
		pRow += 32;
	}
	if (!bAppears)
	{
		m_delete.EnableWindow(true);
		nSelPrch = pNMListView->iItem;
	}
	else
		m_delete.EnableWindow(false);
	m_list1ctrl.SetFocus();
	
	*pResult = 0;
}
