#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgZhifenbiao23 �Ի���

class CDlgZhifenbiao23 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhifenbiao23)

public:
	CDlgZhifenbiao23(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgZhifenbiao23();
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
	enum { IDD = IDD_ZHIFENBIAO23 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_zhilist23;
	CString m_zhiname23;
	CString m_zhimianji23;
	CString m_zhizhanbi23;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
