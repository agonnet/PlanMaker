#if !defined(AFX_OPTIONSDLG_H__5A18AB45_03AD_11D6_B658_DC8BB99FAD32__INCLUDED_)
#define AFX_OPTIONSDLG_H__5A18AB45_03AD_11D6_B658_DC8BB99FAD32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OptionsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COptionsDlg dialog

class COptionsDlg : public CDialog
{
// Construction
public:
	CPlanMakerDoc* pDoc;
	COptionsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COptionsDlg)
	enum { IDD = IDD_OPTIONSDLG };
	CButton	m_check12ctrl;
	CButton	m_check6ctrl;
	CButton	m_no_consec_same_ctrl;
	CButton	m_no_double_ctrl;
	BOOL	m_use_all_lay;
	BOOL	m_no_print_year;
	BOOL	m_print_accredited;
	BOOL	m_use_s_for_comm;
	BOOL	m_print_no_service;
	BOOL	m_no_consec_plan;
	BOOL	m_fill_unused;
	BOOL	m_use_all_age;
	BOOL	m_only_once;
	BOOL	m_no_double;
	BOOL	m_no_consec_same;
	BOOL	m_print_no_service_excl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptionsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COptionsDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnCheck12();
	afx_msg void OnCheck6();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIONSDLG_H__5A18AB45_03AD_11D6_B658_DC8BB99FAD32__INCLUDED_)
