#if !defined(AFX_INCOMPATDLG_H__08A3E2A3_DD22_4456_9BCB_431A09FE18C7__INCLUDED_)
#define AFX_INCOMPATDLG_H__08A3E2A3_DD22_4456_9BCB_431A09FE18C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IncompatDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIncompatDlg dialog

class CIncompatDlg : public CDialog
{
// Construction
public:
	SINFO* pSelRow;
	CIncompatDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CIncompatDlg)
	enum { IDD = IDD_INCOMPATDLG };
	CListBox	m_list2ctrl;
	CListBox	m_list1ctrl;
	CString	m_clicklist1;
	CString	m_clicklist2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIncompatDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CIncompatDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeList1();
	afx_msg void OnSelchangeList2();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INCOMPATDLG_H__08A3E2A3_DD22_4456_9BCB_431A09FE18C7__INCLUDED_)
