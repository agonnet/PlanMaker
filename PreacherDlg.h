#if !defined(AFX_PREACHERDLG_H__944C6A40_8400_11D5_B658_CD921EB01332__INCLUDED_)
#define AFX_PREACHERDLG_H__944C6A40_8400_11D5_B658_CD921EB01332__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PreacherDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPreacherDlg dialog

class CPreacherDlg : public CDialog
{
// Construction
public:
	BOOL bUserCheck7;
	BOOL bUserCheck8;
	BOOL bUserCheck9;
	void AddNewPreacher();
	CPlanMakerDoc* pDoc;
	BOOL ValidateNewPreacher();

	CPreacherDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPreacherDlg)
	enum { IDD = IDD_PREACHER };
	CButton	m_reservedctrl;
	CButton	m_visitorctrl;
	CButton	m_ordainedctrl;
	CButton	m_stipendctrl;
	CButton	m_onnotectrl;
	CButton	m_ontrialctrl;
	CButton	m_paradectrl;
	CButton	m_familyctrl;
	CButton	m_sacramentctrl;
	CEdit	m_edit11;
	CButton	m_ok;
	CButton	m_more;
	CString	m_title;
	CString	m_first_name;
	CString	m_last_name;
	CString	m_address1;
	CString	m_address2;
	CString	m_town;
	CString	m_county;
	CString	m_postcode;
	CString	m_phone;
	CString	m_email;
	CString	m_screen_name;
	BOOL	m_ordained;
	BOOL	m_stipend;
	BOOL	m_visitor;
	BOOL	m_reserved;
	BOOL	m_ontrial;
	BOOL	m_onnote;
	CString	m_additional;
	BOOL	m_sacrament;
	BOOL	m_family;
	BOOL	m_parade;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPreacherDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPreacherDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonMore();
	virtual void OnOK();
	afx_msg void OnCheck7();
	afx_msg void OnCheck8();
	afx_msg void OnCheck9();
	afx_msg void OnCheck1();
	afx_msg void OnCheck4();
	//}}AFX_MSG
	afx_msg LRESULT OnKickIdle(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PREACHERDLG_H__944C6A40_8400_11D5_B658_CD921EB01332__INCLUDED_)
