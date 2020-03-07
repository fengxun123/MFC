// SelectView.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "SelectView.h"
#include "MainFrm.h "

// CSelectView

IMPLEMENT_DYNCREATE(CSelectView, CTreeView)

CSelectView::CSelectView()
{

}

CSelectView::~CSelectView()
{
}

BEGIN_MESSAGE_MAP(CSelectView, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CSelectView::OnTvnSelchanged)
END_MESSAGE_MAP()


// CSelectView 诊断

#ifdef _DEBUG
void CSelectView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectView 消息处理程序


void CSelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	//初始化树视图
	//获取树视图中的树控件CTreeView
	m_treeCtrl = &GetTreeCtrl();
	//1.准备图片集合

	//图标资源加载
	HICON icon[4];
	icon[0] = AfxGetApp()->LoadIconA(IDI_ICONUSER);
	icon[1]= AfxGetApp()->LoadIconA(IDI_ICONPIC);
	icon[2] = AfxGetApp()->LoadIconA(IDI_ICONMENU);
	icon[3] = AfxGetApp()->LoadIconA(IDI_ICONTAB);
	
	//图片列表的创建
	m_imageList.Create(30, 30, ILC_COLOR32, 4, 4);
	
	//图片列表追加图标
	for (int i = 0; i < 4; i++)
	{
		m_imageList.Add(icon[i]);
	}
	
	m_treeCtrl->SetImageList(&m_imageList, TVSIL_NORMAL);

	//2.设置节点
	HTREEITEM parent0=m_treeCtrl->InsertItem(TEXT("个人信息"), 0, 0, NULL);
	
	HTREEITEM parent1 =m_treeCtrl->InsertItem(TEXT("图片数据"), 1, 1, NULL);
	HTREEITEM sub11 =m_treeCtrl->InsertItem(TEXT("三公山1"), 2, 2, parent1);
	HTREEITEM sub21 = m_treeCtrl->InsertItem(TEXT("大龙山1"), 2, 2, parent1);
	HTREEITEM sub31 = m_treeCtrl->InsertItem(TEXT("狮子山1"), 2, 2, parent1);
	HTREEITEM sub41 = m_treeCtrl->InsertItem(TEXT("巢湖东南1"), 2, 2, parent1);
	
	HTREEITEM parent2 = m_treeCtrl->InsertItem(TEXT("土地分类"), 3, 3, NULL);
	HTREEITEM sub12 = m_treeCtrl->InsertItem(TEXT("三公山2"), 2, 2, parent2);
	HTREEITEM sub22 = m_treeCtrl->InsertItem(TEXT("大龙山2"), 2, 2, parent2);
	HTREEITEM sub32 = m_treeCtrl->InsertItem(TEXT("狮子山2"), 2, 2, parent2);
	HTREEITEM sub42 = m_treeCtrl->InsertItem(TEXT("巢湖东南2"), 2,2, parent2);
	
	HTREEITEM parent3 = m_treeCtrl->InsertItem(TEXT("植被覆盖"), 3, 3, NULL);
	HTREEITEM sub13 = m_treeCtrl->InsertItem(TEXT("三公山3"), 2, 2, parent3);
	HTREEITEM sub23 = m_treeCtrl->InsertItem(TEXT("大龙山3"), 2, 2, parent3);
	HTREEITEM sub33 = m_treeCtrl->InsertItem(TEXT("狮子山3"), 2, 2, parent3);
	HTREEITEM sub43 = m_treeCtrl->InsertItem(TEXT("巢湖东南3"), 2, 2, parent3);
	
	HTREEITEM parent4 = m_treeCtrl->InsertItem(TEXT("水土流失"), 3, 3, NULL);
	HTREEITEM sub14 = m_treeCtrl->InsertItem(TEXT("三公山4"), 2, 2, parent4);
	HTREEITEM sub24 = m_treeCtrl->InsertItem(TEXT("大龙山4"), 2, 2, parent4);
	HTREEITEM sub34 = m_treeCtrl->InsertItem(TEXT("狮子山4"), 2, 2, parent4);
	HTREEITEM sub44 = m_treeCtrl->InsertItem(TEXT("巢湖东南4"), 2, 2, parent4);

	//设置默认项
	m_treeCtrl->SelectItem(parent0);

	// TODO: 在此添加专用代码和/或调用基类
}


void CSelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

	//获取当前选中项
	HTREEITEM item = m_treeCtrl->GetSelectedItem();

	//获取这个项中的内容
	CString str = m_treeCtrl->GetItemText(item);
	
	//MessageBox(str);
	if (str == TEXT("个人信息"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
	}

	else if (str == TEXT("三公山1"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B1, (WPARAM)NM_B1, (LPARAM)0);
	}
	else if (str == TEXT("大龙山1"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B1, (WPARAM)NM_C1, (LPARAM)0);
	}

	else if (str == TEXT("狮子山1"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B1, (WPARAM)NM_D1, (LPARAM)0);
	}

	else if (str == TEXT("巢湖东南1"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B1, (WPARAM)NM_E1, (LPARAM)0);
	}


	else if (str == TEXT("三公山2"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B2, (WPARAM)NM_B2, (LPARAM)0);
	}
	else if (str == TEXT("大龙山2"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C2, (WPARAM)NM_C2, (LPARAM)0);
	}

	else if (str == TEXT("狮子山2"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D2, (WPARAM)NM_D2, (LPARAM)0);
	}

	else if (str == TEXT("巢湖东南2"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E2, (WPARAM)NM_E2, (LPARAM)0);
	}

	else if (str == TEXT("三公山3"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B3, (WPARAM)NM_B3, (LPARAM)0);
	}
	else if (str == TEXT("大龙山3"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C3, (WPARAM)NM_C3, (LPARAM)0);
	}

	else if (str == TEXT("狮子山3"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D3, (WPARAM)NM_D3, (LPARAM)0);
	}

	else if (str == TEXT("巢湖东南3"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E3, (WPARAM)NM_E3, (LPARAM)0);
	}

	else if (str == TEXT("三公山4"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B4, (WPARAM)NM_B4, (LPARAM)0);
	}
	else if (str == TEXT("大龙山4"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C4, (WPARAM)NM_C4, (LPARAM)0);
	}

	else if (str == TEXT("狮子山4"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D4, (WPARAM)NM_D4, (LPARAM)0);
	}

	else if(str == TEXT("巢湖东南4"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E4, (WPARAM)NM_E4, (LPARAM)0);
	}
}
