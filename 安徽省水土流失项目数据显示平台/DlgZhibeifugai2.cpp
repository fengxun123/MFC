// DlgZhibeifugai2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhibeifugai2.h"


// CDlgZhibeifugai2

IMPLEMENT_DYNCREATE(CDlgZhibeifugai2, CFormView)

CDlgZhibeifugai2::CDlgZhibeifugai2()
	: CFormView(IDD_ZHIBEIFUGAI2)
{

}

CDlgZhibeifugai2::~CDlgZhibeifugai2()
{
}

void CDlgZhibeifugai2::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_zhitab2);
}

BEGIN_MESSAGE_MAP(CDlgZhibeifugai2, CFormView)
END_MESSAGE_MAP()


// CDlgZhibeifugai2 ���

#ifdef _DEBUG
void CDlgZhibeifugai2::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgZhibeifugai2::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgZhibeifugai2 ��Ϣ�������


void CDlgZhibeifugai2::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	//��ӱ�ǩҳ
	m_zhitab2.AddPage(TEXT("�������ý���ͼ"), &zhijieyitu2, IDD_ZHIJIEYITU2);
	m_zhitab2.AddPage(TEXT("���������ܱ�"), &zhizongbiao20, IDD_ZHIZONGBIAO20);
	m_zhitab2.AddPage(TEXT("�������÷ֱ�1"), &zhifenbiao21, IDD_ZHIFENBIAO21);
	m_zhitab2.AddPage(TEXT("�������÷ֱ�2"), &zhifenbiao22, IDD_ZHIFENBIAO22);
	m_zhitab2.AddPage(TEXT("�������÷ֱ�3"), &zhifenbiao23, IDD_ZHIFENBIAO23);

	//��ʾ��ǩ
	m_zhitab2.Show();
}
