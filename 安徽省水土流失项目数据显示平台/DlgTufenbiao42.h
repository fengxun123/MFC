#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgTufenbiao42 �Ի���

class CDlgTufenbiao42 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTufenbiao42)

public:
	CDlgTufenbiao42(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgTufenbiao42();
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
	enum { IDD = IDD_TUFENBIAO42 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
private:
	CListCtrl m_list42;
	CString m_name42;
//	CString m_mianji41;
	CString m_zhanbi42;

	CString m_mianji42;
};
