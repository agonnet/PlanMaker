#if !defined(AFX_PLACETIMEDLG_H__AE5F9008_882A_11D5_B658_9756C7A23D32__INCLUDED_)
#define AFX_PLACETIMEDLG_H__AE5F9008_882A_11D5_B658_9756C7A23D32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PlaceTimeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPlaceTimeDlg dialog

class CPlaceTimeDlg : public CDialog
{
// Construction
public:
	int m_check;
	CPlanMakerDoc* pDoc;
	CString strPlaceTime;
	CPlaceTimeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPlaceTimeDlg)
	enum { IDD = IDD_PLACETIMEDLG };
	CEdit	m_edit1;
	CButton	m_modify;
	CButton	m_insert;
	CButton	m_delete;
	CString	m_text;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlaceTimeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPlaceTimeDlg)
	virtual BOOL OnInitDialog();
	virtual void OnModify();
	afx_msg void OnChangeEdit1();
	afx_msg void OnDelete();
	afx_msg void OnInsert();
	//}}AFX_MSG
	afx_msg LRESULT OnKickIdle(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLACETIMEDLG_H__AE5F9008_882A_11D5_B658_9756C7A23D32__INCLUDED_)
