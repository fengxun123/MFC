
// ����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc.cpp : C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#endif

#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc

IMPLEMENT_DYNCREATE(C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc, CDocument)

BEGIN_MESSAGE_MAP(C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc, CDocument)
END_MESSAGE_MAP()


// C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc ����/����

C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc::C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc()
{
	// TODO: �ڴ����һ���Թ������

}

C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc::~C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc()
{
}

BOOL C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)
	//����������
	SetTitle(_T("����ʡˮ����ʧ��Ŀ������ʾƽ̨"));

	return TRUE;
}




// C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc ���л�

void C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc ���

#ifdef _DEBUG
void C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc ����
