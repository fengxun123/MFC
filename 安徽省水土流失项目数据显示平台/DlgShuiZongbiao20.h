#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuiZongbiao20 对话框

class CDlgShuiZongbiao20 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuiZongbiao20)

public:
	CDlgShuiZongbiao20(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgShuiZongbiao20();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIZONGBIAO20 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	std::vector<std::string> m_data[100];  //存放数据库记录，最大为100条
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist20;
public:
	virtual BOOL OnInitDialog();
};
