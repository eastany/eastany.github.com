// mfcex01.h : main header file for the MFCEX01 application
//

#if !defined(AFX_MFCEX01_H__B5A0751A_47CC_41B7_AAF0_0B8D1DCF78AA__INCLUDED_)
#define AFX_MFCEX01_H__B5A0751A_47CC_41B7_AAF0_0B8D1DCF78AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMfcexApp:
// See mfcex01.cpp for the implementation of this class
//

class CMfcexApp : public CWinApp
{
public:
	CMfcexApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfcexApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMfcexApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCEX01_H__B5A0751A_47CC_41B7_AAF0_0B8D1DCF78AA__INCLUDED_)
