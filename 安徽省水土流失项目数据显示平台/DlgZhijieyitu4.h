#pragma once
#include "afxwin.h"


// CDlgZhijieyitu4 对话框

class CDlgZhijieyitu4 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhijieyitu4)

public:
	CDlgZhijieyitu4(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgZhijieyitu4();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZHIJIEYITU4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_zhipic4;
public:
	virtual BOOL OnInitDialog();
};
