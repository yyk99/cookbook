
// MFC_asyncView.cpp : implementation of the CMFCasyncView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFC_async.h"
#endif

#include "MFC_asyncDoc.h"
#include "MFC_asyncView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCasyncView

IMPLEMENT_DYNCREATE(CMFCasyncView, CView)

BEGIN_MESSAGE_MAP(CMFCasyncView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCasyncView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCasyncView construction/destruction

CMFCasyncView::CMFCasyncView() noexcept
{
	// TODO: add construction code here

}

CMFCasyncView::~CMFCasyncView()
{
}

BOOL CMFCasyncView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCasyncView drawing

void CMFCasyncView::OnDraw(CDC* /*pDC*/)
{
	CMFCasyncDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCasyncView printing


void CMFCasyncView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCasyncView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCasyncView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCasyncView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCasyncView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCasyncView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCasyncView diagnostics

#ifdef _DEBUG
void CMFCasyncView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCasyncView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCasyncDoc* CMFCasyncView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCasyncDoc)));
	return (CMFCasyncDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCasyncView message handlers
