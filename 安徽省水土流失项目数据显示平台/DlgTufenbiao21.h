#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgTufenbiao21 �Ի���

class CDlgTufenbiao21 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTufenbiao21)

public:
	CDlgTufenbiao21(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgTufenbiao21();

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
	enum { IDD = IDD_TUFENBIAO21 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
private:
	CString m_name21;
	CString m_mianji21;
	CString m_zhanbi21;
	CListCtrl m_list21;
};
