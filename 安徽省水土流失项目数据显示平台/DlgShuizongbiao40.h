#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuizongbiao40 对话框

class CDlgShuizongbiao40 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuizongbiao40)

public:
	CDlgShuizongbiao40(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgShuizongbiao40();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIZONGBIAO40 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	std::vector<std::string> m_data[100];  //存放数据库记录，最大为100条
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist40;
public:
	virtual BOOL OnInitDialog();
};
