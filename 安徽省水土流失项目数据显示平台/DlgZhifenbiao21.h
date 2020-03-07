#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgZhifenbiao21 �Ի���

class CDlgZhifenbiao21 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhifenbiao21)

public:
	CDlgZhifenbiao21(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgZhifenbiao21();
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
	enum { IDD = IDD_ZHIFENBIAO21 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_zhilist21;
	CString m_zhiname21;
	CString m_zhimianji21;
	CString m_zhizhanbi21;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
