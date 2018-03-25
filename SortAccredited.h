#if !defined(AFX_SORTACCREDITED_H__4CC2B1E0_761F_11D6_B658_907ADF235016__INCLUDED_)
#define AFX_SORTACCREDITED_H__4CC2B1E0_761F_11D6_B658_907ADF235016__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SortAccredited.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSortAccredited window

class CSortAccredited : public CWnd
{
// Construction
public:
	CSortAccredited();

// Attributes
public:

// Operations
public:
	static int CSortAccredited::Compare(const void * p1, const void * p2);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSortAccredited)
	//}}AFX_VIRTUAL

// Implementation
public:
	void DoSort();
	virtual ~CSortAccredited();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSortAccredited)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SORTACCREDITED_H__4CC2B1E0_761F_11D6_B658_907ADF235016__INCLUDED_)
