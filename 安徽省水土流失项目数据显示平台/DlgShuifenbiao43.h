#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuifenbiao43 对话框

class CDlgShuifenbiao43 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuifenbiao43)

public:
	CDlgShuifenbiao43(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgShuifenbiao43();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIFENBIAO43 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	std::vector<std::string> m_data[100];  //存放数据库记录，最大为100条
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist43;
public:
	virtual BOOL OnInitDialog();
};
