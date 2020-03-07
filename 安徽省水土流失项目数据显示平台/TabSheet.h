#pragma once

#define MAXPAGE 10

// CTabSheet

class CTabSheet : public CTabCtrl
{
	DECLARE_DYNAMIC(CTabSheet)

public:
	CTabSheet();
	virtual ~CTabSheet();

	CDialog* m_pPages[MAXPAGE];        // page���Ӧ�ĶԻ���
	UINT m_IDD[MAXPAGE];            // �Ի�����Դ��Ӧ��ID
	int m_nNumOfPages;                // ��ӵ���page��
	LPCTSTR m_Title[MAXPAGE];        // page���Ӧ�ı���
	int m_nCurrentPage;                // ��ǰ��ʾ�ĸ�page

	BOOL AddPage(LPCTSTR title, CDialog *pDialog, UINT ID);
	void Show();
	void SetRect();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
}; 
