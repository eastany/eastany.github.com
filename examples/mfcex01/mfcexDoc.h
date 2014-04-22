// mfcexDoc.h : interface of the CMfcexDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCEXDOC_H__9BA5CA3F_04D4_4C09_AEAC_2A3EDF8A5244__INCLUDED_)
#define AFX_MFCEXDOC_H__9BA5CA3F_04D4_4C09_AEAC_2A3EDF8A5244__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "windsoul.h"

class CMfcexDoc : public CDocument
{
protected: // create from serialization only
	CMfcexDoc();
	DECLARE_DYNCREATE(CMfcexDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfcexDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMfcexDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMfcexDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
public:
	void MoveSprite(int w,int h);
	WBitmap m_Bmp;
	int m_X;
	int m_Y;
	int m_Dx;
	int m_Dy;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCEXDOC_H__9BA5CA3F_04D4_4C09_AEAC_2A3EDF8A5244__INCLUDED_)
