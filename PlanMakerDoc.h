// PlanMakerDoc.h : interface of the CPlanMakerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#include <bitset>

#if !defined(AFX_PLANDOC_H__1B862AEA_81E1_11D5_B658_D9FBF4EB1D32__INCLUDED_)
#define AFX_PLANDOC_H__1B862AEA_81E1_11D5_B658_D9FBF4EB1D32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//externals
struct PINFO
{
	CString title;
	CString first_name;
	CString last_name;
	CString address1;
	CString address2;
	CString town;
	CString county;
	CString postcode;
	CString phone;
	CString email;
	CString screen_name;
	CString add_info;
	BOOL ordained;
	BOOL stipend;
	BOOL visitor;
	BOOL on_trial;
	BOOL on_note;
	BOOL reserved;
	BOOL bUsedLastPlan[100];  //archived in bit 4 of prefs
	BOOL authorised[100]; //archived bit 5 prefs
	BOOL family[100];  //archived bit 6 prefs
	BOOL parade[100];  //archived bit 7 prefs
	BOOL one_service;
	BOOL no_consec;
	int nLimit;
	char availability[32];
	char preferences[100];  //archived bits 0-3 prefs, max 15
//following members used by PlanMaker but not archived
	BOOL bDoLabel;
	std::bitset<32> bsAvailFlags[100];
	int nOnPlan;
	int nInRow[100];
	int nToAllocate[100];
};

struct SINFO
{
	BOOL communion;
	BOOL sacrament1; //not used
	BOOL sacrament2; //not used
	BOOL sacrament3; //not used
	BOOL family;
	BOOL parade;
	BOOL baptism;
	BOOL united;
	BOOL no_service;
	BOOL reserved;
//	BOOL allocated;
	char group;
	CString detail;
	CString code;
	CString date;
	CString place_time;
	CString preacher;
//non-archived members
	int nDay;
	int nMonth;
	int nYear;
	int nAvailPrchs;
	CString strChurchCode;
//	CString strChurchCode_tmp;
};

struct LAYSAVAIL
{
	int nRow;
	int nCol;
	int nAvail;
	PINFO* pLay[100];
};


struct LAYSLIST
{
	PINFO* pLay;
	int prefs;
};

class CPlanMakerDoc : public CDocument
{
protected: // create from serialization only
	CPlanMakerDoc();
	DECLARE_DYNCREATE(CPlanMakerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlanMakerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	protected:
	virtual BOOL SaveModified();
	//}}AFX_VIRTUAL

// Implementation
public:
	void CompileDisplayStrings(BOOL bGetAvailPrchs);
	std::bitset<128> bsAllRows;
	std::bitset<128> bsRowsUsed;
	std::bitset<32> bsAllCols;
	std::bitset<32> bsColsUsed;
	CString strPath;
	CString strPathBak;
	CString strPathTmp;
	int GetPreacherAppearances(PINFO* pPInfo, int row, BOOL bUseSInfoBase);
	void DoStatusBar();
	void CreateChurchCodes();
	BOOL RecreateDataFiles();
	void UpdatePlan(BOOL bGetAvailPrchs);
	CString GetCellInfo(int row, int col);
	BOOL bCopyPlan;
	int nPrchDel[4];
	int nPrchIns[12];
	CString codestr[200];
	CString menustr[200];
	int nStartCol;
	CString key[200];
	BOOL bNoLabel;

//functions in doc
	static int CompareLays(const void *p1, const void *p2);
	static int CompareNumAvail(const void *p1, const void *p2);
	static CPlanMakerDoc* GetDoc();
	void DoTempInfo(PINFO* pPSrc, PINFO* pPDest, SINFO* pSSrc, SINFO* pSDest);
	void RemoveNamedPreacher(PINFO *pPInfo, SINFO* pSInfo);
	int GetAvailablePrchs(int nSelRow, int nSelCol, BOOL bOrds);
	void DoServicesPopup(CPoint point);
	void DoCustom(int index);
	BOOL PreacherAppears(PINFO *pPInfo, SINFO *pSInfo);
	CString IntToStr(int value);
	BOOL DoInsert(int nIndex, int nRow, int nCol, BOOL bInsert);
	BOOL AllocateOrd(BOOL bAllocate);
	void AllocateLay();
	void InitAvailability(PINFO* pPBase, SINFO* pSBase, BOOL bOrds);
	void DoAllocate(PINFO* pPBase, SINFO* pSBase, PINFO* pPInfo, int nRow, int nCol);
	CString CopyServiceInfo(int row, int col, BOOL bRtf);
	static int CompareKeys(const void *p1, const void *p2);
	void SortKeys();
	CString GetPreacher(PINFO* pPInfo);
	void Store();
	virtual ~CPlanMakerDoc();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPlanMakerDoc)
	afx_msg void OnFileOptions();
	afx_msg void OnParade();
	afx_msg void OnPreachersClearall();
	afx_msg void OnPreachersResetweightings();
	afx_msg void OnInsert0();
	afx_msg void OnInsert1();
	afx_msg void OnInsert2();
	afx_msg void OnInsert3();
	afx_msg void OnInsert4();
	afx_msg void OnInsert5();
	afx_msg void OnInsert6();
	afx_msg void OnInsert7();
	afx_msg void OnInsert8();
	afx_msg void OnInsert9();
	afx_msg void OnInsert10();
	afx_msg void OnInsert11();
	afx_msg void OnDelete0();
	afx_msg void OnDelete1();
	afx_msg void OnDelete2();
	afx_msg void OnDelete3();
	afx_msg void OnPreacheravail();
	afx_msg void OnPreacherPrefs();
	afx_msg void OnDeleteAll();
	afx_msg void OnPreachersAvailablityfileExport();
	afx_msg void OnPreachersAvailablityfileImport();
	afx_msg void OnPreachersDeallocate();
	afx_msg void OnPreachersResetoptions();
	afx_msg void OnFamily();
	afx_msg void OnInsPreacher();
	afx_msg void OnDetail();
	afx_msg void OnDeldetail();
	afx_msg void OnPreacherdel();
	afx_msg void OnPreacheredit();
	afx_msg void OnPreachernew();
	afx_msg void OnCustom1();
	afx_msg void OnCustom2();
	afx_msg void OnCustom3();
	afx_msg void OnCustom4();
	afx_msg void OnCustom10();
	afx_msg void OnCustom9();
	afx_msg void OnCustom8();
	afx_msg void OnCustom7();
	afx_msg void OnCustom6();
	afx_msg void OnCustom5();
	afx_msg void OnCustom11();
	afx_msg void OnCustom12();
	afx_msg void OnCustom13();
	afx_msg void OnCustom14();
	afx_msg void OnCustom15();
	afx_msg void OnCustom16();
	afx_msg void OnCustom17();
	afx_msg void OnCustom18();
	afx_msg void OnCustom19();
	afx_msg void OnCustom20();
	afx_msg void OnCustom21();
	afx_msg void OnCustom22();
	afx_msg void OnCustom23();
	afx_msg void OnCustom24();
	afx_msg void OnBaptism();
	afx_msg void OnUnited();
	afx_msg void OnReserved();
	afx_msg void OnCommunion();
	afx_msg void OnEditUndo();
	afx_msg void OnEditRedo();
	afx_msg void OnFileSaveAs();
	afx_msg void OnEditCopyKey();
	afx_msg void OnEditCopyPlan();
	afx_msg void OnEditCopyPreachers();
	afx_msg void OnEditCopyVisitors();
	afx_msg void OnEditCopyAnalysis();
	afx_msg void OnFileMakedefault();
	afx_msg void OnAllocate();
	afx_msg void OnFileClose();
	afx_msg void OnFileNew();
	afx_msg void OnFileOpen();
	afx_msg void OnNoservice();
	afx_msg void OnFileSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLANDOC_H__1B862AEA_81E1_11D5_B658_D9FBF4EB1D32__INCLUDED_)
