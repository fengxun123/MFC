// DlgShuituliushi1.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgShuituliushi1.h"


// CDlgShuituliushi1

IMPLEMENT_DYNCREATE(CDlgShuituliushi1, CFormView)

CDlgShuituliushi1::CDlgShuituliushi1()
	: CFormView(IDD_SHUITULIUSHI1)
{

}

CDlgShuituliushi1::~CDlgShuituliushi1()
{
}

void CDlgShuituliushi1::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_shuitab1);
}

BEGIN_MESSAGE_MAP(CDlgShuituliushi1, CFormView)
END_MESSAGE_MAP()


// CDlgShuituliushi1 诊断

#ifdef _DEBUG
void CDlgShuituliushi1::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgShuituliushi1::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgShuituliushi1 消息处理程序


void CDlgShuituliushi1::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//添加标签页
	m_shuitab1.AddPage(TEXT("土地利用解译图"), &shuijieyitu1, IDD_SHUIJIEYITU1);
	m_shuitab1.AddPage(TEXT("土地利用总表"), &shuizongbiao10, IDD_SHUIZONGBIAO10);
	m_shuitab1.AddPage(TEXT("土地利用分表1"), &shuifenbiao11, IDD_SHUIFENBIAO11);
	m_shuitab1.AddPage(TEXT("土地利用分表2"), &shuifenbiao12, IDD_SHUIFENBIAO12);
	m_shuitab1.AddPage(TEXT("土地利用分表3"), &shuifenbiao13, IDD_SHUIFENBIAO13);

	//显示标签
	m_shuitab1.Show();
}
