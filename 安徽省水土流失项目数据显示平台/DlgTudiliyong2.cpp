// DlgTudiliyong2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgTudiliyong2.h"


// CDlgTudiliyong2

IMPLEMENT_DYNCREATE(CDlgTudiliyong2, CFormView)

CDlgTudiliyong2::CDlgTudiliyong2()
	: CFormView(IDD_TUDILIYONG2)
{

}

CDlgTudiliyong2::~CDlgTudiliyong2()
{
}

void CDlgTudiliyong2::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tutab2);
}

BEGIN_MESSAGE_MAP(CDlgTudiliyong2, CFormView)
END_MESSAGE_MAP()


// CDlgTudiliyong2 ���

#ifdef _DEBUG
void CDlgTudiliyong2::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgTudiliyong2::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgTudiliyong2 ��Ϣ�������


void CDlgTudiliyong2::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	//��ӱ�ǩҳ
	m_tutab2.AddPage(TEXT("�������ý���ͼ"), &jieyitu3, IDD_TUJIEYITU3);
	m_tutab2.AddPage(TEXT("���������ܱ�"), &tuzongbiao30, IDD_TUZONGBIAO30);
	m_tutab2.AddPage(TEXT("�������÷ֱ�1"), &tufenbiao31, IDD_TUFENBIAO31);
	m_tutab2.AddPage(TEXT("�������÷ֱ�2"), &tufenbiao32, IDD_TUFENBIAO32);


	//��ʾ��ǩ
	m_tutab2.Show();

}
