#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgZhifenbiao42 �Ի���

class CDlgZhifenbiao42 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhifenbiao42)

public:
	CDlgZhifenbiao42(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgZhifenbiao42();
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
	enum { IDD = IDD_ZHIFENBIAO42 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_zhilist42;
	CString m_zhiname42;
	CString m_zhimianji42;
	CString m_zhizhanbi42;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
};
