#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgZhizongbiao30 �Ի���

class CDlgZhizongbiao30 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhizongbiao30)

public:
	CDlgZhizongbiao30(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgZhizongbiao30();
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
	enum { IDD = IDD_ZHIZONGBIAO30 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_zhilist30;
	CString m_zhiname30;
	CString m_zhimianji30;
	CString m_zhizhanbi30;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
