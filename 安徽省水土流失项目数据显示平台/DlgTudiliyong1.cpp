// DlgTudiliyong1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgTudiliyong1.h"


// CDlgTudiliyong1

IMPLEMENT_DYNCREATE(CDlgTudiliyong1, CFormView)

CDlgTudiliyong1::CDlgTudiliyong1()
	: CFormView(IDD_TUDILIYONG1)
{

}

CDlgTudiliyong1::~CDlgTudiliyong1()
{
}

void CDlgTudiliyong1::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tutab1);
}

BEGIN_MESSAGE_MAP(CDlgTudiliyong1, CFormView)
END_MESSAGE_MAP()


// CDlgTudiliyong1 ���

#ifdef _DEBUG
void CDlgTudiliyong1::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgTudiliyong1::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgTudiliyong1 ��Ϣ�������


void CDlgTudiliyong1::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	//��ӱ�ǩҳ
	m_tutab1.AddPage(TEXT("�������ý���ͼ"), &jieyitu2, IDD_TUJIEYITU2);
	m_tutab1.AddPage(TEXT("���������ܱ�"), &tuzongbiao20, IDD_TUZONGBIAO20);
	m_tutab1.AddPage(TEXT("�������÷ֱ�1"), &tufenbiao21, IDD_TUFENBIAO21);
	m_tutab1.AddPage(TEXT("�������÷ֱ�2"), &tufenbiao22, IDD_TUFENBIAO22);
	m_tutab1.AddPage(TEXT("�������÷ֱ�3"), &tufenbiao23, IDD_TUFENBIAO23);

	//��ʾ��ǩ
	m_tutab1.Show();
}
