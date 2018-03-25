#if !defined(AFX_ANALYSISROWVIEW_H__923BBDDF_AAAB_4A8B_BC2D_00B884F28322__INCLUDED_)
#define AFX_ANALYSISROWVIEW_H__923BBDDF_AAAB_4A8B_BC2D_00B884F28322__INCLUDED_

#include "AnalysisWnd.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AnalysisRowView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAnalysisRowView view

class CAnalysisRowView : public CScrollView
{
protected:
	CAnalysisRowView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CAnalysisRowView)

// Attributes
public:

// Operations
public:
	CAnalysisWnd wnd;
	CFont anFont;
	int nColPitch;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnalysisRowView)
	public:
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CAnalysisRowView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CAnalysisRowView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANALYSISROWVIEW_H__923BBDDF_AAAB_4A8B_BC2D_00B884F28322__INCLUDED_)
