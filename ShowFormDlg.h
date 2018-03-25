#if !defined(AFX_SHOWFORMDLG_H__15888E61_F5A3_4FB2_9ABE_E42FE9FDDD73__INCLUDED_)
#define AFX_SHOWFORMDLG_H__15888E61_F5A3_4FB2_9ABE_E42FE9FDDD73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShowFormDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CShowFormDlg dialog

class CShowFormDlg : public CDialog
{
// Construction
public:
public:
	void DoCheckboxes();
	int nDates;
	BOOL ParseIniFile();
	CButton* pCheckBase;
	CButton* pCheck;
	CButton* pButtonBase;
	CButton* pButton;
	CStatic* pDateBase;
	CStatic* pDate;
	CFont* pFont;
	CStatic* pStaticBase;
	CStatic* pStatic;
	CString date[30];
	char availability[30];

	CShowFormDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CShowFormDlg)
	enum { IDD = IDD_SHOWFORMDLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowFormDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CShowFormDlg)
	virtual void OnCancel();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWFORMDLG_H__15888E61_F5A3_4FB2_9ABE_E42FE9FDDD73__INCLUDED_)
