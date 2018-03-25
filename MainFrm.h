// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__1B862AE8_81E1_11D5_B658_D9FBF4EB1D32__INCLUDED_)
#define AFX_MAINFRM_H__1B862AE8_81E1_11D5_B658_D9FBF4EB1D32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual CDocument* GetActiveDocument();
	virtual void WinHelp(DWORD dwData, UINT nCmd = HELP_CONTEXT);
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL

// Implementation
public:
	CPlanMakerDoc* pDoc;
	void SetColumn(int col, int ideal, int min);
	void SetRow(int row, int ideal, int min);
	CView* ResetView();
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	CSplitterWnd wndSplitter;
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnUpdateStatus(CCmdUI *pCmdUI);
	afx_msg void OnUpdateServices(CCmdUI *pCmdUI);
	afx_msg void OnUpdateAllocated(CCmdUI *pCmdUI);
	afx_msg void OnUpdateUnallocated(CCmdUI *pCmdUI);
	afx_msg void OnUpdateViewAnalysis(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePreachersClearall(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePreachersResetoptions(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePreachersResetweightings(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePreacheravail(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePreacherdel(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePreacheredit(CCmdUI* pCmdUI);
	afx_msg void OnUpdateAllocate(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditCopyAnalysis(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditCopyKey(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditCopyPlan(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditCopyPreachers(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditCopyVisitors(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditUndo(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditRedo(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileClose(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileMakedefault(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePreachernew(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDelpreacher(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePreachersAvailablityfileExport(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePreachersAvailablityfileImport(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePreachersDeallocate(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePreacherprefs(CCmdUI* pCmdUI);
	afx_msg void OnUpdateInspreacher(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDeldetail(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileSave(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBaptism(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFamily(CCmdUI* pCmdUI);
	afx_msg void OnUpdateParade(CCmdUI* pCmdUI);
	afx_msg void OnUpdateReserved(CCmdUI* pCmdUI);
	afx_msg void OnUpdateUnited(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCommunion(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewAvailablepreachers(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewFitwidth(CCmdUI* pCmdUI);
	afx_msg void OnUpdateViewPreacherrecords(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__1B862AE8_81E1_11D5_B658_D9FBF4EB1D32__INCLUDED_)
