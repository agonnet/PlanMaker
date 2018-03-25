// ShowFormDlg.cpp : implementation file
//

#include "stdafx.h"
#include "planmaker.h"
#include "ShowFormDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowFormDlg dialog


CShowFormDlg::CShowFormDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShowFormDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShowFormDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CShowFormDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShowFormDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CShowFormDlg, CDialog)
	//{{AFX_MSG_MAP(CShowFormDlg)
	ON_COMMAND(2103, OnOK)
	ON_COMMAND(2104, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowFormDlg message handlers

BOOL CShowFormDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	if (!ParseIniFile())
	{
		CDialog::OnCancel();
		return false;
	}

//screen width
	int cx = GetSystemMetrics(SM_CXSCREEN);
//screen height
	int cy = GetSystemMetrics(SM_CYSCREEN);

	int rowHeight = cy / 40;
	int colWidth = cx / 10;

	pFont = new CFont;
	if (cx > 800)
		pFont->CreatePointFont(95, "Arial", NULL);
	else
		pFont->CreatePointFont(85, "Arial", NULL);

//size window to fit
	CRect rect;
	this->GetWindowRect(&rect);
	int nWidth = 4 * colWidth + colWidth / 2 + colWidth / 4;
	int nOrgX = (cx - nWidth) / 2;
	int nHeight = nDates * rowHeight + 75;
	int nOrgY = (cy - nHeight) / 2;
	this->MoveWindow(nOrgX, nOrgY, nWidth, nHeight, true);

//column headers
	int posx = cx / 9;
	int posy = rowHeight / 4;
	pStaticBase = new CStatic[4];
	pStatic = pStaticBase;
	for (int i = 0; i < 4; i++)
	{
		CString str;
		switch (i)
		{
		case 0:	str = "Early Morning";
			break;
		case 1: str = "Morning";
			break;
		case 2: str = "Afternoon";
			break;
		case 3: str = "Evening";
		}
		pStatic->Create(str, WS_CHILD | WS_VISIBLE,
			CRect(posx, posy, posx + colWidth, posy + rowHeight), this, 2001); 
		pStatic->SetFont(pFont, true);
		pStatic++;
		posx += colWidth;
	}

//dates
	CString dotline ('.', 150);
	pDateBase = new CStatic[30];
	pDate = pDateBase;
	posx = cx / 200;
	posy = rowHeight / 4 + rowHeight;
	for (i = 0; i < nDates; i++)
	{
		pDate->Create(date[i] + dotline, WS_CHILD | WS_VISIBLE | SS_LEFTNOWORDWRAP,
			CRect(posx, posy, nWidth, posy + rowHeight), this, 2002); 
		pDate->SetFont(pFont, true);
		pDate++;
		posy += rowHeight;
	}

//checkboxes
	pCheckBase = new CButton[120];
	pCheck = pCheckBase;
	posx = cx / 9;
	posy = rowHeight / 4 + rowHeight;
	int cbWidth = cx / 70;
	for (i = 0; i < nDates; i++) //i vertical
	{
		for (int j = 0; j < 4; j++) //j horizontal
		{
			pCheck->Create("", WS_CHILD | WS_VISIBLE | WS_DISABLED | BS_AUTOCHECKBOX,
				CRect(posx, posy, posx + cbWidth, posy + rowHeight), this, 2003);
			pCheck++;
			posx += colWidth;
		}
		posx = cx / 9;
		posy += rowHeight;
	}

//pushbuttons
	this->GetWindowRect(&rect);
	pButtonBase = new CButton[5];
	pButton = pButtonBase;
	int buttonWidth = cx / 15;
	int buttonHeight = cy / 30;
	int buttonPitch = cx / 11;
	posx = cx / 48;
	posy = rect.Height() - cy / 20;
	for (i = 0; i < 5; i++)
	{
		CString str;
		switch (i)
		{
		case 0:	str = "Check All";
			break;
		case 1:	str = "Clear All";
			break;
		case 2: str = "Reset";
			break;
		case 3: str = "OK";
			break;
		case 4: str = "Cancel";
		}
		if (i < 3)
		{
			pButton->Create(str, WS_CHILD | WS_VISIBLE | WS_DISABLED | BS_PUSHBUTTON,
				CRect(posx, posy, posx + buttonWidth, posy + buttonHeight), this, 2100 + i);
		}
		else
		{
			pButton->Create(str, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
				CRect(posx, posy, posx + buttonWidth, posy + buttonHeight), this, 2100 + i);
		}
		pButton->SetFont(pFont);
		pButton++;
		posx += buttonPitch;
	}

//check boxes according to current .ini file
	DoCheckboxes();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CShowFormDlg::OnCancel() 
{
	delete pFont;
	delete [] pCheckBase;
	delete [] pStaticBase;
	delete [] pButtonBase;
	delete [] pDateBase;
	
	CDialog::OnCancel();
}

void CShowFormDlg::OnOK() 
{
	delete pFont;
	delete [] pCheckBase;
	delete [] pStaticBase;
	delete [] pButtonBase;
	delete [] pDateBase;
	
	CDialog::OnOK();
}

extern CString strForm;

BOOL CShowFormDlg::ParseIniFile()
{
	nDates = 0;
//header
	int find = strForm.Find(0x0d);
	strForm = strForm.Mid(find + 2);
//info
	for (int i = 0; i < 30; i++)
	{
		find = strForm.Find('=');
		if (find != -1)
		{
			date[i] = strForm.Left(find);
			availability[i] = strForm.GetAt(find + 1) & ~0x40;
			strForm = strForm.Mid(find + 4);
			nDates++;
		}
		else
			break;
	}
	return true;
}

void CShowFormDlg::DoCheckboxes()
{
	pCheck = pCheckBase;
 	for (int i = 0; i < nDates; i++)
 	{
		if (availability[i] & 1)
			(pCheck)->SetCheck(true);
		else
			(pCheck)->SetCheck(false);
		if (availability[i] & 2)
			(pCheck + 1)->SetCheck(true);
		else
			(pCheck + 1)->SetCheck(false);
		if (availability[i] & 4)
			(pCheck + 2)->SetCheck(true);
		else
			(pCheck + 2)->SetCheck(false);
		if (availability[i] & 8)
			(pCheck + 3)->SetCheck(true);
		else
			(pCheck + 3)->SetCheck(false);
		pCheck += 4;
	}
}
