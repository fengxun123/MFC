
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once
#define NM_A  (WM_USER+100)
#define NM_B1 (WM_USER+101)
#define NM_C1 (WM_USER+102)
#define NM_D1 (WM_USER+103)
#define NM_E1 (WM_USER+104)

#define NM_B2 (WM_USER+105)
#define NM_C2 (WM_USER+106)
#define NM_D2 (WM_USER+107)
#define NM_E2 (WM_USER+108)

#define NM_B3 (WM_USER+109)
#define NM_C3 (WM_USER+110)
#define NM_D3 (WM_USER+111)
#define NM_E3 (WM_USER+112)

#define NM_B4 (WM_USER+113)
#define NM_C4 (WM_USER+114)
#define NM_D4 (WM_USER+115)
#define NM_E4 (WM_USER+116)

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar        m_wndStatusBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

private:
	CSplitterWnd m_spliter;//��ִ��������
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	
	afx_msg LRESULT OnMyChange(WPARAM wParam, LPARAM lParam);


};


