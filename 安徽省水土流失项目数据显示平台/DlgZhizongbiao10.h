#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgZhizongbiao10 �Ի���

class CDlgZhizongbiao10 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhizongbiao10)

public:
	CDlgZhizongbiao10(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgZhizongbiao10();

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
	enum { IDD = IDD_ZHIZONGBIAO10 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_zhilist10;
public:
	virtual BOOL OnInitDialog();
private:
	CString m_zhiname10;
	CString m_zhimianji10;
	CString m_zhizhanbi10;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
