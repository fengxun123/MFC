// DlgZhibeifugai3.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgZhibeifugai3.h"


// CDlgZhibeifugai3

IMPLEMENT_DYNCREATE(CDlgZhibeifugai3, CFormView)

CDlgZhibeifugai3::CDlgZhibeifugai3()
	: CFormView(IDD_ZHIBEIFUGAI3)
{

}

CDlgZhibeifugai3::~CDlgZhibeifugai3()
{
}

void CDlgZhibeifugai3::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_zhitab3);
}

BEGIN_MESSAGE_MAP(CDlgZhibeifugai3, CFormView)
END_MESSAGE_MAP()


// CDlgZhibeifugai3 诊断

#ifdef _DEBUG
void CDlgZhibeifugai3::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgZhibeifugai3::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgZhibeifugai3 消息处理程序


void CDlgZhibeifugai3::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//添加标签页
	m_zhitab3.AddPage(TEXT("土地利用解译图"), &zhijieyitu3, IDD_ZHIJIEYITU3);
	m_zhitab3.AddPage(TEXT("土地利用总表"), &zhizongbiao30, IDD_ZHIZONGBIAO30);
	m_zhitab3.AddPage(TEXT("土地利用分表1"), &zhifenbiao31, IDD_ZHIFENBIAO31);
	m_zhitab3.AddPage(TEXT("土地利用分表2"), &zhifenbiao32, IDD_ZHIFENBIAO32);
	

	//显示标签
	m_zhitab3.Show();
}
