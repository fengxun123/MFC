// DlgShuituliushi2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgShuituliushi2.h"


// CDlgShuituliushi2

IMPLEMENT_DYNCREATE(CDlgShuituliushi2, CFormView)

CDlgShuituliushi2::CDlgShuituliushi2()
	: CFormView(IDD_SHUITULIUSHI2)
{

}

CDlgShuituliushi2::~CDlgShuituliushi2()
{
}

void CDlgShuituliushi2::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_shuitab2);
}

BEGIN_MESSAGE_MAP(CDlgShuituliushi2, CFormView)
END_MESSAGE_MAP()


// CDlgShuituliushi2 ���

#ifdef _DEBUG
void CDlgShuituliushi2::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgShuituliushi2::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgShuituliushi2 ��Ϣ�������


void CDlgShuituliushi2::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	//��ӱ�ǩҳ
	m_shuitab2.AddPage(TEXT("�������ý���ͼ"), &shuijieyitu2, IDD_SHUIJIEYITU2);
	m_shuitab2.AddPage(TEXT("���������ܱ�"), &shuizongbiao20, IDD_SHUIZONGBIAO20);
	m_shuitab2.AddPage(TEXT("�������÷ֱ�1"), &shuifenbiao21, IDD_SHUIFENBIAO21);
	m_shuitab2.AddPage(TEXT("�������÷ֱ�2"), &shuifenbiao22, IDD_SHUIFENBIAO22);
	m_shuitab2.AddPage(TEXT("�������÷ֱ�3"), &shuifenbiao23, IDD_SHUIFENBIAO23);

	//��ʾ��ǩ
	m_shuitab2.Show();
}
