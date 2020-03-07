// DlgTudiliyong.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
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


// CDlgTudiliyong 诊断

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


// CDlgTudiliyong 消息处理程序


void CDlgTudiliyong::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//添加标签页
	m_tutab.AddPage(TEXT("土地利用解译图"), &jieyitu1, IDD_TUJIEYITU11);
	m_tutab.AddPage(TEXT("土地利用总表"), &tuzongbiao10, IDD_TUZONGBIAO10);
	m_tutab.AddPage(TEXT("土地利用分表1"), &tufenbiao11, IDD_TUFENBIAO11);
	m_tutab.AddPage(TEXT("土地利用分表2"), &tufenbiao12, IDD_TUFENBIAO12);
	m_tutab.AddPage(TEXT("土地利用分表3"), &tufenbiao13, IDD_TUFENBIAO13);

	//显示标签
	m_tutab.Show();
}
