// DlgShuituliushi3.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgShuituliushi3.h"


// CDlgShuituliushi3

IMPLEMENT_DYNCREATE(CDlgShuituliushi3, CFormView)

CDlgShuituliushi3::CDlgShuituliushi3()
	: CFormView(IDD_SHUITULIUSHI3)
{

}

CDlgShuituliushi3::~CDlgShuituliushi3()
{
}

void CDlgShuituliushi3::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_shuitab3);
}

BEGIN_MESSAGE_MAP(CDlgShuituliushi3, CFormView)
END_MESSAGE_MAP()


// CDlgShuituliushi3 诊断

#ifdef _DEBUG
void CDlgShuituliushi3::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDlgShuituliushi3::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDlgShuituliushi3 消息处理程序


void CDlgShuituliushi3::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//添加标签页
	m_shuitab3.AddPage(TEXT("土地利用解译图"), &shuijieyitu3, IDD_SHUIJIEYITU3);
	m_shuitab3.AddPage(TEXT("土地利用总表"), &shuizongbiao30, IDD_SHUIZONGBIAO30);
	m_shuitab3.AddPage(TEXT("土地利用分表1"), &shuifenbiao31, IDD_SHUIFENBIAO31);
	m_shuitab3.AddPage(TEXT("土地利用分表2"), &shuifenbiao32, IDD_SHUIFENBIAO32);
	

	//显示标签
	m_shuitab3.Show();
}
