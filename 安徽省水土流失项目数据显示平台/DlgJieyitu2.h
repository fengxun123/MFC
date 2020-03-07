#pragma once
#include "afxwin.h"


// CDlgJieyitu2 对话框

class CDlgJieyitu2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgJieyitu2)

public:
	CDlgJieyitu2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgJieyitu2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUJIEYITU2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_tupic1;
public:
	virtual BOOL OnInitDialog();
};
