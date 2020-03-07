#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgTufenbiao41 对话框

class CDlgTufenbiao41 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTufenbiao41)

public:
	CDlgTufenbiao41(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgTufenbiao41();
	BOOL ConnectDB();		//连接MYSQL数据库
	BOOL InsertDB();		//插入数据
	BOOL DeleteDB();        //删除数据
	BOOL SelectDB();		//查询数据
	void GetDataFromDB();   //从数据库获取数据
	void ShowInfo();        //显示数据
	void ClearData();       //清空数据
	afx_msg void OnDestroy();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUFENBIAO41 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	std::vector<std::string> m_data[100];  //存放数据库记录，最大为100条

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
private:
	CListCtrl m_list41;

public:
//	CEdit m_name41;
private:
	CString m_mianji41;
	CString m_zhanbi41;
	CString m_name41;
public:
	virtual BOOL OnInitDialog();
};
