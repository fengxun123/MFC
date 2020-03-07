// DlgZhibeifugai1.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgZhibeifugai1.h"


// CDlgZhibeifugai1

IMPLEMENT_DYNCREATE(CDlgZhibeifugai1, CFormView)

CDlgZhibeifugai1::CDlgZhibeifugai1()
	: CFormView(IDD_ZHIBEIFUGAI1)
{

}

CDlgZhibeifugai1::~CDlgZhibeifugai1()
{
}

void CDlgZhibeifugai1::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_zhitab1);
}

BEGIN_MESSAGE_MAP(CDlgZhibeifugai1, CFormView)
END_MESSAGE_MAP()


// CDlgZhibeifugai1 诊断

#ifdef _DEBUG
void CDlgZhibeifugai1::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgZhibeifugai1::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgZhibeifugai1 消息处理程序


void CDlgZhibeifugai1::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//添加标签页
	m_zhitab1.AddPage(TEXT("土地利用解译图"), &zhijieyitu1, IDD_ZHIJIEYITU1);
	m_zhitab1.AddPage(TEXT("土地利用总表"), &zhizongbiao10, IDD_ZHIZONGBIAO10);
	m_zhitab1.AddPage(TEXT("土地利用分表1"), &zhifenbiao11, IDD_ZHIFENBIAO11);
	m_zhitab1.AddPage(TEXT("土地利用分表2"), &zhifenbiao12, IDD_ZHIFENBIAO12);
	m_zhitab1.AddPage(TEXT("土地利用分表3"), &zhifenbiao13, IDD_ZHIFENBIAO13);

	//显示标签
	m_zhitab1.Show();
}
