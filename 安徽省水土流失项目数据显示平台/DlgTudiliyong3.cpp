// DlgTudiliyong3.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
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


// CDlgTudiliyong3 诊断

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


// CDlgTudiliyong3 消息处理程序


void CDlgTudiliyong3::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//添加标签页
	m_tutab3.AddPage(TEXT("土地利用解译图"), &jieyitu4, IDD_TUJIEYITU4);
	m_tutab3.AddPage(TEXT("土地利用总表"), &tuzongbiao40, IDD_TUZONGBIAO40);
	m_tutab3.AddPage(TEXT("土地利用分表1"), &tufenbiao41, IDD_TUFENBIAO41);
	m_tutab3.AddPage(TEXT("土地利用分表2"), &tufenbiao42, IDD_TUFENBIAO42);
	m_tutab3.AddPage(TEXT("土地利用分表3"), &tufenbiao43, IDD_TUFENBIAO43);

	//显示标签
	m_tutab3.Show();
}
