#if !defined(AFX_ANALYSISVIEW3_H__441B8D56_52DA_414E_AD35_992148BF1A85__INCLUDED_)
#define AFX_ANALYSISVIEW3_H__441B8D56_52DA_414E_AD35_992148BF1A85__INCLUDED_

#include "AnalysisWnd.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AnalysisView3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAnalysisView view

class CAnalysisView : public CScrollView
{
protected:
	CAnalysisView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CAnalysisView)

// Attributes
public:

// Operations
public:
	PINFO* pPrchList[200];
	CPlanMakerDoc* pDoc;
	CString IntToStr(int value);
	int nOnPlan[200];
	BOOL bGroupUsed[9];
	int nGroupsUsed;
	int nPrchsUsed;
	int nRowPitch;
	int nColPitch;
	CFont anFontB;
	CFont anFont;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnalysisView)
	public:
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CAnalysisView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CAnalysisView)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANALYSISVIEW3_H__441B8D56_52DA_414E_AD35_992148BF1A85__INCLUDED_)
