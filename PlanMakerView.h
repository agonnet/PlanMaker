// PlanMakerView.h : interface of the CPlanMakerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLANVIEW_H__1B862AEC_81E1_11D5_B658_D9FBF4EB1D32__INCLUDED_)
#define AFX_PLANVIEW_H__1B862AEC_81E1_11D5_B658_D9FBF4EB1D32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PlanMakerDoc.h"

class CPlanMakerView : public CScrollView
{
//protected: // create from serialization only
public:
	CPlanMakerView();
protected:
	DECLARE_DYNCREATE(CPlanMakerView)

/// Attributes
public:
	CDocument* GetDocument();
//	CPlanMakerDoc* pDoc;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlanMakerView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	PINFO* pLabelsListBase;
	CPlanMakerDoc* pDoc;
	CRect GetRectFromMouse(CPoint point);
	CRect GetRectFromCell(int row, int col);
	void DoPrintLabels(CDC* pDC, CPrintInfo* pInfo);
	PINFO* pPrchList[200];
	int nOnPlan[200];
	BOOL bGroupUsed[9];
	int nPrchsUsed;
	int nGroupsUsed;
	void DoPrintAnalysis(CDC* pDC, CPrintInfo* pInfo);
	void DoPrintPlan(CDC* pDC, CPrintInfo* pInfo);
	HINSTANCE hRecords;
	CFont font; //fonts for diaplay
	CFont fontb;
	CFont fonti;
	int nCol;
	int nStartPos[10];
	int nLength[10];
	int col_pitch; //printing
	int row_pitch;
	BOOL bPrintLabels;
	BOOL bPrintAnalysis;
	int nPages;
	int nToPrint;
	int nLabelRectLeft;
	int nPrintRectLeft;
	int nLabelRectTop;
	int nPrintRectTop;
	int nRowsPerPage;
	int nColsPerPage;
	int nWidth;
	int nHorzPages;
	int nVertPages;
	int nFirstRow;
	int nFirstCol;
	int nColDown, nColDown0, nColDown1;
	int nRowDown, nRowDown0, nRowDown1;
	CFrameWnd* pWndAnalysis;
	int nPrintFirstPage;
	BOOL bInvalidGroup[9];
	PINFO* pPageStartPrch[10];
	PINFO* pLastPrchPrinted;
	CFont labFont; //fonts for printing
	CFont anFont;
	CFont planFont;
	CString IntToStr(int value);
	float fCol;

	virtual ~CPlanMakerView();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPlanMakerView)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnFilePrintLabels();
	afx_msg void OnFilePrintPlan();
	afx_msg void OnFilePrintpreviewLabels();
	afx_msg void OnFilePrintpreviewPlan();
	afx_msg void OnFilePrintpreviewAnalysis();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnFilePrintsetupFont();
	afx_msg void OnFilePrintAnalysis();
	afx_msg void OnViewAnalysis();
	afx_msg void OnViewFitwidth();
	afx_msg void OnViewAvaliablepreachers();
	afx_msg void OnViewPreacherrecords();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PlanMakerView.cpp
inline CDocument* CPlanMakerView::GetDocument()
   { return (CDocument*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLANVIEW_H__1B862AEC_81E1_11D5_B658_D9FBF4EB1D32__INCLUDED_)
