#pragma once
#include "afxcmn.h"
#include <vector>


// CDlgTufenbiao11 �Ի���

class CDlgTufenbiao11 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTufenbiao11)

public:
	CDlgTufenbiao11(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgTufenbiao11();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUFENBIAO11 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CString m_name11;
	CString m_mianji11;
	CString m_zhanbi11;
	CListCtrl m_list11;
public:
	virtual BOOL OnInitDialog();
	BOOL ConnectDB();		//����MYSQL���ݿ�
	BOOL InsertDB();		//��������
	BOOL DeleteDB();        //ɾ������
	BOOL SelectDB();		//��ѯ����
	void GetDataFromDB();   //�����ݿ��ȡ����
	void ShowInfo();        //��ʾ����
	void ClearData();       //�������
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
