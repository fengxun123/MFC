#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgZhifenbiao13 对话框

class CDlgZhifenbiao13 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhifenbiao13)

public:
	CDlgZhifenbiao13(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgZhifenbiao13();

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
	enum { IDD = IDD_ZHIFENBIAO13 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	std::vector<std::string> m_data[100];  //存放数据库记录，最大为100条
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_zhilist13;
	CString m_zhiname13;
	CString m_zhimianji13;
	CString m_zhizhanbi13;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
