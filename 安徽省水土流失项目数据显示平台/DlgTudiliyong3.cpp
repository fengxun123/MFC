// DlgTudiliyong3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgTudiliyong3.h"


// CDlgTudiliyong3

IMPLEMENT_DYNCREATE(CDlgTudiliyong3, CFormView)

CDlgTudiliyong3::CDlgTudiliyong3()
	: CFormView(IDD_TUDILIYONG3)
{

}

CDlgTudiliyong3::~CDlgTudiliyong3()
{
}

void CDlgTudiliyong3::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_TAB1, m_list4);
	DDX_Control(pDX, IDC_TAB1, m_tutab3);
}

BEGIN_MESSAGE_MAP(CDlgTudiliyong3, CFormView)
END_MESSAGE_MAP()


// CDlgTudiliyong3 ���

#ifdef _DEBUG
void CDlgTudiliyong3::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgTudiliyong3::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgTudiliyong3 ��Ϣ�������


void CDlgTudiliyong3::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	//��ӱ�ǩҳ
	m_tutab3.AddPage(TEXT("�������ý���ͼ"), &jieyitu4, IDD_TUJIEYITU4);
	m_tutab3.AddPage(TEXT("���������ܱ�"), &tuzongbiao40, IDD_TUZONGBIAO40);
	m_tutab3.AddPage(TEXT("�������÷ֱ�1"), &tufenbiao41, IDD_TUFENBIAO41);
	m_tutab3.AddPage(TEXT("�������÷ֱ�2"), &tufenbiao42, IDD_TUFENBIAO42);
	m_tutab3.AddPage(TEXT("�������÷ֱ�3"), &tufenbiao43, IDD_TUFENBIAO43);

	//��ʾ��ǩ
	m_tutab3.Show();
}
