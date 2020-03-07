#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include <vector>

// CDlgTufenbiao23 �Ի���

class CDlgTufenbiao23 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTufenbiao23)

public:
	CDlgTufenbiao23(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgTufenbiao23();
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
	enum { IDD = IDD_TUFENBIAO23 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
//	CEdit m_name23;
	CString m_mianji23;
	CString m_zhanbi23;
	CListCtrl m_list23;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
private:
	CString m_name23;
};
