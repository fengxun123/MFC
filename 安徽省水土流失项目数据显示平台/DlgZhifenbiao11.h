#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgZhifenbiao11 �Ի���

class CDlgZhifenbiao11 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhifenbiao11)

public:
	CDlgZhifenbiao11(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgZhifenbiao11();
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
	enum { IDD = IDD_ZHIFENBIAO11 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
private:
	CListCtrl m_zhilist11;
	CString m_zhiname11;
	CString m_zhimianji11;
	CString m_zhizhanbi11;
public:
	virtual BOOL OnInitDialog();
};
