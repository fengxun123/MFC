// DlgTudiliyong1.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
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


// CDlgTudiliyong1 诊断

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


// CDlgTudiliyong1 消息处理程序


void CDlgTudiliyong1::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//添加标签页
	m_tutab1.AddPage(TEXT("土地利用解译图"), &jieyitu2, IDD_TUJIEYITU2);
	m_tutab1.AddPage(TEXT("土地利用总表"), &tuzongbiao20, IDD_TUZONGBIAO20);
	m_tutab1.AddPage(TEXT("土地利用分表1"), &tufenbiao21, IDD_TUFENBIAO21);
	m_tutab1.AddPage(TEXT("土地利用分表2"), &tufenbiao22, IDD_TUFENBIAO22);
	m_tutab1.AddPage(TEXT("土地利用分表3"), &tufenbiao23, IDD_TUFENBIAO23);

	//显示标签
	m_tutab1.Show();
}
