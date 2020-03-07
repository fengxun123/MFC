#pragma once
#include "afxwin.h"


// CDlgShuijieyitu1 对话框

class CDlgShuijieyitu1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuijieyitu1)

public:
	CDlgShuijieyitu1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgShuijieyitu1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIJIEYITU1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_shuipic1;
public:
	virtual BOOL OnInitDialog();
};
