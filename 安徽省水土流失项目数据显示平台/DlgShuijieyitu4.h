#pragma once
#include "afxwin.h"


// CDlgShuijieyitu4 对话框

class CDlgShuijieyitu4 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuijieyitu4)

public:
	CDlgShuijieyitu4(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgShuijieyitu4();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIJIEYITU4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_shuipic4;
public:
	virtual BOOL OnInitDialog();
};
