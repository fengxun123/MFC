#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgTufenbiao43 �Ի���

class CDlgTufenbiao43 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTufenbiao43)

public:
	CDlgTufenbiao43(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgTufenbiao43();
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
	enum { IDD = IDD_TUFENBIAO43 };
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
	CString m_name43;
	CString m_mianji43;
	CString m_zhanbi43;
	CListCtrl m_list43;
};
