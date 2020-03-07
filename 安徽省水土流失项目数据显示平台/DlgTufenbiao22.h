#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgTufenbiao22 对话框

class CDlgTufenbiao22 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTufenbiao22)

public:
	CDlgTufenbiao22(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgTufenbiao22();

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
	enum { IDD = IDD_TUFENBIAO22 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	std::vector<std::string> m_data[100];  //存放数据库记录，最大为100条
	DECLARE_MESSAGE_MAP()
private:
	CString m_name22;
	CString m_mianji22;
	CString m_zhanbi22;
	CListCtrl m_list22;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
};
