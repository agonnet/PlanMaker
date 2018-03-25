#if !defined(AFX_PRCHPREFSDLG_H__8E1FD9E0_8BF8_11D5_B658_DE0CB4E00532__INCLUDED_)
#define AFX_PRCHPREFSDLG_H__8E1FD9E0_8BF8_11D5_B658_DE0CB4E00532__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PrchPrefsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPrchPrefsDlg dialog

#include "PlanMakerDoc.h"
#include "PlanMakerView.h"	// Added by ClassView


class CPrchPrefsDlg : public CDialog
{
// Construction
public:
	void UpdateList4();
	unsigned int nSelCount;
	BOOL bItemChanged;
	CPlanMakerDoc* pDoc;
	int nListboxRow;
	int nListboxPrch;
	int GetSliderRange(int nSelRow);
	CString IntToStr(int value);
	PINFO* pListboxPrch;

	CPrchPrefsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPrchPrefsDlg)
	enum { IDD = IDD_PRCHPREFSDLG };
	CStatic	m_static9ctrl;
	CButton	m_check3ctrl;
	CButton	m_check2ctrl;
	CButton	m_check1ctrl;
	CListCtrl	m_list4ctrl;
	CListCtrl	m_list1ctrl;
	CSliderCtrl	m_slidctrl;
	CString	m_nLimit;
	int		m_slid;
	int		m_check1;
	int		m_check2;
	int		m_check3;
	CString	m_static9;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrchPrefsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPrchPrefsDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnReleasedcaptureSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	afx_msg void OnCheck3();
	afx_msg void OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemchangedList4(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclickList4(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnCancel();
	//}}AFX_MSG
	afx_msg LRESULT OnKickIdle(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRCHPREFSDLG_H__8E1FD9E0_8BF8_11D5_B658_DE0CB4E00532__INCLUDED_)
