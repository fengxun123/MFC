
// ����ʡˮ����ʧ��Ŀ������ʾƽ̨View.cpp : C����ʡˮ����ʧ��Ŀ������ʾƽ̨View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#endif

#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C����ʡˮ����ʧ��Ŀ������ʾƽ̨View

IMPLEMENT_DYNCREATE(C����ʡˮ����ʧ��Ŀ������ʾƽ̨View, CView)

BEGIN_MESSAGE_MAP(C����ʡˮ����ʧ��Ŀ������ʾƽ̨View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C����ʡˮ����ʧ��Ŀ������ʾƽ̨View ����/����

C����ʡˮ����ʧ��Ŀ������ʾƽ̨View::C����ʡˮ����ʧ��Ŀ������ʾƽ̨View()
{
	// TODO: �ڴ˴���ӹ������

}

C����ʡˮ����ʧ��Ŀ������ʾƽ̨View::~C����ʡˮ����ʧ��Ŀ������ʾƽ̨View()
{
}

BOOL C����ʡˮ����ʧ��Ŀ������ʾƽ̨View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C����ʡˮ����ʧ��Ŀ������ʾƽ̨View ����

void C����ʡˮ����ʧ��Ŀ������ʾƽ̨View::OnDraw(CDC* /*pDC*/)
{
	C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C����ʡˮ����ʧ��Ŀ������ʾƽ̨View ��ӡ

BOOL C����ʡˮ����ʧ��Ŀ������ʾƽ̨View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C����ʡˮ����ʧ��Ŀ������ʾƽ̨View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C����ʡˮ����ʧ��Ŀ������ʾƽ̨View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C����ʡˮ����ʧ��Ŀ������ʾƽ̨View ���

#ifdef _DEBUG
void C����ʡˮ����ʧ��Ŀ������ʾƽ̨View::AssertValid() const
{
	CView::AssertValid();
}

void C����ʡˮ����ʧ��Ŀ������ʾƽ̨View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc* C����ʡˮ����ʧ��Ŀ������ʾƽ̨View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc)));
	return (C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc*)m_pDocument;
}
#endif //_DEBUG


// C����ʡˮ����ʧ��Ŀ������ʾƽ̨View ��Ϣ�������
