#if !defined(AFX_EDITPREACHERDLG_H__A4E14144_8519_11D5_B658_E7252D151A32__INCLUDED_)
#include "PlanMakerView.h"	// Added by ClassView
#define AFX_EDITPREACHER_H__A4E14144_8519_11D5_B658_E7252D151A32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditPreacher.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditPreacher dialog

class CEditPreacherDlg : public CDialog
{
// Construction
public:
	BOOL bUserCheck7;
	BOOL bUserCheck8;
	BOOL bUserCheck9;
	CPlanMakerDoc* pDoc;
	void GetCurrentData();
	int nEditPrch;
	void SetupDlg();
	BOOL ValidateEditedPr();
	CEditPreacherDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditPreacherDlg)
	enum { IDD = IDD_EDITPREACHERDLG };
	CButton	m_paradectrl;
	CButton	m_familyctrl;
	CButton	m_sacramentctrl;
	CButton	m_onnotectrl;
	CButton	m_reservedctrl;
	CButton	m_visitorctrl;
	CButton	m_ontrialctrl;
	CButton	m_ordainedctrl;
	CButton	m_stipendctrl;
	CButton	m_ok;
	CButton	m_previous;
	CButton	m_next;
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
	CString	m_title;
	BOOL	m_ordained;
	BOOL	m_stipend;
	BOOL	m_visitor;
	BOOL	m_reserved;
	BOOL	m_onnote;
	BOOL	m_ontrial;
	CString	m_additional;
	BOOL	m_sacrament;
	BOOL	m_family;
	BOOL	m_parade;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditPreacherDlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditPreacherDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnNext();
	afx_msg void OnPrevious();
	afx_msg void OnCheck7();
	afx_msg void OnCheck8();
	afx_msg void OnCheck9();
	//}}AFX_MSG
	afx_msg LRESULT OnKickIdle(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITPREACHERDLG_H__A4E14144_8519_11D5_B658_E7252D151A32__INCLUDED_)
