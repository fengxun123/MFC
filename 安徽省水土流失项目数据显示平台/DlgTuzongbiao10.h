#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgTuzongbiao10 �Ի���

class CDlgTuzongbiao10 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTuzongbiao10)

public:
	CDlgTuzongbiao10(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgTuzongbiao10();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUZONGBIAO10 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CString m_mianji10;
	CString m_name;
	CString m_zhanbi10;
public:
	
	CListCtrl m_list10;
	virtual BOOL OnInitDialog();
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
};
