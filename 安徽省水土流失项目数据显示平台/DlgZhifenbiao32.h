#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgZhifenbiao32 �Ի���

class CDlgZhifenbiao32 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhifenbiao32)

public:
	CDlgZhifenbiao32(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgZhifenbiao32();
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
	enum { IDD = IDD_ZHIFENBIAO32 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_zhilist32;
	CString m_zhiname32;
	CString m_zhimianji32;
	CString m_zhizhanbi32;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
