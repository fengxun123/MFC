// DlgShuituliushi3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgShuituliushi3.h"


// CDlgShuituliushi3

IMPLEMENT_DYNCREATE(CDlgShuituliushi3, CFormView)

CDlgShuituliushi3::CDlgShuituliushi3()
	: CFormView(IDD_SHUITULIUSHI3)
{

}

CDlgShuituliushi3::~CDlgShuituliushi3()
{
}

void CDlgShuituliushi3::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_shuitab3);
}

BEGIN_MESSAGE_MAP(CDlgShuituliushi3, CFormView)
END_MESSAGE_MAP()


// CDlgShuituliushi3 ���

#ifdef _DEBUG
void CDlgShuituliushi3::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgShuituliushi3::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgShuituliushi3 ��Ϣ�������


void CDlgShuituliushi3::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	//��ӱ�ǩҳ
	m_shuitab3.AddPage(TEXT("�������ý���ͼ"), &shuijieyitu3, IDD_SHUIJIEYITU3);
	m_shuitab3.AddPage(TEXT("���������ܱ�"), &shuizongbiao30, IDD_SHUIZONGBIAO30);
	m_shuitab3.AddPage(TEXT("�������÷ֱ�1"), &shuifenbiao31, IDD_SHUIFENBIAO31);
	m_shuitab3.AddPage(TEXT("�������÷ֱ�2"), &shuifenbiao32, IDD_SHUIFENBIAO32);
	

	//��ʾ��ǩ
	m_shuitab3.Show();
}
