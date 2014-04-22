// mfcexView.cpp : implementation of the CMfcexView class
//

#include "stdafx.h"
#include "mfcex01.h"

#include "mfcexDoc.h"
#include "mfcexView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMfcexView

IMPLEMENT_DYNCREATE(CMfcexView, CView)

BEGIN_MESSAGE_MAP(CMfcexView, CView)
	//{{AFX_MSG_MAP(CMfcexView)
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMfcexView construction/destruction

CMfcexView::CMfcexView()
{
	m_pCanvas=0;
	m_Timer=0;
}

CMfcexView::~CMfcexView()
{
	if (m_pCanvas) delete m_pCanvas;
}

BOOL CMfcexView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMfcexView drawing

void CMfcexView::OnDraw(CDC* pDC)
{
	CMfcexDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	m_pCanvas->Update2DC(pDC->GetSafeHdc(),0,0);
}

/////////////////////////////////////////////////////////////////////////////
// CMfcexView diagnostics

#ifdef _DEBUG
void CMfcexView::AssertValid() const
{
	CView::AssertValid();
}

void CMfcexView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMfcexDoc* CMfcexView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMfcexDoc)));
	return (CMfcexDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMfcexView message handlers

BOOL CMfcexView::OnEraseBkgnd(CDC* pDC) 
{
	return true;
//	return CView::OnEraseBkgnd(pDC);
}

void CMfcexView::UpdateView()
{
	// TODO:: 实际刷新 View 的代码. (不要写在 OnDraw 里面)
	CMfcexDoc *pDoc=GetDocument();
	if (m_pCanvas==0) return;
	m_pCanvas->Change();
	m_pCanvas->SetPos(pDoc->m_X,pDoc->m_Y);
	m_pCanvas->Draw(pDoc->m_Bmp,0);
	m_pCanvas->UnChange();
	m_pCanvas->Clear(0x808080);
	CDC *pDC=GetDC();
	m_pCanvas->Blit2DC(pDC->GetSafeHdc(),0,0);
	ReleaseDC(pDC);
	pDoc->MoveSprite(m_pCanvas->GetW(),m_pCanvas->GetH());
}

void CMfcexView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	if (m_pCanvas) delete m_pCanvas;
	if (cx==0 || cy==0) return;
	m_pCanvas=new WCanvas(cx,cy);
	UpdateView();	
}

void CMfcexView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	UpdateView();
}

void CMfcexView::OnTimer(UINT nIDEvent) 
{
	UpdateView();	
	CView::OnTimer(nIDEvent);
}

void CMfcexView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	if (m_Timer==0) m_Timer=SetTimer(1, 10, 0);
	
}

BOOL CMfcexView::DestroyWindow() 
{
	if (m_Timer) KillTimer(m_Timer);
	m_Timer=0;
	
	return CView::DestroyWindow();
}
