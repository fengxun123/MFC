#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgTufenbiao41 �Ի���

class CDlgTufenbiao41 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTufenbiao41)

public:
	CDlgTufenbiao41(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgTufenbiao41();
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
	enum { IDD = IDD_TUFENBIAO41 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
private:
	CListCtrl m_list41;

public:
//	CEdit m_name41;
private:
	CString m_mianji41;
	CString m_zhanbi41;
	CString m_name41;
public:
	virtual BOOL OnInitDialog();
};
