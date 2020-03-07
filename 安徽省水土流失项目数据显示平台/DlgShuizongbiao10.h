#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuizongbiao10 对话框

class CDlgShuizongbiao10 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuizongbiao10)

public:
	CDlgShuizongbiao10(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgShuizongbiao10();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIZONGBIAO10 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	std::vector<std::string> m_data[100];  //存放数据库记录，最大为100条
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist10;
public:
	virtual BOOL OnInitDialog();
};
