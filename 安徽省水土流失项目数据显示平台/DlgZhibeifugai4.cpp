// DlgZhibeifugai4.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhibeifugai4.h"


// CDlgZhibeifugai4

IMPLEMENT_DYNCREATE(CDlgZhibeifugai4, CFormView)

CDlgZhibeifugai4::CDlgZhibeifugai4()
	: CFormView(IDD_ZHIBEIFUGAI4)
{

}

CDlgZhibeifugai4::~CDlgZhibeifugai4()
{
}

void CDlgZhibeifugai4::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_zhitab4);
}

BEGIN_MESSAGE_MAP(CDlgZhibeifugai4, CFormView)
END_MESSAGE_MAP()


// CDlgZhibeifugai4 ���

#ifdef _DEBUG
void CDlgZhibeifugai4::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgZhibeifugai4::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgZhibeifugai4 ��Ϣ�������


void CDlgZhibeifugai4::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	//��ӱ�ǩҳ
	m_zhitab4.AddPage(TEXT("�������ý���ͼ"), &zhijieyitu4, IDD_ZHIJIEYITU4);
	m_zhitab4.AddPage(TEXT("���������ܱ�"), &zhizongbiao40, IDD_ZHIZONGBIAO40);
	m_zhitab4.AddPage(TEXT("�������÷ֱ�1"), &zhifenbiao41, IDD_ZHIFENBIAO41);
	m_zhitab4.AddPage(TEXT("�������÷ֱ�2"), &zhifenbiao42, IDD_ZHIFENBIAO42);
	m_zhitab4.AddPage(TEXT("�������÷ֱ�3"), &zhifenbiao43, IDD_ZHIFENBIAO43);

	//��ʾ��ǩ
	m_zhitab4.Show();
}
