// DlgTudiliyong.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgTudiliyong.h"


// CDlgTudiliyong

IMPLEMENT_DYNCREATE(CDlgTudiliyong, CFormView)

CDlgTudiliyong::CDlgTudiliyong()
	: CFormView(IDD_TUDILIYONG)
{

}

CDlgTudiliyong::~CDlgTudiliyong()
{
}

void CDlgTudiliyong::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tutab);
}

BEGIN_MESSAGE_MAP(CDlgTudiliyong, CFormView)
END_MESSAGE_MAP()


// CDlgTudiliyong ���

#ifdef _DEBUG
void CDlgTudiliyong::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgTudiliyong::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgTudiliyong ��Ϣ�������


void CDlgTudiliyong::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	//��ӱ�ǩҳ
	m_tutab.AddPage(TEXT("�������ý���ͼ"), &jieyitu1, IDD_TUJIEYITU11);
	m_tutab.AddPage(TEXT("���������ܱ�"), &tuzongbiao10, IDD_TUZONGBIAO10);
	m_tutab.AddPage(TEXT("�������÷ֱ�1"), &tufenbiao11, IDD_TUFENBIAO11);
	m_tutab.AddPage(TEXT("�������÷ֱ�2"), &tufenbiao12, IDD_TUFENBIAO12);
	m_tutab.AddPage(TEXT("�������÷ֱ�3"), &tufenbiao13, IDD_TUFENBIAO13);

	//��ʾ��ǩ
	m_tutab.Show();
}
