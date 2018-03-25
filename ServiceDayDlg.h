#if !defined(AFX_SERVICEDAYDLG_H__C188D083_86B1_11D5_B658_E32BAA5A7F32__INCLUDED_)
#define AFX_SERVICEDAYDLG_H__C188D083_86B1_11D5_B658_E32BAA5A7F32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ServiceDayDlg.h : header file
//

#include "PlanMakerDoc.h"

/////////////////////////////////////////////////////////////////////////////
// CServiceDayDlg dialog

class CServiceDayDlg : public CDialog
{
// Construction
public:
	struct CALENDAR
	{
		SINFO row0Info;
		int nCol;
	};
	int nOldCols;
	CPlanMakerDoc* pDoc;
	static int Compare(const void *p1, const void *p2);
	CServiceDayDlg(CWnd* pParent = NULL);   // standard constructor
	int nItems;
	_SYSTEMTIME date;

// Dialog Data
	//{{AFX_DATA(CServiceDayDlg)
	enum { IDD = IDD_SERVICEDAYDLG };
	CEdit	m_edit1;
	CButton	m_delete;
	CListBox	m_listctrl;
	CMonthCalCtrl	m_datectrl;
	CTime	m_date;
	CString	m_note;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServiceDayDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CServiceDayDlg)
	afx_msg void OnSelectMonthcalendar(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeList1();
	afx_msg void OnAddNote();
	afx_msg void OnDelete();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVICEDAYDLG_H__C188D083_86B1_11D5_B658_E32BAA5A7F32__INCLUDED_)
