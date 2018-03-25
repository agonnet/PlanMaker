#if !defined(AFX_CHOOSEEDITDLG_H__A4E14146_8519_11D5_B658_E7252D151A32__INCLUDED_)
#define AFX_CHOOSEEDITDLG_H__A4E14146_8519_11D5_B658_E7252D151A32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChooseEditDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChooseEditDlg dialog

class CChooseEditDlg : public CDialog
{
// Construction
public:
	CChooseEditDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChooseEditDlg)
	enum { IDD = IDD_CHOOSEPREDIT };
	CButton	m_editctrl;
	CListCtrl	m_list1ctrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChooseEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChooseEditDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEdit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHOOSEEDITDLG_H__A4E14146_8519_11D5_B658_E7252D151A32__INCLUDED_)
