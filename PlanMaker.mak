# Microsoft Developer Studio Generated NMAKE File, Based on Plan.dsp
!IF "$(CFG)" == ""
CFG=Plan - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Plan - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Plan - Win32 Release" && "$(CFG)" != "Plan - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Plan.mak" CFG="Plan - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Plan - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Plan - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "Plan - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : ".\hlp\Plan.hm" ".\Release\Plan.hlp" ".\Release\Plan.cnt" "$(OUTDIR)\Plan.exe"


CLEAN :
	-@erase "$(INTDIR)\Block2Dlg.obj"
	-@erase "$(INTDIR)\BlockDlg.obj"
	-@erase "$(INTDIR)\CannotBlockDlg.obj"
	-@erase "$(INTDIR)\CannotUnblockDlg.obj"
	-@erase "$(INTDIR)\ChooseEditDlg.obj"
	-@erase "$(INTDIR)\ChoosePrDel.obj"
	-@erase "$(INTDIR)\ColumnView.obj"
	-@erase "$(INTDIR)\ConfirmClearDlg.obj"
	-@erase "$(INTDIR)\CornerView.obj"
	-@erase "$(INTDIR)\DetailDlg.obj"
	-@erase "$(INTDIR)\Dialog1.obj"
	-@erase "$(INTDIR)\EditPreacherDlg.obj"
	-@erase "$(INTDIR)\InvPrchDlg1.obj"
	-@erase "$(INTDIR)\InvPrchDlg2.obj"
	-@erase "$(INTDIR)\InvPrchDlg3.obj"
	-@erase "$(INTDIR)\LabelDlg.obj"
	-@erase "$(INTDIR)\LayNotUsedDlg.obj"
	-@erase "$(INTDIR)\LocalOrdDlg.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\NoMoreChurchesDlg.obj"
	-@erase "$(INTDIR)\NoMoreDatesDlg.obj"
	-@erase "$(INTDIR)\NoMorePreachersDlg.obj"
	-@erase "$(INTDIR)\NotAvailDlg.obj"
	-@erase "$(INTDIR)\NotFilledDlg.obj"
	-@erase "$(INTDIR)\OptionsDlg.obj"
	-@erase "$(INTDIR)\OrdNotAllocDlg.obj"
	-@erase "$(INTDIR)\PlaceTimeDlg.obj"
	-@erase "$(INTDIR)\Plan.obj"
	-@erase "$(INTDIR)\Plan.pch"
	-@erase "$(INTDIR)\Plan.res"
	-@erase "$(INTDIR)\PlanDoc.obj"
	-@erase "$(INTDIR)\PlanView.obj"
	-@erase "$(INTDIR)\PrchAvailDlg2.obj"
	-@erase "$(INTDIR)\PrchNotKnownDlg.obj"
	-@erase "$(INTDIR)\PreacherDlg.obj"
	-@erase "$(INTDIR)\RowView.obj"
	-@erase "$(INTDIR)\SaveCurrent.obj"
	-@erase "$(INTDIR)\ServiceDayDlg.obj"
	-@erase "$(INTDIR)\SortAccredited.obj"
	-@erase "$(INTDIR)\SortCalendar.obj"
	-@erase "$(INTDIR)\SortPreachers.obj"
	-@erase "$(INTDIR)\Splash1.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Plan.exe"
	-@erase ".\Release\Plan.cnt"
	-@erase ".\Release\Plan.hlp"
	-@erase "hlp\Plan.hm"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Plan.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x809 /fo"$(INTDIR)\Plan.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Plan.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=Winmm.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Plan.pdb" /machine:I386 /out:"$(OUTDIR)\Plan.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Block2Dlg.obj" \
	"$(INTDIR)\BlockDlg.obj" \
	"$(INTDIR)\CannotBlockDlg.obj" \
	"$(INTDIR)\CannotUnblockDlg.obj" \
	"$(INTDIR)\ChooseEditDlg.obj" \
	"$(INTDIR)\ChoosePrDel.obj" \
	"$(INTDIR)\ColumnView.obj" \
	"$(INTDIR)\ConfirmClearDlg.obj" \
	"$(INTDIR)\CornerView.obj" \
	"$(INTDIR)\DetailDlg.obj" \
	"$(INTDIR)\Dialog1.obj" \
	"$(INTDIR)\EditPreacherDlg.obj" \
	"$(INTDIR)\InvPrchDlg1.obj" \
	"$(INTDIR)\InvPrchDlg2.obj" \
	"$(INTDIR)\InvPrchDlg3.obj" \
	"$(INTDIR)\LabelDlg.obj" \
	"$(INTDIR)\LayNotUsedDlg.obj" \
	"$(INTDIR)\LocalOrdDlg.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\NoMoreChurchesDlg.obj" \
	"$(INTDIR)\NoMoreDatesDlg.obj" \
	"$(INTDIR)\NoMorePreachersDlg.obj" \
	"$(INTDIR)\NotAvailDlg.obj" \
	"$(INTDIR)\NotFilledDlg.obj" \
	"$(INTDIR)\OptionsDlg.obj" \
	"$(INTDIR)\OrdNotAllocDlg.obj" \
	"$(INTDIR)\PlaceTimeDlg.obj" \
	"$(INTDIR)\Plan.obj" \
	"$(INTDIR)\PlanDoc.obj" \
	"$(INTDIR)\PlanView.obj" \
	"$(INTDIR)\PrchAvailDlg2.obj" \
	"$(INTDIR)\PrchNotKnownDlg.obj" \
	"$(INTDIR)\PreacherDlg.obj" \
	"$(INTDIR)\RowView.obj" \
	"$(INTDIR)\SaveCurrent.obj" \
	"$(INTDIR)\ServiceDayDlg.obj" \
	"$(INTDIR)\SortAccredited.obj" \
	"$(INTDIR)\SortCalendar.obj" \
	"$(INTDIR)\SortPreachers.obj" \
	"$(INTDIR)\Splash1.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Plan.res"

"$(OUTDIR)\Plan.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Plan - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Plan.exe"


CLEAN :
	-@erase "$(INTDIR)\Block2Dlg.obj"
	-@erase "$(INTDIR)\BlockDlg.obj"
	-@erase "$(INTDIR)\CannotBlockDlg.obj"
	-@erase "$(INTDIR)\CannotUnblockDlg.obj"
	-@erase "$(INTDIR)\ChooseEditDlg.obj"
	-@erase "$(INTDIR)\ChoosePrDel.obj"
	-@erase "$(INTDIR)\ColumnView.obj"
	-@erase "$(INTDIR)\ConfirmClearDlg.obj"
	-@erase "$(INTDIR)\CornerView.obj"
	-@erase "$(INTDIR)\DetailDlg.obj"
	-@erase "$(INTDIR)\Dialog1.obj"
	-@erase "$(INTDIR)\EditPreacherDlg.obj"
	-@erase "$(INTDIR)\InvPrchDlg1.obj"
	-@erase "$(INTDIR)\InvPrchDlg2.obj"
	-@erase "$(INTDIR)\InvPrchDlg3.obj"
	-@erase "$(INTDIR)\LabelDlg.obj"
	-@erase "$(INTDIR)\LayNotUsedDlg.obj"
	-@erase "$(INTDIR)\LocalOrdDlg.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\NoMoreChurchesDlg.obj"
	-@erase "$(INTDIR)\NoMoreDatesDlg.obj"
	-@erase "$(INTDIR)\NoMorePreachersDlg.obj"
	-@erase "$(INTDIR)\NotAvailDlg.obj"
	-@erase "$(INTDIR)\NotFilledDlg.obj"
	-@erase "$(INTDIR)\OptionsDlg.obj"
	-@erase "$(INTDIR)\OrdNotAllocDlg.obj"
	-@erase "$(INTDIR)\PlaceTimeDlg.obj"
	-@erase "$(INTDIR)\Plan.obj"
	-@erase "$(INTDIR)\Plan.pch"
	-@erase "$(INTDIR)\Plan.res"
	-@erase "$(INTDIR)\PlanDoc.obj"
	-@erase "$(INTDIR)\PlanView.obj"
	-@erase "$(INTDIR)\PrchAvailDlg2.obj"
	-@erase "$(INTDIR)\PrchNotKnownDlg.obj"
	-@erase "$(INTDIR)\PreacherDlg.obj"
	-@erase "$(INTDIR)\RowView.obj"
	-@erase "$(INTDIR)\SaveCurrent.obj"
	-@erase "$(INTDIR)\ServiceDayDlg.obj"
	-@erase "$(INTDIR)\SortAccredited.obj"
	-@erase "$(INTDIR)\SortCalendar.obj"
	-@erase "$(INTDIR)\SortPreachers.obj"
	-@erase "$(INTDIR)\Splash1.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Plan.exe"
	-@erase "$(OUTDIR)\Plan.ilk"
	-@erase "$(OUTDIR)\Plan.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Plan.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x809 /fo"$(INTDIR)\Plan.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Plan.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=Winmm.lib Winspool.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Plan.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Plan.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Block2Dlg.obj" \
	"$(INTDIR)\BlockDlg.obj" \
	"$(INTDIR)\CannotBlockDlg.obj" \
	"$(INTDIR)\CannotUnblockDlg.obj" \
	"$(INTDIR)\ChooseEditDlg.obj" \
	"$(INTDIR)\ChoosePrDel.obj" \
	"$(INTDIR)\ColumnView.obj" \
	"$(INTDIR)\ConfirmClearDlg.obj" \
	"$(INTDIR)\CornerView.obj" \
	"$(INTDIR)\DetailDlg.obj" \
	"$(INTDIR)\Dialog1.obj" \
	"$(INTDIR)\EditPreacherDlg.obj" \
	"$(INTDIR)\InvPrchDlg1.obj" \
	"$(INTDIR)\InvPrchDlg2.obj" \
	"$(INTDIR)\InvPrchDlg3.obj" \
	"$(INTDIR)\LabelDlg.obj" \
	"$(INTDIR)\LayNotUsedDlg.obj" \
	"$(INTDIR)\LocalOrdDlg.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\NoMoreChurchesDlg.obj" \
	"$(INTDIR)\NoMoreDatesDlg.obj" \
	"$(INTDIR)\NoMorePreachersDlg.obj" \
	"$(INTDIR)\NotAvailDlg.obj" \
	"$(INTDIR)\NotFilledDlg.obj" \
	"$(INTDIR)\OptionsDlg.obj" \
	"$(INTDIR)\OrdNotAllocDlg.obj" \
	"$(INTDIR)\PlaceTimeDlg.obj" \
	"$(INTDIR)\Plan.obj" \
	"$(INTDIR)\PlanDoc.obj" \
	"$(INTDIR)\PlanView.obj" \
	"$(INTDIR)\PrchAvailDlg2.obj" \
	"$(INTDIR)\PrchNotKnownDlg.obj" \
	"$(INTDIR)\PreacherDlg.obj" \
	"$(INTDIR)\RowView.obj" \
	"$(INTDIR)\SaveCurrent.obj" \
	"$(INTDIR)\ServiceDayDlg.obj" \
	"$(INTDIR)\SortAccredited.obj" \
	"$(INTDIR)\SortCalendar.obj" \
	"$(INTDIR)\SortPreachers.obj" \
	"$(INTDIR)\Splash1.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Plan.res"

"$(OUTDIR)\Plan.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Plan.dep")
!INCLUDE "Plan.dep"
!ELSE 
!MESSAGE Warning: cannot find "Plan.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Plan - Win32 Release" || "$(CFG)" == "Plan - Win32 Debug"
SOURCE=.\Block2Dlg.cpp

"$(INTDIR)\Block2Dlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\BlockDlg.cpp

"$(INTDIR)\BlockDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\CannotBlockDlg.cpp

"$(INTDIR)\CannotBlockDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\CannotUnblockDlg.cpp

"$(INTDIR)\CannotUnblockDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\ChooseEditDlg.cpp

"$(INTDIR)\ChooseEditDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\ChoosePrDel.cpp

"$(INTDIR)\ChoosePrDel.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\ColumnView.cpp

"$(INTDIR)\ColumnView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\ConfirmClearDlg.cpp

"$(INTDIR)\ConfirmClearDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\CornerView.cpp

"$(INTDIR)\CornerView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\DetailDlg.cpp

"$(INTDIR)\DetailDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\Dialog1.cpp

"$(INTDIR)\Dialog1.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\EditPreacherDlg.cpp

"$(INTDIR)\EditPreacherDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\InvPrchDlg1.cpp

"$(INTDIR)\InvPrchDlg1.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\InvPrchDlg2.cpp

"$(INTDIR)\InvPrchDlg2.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\InvPrchDlg3.cpp

"$(INTDIR)\InvPrchDlg3.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\LabelDlg.cpp

"$(INTDIR)\LabelDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\LayNotUsedDlg.cpp

"$(INTDIR)\LayNotUsedDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\LocalOrdDlg.cpp

"$(INTDIR)\LocalOrdDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\MainFrm.cpp

"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\NoMoreChurchesDlg.cpp

"$(INTDIR)\NoMoreChurchesDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\NoMoreDatesDlg.cpp

"$(INTDIR)\NoMoreDatesDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\NoMorePreachersDlg.cpp

"$(INTDIR)\NoMorePreachersDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\NotAvailDlg.cpp

"$(INTDIR)\NotAvailDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\NotFilledDlg.cpp

"$(INTDIR)\NotFilledDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\OptionsDlg.cpp

"$(INTDIR)\OptionsDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\OrdNotAllocDlg.cpp

"$(INTDIR)\OrdNotAllocDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\PlaceTimeDlg.cpp

"$(INTDIR)\PlaceTimeDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\Plan.cpp

"$(INTDIR)\Plan.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\hlp\Plan.hpj

!IF  "$(CFG)" == "Plan - Win32 Release"

OutDir=.\Release
InputPath=.\hlp\Plan.hpj
InputName=Plan

"$(INTDIR)\Plan.hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	start /wait hcw /C /E /M "hlp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "hlp\$(InputName).hlp" goto :Error 
	copy "hlp\$(InputName).hlp" $(OutDir) 
	goto :done 
	:Error 
	echo hlp\$(InputName).hpj(1) : error: 
	type "hlp\$(InputName).log" 
	:done 
<< 
	

!ELSEIF  "$(CFG)" == "Plan - Win32 Debug"

!ENDIF 

SOURCE=.\Plan.rc

"$(INTDIR)\Plan.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\PlanDoc.cpp

"$(INTDIR)\PlanDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\PlanView.cpp

"$(INTDIR)\PlanView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\PrchAvailDlg2.cpp

"$(INTDIR)\PrchAvailDlg2.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\PrchNotKnownDlg.cpp

"$(INTDIR)\PrchNotKnownDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\PreacherDlg.cpp

"$(INTDIR)\PreacherDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\RowView.cpp

"$(INTDIR)\RowView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\SaveCurrent.cpp

"$(INTDIR)\SaveCurrent.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\ServiceDayDlg.cpp

"$(INTDIR)\ServiceDayDlg.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\SortAccredited.cpp

"$(INTDIR)\SortAccredited.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\SortCalendar.cpp

"$(INTDIR)\SortCalendar.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\SortPreachers.cpp

"$(INTDIR)\SortPreachers.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\Splash1.cpp

"$(INTDIR)\Splash1.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Plan.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Plan - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Plan.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Plan.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Plan - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\Plan.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\Plan.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Resource.h

!IF  "$(CFG)" == "Plan - Win32 Release"

TargetName=Plan
InputPath=.\Resource.h

".\hlp\Plan.hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	echo. >"hlp\$(TargetName).hm" 
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm" 
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm" 
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm" 
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm" 
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm" 
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm" 
<< 
	

!ELSEIF  "$(CFG)" == "Plan - Win32 Debug"

!ENDIF 

SOURCE=.\hlp\Plan.cnt

!IF  "$(CFG)" == "Plan - Win32 Release"

OutDir=.\Release
InputPath=.\hlp\Plan.cnt
InputName=Plan

"$(INTDIR)\Plan.cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	<<tempfile.bat 
	@echo off 
	copy "hlp\$(InputName).cnt" $(OutDir)
<< 
	

!ELSEIF  "$(CFG)" == "Plan - Win32 Debug"

!ENDIF 


!ENDIF 

