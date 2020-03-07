#pragma once
#include "afxwin.h"


// CDlgZhijieyitu2 对话框

class CDlgZhijieyitu2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhijieyitu2)

public:
	CDlgZhijieyitu2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgZhijieyitu2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZHIJIEYITU2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_zhipic2;
public:
	virtual BOOL OnInitDialog();
};
