#if !defined(AFX_SORTPREACHERS_H__3BC9BE60_8C05_11D5_B658_DE0CB4E00532__INCLUDED_)
#define AFX_SORTPREACHERS_H__3BC9BE60_8C05_11D5_B658_DE0CB4E00532__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SortPreachers.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSortPreachers window

class CSortPreachers : public CWnd
{
// Construction
public:
	CSortPreachers();

// Attributes
public:

// Operations
public:
	static int Compare(const void * p1, const void * p2);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSortPreachers)
	//}}AFX_VIRTUAL

// Implementation
public:
	CPlanMakerDoc* pDoc;
	void DoSort();
	virtual ~CSortPreachers();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSortPreachers)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SORTPREACHERS_H__3BC9BE60_8C05_11D5_B658_DE0CB4E00532__INCLUDED_)
