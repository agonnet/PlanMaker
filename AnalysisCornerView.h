#if !defined(AFX_ANALYSISCORNERVIEW_H__04374CC2_4540_4A1A_9BB8_09EB779D3601__INCLUDED_)
#define AFX_ANALYSISCORNERVIEW_H__04374CC2_4540_4A1A_9BB8_09EB779D3601__INCLUDED_

#include "AnalysisWnd.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AnalysisCornerView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAnalysisCornerView view

class CAnalysisCornerView : public CScrollView
{
protected:
	CAnalysisCornerView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CAnalysisCornerView)

// Attributes
public:
//	CSize sizeTotal;

// Operations
public:
	CAnalysisWnd wnd;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnalysisCornerView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CAnalysisCornerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CAnalysisCornerView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANALYSISCORNERVIEW_H__04374CC2_4540_4A1A_9BB8_09EB779D3601__INCLUDED_)
