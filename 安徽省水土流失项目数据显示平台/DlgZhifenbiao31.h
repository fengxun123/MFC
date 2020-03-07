#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgZhifenbiao31 �Ի���

class CDlgZhifenbiao31 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhifenbiao31)

public:
	CDlgZhifenbiao31(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgZhifenbiao31();
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
	enum { IDD = IDD_ZHIFENBIAO31 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_zhilist31;
	CString m_zhiname31;
	CString m_zhimianji31;
	CString m_zhizhanbi31;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
