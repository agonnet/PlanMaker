// PlanMaker.h : main header file for the PLAN application
//

#if !defined(AFX_PLANMAKER_H__1B862AE4_81E1_11D5_B658_D9FBF4EB1D32__INCLUDED_)
#define AFX_PLANMAKER_H__1B862AE4_81E1_11D5_B658_D9FBF4EB1D32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "PlanMakerDoc.h"	// Added by ClassView

/////////////////////////////////////////////////////////////////////////////
// CPlanMakerApp:
// See PlanMaker.cpp for the implementation of this class
//

class CPlanMakerApp : public CWinApp
{
public:
	void Resync();
	CPlanMakerDoc* pDoc;
	void SetPortrait();
	void SetLandscape();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CPlanMakerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlanMakerApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL OnIdle(LONG lCount);
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPlanMakerApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAN_H__1B862AE4_81E1_11D5_B658_D9FBF4EB1D32__INCLUDED_)
