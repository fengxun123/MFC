#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgZhifenbiao13 �Ի���

class CDlgZhifenbiao13 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhifenbiao13)

public:
	CDlgZhifenbiao13(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgZhifenbiao13();

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
	enum { IDD = IDD_ZHIFENBIAO13 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
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
