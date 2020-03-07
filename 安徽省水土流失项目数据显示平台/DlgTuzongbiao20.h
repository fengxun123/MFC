#pragma once
#include <vector>
#include "afxcmn.h"

// CDlgTuzongbiao20 �Ի���

class CDlgTuzongbiao20 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTuzongbiao20)

public:
	CDlgTuzongbiao20(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgTuzongbiao20();


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
	enum { IDD = IDD_TUZONGBIAO20 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CString m_name20;
	CString m_mianji20;
	CString m_zhanbi20;
//	CTabSheet m_list20;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
private:
	CListCtrl m_list20;
};
