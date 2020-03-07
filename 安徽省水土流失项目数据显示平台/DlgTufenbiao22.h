#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgTufenbiao22 �Ի���

class CDlgTufenbiao22 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTufenbiao22)

public:
	CDlgTufenbiao22(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgTufenbiao22();

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
	enum { IDD = IDD_TUFENBIAO22 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CString m_name22;
	CString m_mianji22;
	CString m_zhanbi22;
	CListCtrl m_list22;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
};
