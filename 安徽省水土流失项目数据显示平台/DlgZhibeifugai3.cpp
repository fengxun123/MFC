// DlgZhibeifugai3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhibeifugai3.h"


// CDlgZhibeifugai3

IMPLEMENT_DYNCREATE(CDlgZhibeifugai3, CFormView)

CDlgZhibeifugai3::CDlgZhibeifugai3()
	: CFormView(IDD_ZHIBEIFUGAI3)
{

}

CDlgZhibeifugai3::~CDlgZhibeifugai3()
{
}

void CDlgZhibeifugai3::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_zhitab3);
}

BEGIN_MESSAGE_MAP(CDlgZhibeifugai3, CFormView)
END_MESSAGE_MAP()


// CDlgZhibeifugai3 ���

#ifdef _DEBUG
void CDlgZhibeifugai3::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgZhibeifugai3::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgZhibeifugai3 ��Ϣ�������


void CDlgZhibeifugai3::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	//��ӱ�ǩҳ
	m_zhitab3.AddPage(TEXT("�������ý���ͼ"), &zhijieyitu3, IDD_ZHIJIEYITU3);
	m_zhitab3.AddPage(TEXT("���������ܱ�"), &zhizongbiao30, IDD_ZHIZONGBIAO30);
	m_zhitab3.AddPage(TEXT("�������÷ֱ�1"), &zhifenbiao31, IDD_ZHIFENBIAO31);
	m_zhitab3.AddPage(TEXT("�������÷ֱ�2"), &zhifenbiao32, IDD_ZHIFENBIAO32);
	

	//��ʾ��ǩ
	m_zhitab3.Show();
}
