#pragma once
#include "afxwin.h"


// CDlgShuijieyitu3 对话框

class CDlgShuijieyitu3 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuijieyitu3)

public:
	CDlgShuijieyitu3(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgShuijieyitu3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIJIEYITU3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_shuipic3;
public:
	virtual BOOL OnInitDialog();
};
