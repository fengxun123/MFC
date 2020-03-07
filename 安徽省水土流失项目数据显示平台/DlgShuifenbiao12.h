#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuifenbiao12 对话框

class CDlgShuifenbiao12 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuifenbiao12)

public:
	CDlgShuifenbiao12(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgShuifenbiao12();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIFENBIAO12 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	std::vector<std::string> m_data[100];  //存放数据库记录，最大为100条
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist12;
public:
	virtual BOOL OnInitDialog();
};
