#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgZhifenbiao12 对话框

class CDlgZhifenbiao12 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhifenbiao12)

public:
	CDlgZhifenbiao12(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgZhifenbiao12();

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
	enum { IDD = IDD_ZHIFENBIAO12 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	std::vector<std::string> m_data[100];  //存放数据库记录，最大为100条
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_zhilist12;
	CString m_zhiname12;
	CString m_zhimianji12;
	CString m_zhizhanbi12;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
