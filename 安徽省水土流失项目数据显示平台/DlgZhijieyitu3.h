#pragma once
#include "afxwin.h"


// CDlgZhijieyitu3 对话框

class CDlgZhijieyitu3 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhijieyitu3)

public:
	CDlgZhijieyitu3(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgZhijieyitu3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZHIJIEYITU3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_zhipic3;
public:
	virtual BOOL OnInitDialog();
};
