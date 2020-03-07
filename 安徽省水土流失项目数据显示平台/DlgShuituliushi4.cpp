// DlgShuituliushi4.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgShuituliushi4.h"


// CDlgShuituliushi4

IMPLEMENT_DYNCREATE(CDlgShuituliushi4, CFormView)

CDlgShuituliushi4::CDlgShuituliushi4()
	: CFormView(IDD_SHUITULIUSHI4)
{

}

CDlgShuituliushi4::~CDlgShuituliushi4()
{
}

void CDlgShuituliushi4::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_shuitab4);
}

BEGIN_MESSAGE_MAP(CDlgShuituliushi4, CFormView)
END_MESSAGE_MAP()


// CDlgShuituliushi4 诊断

#ifdef _DEBUG
void CDlgShuituliushi4::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgShuituliushi4::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgShuituliushi4 消息处理程序


void CDlgShuituliushi4::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//添加标签页
	m_shuitab4.AddPage(TEXT("土地利用解译图"), &shuijieyitu4, IDD_SHUIJIEYITU4);
	m_shuitab4.AddPage(TEXT("土地利用总表"), &shuizongbiao40, IDD_SHUIZONGBIAO40);
	m_shuitab4.AddPage(TEXT("土地利用分表1"), &shuifenbiao41, IDD_SHUIFENBIAO41);
	m_shuitab4.AddPage(TEXT("土地利用分表2"), &shuifenbiao42, IDD_SHUIFENBIAO42);
	m_shuitab4.AddPage(TEXT("土地利用分表3"), &shuifenbiao43, IDD_SHUIFENBIAO43);

	//显示标签
	m_shuitab4.Show();
}
