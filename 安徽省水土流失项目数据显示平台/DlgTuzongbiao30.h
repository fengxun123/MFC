#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgTuzongbiao30 �Ի���

class CDlgTuzongbiao30 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTuzongbiao30)

public:
	CDlgTuzongbiao30(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgTuzongbiao30();

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
	enum { IDD = IDD_TUZONGBIAO30 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
private:
	CString m_name30;
	CString m_mianji30;
	CString m_zhanbi30;
	CListCtrl m_list30;
public:
	virtual BOOL OnInitDialog();
};
