#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgTufenbiao32 �Ի���

class CDlgTufenbiao32 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTufenbiao32)

public:
	CDlgTufenbiao32(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgTufenbiao32();
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
	enum { IDD = IDD_TUFENBIAO32 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
private:
	CString m_name32;
	CString m_mianji32;
	CString m_zhanbi32;
public:
	virtual BOOL OnInitDialog();
private:
	CListCtrl m_list32;
};
