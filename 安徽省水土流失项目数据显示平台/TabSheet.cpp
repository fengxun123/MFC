// TabSheet.cpp : implementation file
//

#include "stdafx.h"
#include "TabSheet.h"


// CTabSheet

IMPLEMENT_DYNAMIC(CTabSheet, CTabCtrl)

CTabSheet::CTabSheet()
{
	m_nNumOfPages = 0;
	m_nCurrentPage = 0; // ��ʼ��ʾ�ĸ�page
}

CTabSheet::~CTabSheet()
{
}


BEGIN_MESSAGE_MAP(CTabSheet, CTabCtrl)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CTabSheet message handlers
BOOL CTabSheet::AddPage(LPCTSTR title, CDialog *pDialog, UINT ID)
{
	if (MAXPAGE == m_nNumOfPages)
		return FALSE;

	// ����Ŀǰ�ܵ��ӶԻ�����
	m_nNumOfPages++;

	// ��¼�ӶԻ����ָ�롢��ԴID��Ҫ�ڱ�ǩ����ʾ������
	m_pPages[m_nNumOfPages - 1] = pDialog;
	m_IDD[m_nNumOfPages - 1] = ID;
	m_Title[m_nNumOfPages - 1] = title;

	return TRUE;
}
void CTabSheet::Show()
{
	// ����CDialog::Create�������ӶԻ��򣬲���ʹ��CTabCtrl::InsertItem��������Ӧ�ı�ǩ
	for (int i = 0; i < m_nNumOfPages; i++)
	{
		m_pPages[i]->Create(m_IDD[i], this);
		InsertItem(i, m_Title[i]);
	}

	// ���ڶԻ�����ʾʱĬ�ϵ��ǵ�һ����ǩ��ѡ�У�����Ӧ���õ�һ���ӶԻ�����ʾ�������ӶԻ�������
	m_pPages[0]->ShowWindow(SW_SHOW);
	for (int i = 1; i < m_nNumOfPages; i++)
		m_pPages[i]->ShowWindow(SW_HIDE);

	SetRect();
}

void CTabSheet::SetRect()
{
	CRect tabRect, itemRect;
	int nX, nY, nXc, nYc;

	// �õ�Tab Control�Ĵ�С
	GetClientRect(&tabRect);
	GetItemRect(0, &itemRect);

	// ��������ӶԻ���������Tab Control��λ�úʹ�С
	nX = itemRect.left;
	nY = itemRect.bottom + 1;
	nXc = tabRect.right - nX - 2;
	nYc = tabRect.bottom - nY - 2;

	//���ü���������ݶԸ��ӶԻ�����е���
	m_pPages[0]->SetWindowPos(&wndTop, nX, nY, nXc, nYc, SWP_SHOWWINDOW);
	for (int nCount = 1; nCount < m_nNumOfPages; nCount++)
		m_pPages[nCount]->SetWindowPos(&wndTop, nX, nY, nXc, nYc, SWP_HIDEWINDOW);

}

void CTabSheet::OnLButtonDown(UINT nFlags, CPoint point)
{
	CTabCtrl::OnLButtonDown(nFlags, point);

	// �ж��Ƿ񵥻���������ǩ
	if (m_nCurrentPage != GetCurFocus())
	{
		// ��ԭ�ȵ��ӶԻ�������
		m_pPages[m_nCurrentPage]->ShowWindow(SW_HIDE);
		m_nCurrentPage = GetCurFocus();

		// ��ʾ��ǰ��ǩ����Ӧ���ӶԻ���
		m_pPages[m_nCurrentPage]->ShowWindow(SW_SHOW);
	}
}