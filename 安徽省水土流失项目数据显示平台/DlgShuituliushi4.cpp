// DlgShuituliushi4.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgShuituliushi4.h"


// CDlgShuituliushi4

IMPLEMENT_DYNCREATE(CDlgShuituliushi4, CFormView)

CDlgShuituliushi4::CDlgShuituliushi4()
	: CFormView(IDD_SHUITULIUSHI4)
{

}

CDlgShuituliushi4::~CDlgShuituliushi4()
{
}

void CDlgShuituliushi4::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_shuitab4);
}

BEGIN_MESSAGE_MAP(CDlgShuituliushi4, CFormView)
END_MESSAGE_MAP()


// CDlgShuituliushi4 ���

#ifdef _DEBUG
void CDlgShuituliushi4::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgShuituliushi4::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgShuituliushi4 ��Ϣ�������


void CDlgShuituliushi4::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	//��ӱ�ǩҳ
	m_shuitab4.AddPage(TEXT("�������ý���ͼ"), &shuijieyitu4, IDD_SHUIJIEYITU4);
	m_shuitab4.AddPage(TEXT("���������ܱ�"), &shuizongbiao40, IDD_SHUIZONGBIAO40);
	m_shuitab4.AddPage(TEXT("�������÷ֱ�1"), &shuifenbiao41, IDD_SHUIFENBIAO41);
	m_shuitab4.AddPage(TEXT("�������÷ֱ�2"), &shuifenbiao42, IDD_SHUIFENBIAO42);
	m_shuitab4.AddPage(TEXT("�������÷ֱ�3"), &shuifenbiao43, IDD_SHUIFENBIAO43);

	//��ʾ��ǩ
	m_shuitab4.Show();
}
