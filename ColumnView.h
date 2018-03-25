#if !defined(AFX_COLUMNVIEW_H__801791C2_A94A_11D5_B658_847118EA1532__INCLUDED_)
#define AFX_COLUMNVIEW_H__801791C2_A94A_11D5_B658_847118EA1532__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ColumnView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColumnView view

class CColumnView : public CScrollView
{
protected:
	CColumnView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CColumnView)

// Attributes
public:

// Operations
public:
	void RemoveIncompatiblePreachers();
	CPlanMakerDoc* pDoc;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColumnView)
	public:
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CColumnView();
	CFont font;
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CColumnView)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLUMNVIEW_H__801791C2_A94A_11D5_B658_847118EA1532__INCLUDED_)
