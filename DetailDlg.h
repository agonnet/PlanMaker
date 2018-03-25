#if !defined(AFX_DETAILDLG_H__4BAFA360_8B3F_11D5_B658_A6D513640932__INCLUDED_)
#define AFX_DETAILDLG_H__4BAFA360_8B3F_11D5_B658_A6D513640932__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DetailDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDetailDlg dialog

class CDetailDlg : public CDialog
{
// Construction
public:
	CDetailDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDetailDlg)
	enum { IDD = IDD_DETAILDLG };
	CString	m_detail;
	CString	m_code;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDetailDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDetailDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DETAILDLG_H__4BAFA360_8B3F_11D5_B658_A6D513640932__INCLUDED_)
