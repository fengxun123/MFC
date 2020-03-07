// SelectView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
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


// CSelectView ���

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


// CSelectView ��Ϣ�������


void CSelectView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	//��ʼ������ͼ
	//��ȡ����ͼ�е����ؼ�CTreeView
	m_treeCtrl = &GetTreeCtrl();
	//1.׼��ͼƬ����

	//ͼ����Դ����
	HICON icon[4];
	icon[0] = AfxGetApp()->LoadIconA(IDI_ICONUSER);
	icon[1]= AfxGetApp()->LoadIconA(IDI_ICONPIC);
	icon[2] = AfxGetApp()->LoadIconA(IDI_ICONMENU);
	icon[3] = AfxGetApp()->LoadIconA(IDI_ICONTAB);
	
	//ͼƬ�б�Ĵ���
	m_imageList.Create(30, 30, ILC_COLOR32, 4, 4);
	
	//ͼƬ�б�׷��ͼ��
	for (int i = 0; i < 4; i++)
	{
		m_imageList.Add(icon[i]);
	}
	
	m_treeCtrl->SetImageList(&m_imageList, TVSIL_NORMAL);

	//2.���ýڵ�
	HTREEITEM parent0=m_treeCtrl->InsertItem(TEXT("������Ϣ"), 0, 0, NULL);
	
	HTREEITEM parent1 =m_treeCtrl->InsertItem(TEXT("ͼƬ����"), 1, 1, NULL);
	HTREEITEM sub11 =m_treeCtrl->InsertItem(TEXT("����ɽ1"), 2, 2, parent1);
	HTREEITEM sub21 = m_treeCtrl->InsertItem(TEXT("����ɽ1"), 2, 2, parent1);
	HTREEITEM sub31 = m_treeCtrl->InsertItem(TEXT("ʨ��ɽ1"), 2, 2, parent1);
	HTREEITEM sub41 = m_treeCtrl->InsertItem(TEXT("��������1"), 2, 2, parent1);
	
	HTREEITEM parent2 = m_treeCtrl->InsertItem(TEXT("���ط���"), 3, 3, NULL);
	HTREEITEM sub12 = m_treeCtrl->InsertItem(TEXT("����ɽ2"), 2, 2, parent2);
	HTREEITEM sub22 = m_treeCtrl->InsertItem(TEXT("����ɽ2"), 2, 2, parent2);
	HTREEITEM sub32 = m_treeCtrl->InsertItem(TEXT("ʨ��ɽ2"), 2, 2, parent2);
	HTREEITEM sub42 = m_treeCtrl->InsertItem(TEXT("��������2"), 2,2, parent2);
	
	HTREEITEM parent3 = m_treeCtrl->InsertItem(TEXT("ֲ������"), 3, 3, NULL);
	HTREEITEM sub13 = m_treeCtrl->InsertItem(TEXT("����ɽ3"), 2, 2, parent3);
	HTREEITEM sub23 = m_treeCtrl->InsertItem(TEXT("����ɽ3"), 2, 2, parent3);
	HTREEITEM sub33 = m_treeCtrl->InsertItem(TEXT("ʨ��ɽ3"), 2, 2, parent3);
	HTREEITEM sub43 = m_treeCtrl->InsertItem(TEXT("��������3"), 2, 2, parent3);
	
	HTREEITEM parent4 = m_treeCtrl->InsertItem(TEXT("ˮ����ʧ"), 3, 3, NULL);
	HTREEITEM sub14 = m_treeCtrl->InsertItem(TEXT("����ɽ4"), 2, 2, parent4);
	HTREEITEM sub24 = m_treeCtrl->InsertItem(TEXT("����ɽ4"), 2, 2, parent4);
	HTREEITEM sub34 = m_treeCtrl->InsertItem(TEXT("ʨ��ɽ4"), 2, 2, parent4);
	HTREEITEM sub44 = m_treeCtrl->InsertItem(TEXT("��������4"), 2, 2, parent4);

	//����Ĭ����
	m_treeCtrl->SelectItem(parent0);

	// TODO: �ڴ����ר�ô����/����û���
}


void CSelectView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

	//��ȡ��ǰѡ����
	HTREEITEM item = m_treeCtrl->GetSelectedItem();

	//��ȡ������е�����
	CString str = m_treeCtrl->GetItemText(item);
	
	//MessageBox(str);
	if (str == TEXT("������Ϣ"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);
	}

	else if (str == TEXT("����ɽ1"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B1, (WPARAM)NM_B1, (LPARAM)0);
	}
	else if (str == TEXT("����ɽ1"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B1, (WPARAM)NM_C1, (LPARAM)0);
	}

	else if (str == TEXT("ʨ��ɽ1"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B1, (WPARAM)NM_D1, (LPARAM)0);
	}

	else if (str == TEXT("��������1"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B1, (WPARAM)NM_E1, (LPARAM)0);
	}


	else if (str == TEXT("����ɽ2"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B2, (WPARAM)NM_B2, (LPARAM)0);
	}
	else if (str == TEXT("����ɽ2"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C2, (WPARAM)NM_C2, (LPARAM)0);
	}

	else if (str == TEXT("ʨ��ɽ2"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D2, (WPARAM)NM_D2, (LPARAM)0);
	}

	else if (str == TEXT("��������2"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E2, (WPARAM)NM_E2, (LPARAM)0);
	}

	else if (str == TEXT("����ɽ3"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B3, (WPARAM)NM_B3, (LPARAM)0);
	}
	else if (str == TEXT("����ɽ3"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C3, (WPARAM)NM_C3, (LPARAM)0);
	}

	else if (str == TEXT("ʨ��ɽ3"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D3, (WPARAM)NM_D3, (LPARAM)0);
	}

	else if (str == TEXT("��������3"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E3, (WPARAM)NM_E3, (LPARAM)0);
	}

	else if (str == TEXT("����ɽ4"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B4, (WPARAM)NM_B4, (LPARAM)0);
	}
	else if (str == TEXT("����ɽ4"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C4, (WPARAM)NM_C4, (LPARAM)0);
	}

	else if (str == TEXT("ʨ��ɽ4"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D4, (WPARAM)NM_D4, (LPARAM)0);
	}

	else if(str == TEXT("��������4"))
	{
		::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E4, (WPARAM)NM_E4, (LPARAM)0);
	}
}
