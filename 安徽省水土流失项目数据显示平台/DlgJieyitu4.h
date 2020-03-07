#pragma once
#include "afxwin.h"


// CDlgJieyitu4 对话框

class CDlgJieyitu4 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgJieyitu4)

public:
	CDlgJieyitu4(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgJieyitu4();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUJIEYITU4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_tupic3;
public:
	virtual BOOL OnInitDialog();
};
