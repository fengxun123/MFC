#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgZhizongbiao40 �Ի���

class CDlgZhizongbiao40 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhizongbiao40)

public:
	CDlgZhizongbiao40(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgZhizongbiao40();
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
	enum { IDD = IDD_ZHIZONGBIAO40 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_zhilist40;
	CString m_zhiname40;
	CString m_zhimianji40;
	CString m_zhizhanbi40;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
