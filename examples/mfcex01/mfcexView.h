// mfcexView.h : interface of the CMfcexView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCEXVIEW_H__D2C0D266_B769_40AD_BBB8_83DAC8061935__INCLUDED_)
#define AFX_MFCEXVIEW_H__D2C0D266_B769_40AD_BBB8_83DAC8061935__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "windsoul.h"
#include "wscanvas.h"

class CMfcexView : public CView
{
protected: // create from serialization only
	CMfcexView();
	DECLARE_DYNCREATE(CMfcexView)

// Attributes
public:
	CMfcexDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfcexView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	virtual BOOL DestroyWindow();
	protected:
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMfcexView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMfcexView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void UpdateView();
	WCanvas *m_pCanvas;
	UINT m_Timer;
};

#ifndef _DEBUG  // debug version in mfcexView.cpp
inline CMfcexDoc* CMfcexView::GetDocument()
   { return (CMfcexDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCEXVIEW_H__D2C0D266_B769_40AD_BBB8_83DAC8061935__INCLUDED_)
