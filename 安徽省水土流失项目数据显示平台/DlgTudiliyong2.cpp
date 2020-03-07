// DlgTudiliyong2.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
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


// CDlgTudiliyong2 诊断

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


// CDlgTudiliyong2 消息处理程序


void CDlgTudiliyong2::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//添加标签页
	m_tutab2.AddPage(TEXT("土地利用解译图"), &jieyitu3, IDD_TUJIEYITU3);
	m_tutab2.AddPage(TEXT("土地利用总表"), &tuzongbiao30, IDD_TUZONGBIAO30);
	m_tutab2.AddPage(TEXT("土地利用分表1"), &tufenbiao31, IDD_TUFENBIAO31);
	m_tutab2.AddPage(TEXT("土地利用分表2"), &tufenbiao32, IDD_TUFENBIAO32);


	//显示标签
	m_tutab2.Show();

}
