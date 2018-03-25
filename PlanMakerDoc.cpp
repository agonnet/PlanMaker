// PlanMakerDoc.cpp : implementation of the CPlanMakerDoc class
//

#include "stdafx.h"
#include "PlanMaker.h"
#include "PreacherDlg.h"
#include "PlanMakerDoc.h"
#include "SortPreachers.h"
#include "SortAccredited.h"
#include "LabelDlg.h"
#include "PlanMakerView.h"
#include "PrchAvailDlg.h"
#include "InsertDlg.h"
#include "DetailDlg.h"
#include "ChoosePrDel.h"
#include "ChooseEditDlg.h"
#include "EditPreacherDlg.h"
#include "PrchPrefsDlg.h"
#include "OptionsDlg.h"
#include "ImportDlg.h"
#include "ShowFormDlg.h"
#include "MainFrm.h"
#include "afxinet.h"
#include "randomc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlanMakerDoc

IMPLEMENT_DYNCREATE(CPlanMakerDoc, CDocument)

BEGIN_MESSAGE_MAP(CPlanMakerDoc, CDocument)
	//{{AFX_MSG_MAP(CPlanMakerDoc)
	ON_COMMAND(ID_FILE_OPTIONS, OnFileOptions)
	ON_COMMAND(ID_PARADE, OnParade)
	ON_COMMAND(ID_PREACHERS_CLEARALL, OnPreachersClearall)
	ON_COMMAND(ID_PREACHERS_RESETWEIGHTINGS, OnPreachersResetweightings)
	ON_COMMAND(ID_INSERT0, OnInsert0)
	ON_COMMAND(ID_INSERT1, OnInsert1)
	ON_COMMAND(ID_INSERT2, OnInsert2)
	ON_COMMAND(ID_INSERT3, OnInsert3)
	ON_COMMAND(ID_INSERT4, OnInsert4)
	ON_COMMAND(ID_INSERT5, OnInsert5)
	ON_COMMAND(ID_INSERT6, OnInsert6)
	ON_COMMAND(ID_INSERT7, OnInsert7)
	ON_COMMAND(ID_INSERT8, OnInsert8)
	ON_COMMAND(ID_INSERT9, OnInsert9)
	ON_COMMAND(ID_INSERT10, OnInsert10)
	ON_COMMAND(ID_INSERT11, OnInsert11)
	ON_COMMAND(ID_DELETE0, OnDelete0)
	ON_COMMAND(ID_DELETE1, OnDelete1)
	ON_COMMAND(ID_DELETE2, OnDelete2)
	ON_COMMAND(ID_DELETE3, OnDelete3)
	ON_COMMAND(ID_PREACHERAVAIL, OnPreacheravail)
	ON_COMMAND(ID_PREACHERPREFS, OnPreacherPrefs)
	ON_COMMAND(ID_DELPREACHER, OnDeleteAll)
	ON_COMMAND(ID_PREACHERS_AVAILABLITYFILE_EXPORT, OnPreachersAvailablityfileExport)
	ON_COMMAND(ID_PREACHERS_AVAILABLITYFILE_IMPORT, OnPreachersAvailablityfileImport)
	ON_COMMAND(ID_PREACHERS_DEALLOCATE, OnPreachersDeallocate)
	ON_COMMAND(ID_PREACHERS_RESETOPTIONS, OnPreachersResetoptions)
	ON_COMMAND(ID_FAMILY, OnFamily)
	ON_COMMAND(ID_INSPREACHER, OnInsPreacher)
	ON_COMMAND(ID_DETAIL, OnDetail)
	ON_COMMAND(ID_DELDETAIL, OnDeldetail)
	ON_COMMAND(ID_PREACHERDEL, OnPreacherdel)
	ON_COMMAND(ID_PREACHEREDIT, OnPreacheredit)
	ON_COMMAND(ID_PREACHERNEW, OnPreachernew)
	ON_COMMAND(ID_CUSTOM1, OnCustom1)
	ON_COMMAND(ID_CUSTOM2, OnCustom2)
	ON_COMMAND(ID_CUSTOM3, OnCustom3)
	ON_COMMAND(ID_CUSTOM4, OnCustom4)
	ON_COMMAND(ID_CUSTOM10, OnCustom10)
	ON_COMMAND(ID_CUSTOM9, OnCustom9)
	ON_COMMAND(ID_CUSTOM8, OnCustom8)
	ON_COMMAND(ID_CUSTOM7, OnCustom7)
	ON_COMMAND(ID_CUSTOM6, OnCustom6)
	ON_COMMAND(ID_CUSTOM5, OnCustom5)
	ON_COMMAND(ID_CUSTOM11, OnCustom11)
	ON_COMMAND(ID_CUSTOM12, OnCustom12)
	ON_COMMAND(ID_CUSTOM13, OnCustom13)
	ON_COMMAND(ID_CUSTOM14, OnCustom14)
	ON_COMMAND(ID_CUSTOM15, OnCustom15)
	ON_COMMAND(ID_CUSTOM16, OnCustom16)
	ON_COMMAND(ID_CUSTOM17, OnCustom17)
	ON_COMMAND(ID_CUSTOM18, OnCustom18)
	ON_COMMAND(ID_CUSTOM19, OnCustom19)
	ON_COMMAND(ID_CUSTOM20, OnCustom20)
	ON_COMMAND(ID_CUSTOM21, OnCustom21)
	ON_COMMAND(ID_CUSTOM22, OnCustom22)
	ON_COMMAND(ID_CUSTOM23, OnCustom23)
	ON_COMMAND(ID_CUSTOM24, OnCustom24)
	ON_COMMAND(ID_BAPTISM, OnBaptism)
	ON_COMMAND(ID_UNITED, OnUnited)
	ON_COMMAND(ID_RESERVED, OnReserved)
	ON_COMMAND(ID_COMMUNION, OnCommunion)
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	ON_COMMAND(ID_EDIT_REDO, OnEditRedo)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_COMMAND(ID_EDIT_COPY_KEY, OnEditCopyKey)
	ON_COMMAND(ID_EDIT_COPY_PLAN, OnEditCopyPlan)
	ON_COMMAND(ID_EDIT_COPY_PREACHERS, OnEditCopyPreachers)
	ON_COMMAND(ID_EDIT_COPY_VISITORS, OnEditCopyVisitors)
	ON_COMMAND(ID_EDIT_COPY_ANALYSIS, OnEditCopyAnalysis)
	ON_COMMAND(ID_FILE_MAKEDEFAULT, OnFileMakedefault)
	ON_COMMAND(ID_ALLOCATE, OnAllocate)
	ON_COMMAND(ID_FILE_CLOSE, OnFileClose)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_NOSERVICE, OnNoservice)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_CUSTOM1, OnCustom1)
	ON_COMMAND(ID_CUSTOM2, OnCustom2)
	ON_COMMAND(ID_CUSTOM3, OnCustom3)
	ON_COMMAND(ID_CUSTOM4, OnCustom4)
	ON_COMMAND(ID_CUSTOM10, OnCustom10)
	ON_COMMAND(ID_CUSTOM9, OnCustom9)
	ON_COMMAND(ID_CUSTOM8, OnCustom8)
	ON_COMMAND(ID_CUSTOM7, OnCustom7)
	ON_COMMAND(ID_CUSTOM6, OnCustom6)
	ON_COMMAND(ID_CUSTOM5, OnCustom5)
	ON_COMMAND(ID_CUSTOM11, OnCustom11)
	ON_COMMAND(ID_CUSTOM12, OnCustom12)
	ON_COMMAND(ID_CUSTOM13, OnCustom13)
	ON_COMMAND(ID_CUSTOM14, OnCustom14)
	ON_COMMAND(ID_CUSTOM15, OnCustom15)
	ON_COMMAND(ID_CUSTOM16, OnCustom16)
	ON_COMMAND(ID_CUSTOM17, OnCustom17)
	ON_COMMAND(ID_CUSTOM18, OnCustom18)
	ON_COMMAND(ID_CUSTOM19, OnCustom19)
	ON_COMMAND(ID_CUSTOM20, OnCustom20)
	ON_COMMAND(ID_CUSTOM21, OnCustom21)
	ON_COMMAND(ID_CUSTOM22, OnCustom22)
	ON_COMMAND(ID_CUSTOM23, OnCustom23)
	ON_COMMAND(ID_CUSTOM24, OnCustom24)
	ON_COMMAND(ID_COMMUNION, OnCommunion)
	ON_COMMAND(ID_BAPTISM, OnBaptism)
	ON_COMMAND(ID_UNITED, OnUnited)
	ON_COMMAND(ID_RESERVED, OnReserved)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlanMakerDoc construction/destruction
//globals
PINFO* pPInfoBase;
PINFO* pPInfo1Base;
SINFO* pSInfoBase;
SINFO* pSInfo1Base;
PINFO* pPTmpInfoBase;
SINFO* pSTmpInfoBase;
PINFO* pAvailPrchs;
int rows;
int cols;
int nPreachers;
BOOL bSelected[100][32];
int nDay[32];
int nMonth[32];
int nYear[32];
CString filename;
int nSelRow;
int nSelCol;
int nSelPrch;
CString strDetails[100][32];
CString strAvailPrchs[100][32];
int left, right, top, bottom;
BOOL bEnableUndo;
LPLOGFONT lpFont;
BOOL bAllocationDone;
BOOL bOnlyOnce;
BOOL bEnableRedo;
BOOL bUseAllLay;
BOOL bNoConsecSame;
BOOL bNoConsecPlan;
BOOL bNoPrintYear;
BOOL bPrintNoService;
BOOL bPrintNoServiceExcl;
BOOL bPrintAccredited;
BOOL bUseSforComm;
BOOL bUseAllAge;
BOOL bNoDouble;
BOOL bFillUnused;
COLORREF crPlanFontColor;
BOOL bPrintPlan;
int nAvailPrchIndex[64];
int nTotalServices;
int nServicesAllocated;
BOOL bPlanResized;
int nUnallocReserved;
BOOL bAllocPending;
BOOL bFitWidth;
BOOL bShowAvailPrchs;
int nSelected;
int nNoService;
CString strPathDat;

//globals declared in labeldlg.cpp
extern CString _across;
extern CString _down;
extern CString _left;
extern CString _top;
extern CString _hoff;
extern CString _voff;
extern CString _font;
extern int nLocalLabel;
extern int nVisitorLabel;

//globals declared in planmakerview.cpp
extern BOOL bViewingAnalysis;

CPlanMakerDoc::CPlanMakerDoc()
{
	pPInfoBase = new PINFO[200];
	pPInfo1Base = new PINFO[200];
	pPTmpInfoBase = new PINFO[200];
	pSInfoBase = new SINFO[100 * 32];
	pSInfo1Base = new SINFO[100 * 32];
	pSTmpInfoBase = new SINFO[100 * 32];
	lpFont = new LOGFONT; //font for printing plan

	bViewingAnalysis = false;
}

CPlanMakerDoc::~CPlanMakerDoc()
{
	if (filename == "" && GetFileAttributes(strPathDat) != -1) //if using plan.dat check it exists
		Store();
	delete [] pPInfoBase;
	delete [] pPInfo1Base;
	delete [] pPTmpInfoBase;
	delete [] pSInfoBase;
	delete [] pSInfo1Base;
	delete [] pSTmpInfoBase;
	delete lpFont;
}

BOOL CPlanMakerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	ITEMIDLIST idl;
	LPITEMIDLIST pidl = &idl;
	SHGetSpecialFolderLocation(NULL, CSIDL_PERSONAL, &pidl);
	char buffer[MAX_PATH] = {0};
	SHGetPathFromIDList(pidl, buffer);
	strPath = CString(buffer) + "\\Planmaker";
	strPathDat = strPath + "\\plan.dat";
	strPathBak = strPath + "\\plan.bak";
	strPathTmp = strPath + "\\plan.tmp";
	
	CFile file;
	if (GetFileAttributes(strPath) == -1) //if ...\My Documents\Planmaker folder doesn't exist
	{
		if (GetFileAttributes("c:\\planmaker") == -1) //if c:\planmaker doesn't exist
		{
			if (!RecreateDataFiles())
				return false;
		}
		else //c:\planmaker exists - copy to My Documents
		{
			MessageBox(NULL, "PlanMaker is going to attempt to copy your Planmaker folder from the root of your c: drive to your Documents Folder, but the original folder will remain intact. Click OK to continue.", "PlanMaker", MB_OK | MB_ICONINFORMATION);
			SHFILEOPSTRUCT s = {0};
			s.hwnd = NULL;
			s.wFunc = FO_COPY;
			char szDest[MAX_PATH] = {0};
			strcpy(szDest, strPath);
			char szSrc[MAX_PATH] = {0};
			strcpy(szSrc, "c:\\planmaker");
			s.pTo = szDest;
			s.pFrom = szSrc;
			s.fFlags = FOF_SILENT | FOF_NOCONFIRMMKDIR;
			if (SHFileOperation(&s) != 0) //copy operation failed
			{
				MessageBox(NULL, "The copy operation failed: please copy the folder manually. If you do not do this, PlanMaker will still work, but you will see this message and the previous one every time you start it.", "PlanMaker", MB_OK | MB_ICONEXCLAMATION);
				strPath = "c:\\planmaker";
				strPathDat = "c:\\planmaker\\plan.dat";
				strPathBak = "c:\\planmaker\\plan.bak";
				strPathTmp = "c:\\planmaker\\plan.tmp";
			}
			else
				MessageBox(NULL, "The copy operation succeeded and the path for your data files is now:\n\n" + strPath + "\n\nYou will not see these messages again, and you can delete the original c:\\Planmaker folder if you wish. Click OK to start PlanMaker.", "PlanMaker", MB_OK | MB_ICONINFORMATION);
		}
	}

	if (file.Open(strPathDat, CFile::modeRead))
	{
		CArchive ar(&file, CArchive::load);
		Serialize(ar);
		ar.Close();
		file.Close();
	}
	else if (file.Open(strPathBak, CFile::modeRead))
	{
		CArchive ar(&file, CArchive::load);
		Serialize(ar);
		ar.Close();
		file.Close();
		CopyFile(strPathBak, strPathDat, false);
	}
	else if (!RecreateDataFiles())
		return false;

	filename = "";
	bEnableUndo = false;
	bEnableRedo = false;
	bShowAvailPrchs = false;
	DoTempInfo(pPInfo1Base, pPInfoBase, pSInfo1Base, pSInfoBase); //info1 to info
	bPlanResized = true;
	UpdatePlan(false);
	
	return true;
}

/////////////////////////////////////////////////////////////////////////////
// CPlanMakerDoc serialization

void CPlanMakerDoc::Serialize(CArchive& ar)
{
//store from info, load to info1
	unsigned char buf[32] ={0};
	if (ar.IsStoring())
	{
//storing code
			ar << rows;
			ar << cols;
			ar << nPreachers;
//label printing
			ar << _across;  
			ar << _down;
			ar << _hoff;
			ar << _voff;
			ar << _left;
			ar << _top;
			ar << _font;
//attributes
			buf[0] = bOnlyOnce;
			buf[0] |= bUseAllAge << 1;
			buf[0] |= bFillUnused << 2;
			buf[0] |= bNoDouble << 3;
			buf[0] |= bNoConsecPlan << 4;
			buf[0] |= bPrintNoService << 5;
			buf[0] |= bNoPrintYear << 6;
			buf[0] |= bUseAllLay << 7;

			buf[1] = bNoLabel;
			buf[1] |= nLocalLabel << 1;
			buf[1] |= nVisitorLabel << 3;
			buf[1] |= bNoConsecSame << 5;
			buf[1] |= bAllocationDone << 6;
			buf[1] |= bPrintAccredited << 7;

			buf[2] = bUseSforComm;
			buf[2] |= bPrintNoServiceExcl << 1;
			buf[2] |= bAllocPending << 2;
			buf[2] |= bFitWidth << 3;

			buf[3] = 0;
			buf[4] = 0;
			buf[5] = 0;
			buf[6] = 0;
			buf[7] = 0;

			ar.Write(buf, 8);
//printer font info
			for (int i = 0; i < 32; i++)
				ar << lpFont->lfFaceName[i];
			ar << lpFont->lfCharSet;
			ar << lpFont->lfClipPrecision;
			ar << lpFont->lfEscapement;
			ar << lpFont->lfHeight;
			ar << lpFont->lfItalic;
			ar << lpFont->lfOrientation;
			ar << lpFont->lfOutPrecision;
			ar << lpFont->lfPitchAndFamily;
			ar << lpFont->lfQuality;
			ar << lpFont->lfStrikeOut;
			ar << lpFont->lfUnderline;
			ar << lpFont->lfWeight;
			ar << lpFont->lfWidth;
			ar << crPlanFontColor;
//preacher information
		PINFO* pPInfo = pPInfoBase;
		for (int prch = 0; prch < nPreachers; prch++)
		{
			ar << pPInfo->title;
			ar << pPInfo->first_name;
			ar << pPInfo->last_name;
			ar << pPInfo->address1;
			ar << pPInfo->address2;
			ar << pPInfo->town;
			ar << pPInfo->county;
			ar << pPInfo->postcode;
			ar << pPInfo->phone;
			ar << pPInfo->email;
			ar << pPInfo->screen_name;
			ar << pPInfo->add_info;
			buf[0] = pPInfo->ordained;
			ar.Write(buf, 1);
			buf[0] = pPInfo->stipend;
			ar.Write(buf, 1);
			buf[0] = pPInfo->on_trial;
			ar.Write(buf, 1);
			buf[0] = pPInfo->on_note;
			ar.Write(buf, 1);
			buf[0] = pPInfo->visitor;
			ar.Write(buf, 1);
			buf[0] = pPInfo->reserved;
			ar.Write(buf, 1);
			buf[0] = pPInfo->one_service;
			ar.Write(buf, 1);
			buf[0] = pPInfo->no_consec;
			ar.Write(buf, 1);
			ar << pPInfo->nLimit;
			for (int col = 1; col < cols; col++)
			{
				buf[0] = pPInfo->availability[col];
				ar.Write(buf, 1);
			}
//authorisation, family, parade & where used in last plan
//are flagged with the preferences
			for (int row = 1; row < rows - 1; row++)
			{
				buf[0] = pPInfo->preferences[row]; //bits 0 to 3
				if (pPInfo->bUsedLastPlan[row])
					buf[0] |= 0x10;  //bit 4
				if (pPInfo->authorised[row])
					buf[0] |= 0x20;  //bit 5
				if (pPInfo->family[row])
					buf[0] |= 0x40;  //bit 6
				if (pPInfo->parade[row])
					buf[0] |= 0x80;  //bit 7
				ar.Write(buf, 1);
			}
			pPInfo++;
		}
//places and times
		SINFO* pSInfo = pSInfoBase + 32;  //row 1 col 0
		for (int row = 1; row < rows - 1; row++)
		{
			ar << pSInfo->place_time;
			ar << pSInfo->preacher;
			buf[0] = pSInfo->group;
			ar.Write(buf, 1);
			pSInfo += 32;
		}
//dates
		pSInfo = pSInfoBase + 1;  //row 0 col 1
		for (int col = 1; col < cols; col++)
		{
			ar << pSInfo->date;
			ar << nDay[col];
			ar << nMonth[col];
			ar << nYear[col];
			pSInfo++;
		}
//service info
		SINFO* pRow = pSInfoBase + 32;
		for (row = 1; row < rows - 1; row++)
		{
			SINFO* pSInfo = pRow + 1;
			for (int col = 1; col < cols; col++)
			{
				buf[0] = (char)row;  //this and next only for analysing file
				ar.Write(buf, 1);  //each service has its row & col before
				buf[0] = (char)col;  //it in the file - discarded on loading
				ar.Write(buf, 1);
				buf[0] = pSInfo->communion;
				buf[1] = 0; //pSInfo->sacrament1;
				buf[2] = 0; //pSInfo->sacrament2;
				buf[3] = 0; //pSInfo->sacrament3;
				buf[4] = pSInfo->family;
				buf[5] = pSInfo->parade;
				buf[6] = pSInfo->baptism;
				buf[7] = pSInfo->united;
				buf[8] = pSInfo->no_service;
				buf[9] = pSInfo->reserved;
				buf[10] = 0;
				ar.Write(buf, 11);
				ar << pSInfo->preacher;
				ar << pSInfo->detail;
				ar << pSInfo->code;
				pSInfo++;
			}
			pRow += 32;
		}
	}
	else
	{
//loading code
		ar >> rows;
		ar >> cols;
		ar >> nPreachers;
		ar >> _across;
		ar >> _down;
		ar >> _hoff;
		ar >> _voff;
		ar >> _left;
		ar >> _top;
		ar >> _font;
//attributes
		ar.Read(buf, 8);
		bOnlyOnce = (buf[0] & 0x01) ? true:false;  //bit 0
		bUseAllAge = (buf[0] & 0x02) ? true:false;  //bit 1
		bFillUnused = (buf[0] & 0x04) ? true:false;  //bit 2
		bNoDouble = (buf[0] & 0x08) ? true:false;  //bit 3
		bNoConsecPlan = (buf[0] & 0x10) ? true:false;  //bit 4
		bPrintNoService = (buf[0] & 0x20) ? true:false;  //bit 5
		bNoPrintYear = (buf[0] & 0x40) ? true:false;  //bit 6
		bUseAllLay = (buf[0])& 0x80 ? true:false;  //bit 7

		bNoLabel = (buf[1] & 0x01) ? true:false; //bit 0
		nLocalLabel = (buf[1] & 0x06) >> 2; //bits 1 & 2
		nVisitorLabel = (buf[1] & 0x18) >> 4; //3 & 4
		bNoConsecSame = (buf[1]) & 0x20 ? true:false;  //bit 5
		bAllocationDone = (buf[1]) & 0x40 ? true:false;  //bit6
		bPrintAccredited = (buf[1]) & 0x80 ? true:false;  //bit 7

		bUseSforComm = (buf[2]) & 0x01 ? true:false;
		bPrintNoServiceExcl = (buf[2] & 0x02) ? true : false;
		bAllocPending = (buf[2] & 0x04) ? true : false;
		bFitWidth = (buf[2] & 0x08) ? true : false;

//printer font
		ar.Read(buf, 32);
		for (int i = 0; i < 32; i++)
			lpFont->lfFaceName[i] = buf[i];
		ar >> lpFont->lfCharSet;
		ar >> lpFont->lfClipPrecision;
		ar >> lpFont->lfEscapement;
		ar >> lpFont->lfHeight;
		ar >> lpFont->lfItalic;
		ar >> lpFont->lfOrientation;
		ar >> lpFont->lfOutPrecision;
		ar >> lpFont->lfPitchAndFamily;
		ar >> lpFont->lfQuality;
		ar >> lpFont->lfStrikeOut;
		ar >> lpFont->lfUnderline;
		ar >> lpFont->lfWeight;
		ar >> lpFont->lfWidth;
		ar >> crPlanFontColor;
//preacher info
		PINFO* pPInfo = pPInfo1Base;
		for (int prch = 0; prch < nPreachers; prch++)
		{
			ar >> pPInfo->title;
			ar >> pPInfo->first_name;
			ar >> pPInfo->last_name;
			ar >> pPInfo->address1;
			ar >> pPInfo->address2;
			ar >> pPInfo->town;
			ar >> pPInfo->county;
			ar >> pPInfo->postcode;
			ar >> pPInfo->phone;
			ar >> pPInfo->email;
			ar >> pPInfo->screen_name;
			ar >> pPInfo->add_info;
			ar.Read(buf, 1);
			pPInfo->ordained = (buf[0]) ? true:false;
			ar.Read(buf, 1);
			pPInfo->stipend = (buf[0]) ? true:false;
			ar.Read(buf, 1);
			pPInfo->on_trial = (buf[0]) ? true:false;
			ar.Read(buf, 1);
			pPInfo->on_note = (buf[0]) ? true:false;
			ar.Read(buf, 1);
			pPInfo->visitor = (buf[0]) ? true:false;
			ar.Read(buf, 1);
			pPInfo->reserved = (buf[0]) ? true:false;
			ar.Read(buf, 1);
			pPInfo->one_service = (buf[0]) ? true:false;
			ar.Read(buf, 1);
			pPInfo->no_consec = (buf[0]) ? true:false;
			ar >> pPInfo->nLimit;
			for (int col = 1; col < cols; col++)
			{
				ar.Read(buf, 1);
				pPInfo->availability[col] = buf[0];
			}
//authorisation, family, parade & where used in last plan
//are flagged with the preferences
			for (int row = 1; row < rows - 1; row++)
			{
				ar.Read(buf, 1);
				pPInfo->bUsedLastPlan[row] = (buf[0] & 0x10) ? true:false;  //bit 4
				pPInfo->authorised[row] = (buf[0] & 0x20) ? true:false;  //bit 5
				pPInfo->family[row] = (buf[0] & 0x40) ? true:false;  //bit 6
				pPInfo->parade[row] = (buf[0] & 0x80) ? true:false;  //bit 7
//prefs (up to 15)
				pPInfo->preferences[row] = (buf[0] & 0x0f);  //bits 0 - 3
			}
			pPInfo++;
		}
//places and times
		SINFO* pSInfo = pSInfo1Base + 32; //row 1 col 0
		for (int row = 1; row < rows - 1; row++)
		{
			ar >> pSInfo->place_time;
			ar >> pSInfo->preacher;
			ar.Read(buf, 1);
			pSInfo->group = buf[0];
			pSInfo += 32;
		}
//dates
		pSInfo = pSInfo1Base + 1;  //row 0 col 1
		for (int col = 1; col < cols; col++)
		{
			ar >> pSInfo->date;
			ar >> nDay[col];
			ar >> nMonth[col];
			ar >> nYear[col];
			pSInfo++;
		}
//service info
		SINFO* pRow = pSInfo1Base + 32;
		for (row = 1; row < rows - 1; row++)
		{
			SINFO* pSInfo = pRow + 1;
			for (int col = 1; col < cols; col++)
			{
				ar.Read(buf, 2);  //discard
				ar.Read(buf, 11);
				pSInfo->communion = (buf[0]) ? true:false;
				pSInfo->sacrament1 = false; //(buf[1]) ? true:false;
				pSInfo->sacrament2 = false; //(buf[2]) ? true:false;
				pSInfo->sacrament3 = false; //(buf[3]) ? true:false;
				pSInfo->family = (buf[4]) ? true:false;
				pSInfo->parade = (buf[5]) ? true:false;
				pSInfo->baptism = (buf[6]) ? true:false;
				pSInfo->united = (buf[7]) ? true:false;
				pSInfo->no_service = (buf[8]) ? true:false;
				pSInfo->reserved = (buf[9]) ? true:false;
				ar >> pSInfo->preacher;
				ar >> pSInfo->detail;
				ar >> pSInfo->code;
				pSInfo++;
			}
			pRow += 32;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPlanMakerDoc diagnostics

#ifdef _DEBUG
void CPlanMakerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPlanMakerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPlanMakerDoc commands

void CPlanMakerDoc::Store()
{
//for undo/redo, copy existing data file to .tmp file
	CFile file;
	if (filename == "")
	{
		CopyFile(strPathDat, strPathTmp, false);
		if (!file.Open(strPathDat, CFile::modeWrite))
			MessageBox(NULL, "Your plan data file could not be opened for writing." , "PlanMaker", MB_OK | MB_ICONERROR);
		else
		{
//store new data on disk
			file.SetLength(0);
			CArchive ar(&file, CArchive::store);
			Serialize(ar);
			ar.Close();
			file.Close();
			CopyFile(strPathDat, strPathBak, false);
		}
	}
	else
		CopyFile(filename, strPathTmp, false);
}

void CPlanMakerDoc::OnEditUndo() 
{
	BOOL bFit = bFitWidth; //maintain setting after undo
	int nOldRows = rows;
	int nOldCols = cols;
//retrieve previous data from .tmp file
	CFile file;
	if (!file.Open(strPathTmp, CFile::modeRead))
	{
		MessageBox(NULL, "The Undo operation failed [Code 0].", "PlanMaker", MB_OK | MB_ICONEXCLAMATION);
		return;
	}
	CArchive ar(&file, CArchive::load);
	Serialize(ar);
	ar.Close();
	file.Close();
	bFitWidth = bFit;
	bEnableUndo = false;
	bEnableRedo = true;
	if (rows != nOldRows || cols != nOldCols)
		bPlanResized = true;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnEditRedo()
{
	BOOL bFit = bFitWidth; //maintain setting after redo
	int nOldRows = rows;
	int nOldCols = cols;
//retrieve previous data from .tmp file
	CFile file;
	if (!file.Open(strPathTmp, CFile::modeRead))
	{
		MessageBox(NULL, "The Redo operation failed [Code 0].", "PlanMaker", MB_OK | MB_ICONEXCLAMATION);
		return;
	}
	CArchive ar(&file, CArchive::load);
	Serialize(ar);
	ar.Close();
	file.Close();
	bFitWidth = bFit;
	bEnableUndo = true;
	bEnableRedo = false;
	if (rows != nOldRows || cols != nOldCols)
		bPlanResized = true;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnFileSaveAs() 
{
	CFileDialog dlg(false, ".pln", NULL, OFN_OVERWRITEPROMPT, "Plan Data Files (.pln)|*.pln||");
	ITEMIDLIST idl;
	LPITEMIDLIST pidl = &idl;
	SHGetSpecialFolderLocation(NULL, CSIDL_PERSONAL, &pidl);
	char buf[MAX_PATH] = {0};
	SHGetPathFromIDList(pidl, buf);
	strcat(buf, "\\Planmaker");
	dlg.m_ofn.lpstrInitialDir = buf;
	strcat(buf, "\\*.pln");
	dlg.m_ofn.lpstrFile = buf;

	if (IDOK != dlg.DoModal())
		return;
	CFile file;
	file.Open(dlg.GetPathName(), CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);
	Serialize(ar);
	ar.Close();
	file.Close();
}

void CPlanMakerDoc::OnFileMakedefault() 
{
	CString str = "";
	str += "You are about to replace your default plan file (the plan you see when ";
	str += "you start PlanMaker) with the file ";
	str += filename;
	str += ", which will then become the plan you see when you start PlanMaker.";
	str += "The original default plan will be lost, but the file you opened will ";
	str += "be unaffected. Are you sure you want to do this?";
	if (IDYES == MessageBox(NULL, str, "PlanMaker", MB_YESNO | MB_ICONEXCLAMATION))
	{
		filename = "";
		bEnableUndo = false;
		bEnableRedo = false;
		SetModifiedFlag();
	}
}

void CPlanMakerDoc::OnEditCopyKey() 
{
	if(!OpenClipboard(NULL))
	{
		::MessageBox(NULL, "Cannot open clipboard.", "Error", 0x10010);
		return;
	}
//empty anything already there...
	EmptyClipboard();
//put the data into the string
int nKey = 0;
	for (nKey = 0; nKey < 200; nKey++)
	{
		key[nKey] = "";
	}
	nKey = 0;
	SINFO* pRow = pSInfoBase + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (pSInfo->communion )
			{
				key[nKey] = (bUseSforComm) ? "S" : "C";
				key[nKey] += 0x09;
				key[nKey] += "Communion";
				nKey++;
			}
			if (pSInfo->family )
			{
				if (bUseAllAge)
				{
					key[nKey] = "AA";
					key[nKey] += 0x09;
					key[nKey] += "All Age Worship";
					nKey++;
				}
				else
				{
					key[nKey] = "F";
					key[nKey] += 0x09;
					key[nKey] += "Family Service";
					nKey++;
				}
			}
			if (pSInfo->parade )
			{
				key[nKey] = "P";
				key[nKey] += 0x09;
				key[nKey] += "Parade Service";
				nKey++;
			}
			if (pSInfo->baptism )
			{
				key[nKey] = "B";
				key[nKey] += 0x09;
				key[nKey] += "Baptism";
				nKey++;
			}
			if (pSInfo->united )
			{
				key[nKey] = "U";
				key[nKey] += 0x09;
				key[nKey] += "United Service";
				nKey++;
			}
			if (pSInfo->code != "")
			{
				key[nKey] = pSInfo->code;
				key[nKey] += 0x09;
				key[nKey] += pSInfo->detail;
				nKey++;
			}
			pSInfo++;
		}
		pRow += 32;
	}
//sort and remove duplicates
	SortKeys();
//compile into 1 string
CString ttx = "Key";
	ttx += 0x0d;
	ttx += 0x0a;
	for (int i = 0; i < 200; i++)
	{
		if (key[i] != "")
		{
			ttx += key[i];
			ttx += 0x0d;
			ttx += 0x0a;
		}
	}
//allocate global memory for ttx transfer...
	HGLOBAL hText = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, 65536);//ttx.GetLength());
	char *lpText = (char *)GlobalLock(hText);
//put string into the global memory...
	strcpy(lpText, ttx);
	GlobalUnlock(hText);
//put data on the clipboard
	SetClipboardData(CF_TEXT, hText);
//close the clipboard
	CloseClipboard();
//free memory
	GlobalFree(hText);
}

void CPlanMakerDoc::OnEditCopyPlan() 
{
	bCopyPlan = true;  //set to get italic codes & service details
	bPrintPlan = true; //set to get "No Service" returned from CopyServiceInfo() if applicable
//open the clipboard...
	if(!OpenClipboard(NULL))
	{
		::MessageBox(NULL, "Cannot open clipboard.", "Error", 0x10010);
		return;
	}
//get Clipboard format id for RTF.
	UINT cf = RegisterClipboardFormat("Rich Text Format");

//empty anything already there...
	EmptyClipboard();

CString rtf = "";
CString ttx = "";
//define the cell structure for rtf
	rtf = "{\\rtf1";
//put the data into the strings for rtf and tabs & text
CString str, str1;
SINFO* pRow = pSInfoBase;
	for (int row = 0; row < rows - 1; row++)
	{
		rtf += "\\trowd\\trrh0\\intbl";
		SINFO* pSInfo = pRow;
		if (row == 0)
		{
			for (int col = 0; col < cols; col++)
			{
				if (bNoPrintYear && pSInfo->date.Find(" 20") != -1)
				{
					int year = pSInfo->date.Find(" 20");
					str = pSInfo->date.Left(year);
					str += pSInfo->date.Mid(year + 5);
				}
				else
					str = pSInfo->date;
				int nReturn = str.Find(0x0d);  //look for return before note
				if (nReturn != -1)
				{
					str1 = str.Left(nReturn);  //substitute space
					str1 += " ";
					str1 += str.Mid(nReturn + 2);
				}
				else
					str1 = str;
				if (col == 0)
					rtf += "\\clbrdrl\\brdrdb";
				else if (col == cols - 1)
				{
					rtf += "\\clbrdrl\\brdrs";
					rtf += "\\clbrdrr\\brdrdb";
				}
				else
					rtf += "\\clbrdrl\\brdrs";
				rtf += "\\clbrdrt\\brdrdb";
				rtf += "\\cellx" + IntToStr(1500 + 1000 * col);
				rtf += "\\qc " + str1 + "\\intbl\\cell";
				ttx += str1;
				ttx += 0x09;
				pSInfo++;
			}
			rtf += "\\row";
			ttx += 0x0d;
			ttx += 0x0a;
		}
		else
		{
			for (int col = 0; col < cols; col++)
			{
				if (col == 0)
					rtf += "\\clbrdrl\\brdrdb";
				else if (col == cols - 1)
				{
					rtf += "\\clbrdrl\\brdrs";
					rtf += "\\clbrdrr\\brdrdb";
				}
				else
					rtf += "\\clbrdrl\\brdrs";
				rtf += "\\clbrdrt\\brdrs";
				if (row == rows - 2)
					rtf += "\\clbrdrb\\brdrdb";
				rtf += "\\cellx" + IntToStr(1500 + 1000 * col);
				if (col == 0)
				{
					CString strPlaceTime = pSInfo->place_time;
					int find = strPlaceTime.Find(0x01);
					if (find != -1)
						strPlaceTime = strPlaceTime.Left(find);
					rtf += "\\ql " + strPlaceTime + "\\cell";
					ttx += strPlaceTime;
					ttx += 0x09;
				}
				else
				{
					CString str = CopyServiceInfo(row, col, true);
					rtf += "\\qc " + str + "\\cell";
					str = CopyServiceInfo(row, col, false);
					ttx += str;
					ttx += 0x09;
				}
				pSInfo++;
			}
			rtf += "\\row";
			ttx += 0x0d;
			ttx += 0x0a;
		}
		pRow += 32;
	}
	rtf += "}";
	bCopyPlan = false;

//allocate global memory for rtf transfer...
	HGLOBAL hText = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, rtf.GetLength() + 256);
	char *lpText = (char *)GlobalLock(hText);

//put string into the global memory...
	strcpy(lpText, rtf);
	GlobalUnlock(hText);

//put data on the clipboard
	SetClipboardData(cf, hText);

//allocate global memory for ttx transfer...
	hText = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, ttx.GetLength());
	lpText = (char *)GlobalLock(hText);

//put string into the global memory...
	strcpy(lpText, ttx);
	GlobalUnlock(hText);
	
//put data on the clipboard
	SetClipboardData(CF_TEXT, hText);

//close the clipboard
	CloseClipboard();

//free memory
	GlobalFree(hText);
}

void CPlanMakerDoc::OnEditCopyPreachers() 
{
	if(!OpenClipboard(NULL))
	{
		::MessageBox(NULL, "Cannot open clipboard.", "Error", 0x10010);
		return;
	}
//empty anything already there...
	EmptyClipboard();
//put the data into the string
//store ordained first
	CString ttx = "Ministers";
	ttx += 0x0d;
	ttx += 0x0a;
	PINFO* pPInfo = pPInfoBase;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		if (pPInfo->ordained && !pPInfo->visitor)
		{
			CString str = GetPreacher(pPInfo);
			ttx += str;
		}
		pPInfo++;
	}
	ttx += 0x0d;
	ttx += 0x0a;
//next, accredited preachers, if to be printed separately
	if (bPrintAccredited )
	{
		CSortAccredited srta;
		srta.DoSort();
		ttx += "Accredited Preachers";
		ttx += 0x0d;
		ttx += 0x0a;
		pPInfo = pPInfoBase;
		for (int prch = 0; prch < nPreachers; prch++)
		{
			if (!pPInfo->ordained
					&& !pPInfo->visitor
					&& !pPInfo->on_trial
					&& !pPInfo->on_note
					&& (pPInfo->add_info.Find("19") != -1
						|| pPInfo->add_info.Find("20") != -1))
			{
				CString str = GetPreacher(pPInfo);
				ttx += str;
			}
			pPInfo++;
		}
		ttx += 0x0d;
		ttx += 0x0a;
		CSortPreachers srtp;
		srtp.DoSort();
	}
//then other partnership preachers
	ttx += "Partnership Preachers";
	ttx += 0x0d;
	ttx += 0x0a;
	pPInfo = pPInfoBase;
	for (prch = 0; prch < nPreachers; prch++)
	{
		if (!pPInfo->ordained
				&& !pPInfo->visitor
				&& !pPInfo->on_trial
				&& !pPInfo->on_note
				&& ((pPInfo->add_info.Find("19") == -1
					&& pPInfo->add_info.Find("20") == -1)
					|| !bPrintAccredited))
		{
			CString str = GetPreacher(pPInfo);
			ttx += str;
		}
		pPInfo++;
	}
	ttx += 0x0d;
	ttx += 0x0a;
//those on trial
	ttx += "On Trial";
	ttx += 0x0d;
	ttx += 0x0a;
	pPInfo = pPInfoBase;
	for (prch = 0; prch < nPreachers; prch++)
	{
		if (pPInfo->on_trial )
			ttx += GetPreacher(pPInfo);
		pPInfo++;
	}
	ttx += 0x0d;
	ttx += 0x0a;
//and those on note
	ttx += "On Note";
	ttx += 0x0d;
	ttx += 0x0a;
	pPInfo = pPInfoBase;
	for (prch = 0; prch < nPreachers; prch++)
	{
		if (pPInfo->on_note )
		{
			CString str = GetPreacher(pPInfo);
			ttx += str;
		}
		pPInfo++;
	}
//allocate global memory for ttx transfer...
	HGLOBAL hText = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, 65536);//ttx.GetLength());
	char *lpText = (char *)GlobalLock(hText);
//put string into the global memory...
	strcpy(lpText, ttx);
	GlobalUnlock(hText);
//put data on the clipboard
	SetClipboardData(CF_TEXT, hText);
//close the clipboard
	CloseClipboard();
//free memory
	GlobalFree(hText);
}

void CPlanMakerDoc::OnEditCopyVisitors() 
{
	if(!OpenClipboard(NULL))
	{
		::MessageBox(NULL, "Cannot open clipboard.", "Error", 0x10010);
		return;
	}
//empty anything already there...
	EmptyClipboard();
//put the data into the string
	CString ttx = "Visiting Preachers";
	ttx += 0x0d;
	ttx += 0x0a;
	PINFO* pPInfo = pPInfoBase;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		if (pPInfo->visitor )
		{
//see if preacher is in the plan
			BOOL bIsInPlan = false;
			SINFO* pRow = pSInfoBase + 32;
			for (int row = 1; row < rows - 1; row++)
			{
				SINFO* pSInfo = pRow + 1;
				for (int col = 1; col < cols; col++)
				{
					if (PreacherAppears(pPInfo, pSInfo))
						bIsInPlan = true;
					pSInfo++;
				}
				pRow += 32;
			}
			if (bIsInPlan )
				ttx += GetPreacher(pPInfo);
		}
		pPInfo++;
	}
	ttx += 0x0d;
	ttx += 0x0a;
//allocate global memory for ttx transfer...
	HGLOBAL hText = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, 65536);//ttx.GetLength());
	char *lpText = (char *)GlobalLock(hText);
//put string into the global memory...
	strcpy(lpText, ttx);
	GlobalUnlock(hText);
//put data on the clipboard
	SetClipboardData(CF_TEXT, hText);
//close the clipboard
	CloseClipboard();
//free memory
	GlobalFree(hText);
}

CString CPlanMakerDoc::GetPreacher(PINFO* pPInfo)
{
	CString str = "";
	if (pPInfo->title != "")
		str = pPInfo->title + " ";
	str += pPInfo->first_name + " ";
	str += pPInfo->last_name;
	if (pPInfo->add_info != "")
	{
		str += " (";
		str += pPInfo->add_info;
		str += ")";
	}
	str += ", ";
	str += pPInfo->address1 + ", ";
	if (pPInfo->address2 != "")
		str += pPInfo->address2 + ", ";
	str += pPInfo->town;
	if (pPInfo->visitor )
	{
		if (pPInfo->county != "")
		{
			str += ", " + pPInfo->county;
			str += (pPInfo->county.Right(1) != ".") ? ". " : " ";
		}
		else
			str += ". ";
	}
	else
		str += ". ";
	str += pPInfo->postcode + " ";
	if (pPInfo->phone != "")
	{
		str += "Tel ";
		str += pPInfo->phone + " ";
	}
	if (pPInfo->email != "")
	{
		str += "e-mail ";
		str += pPInfo->email;
	}
	str += 0x0d;
	str += 0x0a;
	return str;	
}

CString CPlanMakerDoc::IntToStr(int value)
{
	char ch[6];
	_itoa(value, ch, 10);
	return ch;
}

CString CPlanMakerDoc::CopyServiceInfo(int row, int col, BOOL bRtf)
{
//get service info for Edit | Copy | Plan
	SINFO* pSInfo = pSInfoBase + 32 * row + col;
	CString str = "";
	if (pSInfo->no_service)
	{
		CString str = "";
		if (pSInfo->no_service && bPrintPlan)
		{
			if (bPrintNoService)
			{
				if (pSInfo->code != "")
				{
					if (bRtf)
						str = "\\i No Service " + pSInfo->code + "\\i0";
					else
						str = "No Service " + pSInfo->code;
				}
				else
				{
					if (bRtf)
						pSInfo->detail != "" ? str = "\\i No Service " + pSInfo->detail + "\\i0": str = "\\i No Service\\i0";
					else
						pSInfo->detail != "" ? str = "No Service " + pSInfo->detail : str = "No Service";
				}
			}
			else if (bPrintNoServiceExcl)
			{
				if (pSInfo->code != "")
				{
					if (bRtf)
						str = "\\i " + pSInfo->code;
					else
						str = pSInfo->code;
				}
				else
				{
					if (bRtf)
						pSInfo->detail != "" ? str = "\\i " + pSInfo->detail : str = "\\i No Service\\i0";
					else
						pSInfo->detail != "" ? str = pSInfo->detail : str = "No Service";
				}
			}
			else if (bRtf)
				pSInfo->code != "" ? str = "\\i " + pSInfo->code + "\\i0" : str = "\\i " + pSInfo->detail + "\\i0";
			else
				pSInfo->code != "" ? str = pSInfo->code : str = pSInfo->detail;
			return str;
		}
	}

//look for local ords first
	PINFO* pPInfo = pPInfoBase;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		if (pPInfo->ordained && !pPInfo->visitor)
		{
			if (PreacherAppears(pPInfo, pSInfo))
			{
				if (str != "")
					str += " / ";
				str += pPInfo->screen_name;
			}
		}
		pPInfo++;
	}
//then lays, visitors & reserved
	pPInfo = pPInfoBase;
	for (prch = 0; prch < nPreachers; prch++)
	{
		if (!pPInfo->ordained || pPInfo->visitor || pPInfo->reserved)
		{
			if (PreacherAppears(pPInfo, pSInfo))
			{
				if (str != "")
					str += " / ";
				str += pPInfo->screen_name;
			}
		}
		pPInfo++;
	}

	if (bRtf)
		str += "\\i ";

	if (pSInfo->communion)
		str += (bUseSforComm) ? " S" : " C";
	if (pSInfo->family)
	{
		str += (bUseAllAge) ? " AA" : " F";
	}
	if (pSInfo->parade)
		str += " P";
	if (pSInfo->baptism)
		str += " B";
	if (pSInfo->united)
		str += " U";
	if (pSInfo->code != "")
		str += " " + pSInfo->code;
	else if (pSInfo->detail != "")
		str += " " + pSInfo->detail;

	if (bRtf)
		str += "\\i0";

	return str;
}

void CPlanMakerDoc::SortKeys()
{
//remove duplicates
	for (int i = 0; i < 200; i++)
	{
		for (int j = 1; i + j < 200; j++)
		{
			if (key[i + j] == key[i])
				key[i + j] = "";
		}
	}

	qsort(&key[0], 200, 4, CompareKeys);

}

int CPlanMakerDoc::CompareKeys(const void *p1, const void *p2)
{
	CString* pKey1 = (CString*)p1;
	CString* pKey2 = (CString*)p2;

	if (*pKey1 > *pKey2) 
		return 1;
	if (*pKey1 < *pKey2)
		return -1;

	return 0;
}

void CPlanMakerDoc::OnEditCopyAnalysis() 
{
//find how many times preacher used in each group and in total
		int nUsed[200][9];
//initialise
		PINFO* pPInfo = pPInfoBase;
		for (int prch = 0; prch < nPreachers; prch++)
		{
			for (int grp = 1; grp < 9; grp <<= 1)
			{
				nUsed[pPInfo - pPInfoBase][grp] = 0;
			}
			pPInfo++;
		}
//count
		pPInfo = pPInfoBase;
		for (prch = 0; prch < nPreachers; prch++)
		{
			SINFO* pRow = pSInfoBase + 32;
			for (int row = 1; row < rows - 1; row++)
			{
				SINFO* pSInfo = pRow + 1;
				for (int col = 1; col < cols; col++)
				{
					if (PreacherAppears(pPInfo, pSInfo))
						nUsed[pPInfo - pPInfoBase][pRow->group]++;
					pSInfo++;
				}
				pRow += 32;
			}
			pPInfo++;
		}
//see if there are invalid groups - groups with no services
		BOOL bInvalidGroup[9];
		for (int grp = 1; grp < 9; grp <<= 1)
		{
			bInvalidGroup[grp] = true;
			{
				SINFO* pRow = pSInfoBase + 32;
				for (int row = 1; row < rows - 1; row++)
				{
					if (pRow->group == grp)
					{
						SINFO* pSInfo = pRow + 1;
						for (int col = 1; col < cols; col++)
						{
							if (!pSInfo->no_service)
								bInvalidGroup[grp] = false;
							pSInfo++;
						}
					}
					pRow += 32;
				}
			}
		}
//open the clipboard...
	if(!OpenClipboard(NULL))
	{
		::MessageBox(NULL, "Cannot open clipboard.", "Error", 0x10010);
		return;
	}
//get Clipboard format id for RTF.
	UINT cf = RegisterClipboardFormat("Rich Text Format");

//empty anything already there...
	EmptyClipboard();

//*** This section of code adds the RTF table to the clipboard
//*** RTF-Data to put on clipboard

CString rtf = "";
CString ttx = "";

	rtf += "{\\rtf1";
	rtf += "{\\colortbl;\\red224\\green224\\blue224;";  //grey 1
	rtf += "\\red255\\green255\\blue192;";  //lt yellow 2
	rtf += "\\red192\\green255\\blue255;";  //cyan 3
	rtf += "\\red192\\green192\\blue255;";  //blue 4
	rtf += "\\red255\\green192\\blue192;";  //red 5
	rtf += "\\red255\\green255\\blue0;";  //yellow highlight 6
	rtf += "\\red0\\green255\\blue0;}";  //green highlight 7

//copy file date & time
		CString str = "File: ";
		CFileStatus status;
		char* pFileName = NULL;
		if (filename == "")
			pFileName = (char*)strPathDat.GetBuffer(64);
		else
		{
			pFileName = (char*)filename.GetBuffer(64);
		}
		if( CFile::GetStatus(pFileName, status))
		{
			str += status.m_mtime.Format("%A, %d %B, %Y; %H:%M:%S");
		    rtf += str + "\\par";
			ttx += str;
			ttx += 0x0d;
			ttx += 0x0a;
		}

		rtf += "\\trowd\\trrh0\\intbl";

//copy column headers
		rtf += "\\cellx1900\\cell\\cellx2500\\cell";
		ttx += 0x09;
		ttx += 0x09;
		for (int col = 1; col < cols; col++)
		{

			rtf += "\\clcbpat1\\cellx"
					+ IntToStr(2500 + 700 * col)
					+ "\\qc "
					+ IntToStr(nDay[col])
					+ "/" + IntToStr(nMonth[col]) + "\\cell";
			ttx += IntToStr(nDay[col])
					+ "/" + IntToStr(nMonth[col]);
			ttx += 0x09;
		}
		rtf += "\\row";
		ttx += 0x0d;
		ttx += 0x0a;
		BOOL bPrintTopBrdr;
		pPInfo = pPInfoBase;
		for (prch = 0; prch < nPreachers; prch++)
		{
			bPrintTopBrdr = true;
			BOOL bNamePrinted = false;
			for (int grp = 1; grp < 9; grp <<= 1)
			{
//don't show if never available in group or group invalid
				BOOL bIsAvailable = false;
				if (!bInvalidGroup[grp])
				{
					for (int col = 1; col < cols; col++)
					{
						if ((pPInfo->availability[col] & grp) != 0)
							bIsAvailable = true;
					}
				}
				if (bIsAvailable)
				{
					rtf += "\\trowd\\trrh0\\intbl";
//copy preacher name
					if (!bNamePrinted)
					{
//count total on plan
						int nUsedTot = 0;
						for (int grp = 1; grp < 9; grp <<= 1)
						{
							nUsedTot += nUsed[pPInfo - pPInfoBase][grp];
						}
						CString str = pPInfo->screen_name.Left(12);
						str	+= " " + IntToStr(nUsedTot);
						if (pPInfo->nLimit != -1)
							str += "/" + IntToStr(pPInfo->nLimit);
						rtf += "\\clbrdrl\\brdrs\\clbrdrt\\brdrs";
						rtf += "\\clcbpat1\\cellx1900\\highlight0\\ql " + str + " \\cell";
						ttx += str;
						ttx += 0x09;
						bNamePrinted = true;
					}
					else
					{
						rtf += "\\clbrdrl\\brdrs";
						rtf += "\\clcbpat1\\cellx1900\\highlight0\\ql \\cell";
						ttx += 0x09;
					}
//copy group code & number
					if (bPrintTopBrdr)
						rtf += "\\clbrdrt\\brdrs";
					rtf += "\\clbrdrl\\brdrs\\clbrdrr\\brdrs";
					switch (grp)
					{
					case 1: rtf += "\\clcbpat2\\cellx2500 \\ql EM ";
							ttx += "EM ";
						break;
					case 2: rtf += "\\clcbpat3\\cellx2500 \\ql M ";
							ttx += "M ";
						break;
					case 4: rtf += "\\clcbpat4\\cellx2500 \\ql A ";
							ttx += "A ";
						break;
					case 8: rtf += "\\clcbpat5\\cellx2500 \\ql E ";
							ttx += "E ";
					}
					rtf += IntToStr(nUsed[pPInfo - pPInfoBase][grp]) + " \\cell";
					ttx += IntToStr(nUsed[pPInfo - pPInfoBase][grp]);
					ttx += 0x09;
//copy data
					for (int col = 1; col < cols; col++)
					{
						if (bPrintTopBrdr)
							rtf += "\\clbrdrt\\brdrs";
						if (col == cols - 1)
							rtf += "\\clbrdrr\\brdrs";
						switch (grp)
						{
						case 1: rtf += "\\clcbpat2\\cellx";
							break;
						case 2: rtf += "\\clcbpat3\\cellx";
							break;
						case 4: rtf += "\\clcbpat4\\cellx";
							break;
						case 8: rtf += "\\clcbpat5\\cellx";
						}
						rtf += IntToStr(2500 + 700 * col);
						for (int row = 1; row < rows - 1; row++)
						{
							SINFO* pSInfo1 = pSInfoBase + 32 * row;
							SINFO* pSInfo2 = pSInfo1 + col;
							if (PreacherAppears(pPInfo, pSInfo2)
								&& pSInfo1->group == grp)
							{
								if (pSInfo2->reserved)
								    rtf += "\\highlight7\\qc " + pSInfo1->strChurchCode;
                                else
                                    rtf += "\\highlight6\\qc " + pSInfo1->strChurchCode;
								ttx += pSInfo1->strChurchCode;
								ttx += 0x09;
							}
						}
//if not available
						if ((pPInfo->availability[col] & grp) == 0)
						{
							rtf += "\\highlight0\\qc N/A";
							ttx += "N/A";
						}
						rtf += " \\cell";
						ttx += 0x09;
					}
					bPrintTopBrdr = false;
					rtf += "\\row";
					ttx += 0x0d;
					ttx += 0x0a;
				}
			}
			pPInfo++;
		}
		rtf += "\\intbl\\trowd\\clbrdrt\\brdrs\\trrh0\\cellx"
				+ IntToStr(2500 + 700 * (cols - 1))
				+ "\\cell\\row";
		rtf += "}";

//allocate global memory for rtf transfer...
	HGLOBAL hText = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, rtf.GetLength() + 256);
	char *lpText = (char *)GlobalLock(hText);

//put string into the global memory...
	strcpy(lpText, rtf);
	GlobalUnlock(hText);

//put data on the clipboard
	SetClipboardData(cf, hText);

//allocate global memory for ttx transfer...
	hText = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, ttx.GetLength() + 256);
	lpText = (char *)GlobalLock(hText);

//put string into the global memory...
	strcpy(lpText, ttx);
	GlobalUnlock(hText);
	
//put data on the clipboard
	SetClipboardData(CF_TEXT, hText);

//close the clipboard
	CloseClipboard();

//free memory
	GlobalFree(hText);
}

void CPlanMakerDoc::DoAllocate(PINFO *pPBase, SINFO *pSBase, PINFO *pPInfo, int nRow, int nCol)
{
	SINFO* pSInfo = pSBase + 32 * nRow + nCol;
	pSInfo->preacher = pPInfo->screen_name;
	pPInfo->nToAllocate[nRow]--;
	pPInfo->nOnPlan++;

//deal with preachers
//all now unavailable for this service
	PINFO* pPInfo1 = pPBase;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		pPInfo1->bsAvailFlags[nRow].reset(nCol);
		pPInfo1++;
	}
//lays unavailable for adjacent dates in same church
//all unavailable for adjacent dates in same church if bNoConsecSame set
	if (!pPInfo->ordained
		|| pPInfo->visitor
		|| bNoConsecSame)
	{
		pPInfo->bsAvailFlags[nRow].reset(nCol - 1);
		pPInfo->bsAvailFlags[nRow].reset(nCol + 1);
	}
//unavailable again in this row if preferences met
	if (pPInfo->nToAllocate[nRow] == 0)
		pPInfo->bsAvailFlags[nRow].reset();

//deal with rows
	SINFO* pRow = pSBase + 32;
	int nGrp = (pSBase + 32 * nRow)->group;
	CString strChurchCode0 = (pSBase + 32 * nRow)->strChurchCode;
	SINFO* pRow0 = pSBase + 32 * nRow;
	char grp = pRow0->group + (char)0x30;
	CString strIncompat = (char)0x01 + pRow0->strChurchCode + grp;
	for (int row = 1; row < rows - 1; row++)
	{
//unavailable for other services in this column and group
		if (pRow->group == nGrp)
			pPInfo->bsAvailFlags[row].reset(nCol);

//unavailable again in this col & church if bNoDouble
//lays unavailable again in this church (any time) if bOnlyOnce
		if (pRow->strChurchCode == strChurchCode0)
		{
			if (bNoDouble)
				pPInfo->bsAvailFlags[row].reset(nCol);
			if (bOnlyOnce && (!pPInfo->ordained || pPInfo->visitor))
				pPInfo->bsAvailFlags[row].reset();
		}

//unavailable in incompatible churches
		if (pRow->place_time.Find(strIncompat) != -1)
			pPInfo->bsAvailFlags[row].reset(nCol);

//unavailable again if limit met
		if (pPInfo->nOnPlan >= pPInfo->nLimit && pPInfo->nLimit != -1)
			pPInfo->bsAvailFlags[row].reset();

//unavailable for adjacent dates if this option set
		if (pPInfo->no_consec)
		{
			pPInfo->bsAvailFlags[row].reset(nCol - 1);
			pPInfo->bsAvailFlags[row].reset(nCol + 1);
		}

//unavailable for other services in this column if only 1 service a day
		if (pPInfo->one_service)
			pPInfo->bsAvailFlags[row].reset(nCol);

		pRow += 32;
	}
}

void CPlanMakerDoc::InitAvailability(PINFO *pPBase, SINFO *pSBase, BOOL bOrds)
{
//enter data into availability array
	PINFO* pPInfo = pPBase;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		if (bOrds && (!pPInfo->ordained || pPInfo->visitor))
		{
			pPInfo++;
			continue;
		}
		SINFO* pRow = pSBase + 32;
		for (int row = 1; row < rows - 1; row++)
		{
			SINFO* pSInfo = pRow + 1;
			for (int col = 1; col < cols; col++)
			{
				if (!(pPInfo->availability[col] & pRow->group)  //about the preacher
					|| (pPInfo->nOnPlan >= pPInfo->nLimit && pPInfo->nLimit != -1)
					|| pPInfo->nToAllocate[row] == 0
					|| (bNoConsecPlan && pPInfo->bUsedLastPlan[row]))
				{
					pPInfo->bsAvailFlags[row].reset(col);
				}
				else if (pSInfo->no_service  //about the service
					|| pSInfo->reserved
					|| pSInfo->preacher != ""
					|| (pSInfo->communion && !pPInfo->authorised[row])
					|| (pSInfo->baptism && !pPInfo->ordained)
					|| (pSInfo->united && !pPInfo->ordained)
					|| (pSInfo->family && !pPInfo->family[row])
					|| (pSInfo->parade && !pPInfo->parade[row]))
				{
					pPInfo->bsAvailFlags[row].reset(col);
				}

//deal with preachers already on plan (inserted if allocating, allocated if floating)
//see if present in this cell
				if (PreacherAppears(pPInfo, pSInfo))
				{
					char grp = pRow->group + (char)0x30;
					CString strIncompat = (char)0x01 + pRow->strChurchCode + grp;
//row where present:
//lay or visitor unavailable in adjacent cols
//all unavailable in adjacent cols if bNoConsecSame
					if (!pPInfo->ordained
						|| pPInfo->visitor
						|| bNoConsecSame)
					{
						pPInfo->bsAvailFlags[row].reset(col - 1);
						pPInfo->bsAvailFlags[row].reset(col + 1);
					}
//all rows:
//current prch unavailable in col & group where present or if churches incompatible
//unavailable again in col if one_service
//unavailable in same church if lay or bNoDouble
//unavailable in adjacent cols if no_consec
					SINFO* pRow1 = pSBase + 32;
					for (int row1 = 1; row1 < rows - 1; row1++)
					{
						if (pRow1->group == pRow->group
							|| pRow1->place_time.Find(strIncompat) != -1
							|| pPInfo->one_service
							|| ((!pPInfo->ordained || pPInfo->visitor || bNoDouble)
									&& pRow1->strChurchCode == pRow->strChurchCode))
							pPInfo->bsAvailFlags[row1].reset(col);
						if (pPInfo->no_consec)
						{
							pPInfo->bsAvailFlags[row1].reset(col - 1);
							pPInfo->bsAvailFlags[row1].reset(col + 1);
						}
						pRow1 += 32;
					}
				}
				pSInfo++;
			}
			pRow += 32;
		}
	
//preachers in last col of previous plan not allocated
//in first col of this plan if no_consec
//or if lay or visitor and bNoConsecSame (only applied to lays & visitors)
//this info is stored in col0
		SINFO* pSInfo = pSBase + 32;  //row 1 col 0
		for (row = 1; row < rows - 1; row++)
		{
			if (PreacherAppears(pPInfo, pSInfo))
			{
				if (pPInfo->no_consec)
				{
					for (int row1 = 1; row1 < rows - 1; row1++)
						pPInfo->bsAvailFlags[row1].reset(1);
				}
				else if ((!pPInfo->ordained || pPInfo->visitor) && bNoConsecSame)
						pPInfo->bsAvailFlags[row].reset(1);
			}
			pSInfo += 32;
		}
		pPInfo++;	
	}
}

BOOL CPlanMakerDoc::PreacherAppears(PINFO *pPInfo, SINFO *pSInfo)
{
	if (pSInfo->preacher == "")  //no preacher
		return false;

	int find = pSInfo->preacher.Find(" / ");
	
	if (find == -1)  //no slash - only 1 preacher
	{
		if (pSInfo->preacher == pPInfo->screen_name)
			return true;
		return false;
	}

	CString strTemp = pSInfo->preacher;
	while (find != -1)  //more than 1
	{
		CString strLeft = strTemp.Left(find);
		if (strLeft == pPInfo->screen_name)
			return true;
		strTemp = strTemp.Mid(find + 3);
		find = strTemp.Find(" / ");
	}
	if (strTemp == pPInfo->screen_name)  //last
		return true;

	return false;
}

void CPlanMakerDoc::OnAllocate() 
{
	AllocateOrd(true);
	AllocateLay();
	bEnableUndo = true;
	bEnableRedo = false;
	bAllocationDone = true;
	bAllocPending = false;
	SetModifiedFlag();
	if (!bUseAllLay)
		return;

//warn if not all available lays are used
	CString str = "";
	PINFO* pPInfo = pPInfo1Base;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		if (!pPInfo->ordained || pPInfo->visitor)
		{
			BOOL bAvailable = false;
			for (int col = 1; col < cols; col++)
			{
				if (pPInfo->availability[col] != 0)
				{
					bAvailable = true;
					break; //available somewhere
				}
			}
			if (!bAvailable) //not available
			{
				pPInfo++;
				continue;
			}
			BOOL bAppears = false;
			SINFO* pRow = pSInfo1Base + 32;
			for (int row = 1; row < rows - 1; row++)
			{
				SINFO* pSInfo = pRow + 1;
				for (int col = 1; col < cols; col++)
				{
					if (PreacherAppears(pPInfo, pSInfo))
					{
						bAppears = true;
						break;
					}
					pSInfo++;
				}
				if (bAppears)
					break;
				pRow += 32;
			}
			if (!bAppears)
				str += (char)0x09 + pPInfo->first_name + " " + pPInfo->last_name + "\n";
		}
		pPInfo++;
	}
	if (str != "")
	{
		str = "The following available Lay Preachers or Visitors could not be used:\n\n" + str;
		MessageBox(NULL, str, "PlanMaker", MB_OK);
	}
}

BOOL CPlanMakerDoc::AllocateOrd(BOOL bAllocate)
{
	PINFO* pPBase;
	SINFO* pSBase;
	if (!bAllocate)
	{
		pPBase = pPTmpInfoBase;
		pSBase = pSTmpInfoBase;
	}
	else
	{
		pPBase = pPInfo1Base;
		pSBase = pSInfo1Base;
	}

//clear allocated preachers (ords & lays)
	SINFO* pRow = pSBase + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (!pSInfo->reserved)
				pSInfo->preacher = "";
			pSInfo++;
		}
		pRow += 32;
	}

//find where inserted and reduce pPInfo->nToAllocate
//compile availability array for each preacher
//initialise flags to 1 for local ordained, 0 for lay & visitor
//find total number of ords to allocate
	int nToAllocate = 0;
	PINFO* pPInfo = pPBase;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		if (pPInfo->ordained && !pPInfo->visitor && !pPInfo->reserved)
		{
			SINFO* pRow = pSBase + 32;
			for (int row = 1; row < rows - 1; row++)
			{
				pPInfo->nToAllocate[row] = pPInfo->preferences[row];
				pPInfo->bsAvailFlags[row].reset();
				pPInfo->nOnPlan = 0;
				int nInserted = 0;
				SINFO* pSInfo = pRow + 1;
				for (int col = 1; col < cols; col++)
				{
					if (pSInfo->reserved && PreacherAppears(pPInfo, pSInfo))
					{
						nInserted++;
						pPInfo->nOnPlan++;
					}
					pPInfo->bsAvailFlags[row].set(col);
					pSInfo++;
				}
				if (pPInfo->nToAllocate[row] > 0)
					pPInfo->nToAllocate[row] -= nInserted;
				nToAllocate += pPInfo->nToAllocate[row];
				pRow += 32;
			}
		}
		else
		{
			for (int row = 1; row < rows - 1; row++)
				pPInfo->bsAvailFlags[row].reset();
		}
		pPInfo++;
	}

	if (!bAllocate && nToAllocate == 0)
		return true;

	InitAvailability(pPBase, pSBase, true);

//initialise bitsets
	bsAllRows = 0;
	for (row = 1; row < rows - 1; row++)
		bsAllRows.set(row);
	bsAllCols = 0;
	for (int col = 1; col < cols; col++)
		bsAllCols.set(col);

//allocate
	TRandomMersenne iRand(0);
	int nAllocated = 0;
	for (int loop = 0; loop < 4; loop++)
	{
		BOOL bAllocated = true;
		while (bAllocated)
		{
//find ord with greatest prefs & which row that's in
			int nMax = 0;
			int nRow = 0;
			PINFO* pPrch = NULL;
			pRow = pSBase + 32;
			for (int row = 1; row < rows - 1; row++)
			{
				pPInfo = pPBase;
				for (int prch = 0; prch < nPreachers; prch++)
				{
					if (pPInfo->ordained && !pPInfo->visitor)
					{
						if (pPInfo->nToAllocate[row] > nMax)
						{
							pPrch = pPInfo;
							nRow = row;
							nMax = pPInfo->nToAllocate[row];
						}
					}
					pPInfo++;
				}
				pRow += 32;
			}
			if (pPrch == NULL || nRow == 0)
				break;
			bAllocated = false;
//loop 0 - allocate communions etc.
//loop 1 - allocate family
//loop 2 = allocate parade
//loop 3 - allocate others
			SINFO* pRow = pSBase + 32 * nRow;
			switch (loop)
			{
			case 0: bsColsUsed = 0;
					while (bsColsUsed != bsAllCols)
					{
						do
							col = iRand.IRandom(1, cols - 1);
						while (bsColsUsed.test(col));
						bsColsUsed.set(col);
						SINFO* pSInfo = pRow + col;
						if (pPrch->bsAvailFlags[nRow].test(col)
							&& pSInfo->communion)
						{
							DoAllocate(pPBase, pSBase, pPrch, nRow, col);
							nAllocated++;
							bAllocated = true;
						}
					}
					break;
			case 1:	bsColsUsed = 0;
					while (bsColsUsed != bsAllCols)
					{
						do
							col = iRand.IRandom(1, cols - 1);
						while (bsColsUsed.test(col));
						bsColsUsed.set(col);
						SINFO* pSInfo = pRow + col;
						if (pPrch->bsAvailFlags[nRow].test(col) && pSInfo->family)
						{
							DoAllocate(pPBase, pSBase, pPrch, nRow, col);
							nAllocated++;
							bAllocated = true;
						}
					}
					break;
			case 2:	bsColsUsed = 0;
					while (bsColsUsed != bsAllCols)
					{
						do
							col = iRand.IRandom(1, cols - 1);
						while (bsColsUsed.test(col));
						bsColsUsed.set(col);
						SINFO* pSInfo = pRow + col;
						if (pPrch->bsAvailFlags[nRow].test(col) && pSInfo->parade)
						{
							DoAllocate(pPBase, pSBase, pPrch, nRow, col);
							nAllocated++;
							bAllocated = true;
						}
					}
					break;
			case 3:	bsColsUsed = 0;
					while (bsColsUsed != bsAllCols)
					{
						do
							col = iRand.IRandom(1, cols - 1);
						while (bsColsUsed.test(col));
						bsColsUsed.set(col);
						SINFO* pSInfo = pRow + col;
						if (pPrch->bsAvailFlags[nRow].test(col))
						{
							DoAllocate(pPBase, pSBase, pPrch, nRow, col);
							nAllocated++;
							bAllocated = true;
						}
					}
			}
		};
	}

	return (nAllocated == nToAllocate);  //true if plan correctly allocated
}

void CPlanMakerDoc::AllocateLay()
{
	LAYSAVAIL* pLaysAvailBase = new LAYSAVAIL[(rows - 2) * (cols - 1)];
	int row, col;

//clear lay preachers and floated ords from all unreserved services
	SINFO* pRow = pSInfo1Base + 32;
	for (row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (col = 1; col < cols; col++)
		{
			if (!pSInfo->reserved)
			{
				PINFO* pPInfo = pPInfo1Base;
				for (int prch = 0; prch < nPreachers; prch++)
				{
					if (PreacherAppears(pPInfo, pSInfo))
					{
						if ((pPInfo->ordained && !pPInfo->visitor && pPInfo->preferences[row] == 0)
							|| !pPInfo->ordained || pPInfo->visitor)
							pSInfo->preacher = "";
					}
					pPInfo++;
				}
			}
			pSInfo++;
		}
		pRow += 32;
	}

//compile availability array for each preacher
//initialise flags & count insertions
//give ministers 1 pref if floating option set
	PINFO* pPInfo = pPInfo1Base;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		pPInfo->nOnPlan = 0;  //insertions
		SINFO* pRow = pSInfo1Base + 32;
		for (row = 1; row < rows - 1; row++)
		{
			pPInfo->bsAvailFlags[row].reset();
			if (!pPInfo->reserved)  //don't include reserved preachers
			{
				if (pPInfo->ordained && !pPInfo->visitor) //if a minister
				{
					if (pPInfo->preferences[row] == 0) //if not allocated in this row
					{
						if (bFillUnused)  //fill unused option set
						{
							pPInfo->nToAllocate[row] = 1;  //give 1 pref in church where not allocated
							SINFO* pSInfo = pRow + 1;
							for (col = 1; col < cols; col++)
							{
								pPInfo->bsAvailFlags[row].set(col); //set flags
								pSInfo++;
							}
						}
					}
					else
					{
						SINFO* pSInfo = pRow + 1;
						for (col = 1; col < cols; col++)
						{
							if (PreacherAppears(pPInfo, pSInfo))
								pPInfo->nOnPlan++;  //count any insertions
							pSInfo++;
						}
					}
				}
				else  //not a minister
				{
					pPInfo->nToAllocate[row] = pPInfo->preferences[row];
					SINFO* pSInfo = pRow + 1;
					for (col = 1; col < cols; col++)
					{
						pPInfo->bsAvailFlags[row].set(col); //set flags
						if (PreacherAppears(pPInfo, pSInfo))
							pPInfo->nOnPlan++;  //count any insertions
						pSInfo++;
					}
				}
			}
			pRow += 32;
		}
		pPInfo++;
	}

	InitAvailability(pPInfo1Base, pSInfo1Base, false);

//prepare initial list of available preachers for each service
	LAYSAVAIL* pLaysAvail = pLaysAvailBase;
	pRow = pSInfo1Base + 32;
	for (row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (col = 1; col < cols; col++)
		{
			pLaysAvail->nAvail = 0;
			if (pSInfo->preacher == "")
			{
				pPInfo = pPInfo1Base;
				for (int prch = 0; prch < nPreachers; prch++)
				{
					if (pPInfo->bsAvailFlags[row].test(col))
					{
						pLaysAvail->pLay[pLaysAvail->nAvail] = pPInfo;
						pLaysAvail->nAvail++;
					}
					pPInfo++;
				}
			}
			pLaysAvail->nRow = row;
			pLaysAvail->nCol = col;
			pLaysAvail++;
			pSInfo++;
		}
		pRow += 32;
	}

//sort services according to number of available preachers, fewest first, zero at end
	qsort(pLaysAvailBase, (rows - 2) * (cols - 1), sizeof(LAYSAVAIL), CompareNumAvail);

//do while some preachers available at top of sorted list
	while (pLaysAvailBase->nAvail != 0)
	{
		pLaysAvail = pLaysAvailBase;

//compile list of available preachers for top of laysavail list
		LAYSLIST* pListBase = new LAYSLIST[pLaysAvail->nAvail];
		LAYSLIST* pList = pListBase;
		for (int i = 0; i < pLaysAvail->nAvail; i++)
		{
			pList->pLay = pLaysAvail->pLay[i];
			pList->prefs = pLaysAvail->pLay[i]->nToAllocate[pLaysAvail->nRow];
			pList++;
		}

		qsort(pListBase, pLaysAvail->nAvail, sizeof(LAYSLIST), CompareLays);

//allocate
		DoAllocate(pPInfo1Base, pSInfo1Base, pListBase->pLay, pLaysAvail->nRow, pLaysAvail->nCol);

//compile new list of available preachers
		pLaysAvail = pLaysAvailBase;
		pRow = pSInfo1Base + 32;
		for (row = 1; row < rows - 1; row++)
		{
			SINFO* pSInfo = pRow + 1;
			for (col = 1; col < cols; col++)
			{
				pLaysAvail->nAvail = 0;
				if (pSInfo->preacher == "")
				{
					pPInfo = pPInfo1Base;
					for (prch = 0; prch < nPreachers; prch++)
					{
						if (pPInfo->bsAvailFlags[row].test(col))
						{
							pLaysAvail->pLay[pLaysAvail->nAvail] = pPInfo;
							pLaysAvail->nAvail++;
						}
						pPInfo++;
					}
				}
				pLaysAvail->nRow = row;
				pLaysAvail->nCol = col;
				pLaysAvail++;
				pSInfo++;
			}
			pRow += 32;
		}

		qsort(pLaysAvailBase, (rows - 2) * (cols - 1), sizeof(LAYSAVAIL), CompareNumAvail);

		delete [] pListBase;

	};

	delete [] pLaysAvailBase;
}

int CPlanMakerDoc::CompareLays(const void *p1, const void *p2)
{
	LAYSLIST* pLay1 = (LAYSLIST*)p1;
	LAYSLIST* pLay2 = (LAYSLIST*)p2;

	if (pLay1->pLay->stipend && !pLay2->pLay->stipend)
		return -1;
	if (!pLay1->pLay->stipend && pLay2->pLay->stipend)
		return 1;

	if (pLay1->pLay->ordained && !pLay1->pLay->visitor && !(pLay2->pLay->ordained && !pLay2->pLay->visitor))
		return -1;
	if (!(pLay1->pLay->ordained && !pLay1->pLay->visitor) && pLay2->pLay->ordained && !pLay2->pLay->visitor)
		return 1;

	if (pLay1->prefs > pLay2->prefs)
		return -1;
	if (pLay1->prefs < pLay2->prefs)
		return 1;

	if (pLay1->pLay->nOnPlan < pLay2->pLay->nOnPlan)
		return -1;
	if (pLay1->pLay->nOnPlan > pLay2->pLay->nOnPlan)
		return 1;

	if (pLay1->pLay->screen_name < pLay2->pLay->screen_name)
		return -1;
	if (pLay1->pLay->screen_name > pLay2->pLay->screen_name)
		return 1;

	return 0;
}

int CPlanMakerDoc::CompareNumAvail(const void *p1, const void *p2)
{
	LAYSAVAIL* pServ1 = (LAYSAVAIL*)p1;
	LAYSAVAIL* pServ2 = (LAYSAVAIL*)p2;

	if (pServ1->nAvail == 0 && pServ2->nAvail != 0)
		return 1;
	if (pServ1->nAvail != 0 && pServ2->nAvail == 0)
		return -1;

	if (pServ1->nAvail < pServ2->nAvail)
		return -1;
	if (pServ1->nAvail > pServ2->nAvail)
		return 1;

	return 0;
}

BOOL CPlanMakerDoc::DoInsert(int nIndex, int nRow, int nCol, BOOL bInsert)
{
	PINFO* pPInfo = pPInfo1Base + nIndex;
//if local ord & prefs in nRow = insertions in nRow, increase pref by 1
	int nInsertions = 0;
	if (pPInfo->ordained && !pPInfo->visitor)
	{
		SINFO* pSInfo = pSInfo1Base + 32 * nRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (PreacherAppears(pPInfo, pSInfo) && pSInfo->reserved)
				nInsertions++;
			pSInfo++;
		}
		if (pPInfo->preferences[nRow] == nInsertions)
			pPInfo->preferences[nRow]++;
	}

//insert
	SINFO* pSInfo = pSInfo1Base + 32 * nRow + nCol;
	if (pSInfo->reserved && pSInfo->preacher != "")
	{
		pSInfo->preacher += " / ";
		pSInfo->preacher += pPInfo->screen_name;
	}
	else
	{
		pSInfo->preacher = pPInfo->screen_name;
		pSInfo->reserved = true;
	}
	BOOL bCanCompile = true;
	if (!bInsert)  //if a test insertion
	{
		DoTempInfo(pPInfo1Base, pPTmpInfoBase, pSInfo1Base, pSTmpInfoBase);
		bCanCompile = AllocateOrd(false);
	}
	return bCanCompile;
}

void CPlanMakerDoc::DoCustom(int index)
{
//deal with custom service details
	SINFO* pRow = pSInfo1Base + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (bSelected[row][col])
			{
				pSInfo->code = codestr[index - 1];
				pSInfo->detail = menustr[index - 1];
			}
			pSInfo++;
		}
		pRow += 32;
	}
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::DoServicesPopup(CPoint point)
{
	CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu* pMenu = menu.GetSubMenu(0);
	if (bUseSforComm)
		pMenu->ModifyMenu(ID_COMMUNION, MF_BYCOMMAND, ID_COMMUNION, "Sacrament");
	if (bUseAllAge)
		pMenu->ModifyMenu(ID_FAMILY, MF_BYCOMMAND, ID_FAMILY, "All Age Worship");

//custom service details popup
	CMenu* pCustom = pMenu->GetSubMenu(5);  //custom item
//make list of keys & codes
	int nItems = 0;
	SINFO* pRow = pSInfoBase + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (pSInfo->code != ""
				&& pSInfo->detail != "")
			{
				BOOL bDuplicate = false;
				for (int h = 0; h < nItems; h++)
				{
					if (codestr[h] == pSInfo->code)
					{
						bDuplicate = true;
						break;
					}
				}
				if (!bDuplicate && nItems < 200)
				{
					codestr[nItems] = pSInfo->code;
					menustr[nItems] = pSInfo->detail;
					nItems++;
				}
			}
			pSInfo++;
		}
		pRow += 32;
	}
//sort
CString tempcodestr;
CString tempmenustr;
BOOL swapped = true;
	while (swapped)
	{
		swapped = false;
		for (int i = 0; i < nItems - 1; i++)
		{
			if (codestr[i] > codestr[i + 1])
			{
				tempcodestr = codestr[i];
				tempmenustr = menustr[i];
				codestr[i] = codestr[i + 1];
				menustr[i] = menustr[i + 1];
				codestr[i + 1] = tempcodestr;
				menustr[i + 1] = tempmenustr;
				swapped = true;
			}
		}
	}
//put into menu
	int nIDC[24] =
	{
		ID_CUSTOM1, ID_CUSTOM2, ID_CUSTOM3, ID_CUSTOM4,
		ID_CUSTOM5, ID_CUSTOM6, ID_CUSTOM7, ID_CUSTOM8,
		ID_CUSTOM9, ID_CUSTOM10, ID_CUSTOM11, ID_CUSTOM12,
		ID_CUSTOM13, ID_CUSTOM14, ID_CUSTOM15, ID_CUSTOM16,
		ID_CUSTOM17, ID_CUSTOM18, ID_CUSTOM19, ID_CUSTOM20,
		ID_CUSTOM21, ID_CUSTOM22, ID_CUSTOM23, ID_CUSTOM24
	};
	pCustom->ModifyMenu(0, MF_BYPOSITION, nIDC[0], (const char *)menustr[0]);
	int i = 1;
	while (menustr[i] != "" && i < 24)
	{
		pCustom->AppendMenu(MF_BYCOMMAND, nIDC[i], (const char *)menustr[i]);
		i++;
	}
//if no items disable custom menu
	if (nItems == 0)
		pMenu->EnableMenuItem(5, MF_GRAYED | MF_BYPOSITION);

//count cells selected & count number marked as communions etc.
//check/uncheck menu items
	nSelected = 0; //global
	int nCommunion = 0;
	int nFamily = 0;
	int nParade = 0;
	int nBaptism = 0;
	int nUnited = 0;
	nNoService = 0; //global
	int nReserved = 0;
	int nCustom[24] = {0};
	pRow = pSInfoBase + 32;
	for (row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (bSelected[row][col])
			{
				nSelected++;
				if (pSInfo->communion)
					nCommunion++;
				if (pSInfo->family)
					nFamily++;
				if (pSInfo->parade)
					nParade++;
				if (pSInfo->baptism)
					nBaptism++;
				if (pSInfo->united)
					nUnited++;
				if (pSInfo->no_service)
					nNoService++;
				if (pSInfo->reserved)
					nReserved++;
				for (int i = 0; i < 24; i++) //custom details
				{
					if (pSInfo->detail == menustr[i])
						nCustom[i]++;
				}
			}
			pSInfo++;
		}
		pRow += 32;
	}

//check menu items where appropriate
	if (nSelected == nCommunion)
		pMenu->CheckMenuItem(ID_COMMUNION, MF_CHECKED);
	else
		pMenu->CheckMenuItem(ID_COMMUNION, MF_UNCHECKED);
	if (nSelected == nFamily)
		pMenu->CheckMenuItem(ID_FAMILY, MF_CHECKED);
	else
		pMenu->CheckMenuItem(ID_FAMILY, MF_UNCHECKED);
	if (nSelected == nParade)
		pMenu->CheckMenuItem(ID_PARADE, MF_CHECKED);
	else
		pMenu->CheckMenuItem(ID_PARADE, MF_UNCHECKED);
	if (nSelected == nBaptism)
		pMenu->CheckMenuItem(ID_BAPTISM, MF_CHECKED);
	else
		pMenu->CheckMenuItem(ID_BAPTISM, MF_UNCHECKED);
	if (nSelected == nUnited)
		pMenu->CheckMenuItem(ID_UNITED, MF_CHECKED);
	else
		pMenu->CheckMenuItem(ID_UNITED, MF_UNCHECKED);
	if (nSelected == nNoService)
	{
		pMenu->CheckMenuItem(ID_NOSERVICE, MF_CHECKED);
		pMenu->EnableMenuItem(5, MF_GRAYED | MF_BYPOSITION); //disable custom menu item
	}
	else
		pMenu->CheckMenuItem(ID_NOSERVICE, MF_UNCHECKED);
	if (nSelected == nReserved)
		pMenu->CheckMenuItem(ID_RESERVED, MF_CHECKED);
	else
		pMenu->CheckMenuItem(ID_RESERVED, MF_UNCHECKED);
	for (i = 0; i < 24; i++) //custom details
	{
		if (nSelected == nCustom[i])
			pCustom->CheckMenuItem(i, MF_CHECKED | MF_BYPOSITION);
		else
			pCustom->CheckMenuItem(i, MF_UNCHECKED | MF_BYPOSITION);
	}

//insert minister popup
	if (nSelected == 1) //only append menu items if 1 cell selected
	{
		CMenu* pInsert = pMenu->GetSubMenu(9);
		SINFO* pSInfo = pSInfo1Base + 32 * nSelRow + nSelCol;
		if (!pSInfo->no_service)
		{
			int nIDM[12] =
			{
				ID_INSERT0, ID_INSERT1, ID_INSERT2, ID_INSERT3,
				ID_INSERT4, ID_INSERT5, ID_INSERT6, ID_INSERT7,
				ID_INSERT8, ID_INSERT9, ID_INSERT10, ID_INSERT11
			};
			pInsert->AppendMenu(MF_BYPOSITION | MF_SEPARATOR, 2);
			int nItems = GetAvailablePrchs(nSelRow, nSelCol, true); //local ords only
			CString strNM = "No Ministers";
			int i = 0;
			if (nItems == 0)
			{
				pInsert->AppendMenu(MF_BYPOSITION | MF_GRAYED, 0, (const char *)strNM);
			}
			else
			{
				while (i < nItems)
				{
					pInsert->AppendMenu(MF_BYCOMMAND, nIDM[i],
						(pPInfoBase + nAvailPrchIndex[i])->first_name + " "
						+ (pPInfoBase + nAvailPrchIndex[i])->last_name);
					nPrchIns[i] = nAvailPrchIndex[i];
					i++;
				}
			}
		}
	}

//delete preacher popup
	if (nSelected == 1)
	{
		CMenu* pDelete = pMenu->GetSubMenu(10);
		int nIDP[4] =
		{
			ID_DELETE0, ID_DELETE1, ID_DELETE2, ID_DELETE3,
		};
		CString strPrch[4];
		int nItems = 0;
		PINFO* pPInfo = pPInfoBase;
		SINFO* pSInfo = pSInfoBase + 32 * nSelRow + nSelCol;
		for (int prch = 0; prch < nPreachers; prch++)
		{
			if (PreacherAppears(pPInfo, pSInfo))
			{
				strPrch[nItems] = pPInfo->first_name + " " + pPInfo->last_name;
				nPrchDel[nItems] = pPInfo - pPInfoBase;
				nItems++;
				if (nItems == 4) //cant have more than 4
					break;
			}
			pPInfo++;
		}
		if (nItems > 1)
		{
			CString strPrch1 = "All Preachers";
			pDelete->ModifyMenu(ID_DELPREACHER, MF_BYCOMMAND, ID_DELPREACHER, strPrch1);
			pDelete->AppendMenu(MF_BYPOSITION |MF_SEPARATOR, 2);
			int i = 0;
			while (i < nItems)
			{
				pDelete->AppendMenu(MF_BYCOMMAND, nIDP[i], (const char *)strPrch[i]);
				i++;
			}
		}
	}
	
	CMainFrame* pMain = (CMainFrame*)AfxGetMainWnd();
	pMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x - 100, point.y, pMain);
}

int CPlanMakerDoc::GetAvailablePrchs(int nRow, int nCol, BOOL bOrds)
{
	SINFO* pSelRow = pSInfoBase + 32 * nRow;  //sel row col 0
	SINFO* pSInfo = pSelRow + nCol;
	int nPrchs = 0;
	int nGrp = pSelRow->group;
	char grp = pSelRow->group + (char)0x30;
	CString strIncompat = (char)0x01 + pSelRow->strChurchCode + grp;
	PINFO* pPInfo = pPInfoBase;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		BOOL bIsAvailable = true;
		if (bOrds && !(pPInfo->ordained && !pPInfo->visitor && !pPInfo->reserved))
			bIsAvailable = false;
//can't insert if not available or prefs = 15 or nPrchs = 64
		if (bIsAvailable && !(pPInfo->availability[nCol] & nGrp) || pPInfo->preferences[nRow] == 15 || nPrchs == 64)
			bIsAvailable = false;
//can't insert if appears anywhere in this col & group (inserted or allocated)
//or if appears in incompatible church in this col
		if (bIsAvailable)
		{
			SINFO* pRow = pSInfoBase + 32;
			for (int row = 1; row < rows - 1; row++)
			{
				SINFO* pSInfo = pRow + nCol;
				if (PreacherAppears(pPInfo, pSInfo)
					&& (pRow->group == nGrp || pRow->place_time.Find(strIncompat) != -1))
				{
					bIsAvailable = false;
					break;
				}
				pRow += 32;
			}	
		}
//if not authorised, can insert if an authorised already inserted
		if (bIsAvailable)
		{
			SINFO* pSInfo = pSelRow + nCol;
			if ((pSInfo->communion && !pPInfo->authorised[nRow]))
			{
				PINFO* pPInfo1 = pPInfoBase;
				for (int prch = 0; prch < nPreachers; prch++)
				{
					if (pSInfo->reserved
						&& PreacherAppears(pPInfo1, pSInfo)
						&& pPInfo1->authorised[nRow])
						break;
					pPInfo1++;
				}
				if (pPInfo1 == pPInfoBase + nPreachers)
					bIsAvailable = false; //didn't find an authorised
			}
			if (pSInfo->family && !pPInfo->family[nRow])
			{
				PINFO* pPInfo1 = pPInfoBase;
				for (int prch = 0; prch < nPreachers; prch++)
				{
					if (pSInfo->reserved
						&& PreacherAppears(pPInfo1, pSInfo)
						&& pPInfo1->family[nRow])
						break;
					pPInfo1++;
				}
				if (pPInfo1 == pPInfoBase + nPreachers)
					bIsAvailable = false; //didn't find an authorised
			}
			if (pSInfo->parade && !pPInfo->parade[nRow])
			{
				PINFO* pPInfo1 = pPInfoBase;
				for (int prch = 0; prch < nPreachers; prch++)
				{
					if (pSInfo->reserved
						&& PreacherAppears(pPInfo1, pSInfo)
						&& pPInfo1->parade[nRow])
						break;
					pPInfo1++;
				}
				if (pPInfo1 == pPInfoBase + nPreachers)
					bIsAvailable = false; //didn't find an authorised
			}
		}
//can't insert if plan won't compile
//try the insertion
		if (bIsAvailable)
		{
			bIsAvailable = DoInsert(prch, nRow, nCol, false); //trial insertion into info1
			DoTempInfo(pPInfoBase, pPInfo1Base, pSInfoBase, pSInfo1Base);  // restore info1
		}
//if ok, add to array
		if (bIsAvailable)
		{
			nAvailPrchIndex[nPrchs] = prch;
			nPrchs++;
		}
		pPInfo++;
	}

	if (bOrds && nPrchs > 12)
		return 12;
	return nPrchs;
}

void CPlanMakerDoc::OnFileClose() 
{
//prompt to save
	switch(MessageBox(NULL, "Do you want to save any changes that you have made?", "PlanMaker", MB_YESNOCANCEL | MB_ICONQUESTION))
	{
	case IDYES: OnFileSave();
				break;
	case IDNO:  break;
	default: return;
	}

//reload plan.dat
	CFile file;
	if (!file.Open(strPathDat, CFile::modeRead))
	{
		MessageBox(NULL, "The default plan data file could not be opened.", "PlanMaker", MB_OK | MB_ICONEXCLAMATION);
		return;
	}
	CArchive ar(&file, CArchive::load);
	Serialize(ar);
	ar.Close();
	file.Close();
	filename = "";
	CPoint pt;
	pt.x = pt.y = 0;
	CMainFrame* pMain = (CMainFrame*)AfxGetMainWnd();
	CPlanMakerView* pPlanView = (CPlanMakerView*)pMain->GetActiveView();
	pPlanView->ScrollToPosition(pt);
	bShowAvailPrchs = false;
	bEnableUndo = false;
	bEnableRedo = false;
	bPlanResized = true;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnFileNew() 
{
	CString str = "";
	str += "This command will create a new default Plan based on the currently displayed Plan. ";
	str += "Your existing default Plan (this is the Plan you see when you start PlanMaker) will be ";
	str += "overwritten. If you are doing this from a previously saved file that you have opened, ";
	str += "the saved file will be unaffected.\n\n";
	str += "Are you sure that you wish to proceed?";
	if (IDNO == ::MessageBox(NULL, str, "PlanMaker", MB_YESNO | MB_ICONINFORMATION))
		return;
//store preachers from last col in col 0
	SINFO* pRow = pSInfo1Base + 32;  //row 1 col 0
	SINFO* pLastCol = pRow + cols - 1;  //last col
	for (int row = 1; row < rows - 1; row++)
	{
		pRow->preacher = pLastCol->preacher;
		pRow += 32;
		pLastCol += 32;
	}

//clear allocations for local ordained
//weightings for lay preachers & visitors retained
	PINFO* pPInfo = pPInfo1Base;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		SINFO* pRow = pSInfo1Base + 32;
		for (int row = 1; row < rows - 1; row++)
		{
			pPInfo->bUsedLastPlan[row] = false;
			SINFO* pSInfo = pRow + 1;
			for (int col = 1; col < cols; col++)
			{
				if (PreacherAppears(pPInfo, pSInfo)
		
					&& ((pPInfo->ordained && !pPInfo->visitor
							&& pPInfo->preferences[row] == 0)
					|| (!pPInfo->ordained || pPInfo->visitor)))
					
					pPInfo->bUsedLastPlan[row] = true;
				pSInfo++;
			}
			if (pPInfo->ordained && !pPInfo->visitor)
				pPInfo->preferences[row] = 0;
			pRow += 32;
		}
		pPInfo++;
	}

//clear dates & service info
	SINFO* pSInfo = pSInfo1Base + 1;  //row 0 col 1
	for (int col = 1; col < cols; col++)
	{
		pSInfo->date = "";		
		pSInfo++;
	}
	pRow = pSInfo1Base + 32;
	for (row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols ; col++)
		{
			pSInfo->communion = false;
			pSInfo->family = false;
			pSInfo->parade = false;
			pSInfo->baptism = false;
			pSInfo->united = false;
			pSInfo->no_service = false;
			pSInfo->reserved = false;
			pSInfo->preacher = "";
			pSInfo->nAvailPrchs = 0;
			pSInfo->detail = "";
			pSInfo->code = "";
			pSInfo++;
		}
		pRow += 32;
	}
	filename = "";
	cols = 1;
	bAllocationDone = false;
	bAllocPending = false;
	bFitWidth = false;
	bShowAvailPrchs = false;
	bEnableUndo = true;
	bEnableRedo = false;
	bPlanResized = true;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnFileOpen() 
{
	if (filename != "")
	{
		switch(MessageBox(NULL, "Do you want to save any changes that you have made to the file that's already open?", "PlanMaker", MB_YESNOCANCEL | MB_ICONQUESTION))
		{
		case IDYES: OnFileSave();
					break;
		case IDNO:  break;
		default: return;
		}
	}
	CFileDialog dlg(true, NULL, NULL, NULL, "Plan Data Files|*.pln||");
	ITEMIDLIST idl;
	LPITEMIDLIST pidl = &idl;
	SHGetSpecialFolderLocation(NULL, CSIDL_PERSONAL, &pidl);
	char buf[MAX_PATH] = {0};
	SHGetPathFromIDList(pidl, buf);
	strcat(buf, "\\Planmaker");
	dlg.m_ofn.lpstrInitialDir = buf;
	strcat(buf, "\\*.pln");
	dlg.m_ofn.lpstrFile = buf;

	if (IDOK != dlg.DoModal())
		return;
	filename = dlg.GetPathName();
	CFile file;
	if (!file.Open(filename, CFile::modeRead))
	{
		MessageBox(NULL, "The file could not be opened.", "PlanMaker", MB_OK | MB_ICONERROR);
		return;
	}
	CArchive ar(&file, CArchive::load);
	Serialize(ar);
	ar.Close();
	file.Close();
	CPoint pt;
	pt.x = pt.y = 0;
	CMainFrame* pMain = (CMainFrame*)AfxGetMainWnd();
	CPlanMakerView* pPlanView = (CPlanMakerView*)pMain->GetActiveView();
	pPlanView->ScrollToPosition(pt);
	bShowAvailPrchs = false;
	bPlanResized = true;
	bEnableUndo = false;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::RemoveNamedPreacher(PINFO *pPInfo, SINFO *pSInfo)
{
//removes preacher from multi-preacher service and reduces pref if local ord
//applies to listed preachers in services popup & delete preacher menu item
//service is reserved (multiple preachers)
	int find = pSInfo->preacher.Find(pPInfo->screen_name);
	if (find == 0)  //first
		pSInfo->preacher = pSInfo->preacher.Mid(find + 3 + pPInfo->screen_name.GetLength());
	else
	{
		find = pSInfo->preacher.Find(" / " + pPInfo->screen_name);
		pSInfo->preacher = pSInfo->preacher.Left(find) + pSInfo->preacher.Mid(find + 3 + pPInfo->screen_name.GetLength());
	}
	if (pPInfo->ordained && !pPInfo->visitor && pPInfo->preferences[nSelRow] != 0)
		pPInfo->preferences[nSelRow]--;
}

void CPlanMakerDoc::DoTempInfo(PINFO* pPSrc, PINFO* pPDest, SINFO* pSSrc, SINFO* pSDest)
{
//preacher info
	PINFO* pPInfoSrc = pPSrc;
	PINFO* pPInfoDest = pPDest;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		*pPInfoDest = *pPInfoSrc;
		pPInfoSrc++;
		pPInfoDest++;
	}

//service info
	SINFO* pRowSrc = pSSrc;
	SINFO* pRowDest = pSDest;
	for (int row = 0; row < rows - 1; row++)
	{
		SINFO* pSInfoSrc = pRowSrc;
		SINFO* pSInfoDest = pRowDest;
		for (int col = 0; col < cols; col++)
		{
			*pSInfoDest = *pSInfoSrc;
			pSInfoSrc++;
			pSInfoDest++;
		}
		pRowSrc += 32;
		pRowDest += 32;
	}
}

CPlanMakerDoc* CPlanMakerDoc::GetDoc()
{
	CFrameWnd * pFrame = (CFrameWnd *)(AfxGetApp()->m_pMainWnd);
    return (CPlanMakerDoc *) pFrame->GetActiveDocument();
}

void CPlanMakerDoc::OnBaptism() 
{
	int nServicesSelected = 0;
	int nBaptisms = 0;
	SINFO* pRow = pSInfo1Base + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (bSelected[row][col] && !pSInfo->no_service) //don't count where no_service
			{
				nServicesSelected++;
				if (pSInfo->baptism)
					nBaptisms++;
			}
			pSInfo++;
		}
		pRow += 32;
	}
	pRow = pSInfo1Base + 32;
	for (row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (bSelected[row][col])
			{
				if (pSInfo->no_service)
					pSInfo->baptism = false;
				else if (nServicesSelected == nBaptisms)
					pSInfo->baptism = false; //if all set, unset all
				else
					pSInfo->baptism = true; //if not all set, set all

				if (pSInfo->baptism && pSInfo->preacher != "") //check preacher
				{
					BOOL bPreacherOk = false;
					PINFO* pPInfo = pPInfo1Base;
					for (int prch = 0; prch < nPreachers; prch++)
					{
						if (PreacherAppears(pPInfo, pSInfo))
						{
							if (pPInfo->ordained)
								bPreacherOk = true;
						}
						pPInfo++;
					}
					if (!bPreacherOk)
					{
						nSelRow = row;
						nSelCol = col;
						OnDeleteAll();
					}
				}
			}
			pSInfo++;
		}
		pRow += 32;
	}
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnUnited() 
{
	int nServicesSelected = 0;
	int nUnited = 0;
	SINFO* pRow = pSInfo1Base + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (bSelected[row][col] && !pSInfo->no_service) //don't count where no_service
			{
				nServicesSelected++;
				if (pSInfo->united)
					nUnited++;
			}
			pSInfo++;
		}
		pRow += 32;
	}
	pRow = pSInfo1Base + 32;
	for (row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (bSelected[row][col])
			{
				if (pSInfo->no_service)
					pSInfo->united = false;
				else if (nServicesSelected == nUnited)
					pSInfo->united = false; //if all set, unset all
				else
					pSInfo->united = true; //if not all set, set all
			}
			pSInfo++;
		}
		pRow += 32;
	}
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnReserved() 
{
	int nServicesSelected = 0;
	int nReserved = 0;
	SINFO* pRow = pSInfo1Base + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (bSelected[row][col] && !pSInfo->no_service) //don't count where no_service
			{
				nServicesSelected++;
				if (pSInfo->reserved)
					nReserved++;
			}
			pSInfo++;
		}
		pRow += 32;
	}
	pRow = pSInfo1Base + 32;
	for (row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (bSelected[row][col])
			{
				if (pSInfo->no_service)
					pSInfo->reserved = false;
				else if (nServicesSelected == nReserved)
					pSInfo->reserved = false; //if all set, unset all
				else
					pSInfo->reserved = true; //if not all set, set all
			}
			pSInfo++;
		}
		pRow += 32;
	}
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnCommunion() 
{
//count how many cells selected and how many are communions
	int nServicesSelected = 0;
	int nCommunions = 0;
	SINFO* pRow = pSInfo1Base + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (bSelected[row][col] && !pSInfo->no_service) //don't count where no_service
			{
				nServicesSelected++;
				if (pSInfo->communion)
					nCommunions++;
			}
			pSInfo++;
		}
		pRow += 32;
	}

//decide what to do based on nSelected & nCommunions
	pRow = pSInfo1Base + 32;
	for (row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (bSelected[row][col])
			{
				if (pSInfo->no_service)
					pSInfo->communion = false;
				else if (nServicesSelected == nCommunions)
					pSInfo->communion = false; //if all set, unset all
				else
					pSInfo->communion = true; //if not all set, set all

				if (pSInfo->communion && pSInfo->preacher != "") //check preacher if present
				{
					BOOL bPreacherOk = false;
					PINFO* pPInfo = pPInfo1Base;
					for (int prch = 0; prch < nPreachers; prch++)
					{
						if (PreacherAppears(pPInfo, pSInfo))
						{
							if (pPInfo->authorised[row])
								bPreacherOk = true;
						}
						pPInfo++;
					}
					if (!bPreacherOk)
					{
						nSelRow = row;
						nSelCol = col;
						OnDeleteAll();
					}
				}
			}
			pSInfo++;
		}
		pRow += 32;
	}
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnCustom1() 
{
	DoCustom(1);
}

void CPlanMakerDoc::OnCustom2() 
{
	DoCustom(2);
}

void CPlanMakerDoc::OnCustom3() 
{
	DoCustom(3);
}

void CPlanMakerDoc::OnCustom4() 
{
	DoCustom(4);
}

void CPlanMakerDoc::OnCustom5()
{
	DoCustom(5);
}

void CPlanMakerDoc::OnCustom6()
{
	DoCustom(6);
}

void CPlanMakerDoc::OnCustom7()
{
	DoCustom(7);
}

void CPlanMakerDoc::OnCustom8()
{
	DoCustom(8);
}

void CPlanMakerDoc::OnCustom9()
{
	DoCustom(9);
}

void CPlanMakerDoc::OnCustom10()
{
	DoCustom(10);
}

void CPlanMakerDoc::OnCustom11()
{
	DoCustom(11);
}
void CPlanMakerDoc::OnCustom12()
{
	DoCustom(12);
}

void CPlanMakerDoc::OnCustom13()
{
	DoCustom(13);
}

void CPlanMakerDoc::OnCustom14()
{
	DoCustom(14);
}

void CPlanMakerDoc::OnCustom15()
{
	DoCustom(15);
}

void CPlanMakerDoc::OnCustom16()
{
	DoCustom(16);
}

void CPlanMakerDoc::OnCustom17()
{
	DoCustom(17);
}
void CPlanMakerDoc::OnCustom18()
{
	DoCustom(18);
}

void CPlanMakerDoc::OnCustom19()
{
	DoCustom(19);
}

void CPlanMakerDoc::OnCustom20()
{
	DoCustom(20);
}

void CPlanMakerDoc::OnCustom21()
{
	DoCustom(21);
}

void CPlanMakerDoc::OnCustom22()
{
	DoCustom(22);
}

void CPlanMakerDoc::OnCustom23()
{
	DoCustom(23);
}

void CPlanMakerDoc::OnCustom24()
{
	DoCustom(24);
}

void CPlanMakerDoc::OnFamily() 
{
	int nServicesSelected = 0;
	int nFamily = 0;
	SINFO* pRow = pSInfo1Base + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (bSelected[row][col] && !pSInfo->no_service) //don't count where no_service
			{
				nServicesSelected++;
				if (pSInfo->family)
					nFamily++;
			}
			pSInfo++;
		}
		pRow += 32;
	}
	pRow = pSInfo1Base + 32;
	for (row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (bSelected[row][col])
			{
				if (pSInfo->no_service)
					pSInfo->family = false;
				else if (nServicesSelected == nFamily)
					pSInfo->family = false; //if all set, unset all
				else
					pSInfo->family = true; //if not all set, set all

				if (pSInfo->family && pSInfo->preacher != "") //check preacher
				{
					BOOL bPreacherOk = false;
					PINFO* pPInfo = pPInfo1Base;
					for (int prch = 0; prch < nPreachers; prch++)
					{
						if (PreacherAppears(pPInfo, pSInfo))
						{
							if (pPInfo->family[row])
								bPreacherOk = true;
						}
						pPInfo++;
					}
					if (!bPreacherOk)
					{
						nSelRow = row;
						nSelCol = col;
						OnDeleteAll();
					}
				}
			}
			pSInfo++;
		}
		pRow += 32;
	}
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnInsPreacher() 
{
	CInsertDlg dlg;
	if (IDOK != dlg.DoModal())
		return;
	DoInsert(dlg.nSelPrch, nSelRow, nSelCol, true);
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnDetail() 
{
	CDetailDlg dlg;
	if (IDOK !=dlg.DoModal())
		return;
	SINFO* pRow = pSInfo1Base + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (bSelected[row][col])
			{
				pSInfo->detail = dlg.m_detail;
				pSInfo->code = dlg.m_code;
			}
			pSInfo++;
		}
		pRow += 32;
	}
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnDeldetail() 
{
	SINFO* pRow = pSInfo1Base + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (bSelected[row][col])
			{
				pSInfo->detail = "";
				pSInfo->code = "";
			}
			pSInfo++;
		}
		pRow += 32;
	}
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnPreacherdel() 
{
	CChoosePrDel dlg;
	if (IDOK != dlg.DoModal())
		return;
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnPreacheredit() 
{
	CChooseEditDlg dlg; //open the choose dlg
	if (IDOK != dlg.DoModal())
		return;
	CEditPreacherDlg dlg1; //open the edit dlg
	if (IDOK != dlg1.DoModal())
		return;
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnPreachernew() 
{
	if (nPreachers >= 199)
	{
		MessageBox(NULL, "The Preachers database is full and you cannot add any more. If you really need more Preachers, contact the program author to see if PlanMaker can be customised for you.", "PlanMaker", MB_OK | MB_ICONINFORMATION);
		return;
	}
	CPreacherDlg dlg;
	if (IDOK != dlg.DoModal())
		return;
	Store();
}

void CPlanMakerDoc::OnParade() 
{
	int nServicesSelected = 0;
	int nParade = 0;
	SINFO* pRow = pSInfo1Base + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (bSelected[row][col] && !pSInfo->no_service) //don't count where no_service
			{
				nServicesSelected++;
				if (pSInfo->parade)
					nParade++;
			}
			pSInfo++;
		}
		pRow += 32;
	}
	pRow = pSInfo1Base + 32;
	for (row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (bSelected[row][col])
			{
				if (pSInfo->no_service)
					pSInfo->parade = false;
				else if (nServicesSelected == nParade)
					pSInfo->parade = false; //if all set, unset all
				else
					pSInfo->parade = true; //if not all set, set all

				if (pSInfo->parade && pSInfo->preacher != "") //check preacher
				{
					BOOL bPreacherOk = false;
					PINFO* pPInfo = pPInfo1Base;
					for (int prch = 0; prch < nPreachers; prch++)
					{
						if (PreacherAppears(pPInfo, pSInfo))
						{
							if (pPInfo->parade[row])
								bPreacherOk = true;
						}
						pPInfo++;
					}
					if (!bPreacherOk)
					{
						nSelRow = row;
						nSelCol = col;
						OnDeleteAll();
					}
				}
			}
			pSInfo++;
		}
		pRow += 32;
	}
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnNoservice() 
{
	int nServicesSelected = 0;
	int nNoService = 0;
	SINFO* pRow = pSInfo1Base + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (bSelected[row][col])
			{
				nServicesSelected++;
				if (pSInfo->no_service)
					nNoService++;
			}
			pSInfo++;
		}
		pRow += 32;
	}
	pRow = pSInfo1Base + 32;
	for (row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (bSelected[row][col])
			{
				if (nServicesSelected == nNoService) //if all set, unset all
					pSInfo->no_service = false;
				else //if not all set, set all
					pSInfo->no_service = true;

				if (pSInfo->no_service && pSInfo->preacher != "") //remove preacher if no service
				{
					PINFO* pPInfo = pPInfo1Base;
					for (int prch = 0; prch < nPreachers; prch++)
					{
						if (PreacherAppears(pPInfo, pSInfo) //if local ord or reserved preacher
							&& ((pPInfo->ordained && !pPInfo->visitor) || pPInfo->reserved))
						{
							if (pSInfo->reserved) //reduce prefs if inserted (may be more than 1)
							{
								if (pPInfo->preferences[row] != 0)
									pPInfo->preferences[row]--;
							}
							else //reduce prefs if plan won't compile (can only be 1)
							{
								pSInfo->preacher = "";
								pSInfo->reserved = true; //temporarily reserve so can't be allocated here in test allocation
								DoTempInfo(pPInfo1Base, pPTmpInfoBase, pSInfo1Base, pSTmpInfoBase);
								if (!AllocateOrd(false) && pPInfo->preferences[row] != 0)
									pPInfo->preferences[row]--;
							}
						}
						pPInfo++;
					}
				}
				pSInfo->preacher = "";
				pSInfo->reserved = false;
				pSInfo->communion = false;
				pSInfo->family = false;
				pSInfo->parade = false;
				pSInfo->baptism = false;
				pSInfo->united = false;
				pSInfo->detail = "";
				pSInfo->code = "";
			}
			pSInfo++;
		}
		pRow += 32;
	}
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnPreacheravail() 
{
	CPrchAvailDlg dlg;
	if (IDOK != dlg.DoModal())
		return;
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnPreacherPrefs()
{
	CPrchPrefsDlg dlg;
	if (IDOK != dlg.DoModal())
		return;
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnPreachersDeallocate()
{
	SINFO* pRow = pSInfo1Base + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (!pSInfo->reserved)
				pSInfo->preacher = "";
			pSInfo++;
		}
		pRow += 32;
	}
	bAllocationDone = false;
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnPreachersClearall()
{
//this removes all preachers from all services
	CString str = "";
	str += "This command will clear all the Preachers from your Plan, ";
	str += "including any you have inserted, and reset the allocations ";
	str += "for Local Ordained Ministers to zero. If you proceed ";
	str += "by mistake, immediately click Edit | Undo and your Plan ";
	str += "will be restored.\n\n";
	str += "Are you sure that you wish to proceed?";
	if (IDNO == MessageBox(NULL, str, "PlanMaker", MB_YESNO | MB_ICONEXCLAMATION))
		return;
	SINFO* pRow = pSInfo1Base + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			pSInfo->preacher = "";
			pSInfo->reserved = false;
			pSInfo++;
		}
		pRow += 32;
	}
	PINFO* pPInfo = pPInfo1Base;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		for (int row = 1; row < rows - 1; row++)
		{
			if (pPInfo->ordained && !pPInfo->visitor)
				pPInfo->preferences[row] = 0;
		}
		pPInfo++;
	}
	bAllocationDone = false;
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnFileOptions() 
{
	COptionsDlg dlg;
	if (IDOK != dlg.DoModal())
		return;
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnPreachersResetoptions() 
{
	PINFO* pPInfo = pPInfo1Base;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		pPInfo->nLimit = -1;
		pPInfo->no_consec = false;
		pPInfo->one_service = false;
		pPInfo++;
	}
	bAllocPending = true;
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnPreachersResetweightings() 
{
	for (int row = 1; row < rows - 1; row++)
	{
		PINFO* pPInfo = pPInfo1Base;
		for (int prch = 0; prch < nPreachers; prch++)
		{
			if (!pPInfo->ordained
				|| pPInfo->visitor )
				pPInfo->preferences[row] = 1;
			pPInfo++;
		}
	}
	bAllocPending = true;
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnInsert0() 
{
	DoInsert(nPrchIns[0], nSelRow, nSelCol, true);
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnInsert1() 
{
	DoInsert(nPrchIns[1], nSelRow, nSelCol, true);
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnInsert2() 
{
	DoInsert(nPrchIns[2], nSelRow, nSelCol, true);
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnInsert3() 
{
	DoInsert(nPrchIns[3], nSelRow, nSelCol, true);
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnInsert4() 
{
	DoInsert(nPrchIns[4], nSelRow, nSelCol, true);
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnInsert5() 
{
	DoInsert(nPrchIns[5], nSelRow, nSelCol, true);
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnInsert6() 
{
	DoInsert(nPrchIns[6], nSelRow, nSelCol, true);
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnInsert7() 
{
	DoInsert(nPrchIns[7], nSelRow, nSelCol, true);
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnInsert8() 
{
	DoInsert(nPrchIns[8], nSelRow, nSelCol, true);
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnInsert9() 
{
	DoInsert(nPrchIns[9], nSelRow, nSelCol, true);
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnInsert10() 
{
	DoInsert(nPrchIns[10], nSelRow, nSelCol, true);
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnInsert11() 
{
	DoInsert(nPrchIns[11], nSelRow, nSelCol, true);
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnDeleteAll()
{
//delete all preachers from a service (preacher or all preachers menu item)
//if reserved reduce prefs for local ords
//if not reserved & local ord, do a test allocation & reduce prefs if won't compile
	SINFO* pSInfo = pSInfo1Base + 32 * nSelRow + nSelCol;
	PINFO* pPInfo = pPInfo1Base;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		if (PreacherAppears(pPInfo, pSInfo) //if local ord or reserved preacher
			&& ((pPInfo->ordained && !pPInfo->visitor) || pPInfo->reserved))
		{
			if (pSInfo->reserved) //reduce prefs if inserted (may be more than 1)
			{
				if (pPInfo->preferences[nSelRow] != 0)
					pPInfo->preferences[nSelRow]--;
			}
			else //reduce prefs if plan won't compile (can only be 1)
			{
				pSInfo->preacher = "";
				pSInfo->reserved = true; //temporarily reserve so can't be allocated here in test allocation
				DoTempInfo(pPInfo1Base, pPTmpInfoBase, pSInfo1Base, pSTmpInfoBase);
				if (!AllocateOrd(false) && pPInfo->preferences[nSelRow] != 0)
					pPInfo->preferences[nSelRow]--;
			}
		}
		pPInfo++;
	}
	pSInfo->preacher = "";
	pSInfo->reserved = false;
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnDelete0() 
{
	RemoveNamedPreacher(pPInfo1Base + nPrchDel[0], pSInfo1Base + 32 * nSelRow + nSelCol);
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnDelete1() 
{
	RemoveNamedPreacher(pPInfo1Base + nPrchDel[1], pSInfo1Base + 32 * nSelRow + nSelCol);
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnDelete2() 
{
	RemoveNamedPreacher(pPInfo1Base + nPrchDel[2], pSInfo1Base + 32 * nSelRow + nSelCol);
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnDelete3() 
{
	RemoveNamedPreacher(pPInfo1Base + nPrchDel[3], pSInfo1Base + 32 * nSelRow + nSelCol);
	bEnableUndo = true;

	bEnableRedo = false;
	SetModifiedFlag();
}

void CPlanMakerDoc::OnPreachersAvailablityfileExport() 
{
//write the .ini file
	CFile file;
	if (!file.Open(strPath + "\\Availability.pma", CFile::modeCreate | CFile::modeWrite))
	{
		MessageBox(NULL, "The availability file could not be created.", "PlanMaker", MB_OK);
		return;
	}
	CString str = "Planmaker availability file - do not edit this file!";
	str += 0x0d;
	str += 0x0a;
	file.Write(str, str.GetLength());

	str = '=';
	str += 0x40;
	str += 0x0d;
	str += 0x0a;

	SINFO* pSInfo = pSInfoBase + 1;
	for (int col = 1; col < cols; col++)
	{
		CString date;
		int find = pSInfo->date.Find(0x0d);
		if (find != -1)
			date = pSInfo->date.Left(find);
		else
			date = pSInfo->date;
		find = (date.Find(" 20")); //discard the year
		if (find != -1)
			date = date.Left(find);
		file.Write(date, date.GetLength());
		file.Write(str, str.GetLength());
		pSInfo++;
	}

	file.Close();

	MessageBox(NULL, "The file has been saved to " + strPath + "\\Availability.pma", "PlanMaker", MB_OK);
}

CString strForm;

void CPlanMakerDoc::OnPreachersAvailablityfileImport() 
{
//get the file to open
	CFileDialog dlg(true, NULL, NULL, NULL, "Planmaker Availability Forms|*.pma||");
	ITEMIDLIST idl;
	LPITEMIDLIST pidl = &idl;
	SHGetSpecialFolderLocation(NULL, CSIDL_PERSONAL, &pidl);
	char buf[MAX_PATH] = {0};
	SHGetPathFromIDList(pidl, buf);
	strcat(buf, "\\Planmaker");
	dlg.m_ofn.lpstrInitialDir = buf;
	strcat(buf, "\\*.pma");
	dlg.m_ofn.lpstrFile = buf;

	if (IDOK != dlg.DoModal())
		return;
	CString path = dlg.GetPathName();
	CString filename = dlg.GetFileName();

//open & read the file
	CFile file;
	if (!file.Open(path, CFile::modeRead))
	{
		MessageBox(NULL, "The availability file could not be opened.", "PlanMaker", MB_OK | MB_ICONERROR);
		return;
	}
	char buffer[1024] = {0};
	if (file.GetLength() < 1024)
	{
		file.Read(buffer, file.GetLength());
		strForm = CString(buffer);
		CString strHeader = "Planmaker availability file - do not edit this file!";
		strHeader += 0x0d;
		strHeader += 0x0a;
		if (strForm.Find(strHeader) == -1)
		{
			MessageBox(NULL, "The file is not a valid PlanMaker Availability Form.", "PlanMaker", MB_OK | MB_ICONERROR);
			file.Close();
			return;
		}
	}
	else
	{
		MessageBox(NULL, "The file could not be opened: buffer overflow.", "PlanMaker", MB_OK | MB_ICONERROR);
		file.Close();
		return;
	}
	file.Close();
	
//see if right dates in import file
//discard header
	CString dateAvail;
	CString datePlan;
	int nDates = 0;
	int find = strForm.Find(0x0d);
	strForm = strForm.Mid(find + 2);

//check dates
	for (int i = 0; i < 30; i++)
	{
		find = strForm.Find('=');
		if (find != -1)
		{
			dateAvail = strForm.Left(find);
			strForm = strForm.Mid(find + 4);
			nDates++;
			SINFO* pSInfo = pSInfo1Base + i + 1;
			if (pSInfo < pSInfo1Base + cols)
			{
				find = pSInfo->date.Find(0x0d);
				if (find != -1)
					datePlan = pSInfo->date.Left(find);
				else
					datePlan = pSInfo->date;
				find = (datePlan.Find(" 20"));
				if (find != -1)
					datePlan = datePlan.Left(find);
			}
			else
				break;
			if (dateAvail != datePlan)
			{
				MessageBox(NULL, "The dates in the import form do not match the dates in the Plan: import cannot proceed.", 
					"PlanMaker", MB_OK);
				return;
			}
		}
		else
			break;
	}

//check number of dates
	if (nDates != cols - 1)
	{
		MessageBox(NULL, "The number of dates in the import form differs from the number of dates in the Plan: import cannot proceed.", 
			"PlanMaker", MB_OK);
		return;
	}

//if ok proceed
//get the preacher
	CImportDlg dlg2;
	if (IDOK != dlg2.DoModal())
		return;
	PINFO* pPInfo = pPInfo1Base + dlg2.m_nSelprch;

	strForm = (CString)buffer;
//show form if requested
	if (dlg2.m_check)
	{
		CShowFormDlg dlg3;
		if (IDOK != dlg3.DoModal())
			return;
		strForm = CString(buffer);
	}

//import it
	for (int col = 1; col < cols; col++)
	{
		find = strForm.Find('=');
		if (find != -1)
		{
			pPInfo->availability[col] = strForm.GetAt(find + 1) & ~0x40;
			strForm = strForm.Mid(find + 4);
		}
	}

//delete the file unless it's the exported file
	if (filename != "Availability.pma")
		file.Remove(path);

	bAllocPending = true;
	bEnableUndo = true;
	bEnableRedo = false;
	SetModifiedFlag();
}

BOOL CPlanMakerDoc::RecreateDataFiles()
{
	CString str = "Your plan data files could not be found.\n\n";
	str += "If you are running PlanMaker for the first time, ";
	str += "click Yes to create a new, empty file. Otherwise, click No and a File Open Dialog will appear to ";
	str += "allow you to open one of your saved files. A plan data file based on this file will then be created, ";
	str += "but the file you opened will not be affected.\n\n";
	str += "Do you want to create a new, empty data file?";
	if (IDYES == MessageBox(NULL, str, "PlanMaker", MB_YESNO | MB_ICONEXCLAMATION))
	{
//initialise an empty plan
		rows = 2;
		cols = 1;
		nPreachers = 0;
//label defaults
		_across = "0";
		_down = "0";
		_left = "0";
		_top = "0";
		_hoff = "0";
		_voff = "0";
		_font = "0";
//plan printing defaults
		lpFont->lfHeight = 0;
		lpFont->lfWidth = 0;
		lpFont->lfEscapement = 0;
		lpFont->lfOrientation = 0;
		lpFont->lfWeight = 0;
		lpFont->lfItalic = 0;
		lpFont->lfUnderline = 0;
		lpFont->lfStrikeOut = 0;
		lpFont->lfCharSet = 0;
		lpFont->lfOutPrecision = 0;
		lpFont->lfClipPrecision = 0;
		lpFont->lfQuality = 0;
		lpFont->lfPitchAndFamily = 0;
		lpFont->lfFaceName, "";
		crPlanFontColor = 0x00000000;
		if (GetFileAttributes(strPath) == -1) //if My Documents\Planmaker folder doesn't exist, create it
			CreateDirectory(strPath, NULL);
		CFile file;
		file.Open(strPathDat, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		Serialize(ar);
		ar.Close();
		file.Close();
		CopyFile(strPathDat, strPathBak, false);
		bAllocationDone = false;
	}
	else
	{
		CFileDialog dlg(true, NULL, NULL, NULL, "Plan Data Files|*.pln||");
		ITEMIDLIST idl;
		LPITEMIDLIST pidl = &idl;
		SHGetSpecialFolderLocation(NULL, CSIDL_PERSONAL, &pidl);
		char buf[MAX_PATH] = {0};
		SHGetPathFromIDList(pidl, buf);
		strcat(buf, "\\Planmaker");
		dlg.m_ofn.lpstrInitialDir = buf;
		strcat(buf, "\\*.pln");
		dlg.m_ofn.lpstrFile = buf;

		if (IDOK != dlg.DoModal())
			return false;
		filename = dlg.GetPathName();
		CFile file;
		if (!file.Open(filename, CFile::modeRead))
		{
			MessageBox(NULL, "The file could not be opened.", "PlanMaker", MB_OK | MB_ICONERROR);
			return false;
		}
		CArchive ar(&file, CArchive::load);
		Serialize(ar);
		ar.Close();
		file.Close();
		if (GetFileAttributes(strPath) == -1) //if My Documents\Planmaker folder doesn't exist, create it
			CreateDirectory(strPath, NULL);
		CopyFile(filename, strPathDat, false);
		CopyFile(filename, strPathBak, false);
		filename = "";
		DoTempInfo(pPInfo1Base, pPInfoBase, pSInfo1Base, pSInfoBase); //info1 to info
		UpdatePlan(false);
		bPlanResized = false;
	}
	bEnableUndo = false;
	bEnableRedo = false;
	return true;
}

void CPlanMakerDoc::UpdatePlan(BOOL bGetAvailPrchs)
{
	CWaitCursor wait;
	DoStatusBar();
	if (bPlanResized)
		CreateChurchCodes();
	CompileDisplayStrings(bGetAvailPrchs);
}

CString CPlanMakerDoc::GetCellInfo(int row, int col)
{
//get service info for dates/churches display or print/printpreview
	SINFO* pSInfo = pSInfo1Base + 32 * row + col;

	if (row == 0)
		return pSInfo->date;

	if (col == 0)
	{
		CString strPlaceTime = pSInfo->place_time;
		int find = strPlaceTime.Find(0x01);
		if (find != -1)
			strPlaceTime = strPlaceTime.Left(find);
		return strPlaceTime;
	}

	CString str = "";
	if (pSInfo->no_service && bPrintPlan)
	{
		if (bPrintNoService)
		{
			if (pSInfo->code != "")
				str = "No Service " + pSInfo->code;
			else
				pSInfo->detail != "" ? str = "No Service " + pSInfo->detail : str = "No Service";
		}
		else if (bPrintNoServiceExcl)
		{
			if (pSInfo->code != "")
				str = pSInfo->code;
			else
				pSInfo->detail != "" ? str = pSInfo->detail : str = "No Service";
		}
		else
			pSInfo->code != "" ? str = pSInfo->code : str = pSInfo->detail;
		return str;
	}

//look for local ords first
	PINFO* pPInfo = pPInfo1Base;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		if (pPInfo->ordained && !pPInfo->visitor)
		{
			if (PreacherAppears(pPInfo, pSInfo))
			{
				if (str != "")
					str += " / ";
				str += pPInfo->screen_name;
			}
		}
		pPInfo++;
	}
//then lays, visitors & reserved
	pPInfo = pPInfo1Base;
	for (prch = 0; prch < nPreachers; prch++)
	{
		if (!pPInfo->ordained || pPInfo->visitor || pPInfo->reserved)
		{
			if (PreacherAppears(pPInfo, pSInfo))
			{
				if (str != "")
					str += " / ";
				str += pPInfo->screen_name;
			}
		}
		pPInfo++;
	}
//service details
	if (pSInfo->communion)
	{
		if (bUseSforComm)
			str += str == "" ? "S" : " S";
		else
			str += str == "" ? "C" : " C";
	}
	if (pSInfo->family)
	{
		if (bUseAllAge)
			str += str == "" ? "AA" : " AA";
		else
			str += str == "" ? "F" : " F";
	}
	if (pSInfo->parade)
		str += str == "" ? "P" : " P";
	if (pSInfo->baptism)
		str += str == "" ? "B" : " B";
	if (pSInfo->united)
		str += str == "" ? "U" : " U";
	if (pSInfo->code != "")
		str += str == "" ? pSInfo->code : " " + pSInfo->code;
	else if (pSInfo->detail != "")
		str += str == "" ? pSInfo->detail : " " + pSInfo->detail;

	return str;
}

void CPlanMakerDoc::CreateChurchCodes()
{
//create church codes
//only include upper & lower case letters
//break when number reached
	CString strChurchCode[200]; //contains whole thing up to first number
	SINFO* pSInfo = pSInfoBase + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		pSInfo->strChurchCode = "";
		strChurchCode[row] = "";
		for (int i = 0; i < pSInfo->place_time.GetLength(); i++)
		{
			char chr = pSInfo->place_time.GetAt(i);
			if (chr >= 0x30 && chr <= 0x39)
				break;
			if ((chr >= 0x41 && chr <= 0x5a)
				|| (chr >= 0x61 && chr <= 0x7a))
			{
				strChurchCode[row] += chr;
			}
		}
		pSInfo->strChurchCode = strChurchCode[row].Left(4);
		pSInfo += 32;
	}

//check for duplicates
//if duplicated, take 1st 3 letters and 1st that is different
	pSInfo = pSInfoBase + 32;
	for (row = 1; row < rows - 1; row++)
	{
		for (int row1 = row + 1; row1 < rows - 1; row1++)
		{
			if (pSInfo->strChurchCode == strChurchCode[row1].Left(4)  //1st 4 letters duplicated
				&& strChurchCode[row1] != strChurchCode[row])  //whole thing different
			{
				for (int h = 0; h < strChurchCode[row].GetLength() && h < strChurchCode[row1].GetLength(); h++)
				{
					if (strChurchCode[row].GetAt(h) != strChurchCode[row1].GetAt(h))
					{
						pSInfo->strChurchCode = strChurchCode[row].Left(3) + strChurchCode[row].GetAt(h);
//						pSInfo1->strChurchCode = pSInfo1->strChurchCode_tmp.Left(3) + pSInfo1->strChurchCode_tmp.GetAt(h);
						break;
					}
				}
			}
		}
		pSInfo += 32;
	}

//copy to info1 - needed for incompatible churches dialog
	pSInfo = pSInfoBase + 32;
	SINFO* pSInfo1 = pSInfo1Base + 32;
	for (row = 1; row < rows - 1; row++)
	{
		pSInfo1->strChurchCode = pSInfo->strChurchCode;
		pSInfo += 32;
		pSInfo1 += 32;
	}
}

void CPlanMakerDoc::DoStatusBar()
{
//see how many services there are
//how many are allocated,
//how many are unallocated and reserved
	nTotalServices = 0;
	nServicesAllocated = 0;
	nUnallocReserved = 0;
	SINFO* pRow = pSInfoBase + 32;
	for (int row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			if (!pSInfo->no_service)
			{
				nTotalServices++;
				if (pSInfo->preacher != "")
					nServicesAllocated++;
				else if (pSInfo->reserved)
					nUnallocReserved++;
			}
			pSInfo++;
		}
		pRow += 32;
	}
}

int CPlanMakerDoc::GetPreacherAppearances(PINFO *pPInfo, int row, BOOL bUseSInfoBase)
{
	if (row == -1) //count all appearances
	{
		pPInfo->nOnPlan = 0;
		SINFO* pRow;
		if (bUseSInfoBase)
			pRow = pSInfoBase + 32;
		else
			pRow = pSInfo1Base + 32;
		for (int row = 1; row < rows - 1; row++)
		{
			SINFO* pSInfo = pRow + 1;
			for (int col = 1; col < cols; col++)
			{
				if (PreacherAppears(pPInfo, pSInfo))
					pPInfo->nOnPlan++;
				pSInfo++;
			}
			pRow += 32;
		}
		return pPInfo->nOnPlan;
	}
	else //count appearances in row
	{
		pPInfo->nInRow[row] = 0;
		SINFO* pSInfo = pSInfoBase + 32 * row + 1;
		for (int col = 1; col < cols; col++)
		{
			if (PreacherAppears(pPInfo, pSInfo))
				pPInfo->nInRow[row]++;
			pSInfo++;
		}
		return pPInfo->nInRow[row];
	}
}

BOOL CPlanMakerDoc::SaveModified() 
{
	if (filename != "")
	{
		CFile file;
		switch(MessageBox(NULL, "Do you want to save any changes that you have made?", "PlanMaker", MB_YESNOCANCEL | MB_ICONQUESTION))
		{
		case IDYES: OnFileSave();
					break;
		case IDNO:  break;
		default: return 0;
		}
	}
	return CDocument::SaveModified();
}

void CPlanMakerDoc::OnFileSave() 
{
	CFile file;
	file.Open(filename, CFile::modeWrite);
	CArchive ar(&file, CArchive::store);
	Serialize(ar);
	ar.Close();
	file.Close();
}	

void CPlanMakerDoc::CompileDisplayStrings(BOOL bGetAvailPrchs)
{
//get preacher appearances into pPInfo
//ords by row
	for (int row = 1; row < rows - 1; row++)
	{
		PINFO* pPInfo = pPInfoBase;
		for (int prch = 0; prch < nPreachers; prch++)
		{
			if (pPInfo->ordained && !pPInfo->visitor)
				pPInfo->nInRow[row] = GetPreacherAppearances(pPInfo, row, true);
			pPInfo++;
		}
	}
//lays, visitors & reserved by plan
	PINFO* pPInfo = pPInfoBase;
	for (int prch = 0; prch < nPreachers; prch++)
	{
		if (!pPInfo->ordained || pPInfo->visitor || pPInfo->reserved)
			pPInfo->nOnPlan = GetPreacherAppearances(pPInfo, -1, true);
		pPInfo++;
	}

//compile service type & detail display strings
	SINFO* pRow = pSInfoBase + 32;
	for (row = 1; row < rows - 1; row++)
	{
		SINFO* pSInfo = pRow + 1;
		for (int col = 1; col < cols; col++)
		{
			CString str = "";
			if (pSInfo->communion)
				str += (bUseSforComm) ? "S" : "C";
			if (pSInfo->family)
			{
				if (bUseAllAge)
					str += str == "" ? "AA" : " AA";
				else
					str += str == "" ? "F" : " F";
			}
			if (pSInfo->parade)
				str += str == "" ? "P" : " P";
			if (pSInfo->baptism)
				str += str == "" ? "B" : " B";
			if (pSInfo->united)
				str += str == "" ? "U" : " U";
			if (pSInfo->code != "")
				str += str == "" ? pSInfo->code : " " + pSInfo->code;
			else if (pSInfo->detail != "")
				str += str == "" ? pSInfo->detail : " " + pSInfo->detail;
			strDetails[row][col] = str;
			pSInfo++;
		}
		pRow += 32;
	}

//compile prchs avail strings if needed
	if (bGetAvailPrchs)
	{
		SINFO* pRow = pSInfoBase;
		for (int row = 0; row < rows - 1; row++)
		{
			SINFO* pSInfo = pRow;
			for (int col = 0; col < cols; col++)
			{
				CString str = "";
				if (pSInfo->preacher == "" && !pSInfo->no_service)
				{
					pSInfo->nAvailPrchs = GetAvailablePrchs(row, col, false);
					if (str != "")
						str += "\r\n";
					str += IntToStr(pSInfo->nAvailPrchs) + " available";
				}
				strAvailPrchs[row][col] = str;
				pSInfo++;
			}
			pRow += 32;
		}
	}
}




