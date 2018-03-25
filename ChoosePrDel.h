#if !defined(AFX_CHOOSEPRDEL_H__6CE7A380_85C1_11D5_B658_934A05578032__INCLUDED_)
#define AFX_CHOOSEPRDEL_H__6CE7A380_85C1_11D5_B658_934A05578032__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChoosePrDel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChoosePrDel dialog

class CChoosePrDel : public CDialog
{
// Construction
public:
	CPlanMakerDoc* pDoc;
	CChoosePrDel(CWnd* pParent = NULL);   // standard constructor
	int nSelPrch;

// Dialog Data
	//{{AFX_DATA(CChoosePrDel)
	enum { IDD = IDD_CHOOSEPRDEL };
	CListCtrl	m_list1ctrl;
	CButton	m_delete;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChoosePrDel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChoosePrDel)
	virtual BOOL OnInitDialog();
	afx_msg void OnDelete();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHOOSEPRDEL_H__6CE7A380_85C1_11D5_B658_934A05578032__INCLUDED_)
