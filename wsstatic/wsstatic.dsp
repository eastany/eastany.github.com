# Microsoft Developer Studio Project File - Name="wsstatic" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=wsstatic - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "wsstatic.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "wsstatic.mak" CFG="wsstatic - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "wsstatic - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "wsstatic - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "Perforce Project"
# PROP Scc_LocalPath ".."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "wsstatic - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "../include" /D "NDEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "_MSVC" /D "_AFXDLL" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../lib/wsstatic.lib"

!ELSEIF  "$(CFG)" == "wsstatic - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /ML /W3 /Gm /GX /ZI /Od /I "../include" /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "_MSVC" /YX /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"../lib/wsstaticd.lib"

!ENDIF 

# Begin Target

# Name "wsstatic - Win32 Release"
# Name "wsstatic - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "jpeg"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\JPEG\DECODE.C
# End Source File
# Begin Source File

SOURCE=..\JPEG\HUFFMAN.C
# End Source File
# Begin Source File

SOURCE=..\JPEG\IDCT.C
# End Source File
# Begin Source File

SOURCE=..\JPEG\JPEG.CPP
# End Source File
# Begin Source File

SOURCE=..\jpeg\jpegint.h
# End Source File
# Begin Source File

SOURCE=..\JPEG\Quanty.c
# End Source File
# Begin Source File

SOURCE=..\JPEG\RGB.C
# End Source File
# Begin Source File

SOURCE=..\JPEG\SEGMENT.C
# End Source File
# End Group
# Begin Source File

SOURCE=..\WINDSOUL\ACHANNEL.CPP
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\BITMAP.CPP
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\BLIT.CPP
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\CANVAS.CPP
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\DATAFILE.CPP
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\FONT.CPP
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\GDI.CPP
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\GEOMETRY.CPP
# End Source File
# Begin Source File

SOURCE=..\windsoul\memory.cpp
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\OBJECT.CPP
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\READBMP.CPP
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\READTGA.CPP
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\TEXT.CPP
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\TIMER.CPP
# End Source File
# Begin Source File

SOURCE=..\WSAPP\WSAPP.CPP
# End Source File
# Begin Source File

SOURCE=..\WSAPP\WSMAP.CPP
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\WSTRING.CPP
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\WSURFACE.CPP
# End Source File
# Begin Source File

SOURCE=..\WSAPP\WSWND.CPP
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\Release\text16.obj
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\Release\blit16.obj
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\Release\font16.obj
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\Release\alpha16.obj
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\Release\surface.obj
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\Release\box16.obj
# End Source File
# Begin Source File

SOURCE=..\WINDSOUL\Release\string.obj
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# End Target
# End Project
