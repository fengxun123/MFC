#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgTufenbiao13 �Ի���

class CDlgTufenbiao13 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTufenbiao13)

public:
	CDlgTufenbiao13(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgTufenbiao13();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUFENBIAO13 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CString m_name13;
	CString m_mianji13;
	CString m_zhanbi13;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	BOOL ConnectDB();		//����MYSQL���ݿ�
	BOOL InsertDB();		//��������
	BOOL DeleteDB();        //ɾ������
	BOOL SelectDB();		//��ѯ����
	void GetDataFromDB();   //�����ݿ��ȡ����
	void ShowInfo();        //��ʾ����
	void ClearData();       //�������
	afx_msg void OnDestroy();
private:
	CListCtrl m_list13;
public:
	virtual BOOL OnInitDialog();
};
