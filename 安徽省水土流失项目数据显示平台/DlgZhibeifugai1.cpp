// DlgZhibeifugai1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhibeifugai1.h"


// CDlgZhibeifugai1

IMPLEMENT_DYNCREATE(CDlgZhibeifugai1, CFormView)

CDlgZhibeifugai1::CDlgZhibeifugai1()
	: CFormView(IDD_ZHIBEIFUGAI1)
{

}

CDlgZhibeifugai1::~CDlgZhibeifugai1()
{
}

void CDlgZhibeifugai1::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_zhitab1);
}

BEGIN_MESSAGE_MAP(CDlgZhibeifugai1, CFormView)
END_MESSAGE_MAP()


// CDlgZhibeifugai1 ���

#ifdef _DEBUG
void CDlgZhibeifugai1::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgZhibeifugai1::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgZhibeifugai1 ��Ϣ�������


void CDlgZhibeifugai1::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	//��ӱ�ǩҳ
	m_zhitab1.AddPage(TEXT("�������ý���ͼ"), &zhijieyitu1, IDD_ZHIJIEYITU1);
	m_zhitab1.AddPage(TEXT("���������ܱ�"), &zhizongbiao10, IDD_ZHIZONGBIAO10);
	m_zhitab1.AddPage(TEXT("�������÷ֱ�1"), &zhifenbiao11, IDD_ZHIFENBIAO11);
	m_zhitab1.AddPage(TEXT("�������÷ֱ�2"), &zhifenbiao12, IDD_ZHIFENBIAO12);
	m_zhitab1.AddPage(TEXT("�������÷ֱ�3"), &zhifenbiao13, IDD_ZHIFENBIAO13);

	//��ʾ��ǩ
	m_zhitab1.Show();
}
