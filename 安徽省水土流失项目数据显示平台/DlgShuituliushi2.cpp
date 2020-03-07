// DlgShuituliushi2.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgShuituliushi2.h"


// CDlgShuituliushi2

IMPLEMENT_DYNCREATE(CDlgShuituliushi2, CFormView)

CDlgShuituliushi2::CDlgShuituliushi2()
	: CFormView(IDD_SHUITULIUSHI2)
{

}

CDlgShuituliushi2::~CDlgShuituliushi2()
{
}

void CDlgShuituliushi2::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_shuitab2);
}

BEGIN_MESSAGE_MAP(CDlgShuituliushi2, CFormView)
END_MESSAGE_MAP()


// CDlgShuituliushi2 诊断

#ifdef _DEBUG
void CDlgShuituliushi2::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgShuituliushi2::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgShuituliushi2 消息处理程序


void CDlgShuituliushi2::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//添加标签页
	m_shuitab2.AddPage(TEXT("土地利用解译图"), &shuijieyitu2, IDD_SHUIJIEYITU2);
	m_shuitab2.AddPage(TEXT("土地利用总表"), &shuizongbiao20, IDD_SHUIZONGBIAO20);
	m_shuitab2.AddPage(TEXT("土地利用分表1"), &shuifenbiao21, IDD_SHUIFENBIAO21);
	m_shuitab2.AddPage(TEXT("土地利用分表2"), &shuifenbiao22, IDD_SHUIFENBIAO22);
	m_shuitab2.AddPage(TEXT("土地利用分表3"), &shuifenbiao23, IDD_SHUIFENBIAO23);

	//显示标签
	m_shuitab2.Show();
}
