#if !defined(AFX_ANALYSISCOLUMNVIEW_H__67EA7006_4A98_4984_A819_130ADC28E63E__INCLUDED_)
#define AFX_ANALYSISCOLUMNVIEW_H__67EA7006_4A98_4984_A819_130ADC28E63E__INCLUDED_

#include "AnalysisWnd.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AnalysisColumnView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAnalysisColumnView view

class CAnalysisColumnView : public CScrollView
{
protected:
	CAnalysisColumnView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CAnalysisColumnView)

// Attributes
public:

// Operations
public:
	CAnalysisWnd wnd;
	int nOnPlan[200];
	PINFO* pPrchList[200];
	CFont anFontB;
	CFont anFont;
	int nRowPitch;
	int nPrchsUsed;
	int nGroupsUsed;
	BOOL bGroupUsed[9];

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnalysisColumnView)
	public:
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CAnalysisColumnView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CAnalysisColumnView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANALYSISCOLUMNVIEW_H__67EA7006_4A98_4984_A819_130ADC28E63E__INCLUDED_)
