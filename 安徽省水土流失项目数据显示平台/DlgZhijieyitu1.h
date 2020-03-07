#pragma once
#include "afxwin.h"


// CDlgZhijieyitu1 对话框

class CDlgZhijieyitu1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhijieyitu1)

public:
	CDlgZhijieyitu1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgZhijieyitu1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZHIJIEYITU1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_zhipic1;
public:
	virtual BOOL OnInitDialog();
};
