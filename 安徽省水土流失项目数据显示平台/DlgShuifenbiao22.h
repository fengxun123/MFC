#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuifenbiao22 对话框

class CDlgShuifenbiao22 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuifenbiao22)

public:
	CDlgShuifenbiao22(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgShuifenbiao22();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIFENBIAO22 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	std::vector<std::string> m_data[100];  //存放数据库记录，最大为100条
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist22;
public:
	virtual BOOL OnInitDialog();
};
