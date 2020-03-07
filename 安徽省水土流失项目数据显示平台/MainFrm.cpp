
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "Login.h"
#include "MainFrm.h"
#include "SelectView.h"
#include "DisplayView.h"
#include "UserDlg.h"
#include "PictureDlg11.h"
#include "PictureDlg21.h"
#include "PictureDlg31.h"
#include "PictureDlg41.h"
#include "DlgTudiliyong.h"
#include "DlgTudiliyong1.h"
#include "DlgTudiliyong2.h"
#include "DlgTudiliyong3.h"
#include "DlgZhibeifugai1.h"
#include "DlgZhibeifugai2.h"
#include "DlgZhibeifugai3.h"
#include "DlgZhibeifugai4.h"
#include "DlgShuituliushi1.h"
#include "DlgShuituliushi2.h"
#include "DlgShuituliushi3.h"
#include "DlgShuituliushi4.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
ON_WM_CREATE()
ON_MESSAGE(NM_A, OnMyChange)
ON_MESSAGE(NM_B1, OnMyChange)
ON_MESSAGE(NM_C1, OnMyChange)
ON_MESSAGE(NM_D1, OnMyChange)
ON_MESSAGE(NM_E1, OnMyChange)
	
ON_MESSAGE(NM_B2, OnMyChange)
ON_MESSAGE(NM_C2, OnMyChange)
ON_MESSAGE(NM_D2, OnMyChange)
ON_MESSAGE(NM_E2, OnMyChange)

ON_MESSAGE(NM_B3, OnMyChange)
ON_MESSAGE(NM_C3, OnMyChange)
ON_MESSAGE(NM_D3, OnMyChange)
ON_MESSAGE(NM_E3, OnMyChange)

ON_MESSAGE(NM_B4, OnMyChange)
ON_MESSAGE(NM_C4, OnMyChange)
ON_MESSAGE(NM_D4, OnMyChange)
ON_MESSAGE(NM_E4, OnMyChange)

END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));
	//设置图标
	SetClassLong(m_hWnd, GCL_HICON, (LONG)AfxGetApp()->LoadIconA(IDI_ICONWIN));
	//设置右侧标题
	SetTitle(TEXT("2018/12/8"));

	//设置窗口大小
	MoveWindow(0, 0, 1000, 600);
	CenterWindow();//设置居中显示
	//至此，前期配置完成！

	/*测试CLogin
	CLogin log;
	CString name;
	CString pwd;
	log.ReadLogin(name, pwd);
	
	MessageBox(name);
	MessageBox(pwd);

	修改密码；
	log.WritePwd("胡歌", "1234");
	*/
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类
	//静态拆分窗口代码
	//拆分成1行2列
	m_spliter.CreateStatic(this, 1, 2);
	//创建视图，RUNTIME_CLASS(CSelectView),需包含"SelectView.h",CSize视图的宽高，pContext为最后参数
	//左右侧具体显示的内容
	m_spliter.CreateView(0, 0, RUNTIME_CLASS(CSelectView), CSize(200, 600), pContext);

	m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDisplayView), CSize(800, 600), pContext);

	//return CFrameWnd::OnCreateClient(lpcs, pContext);
	return TRUE;//代表自己拆分
}

LRESULT CMainFrame::OnMyChange(WPARAM wParam, LPARAM lParam)
{
	CCreateContext Context;

	if (wParam == NM_A) {
		//声明新的视图类 CUserDlg继承CFormView类
		Context.m_pNewViewClass = RUNTIME_CLASS(CUserDlg); 
		//当前类为CMainFrame类
		Context.m_pCurrentFrame = this; 

		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1); //m_spliter为窗口分割类

		m_spliter.DeleteView(0, 1); //删除当前视图

		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CUserDlg), CSize(800, 600), &Context); //创建新的视图

		CUserDlg *pNewView = (CUserDlg *)m_spliter.GetPane(0, 1); //GetPane 返回位于指定行和列处的窗格

		m_spliter.RecalcLayout(); //在调整行或列尺寸后调用此函数来重新显示该分隔器窗口

		pNewView->OnInitialUpdate(); //重新初始化窗口

		m_spliter.SetActivePane(0, 1); //在框架中设置一个活动窗
		
	}
	else if (wParam == NM_B1)
	{
		Context.m_pNewViewClass = RUNTIME_CLASS(CPictureDlg11);
		//当前类为CMainFrame类
		Context.m_pCurrentFrame = this;

		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1); //m_spliter为窗口分割类

		m_spliter.DeleteView(0, 1); //删除当前视图

		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CPictureDlg11), CSize(800, 600), &Context); //创建新的视图

		CPictureDlg11 *pNewView = (CPictureDlg11 *)m_spliter.GetPane(0, 1); //GetPane 返回位于指定行和列处的窗格

		m_spliter.RecalcLayout(); //在调整行或列尺寸后调用此函数来重新显示该分隔器窗口

		pNewView->OnInitialUpdate(); //重新初始化窗口

		m_spliter.SetActivePane(0, 1); //在框架中设置一个活动窗

	}
	else if (wParam == NM_C1)
	{
		Context.m_pNewViewClass = RUNTIME_CLASS(CPictureDlg21);
		//当前类为CMainFrame类
		Context.m_pCurrentFrame = this;

		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1); //m_spliter为窗口分割类

		m_spliter.DeleteView(0, 1); //删除当前视图

		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CPictureDlg21), CSize(800, 600), &Context); //创建新的视图

		CPictureDlg21 *pNewView = (CPictureDlg21 *)m_spliter.GetPane(0, 1); //GetPane 返回位于指定行和列处的窗格

		m_spliter.RecalcLayout(); //在调整行或列尺寸后调用此函数来重新显示该分隔器窗口

		pNewView->OnInitialUpdate(); //重新初始化窗口

		m_spliter.SetActivePane(0, 1); //在框架中设置一个活动窗

	}
	else if (wParam == NM_D1)
	{
		Context.m_pNewViewClass = RUNTIME_CLASS(CPictureDlg31);
		//当前类为CMainFrame类
		Context.m_pCurrentFrame = this;

		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1); //m_spliter为窗口分割类

		m_spliter.DeleteView(0, 1); //删除当前视图

		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CPictureDlg31), CSize(800, 600), &Context); //创建新的视图

		CPictureDlg31 *pNewView = (CPictureDlg31 *)m_spliter.GetPane(0, 1); //GetPane 返回位于指定行和列处的窗格

		m_spliter.RecalcLayout(); //在调整行或列尺寸后调用此函数来重新显示该分隔器窗口

		pNewView->OnInitialUpdate(); //重新初始化窗口

		m_spliter.SetActivePane(0, 1); //在框架中设置一个活动窗

	}
	else if (wParam == NM_E1)
	{
		Context.m_pNewViewClass = RUNTIME_CLASS(CPictureDlg41);
		//当前类为CMainFrame类
		Context.m_pCurrentFrame = this;

		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1); //m_spliter为窗口分割类

		m_spliter.DeleteView(0, 1); //删除当前视图

		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CPictureDlg41), CSize(800, 600), &Context); //创建新的视图

		CPictureDlg41 *pNewView = (CPictureDlg41 *)m_spliter.GetPane(0, 1); //GetPane 返回位于指定行和列处的窗格

		m_spliter.RecalcLayout(); //在调整行或列尺寸后调用此函数来重新显示该分隔器窗口

		pNewView->OnInitialUpdate(); //重新初始化窗口

		m_spliter.SetActivePane(0, 1); //在框架中设置一个活动窗

	}

	else if (wParam == NM_B2)
	{
		Context.m_pNewViewClass = RUNTIME_CLASS(CDlgTudiliyong);
		//当前类为CMainFrame类
		Context.m_pCurrentFrame = this;

		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1); //m_spliter为窗口分割类

		m_spliter.DeleteView(0, 1); //删除当前视图

		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDlgTudiliyong), CSize(800, 600), &Context); //创建新的视图

		CDlgTudiliyong *pNewView = (CDlgTudiliyong *)m_spliter.GetPane(0, 1); //GetPane 返回位于指定行和列处的窗格

		m_spliter.RecalcLayout(); //在调整行或列尺寸后调用此函数来重新显示该分隔器窗口

		pNewView->OnInitialUpdate(); //重新初始化窗口

		m_spliter.SetActivePane(0, 1); //在框架中设置一个活动窗

	}

	else if (wParam == NM_C2)
	{
		Context.m_pNewViewClass = RUNTIME_CLASS(CDlgTudiliyong1);
		//当前类为CMainFrame类
		Context.m_pCurrentFrame = this;

		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1); //m_spliter为窗口分割类

		m_spliter.DeleteView(0, 1); //删除当前视图

		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDlgTudiliyong1), CSize(800, 600), &Context); //创建新的视图

		CDlgTudiliyong1 *pNewView = (CDlgTudiliyong1 *)m_spliter.GetPane(0, 1); //GetPane 返回位于指定行和列处的窗格

		m_spliter.RecalcLayout(); //在调整行或列尺寸后调用此函数来重新显示该分隔器窗口

		pNewView->OnInitialUpdate(); //重新初始化窗口

		m_spliter.SetActivePane(0, 1); //在框架中设置一个活动窗

	}
	else if (wParam == NM_D2)
	{
		Context.m_pNewViewClass = RUNTIME_CLASS(CDlgTudiliyong2);
		//当前类为CMainFrame类
		Context.m_pCurrentFrame = this;

		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1); //m_spliter为窗口分割类

		m_spliter.DeleteView(0, 1); //删除当前视图

		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDlgTudiliyong2), CSize(800, 600), &Context); //创建新的视图

		CDlgTudiliyong2 *pNewView = (CDlgTudiliyong2 *)m_spliter.GetPane(0, 1); //GetPane 返回位于指定行和列处的窗格

		m_spliter.RecalcLayout(); //在调整行或列尺寸后调用此函数来重新显示该分隔器窗口

		pNewView->OnInitialUpdate(); //重新初始化窗口

		m_spliter.SetActivePane(0, 1); //在框架中设置一个活动窗

	}
	else if (wParam == NM_E2)
	{
		Context.m_pNewViewClass = RUNTIME_CLASS(CDlgTudiliyong3);
		//当前类为CMainFrame类
		Context.m_pCurrentFrame = this;

		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1); //m_spliter为窗口分割类

		m_spliter.DeleteView(0, 1); //删除当前视图

		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDlgTudiliyong3), CSize(800, 600), &Context); //创建新的视图

		CDlgTudiliyong3 *pNewView = (CDlgTudiliyong3 *)m_spliter.GetPane(0, 1); //GetPane 返回位于指定行和列处的窗格

		m_spliter.RecalcLayout(); //在调整行或列尺寸后调用此函数来重新显示该分隔器窗口

		pNewView->OnInitialUpdate(); //重新初始化窗口

		m_spliter.SetActivePane(0, 1); //在框架中设置一个活动窗

	}

	else if (wParam == NM_B3)
	{
		Context.m_pNewViewClass = RUNTIME_CLASS(CDlgZhibeifugai1);
		//当前类为CMainFrame类
		Context.m_pCurrentFrame = this;

		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1); //m_spliter为窗口分割类

		m_spliter.DeleteView(0, 1); //删除当前视图

		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDlgZhibeifugai1), CSize(800, 600), &Context); //创建新的视图

		CDlgZhibeifugai1 *pNewView = (CDlgZhibeifugai1 *)m_spliter.GetPane(0, 1); //GetPane 返回位于指定行和列处的窗格

		m_spliter.RecalcLayout(); //在调整行或列尺寸后调用此函数来重新显示该分隔器窗口

		pNewView->OnInitialUpdate(); //重新初始化窗口

		m_spliter.SetActivePane(0, 1); //在框架中设置一个活动窗

	}
	
	else if (wParam == NM_C3)
	{
		Context.m_pNewViewClass = RUNTIME_CLASS(CDlgZhibeifugai2);
		//当前类为CMainFrame类
		Context.m_pCurrentFrame = this;

		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1); //m_spliter为窗口分割类

		m_spliter.DeleteView(0, 1); //删除当前视图

		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDlgZhibeifugai2), CSize(800, 600), &Context); //创建新的视图

		CDlgZhibeifugai2 *pNewView = (CDlgZhibeifugai2 *)m_spliter.GetPane(0, 1); //GetPane 返回位于指定行和列处的窗格

		m_spliter.RecalcLayout(); //在调整行或列尺寸后调用此函数来重新显示该分隔器窗口

		pNewView->OnInitialUpdate(); //重新初始化窗口

		m_spliter.SetActivePane(0, 1); //在框架中设置一个活动窗

	}

	else if (wParam == NM_D3)
	{
		Context.m_pNewViewClass = RUNTIME_CLASS(CDlgZhibeifugai3);
		//当前类为CMainFrame类
		Context.m_pCurrentFrame = this;

		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1); //m_spliter为窗口分割类

		m_spliter.DeleteView(0, 1); //删除当前视图

		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDlgZhibeifugai3), CSize(800, 600), &Context); //创建新的视图

		CDlgZhibeifugai3 *pNewView = (CDlgZhibeifugai3 *)m_spliter.GetPane(0, 1); //GetPane 返回位于指定行和列处的窗格

		m_spliter.RecalcLayout(); //在调整行或列尺寸后调用此函数来重新显示该分隔器窗口

		pNewView->OnInitialUpdate(); //重新初始化窗口

		m_spliter.SetActivePane(0, 1); //在框架中设置一个活动窗

	}

	else if (wParam == NM_E3)
	{
		Context.m_pNewViewClass = RUNTIME_CLASS(CDlgZhibeifugai4);
		//当前类为CMainFrame类
		Context.m_pCurrentFrame = this;

		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1); //m_spliter为窗口分割类

		m_spliter.DeleteView(0, 1); //删除当前视图

		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDlgZhibeifugai4), CSize(800, 600), &Context); //创建新的视图

		CDlgZhibeifugai4 *pNewView = (CDlgZhibeifugai4 *)m_spliter.GetPane(0, 1); //GetPane 返回位于指定行和列处的窗格

		m_spliter.RecalcLayout(); //在调整行或列尺寸后调用此函数来重新显示该分隔器窗口

		pNewView->OnInitialUpdate(); //重新初始化窗口

		m_spliter.SetActivePane(0, 1); //在框架中设置一个活动窗

	}

	else if (wParam == NM_B4)
	{
		Context.m_pNewViewClass = RUNTIME_CLASS(CDlgShuituliushi1);
		//当前类为CMainFrame类
		Context.m_pCurrentFrame = this;

		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1); //m_spliter为窗口分割类

		m_spliter.DeleteView(0, 1); //删除当前视图

		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDlgShuituliushi1), CSize(800, 600), &Context); //创建新的视图

		CDlgShuituliushi1 *pNewView = (CDlgShuituliushi1 *)m_spliter.GetPane(0, 1); //GetPane 返回位于指定行和列处的窗格

		m_spliter.RecalcLayout(); //在调整行或列尺寸后调用此函数来重新显示该分隔器窗口

		pNewView->OnInitialUpdate(); //重新初始化窗口

		m_spliter.SetActivePane(0, 1); //在框架中设置一个活动窗

	}
	else if (wParam == NM_C4)
	{
		Context.m_pNewViewClass = RUNTIME_CLASS(CDlgShuituliushi2);
		//当前类为CMainFrame类
		Context.m_pCurrentFrame = this;

		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1); //m_spliter为窗口分割类

		m_spliter.DeleteView(0, 1); //删除当前视图

		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDlgShuituliushi2), CSize(800, 600), &Context); //创建新的视图

		CDlgShuituliushi2 *pNewView = (CDlgShuituliushi2 *)m_spliter.GetPane(0, 1); //GetPane 返回位于指定行和列处的窗格

		m_spliter.RecalcLayout(); //在调整行或列尺寸后调用此函数来重新显示该分隔器窗口

		pNewView->OnInitialUpdate(); //重新初始化窗口

		m_spliter.SetActivePane(0, 1); //在框架中设置一个活动窗

	}
	else if (wParam == NM_D4)
	{
		Context.m_pNewViewClass = RUNTIME_CLASS(CDlgShuituliushi3);
		//当前类为CMainFrame类
		Context.m_pCurrentFrame = this;

		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1); //m_spliter为窗口分割类

		m_spliter.DeleteView(0, 1); //删除当前视图

		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDlgShuituliushi3), CSize(800, 600), &Context); //创建新的视图

		CDlgShuituliushi3 *pNewView = (CDlgShuituliushi3 *)m_spliter.GetPane(0, 1); //GetPane 返回位于指定行和列处的窗格

		m_spliter.RecalcLayout(); //在调整行或列尺寸后调用此函数来重新显示该分隔器窗口

		pNewView->OnInitialUpdate(); //重新初始化窗口

		m_spliter.SetActivePane(0, 1); //在框架中设置一个活动窗

	}
	else if (wParam == NM_E4)
	{
		Context.m_pNewViewClass = RUNTIME_CLASS(CDlgShuituliushi4);
		//当前类为CMainFrame类
		Context.m_pCurrentFrame = this;

		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1); //m_spliter为窗口分割类

		m_spliter.DeleteView(0, 1); //删除当前视图

		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDlgShuituliushi4), CSize(800, 600), &Context); //创建新的视图

		CDlgShuituliushi4 *pNewView = (CDlgShuituliushi4 *)m_spliter.GetPane(0, 1); //GetPane 返回位于指定行和列处的窗格

		m_spliter.RecalcLayout(); //在调整行或列尺寸后调用此函数来重新显示该分隔器窗口

		pNewView->OnInitialUpdate(); //重新初始化窗口

		m_spliter.SetActivePane(0, 1); //在框架中设置一个活动窗

	}
	return 0;
}

