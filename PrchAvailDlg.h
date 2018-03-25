#if !defined(AFX_PRCHAVAILDLG_H__8E1FD9E0_8BF8_11D5_B658_DE0CB4E00532__INCLUDED_)
#define AFX_PrchAvailDlg_H__8E1FD9E0_8BF8_11D5_B658_DE0CB4E00532__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PrchAvailDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPrchAvailDlg dialog

#include "PlanMakerDoc.h"
#include "PlanMakerView.h"	// Added by ClassView


class CPrchAvailDlg : public CDialog
{
// Construction
public:
	void UpdateList2();
	unsigned int nSelCount;
	BOOL bItemChanged;
	CPlanMakerDoc* pDoc;
	void DoAvailability(int nID, BOOL bMakeAvailable);
	int nListboxPrch;
	CString IntToStr(int value);
	PINFO* pListboxPrch;

	CPrchAvailDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPrchAvailDlg)
	enum { IDD = IDD_PRCHAVAILDLG };
	CButton	m_check9ctrl;
	CButton	m_check8ctrl;
	CButton	m_check7ctrl;
	CButton	m_check6ctrl;
	CStatic	m_static7ctrl;
	CButton	m_check5ctrl;
	CButton	m_check4ctrl;
	CListCtrl	m_list1ctrl;
	CListCtrl	m_list2ctrl;
	CComboBox	m_comboctrl;
	CString	m_nLimit;
	BOOL	m_check4;
	BOOL	m_check5;
	BOOL	m_check6;
	BOOL	m_check7;
	BOOL	m_check8;
	BOOL	m_check9;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrchAvailDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPrchAvailDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnCheck6();
	afx_msg void OnCheck7();
	afx_msg void OnCheck8();
	afx_msg void OnCheck9();
	afx_msg void OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCheck4();
	afx_msg void OnCheck5();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnCancel();
	//}}AFX_MSG
	afx_msg LRESULT OnKickIdle(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRCHAVAILDLG_H__8E1FD9E0_8BF8_11D5_B658_DE0CB4E00532__INCLUDED_)
