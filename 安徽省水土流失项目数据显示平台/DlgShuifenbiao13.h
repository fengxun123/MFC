#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuifenbiao13 对话框

class CDlgShuifenbiao13 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuifenbiao13)

public:
	CDlgShuifenbiao13(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgShuifenbiao13();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIFENBIAO13 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	std::vector<std::string> m_data[100];  //存放数据库记录，最大为100条
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist13;
public:
	virtual BOOL OnInitDialog();
};
