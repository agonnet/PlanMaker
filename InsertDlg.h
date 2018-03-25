#if !defined(AFX_INSERTDLG_H__58541DC8_838E_11D5_B658_B12C22393332__INCLUDED_)
#define AFX_DIALOG1_H__58541DC8_838E_11D5_B658_B12C22393332__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InsertDlg.h : header file
//

#include "PlanMakerDoc.h"
#include "PlanMakerView.h"	// Added by ClassView

/////////////////////////////////////////////////////////////////////////////
// CInsertDlg dialog

class CInsertDlg : public CDialog
{
// Construction
public:
	int nSelPrch;
	int nAvailPrch;
	CPlanMakerDoc* pDoc;
	CString IntToStr(int value);
	CInsertDlg(CWnd* pParent = NULL);   // standard constructor
	int nPreferences[200][64];
// Dialog Data
	//{{AFX_DATA(CInsertDlg)
	enum { IDD = IDD_INSERTDLG };
	CListBox m_listctrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInsertDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInsertDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeList1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INSERTDLG_H__58541DC8_838E_11D5_B658_B12C22393332__INCLUDED_)
