#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuizongbiao30 �Ի���

class CDlgShuizongbiao30 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuizongbiao30)

public:
	CDlgShuizongbiao30(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgShuizongbiao30();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIZONGBIAO30 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist30;
public:
	virtual BOOL OnInitDialog();
};
