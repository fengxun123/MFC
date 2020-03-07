// DlgZhibeifugai4.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgZhibeifugai4.h"


// CDlgZhibeifugai4

IMPLEMENT_DYNCREATE(CDlgZhibeifugai4, CFormView)

CDlgZhibeifugai4::CDlgZhibeifugai4()
	: CFormView(IDD_ZHIBEIFUGAI4)
{

}

CDlgZhibeifugai4::~CDlgZhibeifugai4()
{
}

void CDlgZhibeifugai4::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_zhitab4);
}

BEGIN_MESSAGE_MAP(CDlgZhibeifugai4, CFormView)
END_MESSAGE_MAP()


// CDlgZhibeifugai4 诊断

#ifdef _DEBUG
void CDlgZhibeifugai4::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgZhibeifugai4::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgZhibeifugai4 消息处理程序


void CDlgZhibeifugai4::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//添加标签页
	m_zhitab4.AddPage(TEXT("土地利用解译图"), &zhijieyitu4, IDD_ZHIJIEYITU4);
	m_zhitab4.AddPage(TEXT("土地利用总表"), &zhizongbiao40, IDD_ZHIZONGBIAO40);
	m_zhitab4.AddPage(TEXT("土地利用分表1"), &zhifenbiao41, IDD_ZHIFENBIAO41);
	m_zhitab4.AddPage(TEXT("土地利用分表2"), &zhifenbiao42, IDD_ZHIFENBIAO42);
	m_zhitab4.AddPage(TEXT("土地利用分表3"), &zhifenbiao43, IDD_ZHIFENBIAO43);

	//显示标签
	m_zhitab4.Show();
}
