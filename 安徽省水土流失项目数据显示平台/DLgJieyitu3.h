#pragma once
#include "afxwin.h"


// CDLgJieyitu3 对话框

class CDLgJieyitu3 : public CDialogEx
{
	DECLARE_DYNAMIC(CDLgJieyitu3)

public:
	CDLgJieyitu3(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDLgJieyitu3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUJIEYITU3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_tupic2;
public:
	virtual BOOL OnInitDialog();
};
