#if !defined(AFX_ANALYSISWND_H__887D39C2_F45D_4B3D_8F00_5CC1909BB8C4__INCLUDED_)
#define AFX_ANALYSISWND_H__887D39C2_F45D_4B3D_8F00_5CC1909BB8C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AnalysisWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAnalysisWnd frame

class CAnalysisWnd : public CFrameWnd
{
	DECLARE_DYNCREATE(CAnalysisWnd)
public:
//protected:
	CAnalysisWnd();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:
	CSplitterWnd wndSplitter;
	virtual ~CAnalysisWnd();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnalysisWnd)
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL

// Implementation
//protected:

	// Generated message map functions
	//{{AFX_MSG(CAnalysisWnd)
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANALYSISWND_H__887D39C2_F45D_4B3D_8F00_5CC1909BB8C4__INCLUDED_)
