#if !defined(AFX_ROWVIEW_H__801791C4_A94A_11D5_B658_847118EA1532__INCLUDED_)
#define AFX_ROWVIEW_H__801791C4_A94A_11D5_B658_847118EA1532__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RowView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRowView view

class CRowView : public CScrollView
{
protected:
	CRowView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CRowView)

// Attributes
public:
	CPlanMakerDoc* pDoc;

// Operations
public:
	int col_pitch;
	CFont font;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRowView)
	public:
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CRowView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CRowView)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROWVIEW_H__801791C4_A94A_11D5_B658_847118EA1532__INCLUDED_)
