#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgZhifenbiao41 �Ի���

class CDlgZhifenbiao41 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhifenbiao41)

public:
	CDlgZhifenbiao41(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgZhifenbiao41();
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
	enum { IDD = IDD_ZHIFENBIAO41 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_zhilist41;
	CString m_zhiname41;
	CString m_zhimianji41;
	CString m_zhizhanbi41;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
