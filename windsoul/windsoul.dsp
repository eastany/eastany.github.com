# Microsoft Developer Studio Project File - Name="windsoul" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=windsoul - Win32 CanvasDebug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "windsoul.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "windsoul.mak" CFG="windsoul - Win32 CanvasDebug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "windsoul - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "windsoul - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "windsoul - Win32 VTune" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "windsoul - Win32 API" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "windsoul - Win32 CanvasDebug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "Perforce Project"
# PROP Scc_LocalPath ".."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "windsoul - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../lib"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "WINDSOUL_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "../include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_MSVC" /D "WINDSOUL_EXPORTS" /Fr /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /base:"0x11000000" /dll /machine:I386 /out:"../dll/windsoul.dll" /pdbtype:sept /MAPINFO:LINES
# SUBTRACT LINK32 /pdb:none /map

!ELSEIF  "$(CFG)" == "windsoul - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../lib"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "WINDSOUL_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_MSVC" /D "WINDSOUL_EXPORTS" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 ddraw.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /base:"0x11000000" /dll /debug /machine:I386 /out:"../dll/wsdebug.dll"

!ELSEIF  "$(CFG)" == "windsoul - Win32 VTune"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "windsoul___Win32_VTune"
# PROP BASE Intermediate_Dir "windsoul___Win32_VTune"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "windsoul___Win32_VTune"
# PROP Intermediate_Dir "windsoul___Win32_VTune"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "../include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_MSVC" /D "WINDSOUL_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /Zi /O2 /I "../include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_MSVC" /D "WINDSOUL_EXPORTS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 ddraw.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386 /out:"../dll/windsoul.dll"
# ADD LINK32 ddraw.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /base:"0x11000000" /dll /machine:I386 /out:"../dll/windsoul.dll"

!ELSEIF  "$(CFG)" == "windsoul - Win32 API"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "windsoul___Win32_API"
# PROP BASE Intermediate_Dir "windsoul___Win32_API"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "windsoul___Win32_API"
# PROP Intermediate_Dir "windsoul___Win32_API"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "../include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_MSVC" /D "WINDSOUL_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "../include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_MSVC" /D "WINDSOUL_EXPORTS" /D "_API" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 ddraw.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386 /out:"../dll/windsoul.dll"
# ADD LINK32 ddraw.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /base:"0x11000000" /dll /machine:I386 /out:"../dll/wsapi.dll"

!ELSEIF  "$(CFG)" == "windsoul - Win32 CanvasDebug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "windsoul___Win32_CanvasDebug"
# PROP BASE Intermediate_Dir "windsoul___Win32_CanvasDebug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../lib"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_MSVC" /D "WINDSOUL_EXPORTS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_MSVC" /D "WINDSOUL_EXPORTS" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 ddraw.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /out:"../dll/wsdebug.dll" /pdbtype:sept
# ADD LINK32 ddraw.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /base:"0x11000000" /dll /debug /machine:I386 /out:"../dll/wsdebug.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "windsoul - Win32 Release"
# Name "windsoul - Win32 Debug"
# Name "windsoul - Win32 VTune"
# Name "windsoul - Win32 API"
# Name "windsoul - Win32 CanvasDebug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Internal Header"

# PROP Default_Filter "h"
# Begin Source File

SOURCE=.\achannel.h
# End Source File
# Begin Source File

SOURCE=.\bmpmem.h
# End Source File
# Begin Source File

SOURCE=.\canvasin.h
# End Source File
# Begin Source File

SOURCE=.\fontint.h
# End Source File
# Begin Source File

SOURCE=.\geoint.h
# End Source File
# Begin Source File

SOURCE=.\objheap.h
# End Source File
# Begin Source File

SOURCE=.\textint.h
# End Source File
# Begin Source File

SOURCE=..\wsapp\wsmap.h
# End Source File
# End Group
# Begin Group "Application"

# PROP Default_Filter "cpp"
# Begin Source File

SOURCE=..\wsapp\wsapp.cpp
# End Source File
# Begin Source File

SOURCE=..\wsapp\wsmap.cpp
# End Source File
# Begin Source File

SOURCE=..\wsapp\wswnd.cpp
# End Source File
# End Group
# Begin Group "ASM Files"

# PROP Default_Filter "asm"
# Begin Source File

SOURCE=.\alpha16.asm

!IF  "$(CFG)" == "windsoul - Win32 Release"

USERDEP__ALPHA="c32.mac"	"wpp.inc"	"bmpclip.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Release
InputPath=.\alpha16.asm
InputName=alpha16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 Debug"

USERDEP__ALPHA="c32.mac"	"wpp.inc"	"bmpclip.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Debug
InputPath=.\alpha16.asm
InputName=alpha16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 VTune"

USERDEP__ALPHA="c32.mac"	"wpp.inc"	"bmpclip.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\windsoul___Win32_VTune
InputPath=.\alpha16.asm
InputName=alpha16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 API"

USERDEP__ALPHA="c32.mac"	"wpp.inc"	"bmpclip.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\windsoul___Win32_API
InputPath=.\alpha16.asm
InputName=alpha16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 CanvasDebug"

USERDEP__ALPHA="c32.mac"	"wpp.inc"	"bmpclip.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Debug
InputPath=.\alpha16.asm
InputName=alpha16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\blit16.asm

!IF  "$(CFG)" == "windsoul - Win32 Release"

USERDEP__BLIT1="c32.mac"	"wpp.inc"	"bmpclip.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Release
InputPath=.\blit16.asm
InputName=blit16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 Debug"

USERDEP__BLIT1="c32.mac"	"wpp.inc"	"bmpclip.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Debug
InputPath=.\blit16.asm
InputName=blit16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 VTune"

USERDEP__BLIT1="c32.mac"	"wpp.inc"	"bmpclip.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\windsoul___Win32_VTune
InputPath=.\blit16.asm
InputName=blit16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 API"

USERDEP__BLIT1="c32.mac"	"wpp.inc"	"bmpclip.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\windsoul___Win32_API
InputPath=.\blit16.asm
InputName=blit16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 CanvasDebug"

USERDEP__BLIT1="c32.mac"	"wpp.inc"	"bmpclip.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Debug
InputPath=.\blit16.asm
InputName=blit16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\box16.ASM

!IF  "$(CFG)" == "windsoul - Win32 Release"

USERDEP__BOX16="c32.mac"	"wpp.inc"	"boxclip.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Release
InputPath=.\box16.ASM
InputName=box16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 Debug"

USERDEP__BOX16="c32.mac"	"wpp.inc"	"boxclip.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Debug
InputPath=.\box16.ASM
InputName=box16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 VTune"

USERDEP__BOX16="c32.mac"	"wpp.inc"	"boxclip.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\windsoul___Win32_VTune
InputPath=.\box16.ASM
InputName=box16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 API"

USERDEP__BOX16="c32.mac"	"wpp.inc"	"boxclip.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\windsoul___Win32_API
InputPath=.\box16.ASM
InputName=box16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 CanvasDebug"

USERDEP__BOX16="c32.mac"	"wpp.inc"	"boxclip.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Debug
InputPath=.\box16.ASM
InputName=box16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\font16.asm

!IF  "$(CFG)" == "windsoul - Win32 Release"

USERDEP__FONT1="wpp.inc"	"c32.mac"	"fontclip.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Release
InputPath=.\font16.asm
InputName=font16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 Debug"

USERDEP__FONT1="wpp.inc"	"c32.mac"	"fontclip.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Debug
InputPath=.\font16.asm
InputName=font16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 VTune"

USERDEP__FONT1="wpp.inc"	"c32.mac"	"fontclip.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\windsoul___Win32_VTune
InputPath=.\font16.asm
InputName=font16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 API"

USERDEP__FONT1="wpp.inc"	"c32.mac"	"fontclip.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\windsoul___Win32_API
InputPath=.\font16.asm
InputName=font16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 CanvasDebug"

USERDEP__FONT1="wpp.inc"	"c32.mac"	"fontclip.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Debug
InputPath=.\font16.asm
InputName=font16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\string.asm

!IF  "$(CFG)" == "windsoul - Win32 Release"

USERDEP__STRIN="c32.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Release
InputPath=.\string.asm
InputName=string

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 Debug"

USERDEP__STRIN="c32.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Debug
InputPath=.\string.asm
InputName=string

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 VTune"

USERDEP__STRIN="c32.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\windsoul___Win32_VTune
InputPath=.\string.asm
InputName=string

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 API"

USERDEP__STRIN="c32.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\windsoul___Win32_API
InputPath=.\string.asm
InputName=string

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 CanvasDebug"

USERDEP__STRIN="c32.mac"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Debug
InputPath=.\string.asm
InputName=string

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\surface.asm

!IF  "$(CFG)" == "windsoul - Win32 Release"

USERDEP__SURFA="c32.mac"	"wpp.inc"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Release
InputPath=.\surface.asm
InputName=surface

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 Debug"

USERDEP__SURFA="c32.mac"	"wpp.inc"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Debug
InputPath=.\surface.asm
InputName=surface

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 VTune"

USERDEP__SURFA="c32.mac"	"wpp.inc"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\windsoul___Win32_VTune
InputPath=.\surface.asm
InputName=surface

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 API"

USERDEP__SURFA="c32.mac"	"wpp.inc"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\windsoul___Win32_API
InputPath=.\surface.asm
InputName=surface

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 CanvasDebug"

USERDEP__SURFA="c32.mac"	"wpp.inc"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Debug
InputPath=.\surface.asm
InputName=surface

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\text16.asm

!IF  "$(CFG)" == "windsoul - Win32 Release"

USERDEP__TEXT1="c32.mac"	"wpp.inc"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Release
InputPath=.\text16.asm
InputName=text16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 Debug"

USERDEP__TEXT1="c32.mac"	"wpp.inc"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Debug
InputPath=.\text16.asm
InputName=text16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 VTune"

USERDEP__TEXT1="c32.mac"	"wpp.inc"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\windsoul___Win32_VTune
InputPath=.\text16.asm
InputName=text16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 API"

USERDEP__TEXT1="c32.mac"	"wpp.inc"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\windsoul___Win32_API
InputPath=.\text16.asm
InputName=text16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ELSEIF  "$(CFG)" == "windsoul - Win32 CanvasDebug"

USERDEP__TEXT1="c32.mac"	"wpp.inc"	
# Begin Custom Build - $(InputName).asm Compiling...
IntDir=.\Debug
InputPath=.\text16.asm
InputName=text16

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	nasmw -o $(IntDir)\$(InputName).obj -f win32 $(InputName).asm

# End Custom Build

!ENDIF 

# End Source File
# End Group
# Begin Group "ASM Header"

# PROP Default_Filter "mac;inc"
# Begin Source File

SOURCE=.\bmpclip.mac
# End Source File
# Begin Source File

SOURCE=.\boxclip.mac
# End Source File
# Begin Source File

SOURCE=.\c32.mac
# End Source File
# Begin Source File

SOURCE=.\fontclip.mac
# End Source File
# Begin Source File

SOURCE=.\wpp.inc
# End Source File
# End Group
# Begin Group "Additional Class"

# PROP Default_Filter "cpp"
# Begin Source File

SOURCE=.\achannel.cpp
# End Source File
# Begin Source File

SOURCE=.\CANVAS.CPP

!IF  "$(CFG)" == "windsoul - Win32 Release"

!ELSEIF  "$(CFG)" == "windsoul - Win32 Debug"

!ELSEIF  "$(CFG)" == "windsoul - Win32 VTune"

!ELSEIF  "$(CFG)" == "windsoul - Win32 API"

!ELSEIF  "$(CFG)" == "windsoul - Win32 CanvasDebug"

# ADD CPP /D "_DEBUG_CANVAS"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\font.cpp
# End Source File
# Begin Source File

SOURCE=.\geometry.cpp
# End Source File
# Begin Source File

SOURCE=.\timer.cpp
# End Source File
# Begin Source File

SOURCE=.\wstring.cpp
# End Source File
# Begin Source File

SOURCE=.\wsurface.cpp
# End Source File
# End Group
# Begin Group "Jpeg"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\jpeg\decode.c

!IF  "$(CFG)" == "windsoul - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 VTune"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 API"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 CanvasDebug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\jpeg\huffman.c

!IF  "$(CFG)" == "windsoul - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 VTune"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 API"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 CanvasDebug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\jpeg\idct.c

!IF  "$(CFG)" == "windsoul - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 VTune"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 API"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 CanvasDebug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\jpeg\jpeg.cpp

!IF  "$(CFG)" == "windsoul - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 VTune"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 API"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 CanvasDebug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\jpeg\jpegint.h

!IF  "$(CFG)" == "windsoul - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 VTune"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 API"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 CanvasDebug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\jpeg\Quanty.c

!IF  "$(CFG)" == "windsoul - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 VTune"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 API"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 CanvasDebug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\jpeg\rgb.c

!IF  "$(CFG)" == "windsoul - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 VTune"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 API"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 CanvasDebug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\jpeg\segment.c

!IF  "$(CFG)" == "windsoul - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 VTune"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 API"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "windsoul - Win32 CanvasDebug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=.\bitmap.cpp
# End Source File
# Begin Source File

SOURCE=.\blit.cpp
# End Source File
# Begin Source File

SOURCE=.\datafile.cpp
# End Source File
# Begin Source File

SOURCE=.\gdi.cpp
# End Source File
# Begin Source File

SOURCE=.\memory.cpp
# End Source File
# Begin Source File

SOURCE=.\object.cpp
# End Source File
# Begin Source File

SOURCE=.\readbmp.cpp
# End Source File
# Begin Source File

SOURCE=.\readtga.cpp
# End Source File
# Begin Source File

SOURCE=.\text.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\include\windsoul.h
# End Source File
# Begin Source File

SOURCE=..\include\wsalpha.h
# End Source File
# Begin Source File

SOURCE=..\include\wsapi.h
# End Source File
# Begin Source File

SOURCE=..\include\wsapp.h
# End Source File
# Begin Source File

SOURCE=..\include\wsbitmap.h
# End Source File
# Begin Source File

SOURCE=..\INCLUDE\WSCANVAS.H
# End Source File
# Begin Source File

SOURCE=..\include\wserror.h
# End Source File
# Begin Source File

SOURCE=..\include\wsfile.h
# End Source File
# Begin Source File

SOURCE=..\include\wsfont.h
# End Source File
# Begin Source File

SOURCE=..\include\wsgeo.h
# End Source File
# Begin Source File

SOURCE=..\include\wshelper.h
# End Source File
# Begin Source File

SOURCE=..\include\wsjpeg.h
# End Source File
# Begin Source File

SOURCE=..\include\wsmemory.h
# End Source File
# Begin Source File

SOURCE=..\include\wsstring.h
# End Source File
# Begin Source File

SOURCE=..\include\wstimer.h
# End Source File
# Begin Source File

SOURCE=..\include\wsurface.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\windsoul.rc
# End Source File
# End Group
# End Target
# End Project
