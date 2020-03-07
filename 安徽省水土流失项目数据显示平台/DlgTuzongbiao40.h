#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgTuzongbiao40 �Ի���

class CDlgTuzongbiao40 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTuzongbiao40)

public:
	CDlgTuzongbiao40(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgTuzongbiao40();
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
	enum { IDD = IDD_TUZONGBIAO40 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_list40;
	CString m_name40;
	CString m_mianji40;
	CString m_zhanbi40;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
};
