# Microsoft Developer Studio Project File - Name="PlanMaker" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=PlanMaker - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "PlanMaker.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PlanMaker.mak" CFG="PlanMaker - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PlanMaker - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "PlanMaker - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "PlanMaker - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x809 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 htmlhelp.lib /nologo /subsystem:windows /machine:I386 /nodefaultlib:"LIBCMT"
# SUBTRACT LINK32 /nodefaultlib

!ELSEIF  "$(CFG)" == "PlanMaker - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x809 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x809 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 htmlhelp.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "PlanMaker - Win32 Release"
# Name "PlanMaker - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AnalysisColumnView.cpp
# End Source File
# Begin Source File

SOURCE=.\AnalysisCornerView.cpp
# End Source File
# Begin Source File

SOURCE=.\AnalysisRowView.cpp
# End Source File
# Begin Source File

SOURCE=.\AnalysisView3.cpp
# End Source File
# Begin Source File

SOURCE=.\AnalysisWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\ChooseEditDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ChoosePrDel.cpp
# End Source File
# Begin Source File

SOURCE=.\ColumnView.cpp
# End Source File
# Begin Source File

SOURCE=.\CornerView.cpp
# End Source File
# Begin Source File

SOURCE=.\DetailDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgTemplate.cpp
# End Source File
# Begin Source File

SOURCE=.\EditPreacherDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ImportDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\IncompatDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\InsertDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LabelDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\mersenne.cpp
# End Source File
# Begin Source File

SOURCE=.\OptionsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PlaceTimeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PlanMaker.cpp
# End Source File
# Begin Source File

SOURCE=.\PlanMaker.rc
# End Source File
# Begin Source File

SOURCE=.\PlanMakerDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\PlanMakerView.cpp
# End Source File
# Begin Source File

SOURCE=.\PrchAvailDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PrchPrefsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PreacherDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RowView.cpp
# End Source File
# Begin Source File

SOURCE=.\ServiceDayDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ShowFormDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SortAccredited.cpp
# End Source File
# Begin Source File

SOURCE=.\SortPreachers.cpp
# End Source File
# Begin Source File

SOURCE=.\Splash1.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AnalysisColumnView.h
# End Source File
# Begin Source File

SOURCE=.\AnalysisCornerView.h
# End Source File
# Begin Source File

SOURCE=.\AnalysisRowView.h
# End Source File
# Begin Source File

SOURCE=.\AnalysisView3.h
# End Source File
# Begin Source File

SOURCE=.\AnalysisWnd.h
# End Source File
# Begin Source File

SOURCE=.\ChooseEditDlg.h
# End Source File
# Begin Source File

SOURCE=.\ChoosePrDel.h
# End Source File
# Begin Source File

SOURCE=.\ColumnView.h
# End Source File
# Begin Source File

SOURCE=.\CornerView.h
# End Source File
# Begin Source File

SOURCE=.\DetailDlg.h
# End Source File
# Begin Source File

SOURCE=.\DlgTemplate.h
# End Source File
# Begin Source File

SOURCE=.\EditPreacherDlg.h
# End Source File
# Begin Source File

SOURCE=.\ImportDlg.h
# End Source File
# Begin Source File

SOURCE=.\IncompatDlg.h
# End Source File
# Begin Source File

SOURCE=.\InsertDlg.h
# End Source File
# Begin Source File

SOURCE=.\LabelDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\OptionsDlg.h
# End Source File
# Begin Source File

SOURCE=.\PlaceTimeDlg.h
# End Source File
# Begin Source File

SOURCE=.\PlanMaker.h
# End Source File
# Begin Source File

SOURCE=.\PlanMakerDoc.h
# End Source File
# Begin Source File

SOURCE=.\PlanMakerView.h
# End Source File
# Begin Source File

SOURCE=.\PrchAvailDlg.h
# End Source File
# Begin Source File

SOURCE=.\PrchPrefsDlg.h
# End Source File
# Begin Source File

SOURCE=.\PreacherDlg.h
# End Source File
# Begin Source File

SOURCE=.\randomc.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RowView.h
# End Source File
# Begin Source File

SOURCE=.\ServiceDayDlg.h
# End Source File
# Begin Source File

SOURCE=.\ShowFormDlg.h
# End Source File
# Begin Source File

SOURCE=.\SortAccredited.h
# End Source File
# Begin Source File

SOURCE=.\SortPreachers.h
# End Source File
# Begin Source File

SOURCE=.\Splash1.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\icon3.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon4.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon5.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon6.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon7.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon8.ico
# End Source File
# Begin Source File

SOURCE=.\res\PlanMaker.ico
# End Source File
# Begin Source File

SOURCE=.\res\PlanMaker.rc2
# End Source File
# Begin Source File

SOURCE=.\res\PlanMakerDoc.ico
# End Source File
# Begin Source File

SOURCE=.\Splsh16.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
