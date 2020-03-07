#pragma once

#define MAXPAGE 10

// CTabSheet

class CTabSheet : public CTabCtrl
{
	DECLARE_DYNAMIC(CTabSheet)

public:
	CTabSheet();
	virtual ~CTabSheet();

	CDialog* m_pPages[MAXPAGE];        // page相对应的对话框
	UINT m_IDD[MAXPAGE];            // 对话框资源对应的ID
	int m_nNumOfPages;                // 添加的总page数
	LPCTSTR m_Title[MAXPAGE];        // page相对应的标题
	int m_nCurrentPage;                // 当前显示哪个page

	BOOL AddPage(LPCTSTR title, CDialog *pDialog, UINT ID);
	void Show();
	void SetRect();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
}; 
