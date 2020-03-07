#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgTufenbiao31 �Ի���

class CDlgTufenbiao31 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTufenbiao31)

public:
	CDlgTufenbiao31(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgTufenbiao31();
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
	enum { IDD = IDD_TUFENBIAO31 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list31;
	CString m_name31;
	CString m_mianji31;
	CString m_zhanbi31;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
};
