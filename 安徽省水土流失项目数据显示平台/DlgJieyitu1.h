#pragma once
#include "afxwin.h"


// CDlgJieyitu1 对话框

class CDlgJieyitu1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgJieyitu1)

public:
	CDlgJieyitu1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgJieyitu1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUJIEYITU1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_tupic;
public:
	virtual BOOL OnInitDialog();
};
