#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgZhizongbiao20 �Ի���

class CDlgZhizongbiao20 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhizongbiao20)

public:
	CDlgZhizongbiao20(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgZhizongbiao20();
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
	enum { IDD = IDD_ZHIZONGBIAO20 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_zhilist20;
	CString m_zhiname20;
	CString m_zhimianji20;
	CString m_zhizhanbi20;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
