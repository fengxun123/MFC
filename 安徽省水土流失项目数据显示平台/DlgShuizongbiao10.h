#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuizongbiao10 �Ի���

class CDlgShuizongbiao10 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuizongbiao10)

public:
	CDlgShuizongbiao10(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgShuizongbiao10();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIZONGBIAO10 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist10;
public:
	virtual BOOL OnInitDialog();
};
