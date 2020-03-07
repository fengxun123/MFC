#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgTufenbiao12 �Ի���

class CDlgTufenbiao12 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTufenbiao12)

public:
	CDlgTufenbiao12(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgTufenbiao12();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUFENBIAO12 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CString m_name12;
	CString m_mianji12;
	CString m_zhanbi12;
	CListCtrl m_list12;
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
	virtual BOOL OnInitDialog();
};
