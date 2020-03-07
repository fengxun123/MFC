
// MainFrm.h : CMainFrame 类的接口
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
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CStatusBar        m_wndStatusBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

private:
	CSplitterWnd m_spliter;//拆分窗口类对象
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	
	afx_msg LRESULT OnMyChange(WPARAM wParam, LPARAM lParam);


};


