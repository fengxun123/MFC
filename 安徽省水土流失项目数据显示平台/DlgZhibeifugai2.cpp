// DlgZhibeifugai2.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgZhibeifugai2.h"


// CDlgZhibeifugai2

IMPLEMENT_DYNCREATE(CDlgZhibeifugai2, CFormView)

CDlgZhibeifugai2::CDlgZhibeifugai2()
	: CFormView(IDD_ZHIBEIFUGAI2)
{

}

CDlgZhibeifugai2::~CDlgZhibeifugai2()
{
}

void CDlgZhibeifugai2::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_zhitab2);
}

BEGIN_MESSAGE_MAP(CDlgZhibeifugai2, CFormView)
END_MESSAGE_MAP()


// CDlgZhibeifugai2 诊断

#ifdef _DEBUG
void CDlgZhibeifugai2::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgZhibeifugai2::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgZhibeifugai2 消息处理程序


void CDlgZhibeifugai2::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//添加标签页
	m_zhitab2.AddPage(TEXT("土地利用解译图"), &zhijieyitu2, IDD_ZHIJIEYITU2);
	m_zhitab2.AddPage(TEXT("土地利用总表"), &zhizongbiao20, IDD_ZHIZONGBIAO20);
	m_zhitab2.AddPage(TEXT("土地利用分表1"), &zhifenbiao21, IDD_ZHIFENBIAO21);
	m_zhitab2.AddPage(TEXT("土地利用分表2"), &zhifenbiao22, IDD_ZHIFENBIAO22);
	m_zhitab2.AddPage(TEXT("土地利用分表3"), &zhifenbiao23, IDD_ZHIFENBIAO23);

	//显示标签
	m_zhitab2.Show();
}
