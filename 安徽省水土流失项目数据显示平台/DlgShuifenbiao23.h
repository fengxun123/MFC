#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuifenbiao23 对话框

class CDlgShuifenbiao23 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuifenbiao23)

public:
	CDlgShuifenbiao23(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgShuifenbiao23();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIFENBIAO23 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	std::vector<std::string> m_data[100];  //存放数据库记录，最大为100条
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist23;
public:
	virtual BOOL OnInitDialog();
};
