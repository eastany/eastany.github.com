// mfcexDoc.cpp : implementation of the CMfcexDoc class
//

#include "stdafx.h"
#include "mfcex01.h"

#include "mfcexDoc.h"
#include "windsoul.h"
#include "wsfile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMfcexDoc

IMPLEMENT_DYNCREATE(CMfcexDoc, CDocument)

BEGIN_MESSAGE_MAP(CMfcexDoc, CDocument)
	//{{AFX_MSG_MAP(CMfcexDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMfcexDoc construction/destruction

CMfcexDoc::CMfcexDoc()
{
	WFile::OpenDataFile("data.wdf");
	m_X=m_Y=0;
	m_Dx=m_Dy=1;
}

CMfcexDoc::~CMfcexDoc()
{
}

BOOL CMfcexDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	WFile f;
	WSERR r=f.Load("data/sm.bmp");
	if (r!=WS_OK)
		AfxThrowFileException(CFileException::fileNotFound);
	m_Bmp.Load(f);
	m_X=m_Y=0;
	m_Dx=m_Dy=1;
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMfcexDoc serialization

void CMfcexDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMfcexDoc diagnostics

#ifdef _DEBUG
void CMfcexDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMfcexDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMfcexDoc commands

void CMfcexDoc::MoveSprite(int w,int h)
{
	if (!m_Bmp.IsValid()) return;
	m_X+=m_Dx;
	m_Y+=m_Dy;
	if (m_X>=w-m_Bmp.GetW()) m_Dx=-1;
	else if (m_X<=0) m_Dx=1;
	if (m_Y>=h-m_Bmp.GetH()) m_Dy=-1;
	else if (m_Y<=0) m_Dy=1;
}
