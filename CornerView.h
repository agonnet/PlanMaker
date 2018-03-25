#if !defined(AFX_CORNERVIEW_H__E4E000A0_A9C3_11D5_B658_CD54B3CE1832__INCLUDED_)
#define AFX_CORNERVIEW_H__E4E000A0_A9C3_11D5_B658_CD54B3CE1832__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CornerView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCornerView view

class CCornerView : public CView
{
protected:
	CCornerView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CCornerView)

// Attributes
public:

// Operations
public:
	void ResetView();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCornerView)
	public:
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCornerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CCornerView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CORNERVIEW_H__E4E000A0_A9C3_11D5_B658_CD54B3CE1832__INCLUDED_)
