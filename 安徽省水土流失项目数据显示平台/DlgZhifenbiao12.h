#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgZhifenbiao12 �Ի���

class CDlgZhifenbiao12 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhifenbiao12)

public:
	CDlgZhifenbiao12(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgZhifenbiao12();

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
	enum { IDD = IDD_ZHIFENBIAO12 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
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
