// DlgShuituliushi1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgShuituliushi1.h"


// CDlgShuituliushi1

IMPLEMENT_DYNCREATE(CDlgShuituliushi1, CFormView)

CDlgShuituliushi1::CDlgShuituliushi1()
	: CFormView(IDD_SHUITULIUSHI1)
{

}

CDlgShuituliushi1::~CDlgShuituliushi1()
{
}

void CDlgShuituliushi1::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_shuitab1);
}

BEGIN_MESSAGE_MAP(CDlgShuituliushi1, CFormView)
END_MESSAGE_MAP()


// CDlgShuituliushi1 ���

#ifdef _DEBUG
void CDlgShuituliushi1::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgShuituliushi1::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgShuituliushi1 ��Ϣ�������


void CDlgShuituliushi1::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	//��ӱ�ǩҳ
	m_shuitab1.AddPage(TEXT("�������ý���ͼ"), &shuijieyitu1, IDD_SHUIJIEYITU1);
	m_shuitab1.AddPage(TEXT("���������ܱ�"), &shuizongbiao10, IDD_SHUIZONGBIAO10);
	m_shuitab1.AddPage(TEXT("�������÷ֱ�1"), &shuifenbiao11, IDD_SHUIFENBIAO11);
	m_shuitab1.AddPage(TEXT("�������÷ֱ�2"), &shuifenbiao12, IDD_SHUIFENBIAO12);
	m_shuitab1.AddPage(TEXT("�������÷ֱ�3"), &shuifenbiao13, IDD_SHUIFENBIAO13);

	//��ʾ��ǩ
	m_shuitab1.Show();
}
