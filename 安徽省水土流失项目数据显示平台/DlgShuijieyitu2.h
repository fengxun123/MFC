#pragma once
#include "afxwin.h"


// CDlgShuijieyitu2 对话框

class CDlgShuijieyitu2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuijieyitu2)

public:
	CDlgShuijieyitu2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgShuijieyitu2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIJIEYITU2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_shuipic2;
public:
	virtual BOOL OnInitDialog();
};
