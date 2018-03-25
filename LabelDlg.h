#if !defined(AFX_LABELDLG_H__C21A6780_B2B6_11D5_B658_F97783AF1232__INCLUDED_)
#define AFX_LABELDLG_H__C21A6780_B2B6_11D5_B658_F97783AF1232__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LabelDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLabelDlg dialog

class CLabelDlg : public CDialog
{
// Construction
public:
	CPlanMakerDoc* pDoc;
	int StrToInt(CString str);
	CLabelDlg(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CLabelDlg)
	enum { IDD = IDD_LABELS };
	CString	m_across;
	CString	m_down;
	CString	m_left;
	CString	m_top;
	CString	m_hoff;
	CString	m_voff;
	CString	m_startrow;
	CString	m_font;
	BOOL	m_no_label;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLabelDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLabelDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnCheck1();
	afx_msg void OnSelchangeCombo2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LABELDLG_H__C21A6780_B2B6_11D5_B658_F97783AF1232__INCLUDED_)
