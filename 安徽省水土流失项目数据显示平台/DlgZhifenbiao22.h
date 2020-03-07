#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgZhifenbiao22 �Ի���

class CDlgZhifenbiao22 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhifenbiao22)

public:
	CDlgZhifenbiao22(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgZhifenbiao22();
	BOOL ConnectDB();		//����MYSQL���ݿ�
	BOOL InsertDB();		//��������
	BOOL DeleteDB();        //ɾ������
	BOOL SelectDB();		//��ѯ����
	void GetDataFromDB();   //�����ݿ��ȡ����
	void ShowInfo();        //��ʾ����
	void ClearData();       //�������
	afx_msg void OnDestroy();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZHIFENBIAO22 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_zhilist22;
	CString m_zhiname22;
	CString m_zhimianji22;
	CString m_zhizhanbi22;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
