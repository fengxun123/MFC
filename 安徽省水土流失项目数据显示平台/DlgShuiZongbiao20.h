#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuiZongbiao20 �Ի���

class CDlgShuiZongbiao20 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuiZongbiao20)

public:
	CDlgShuiZongbiao20(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgShuiZongbiao20();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIZONGBIAO20 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist20;
public:
	virtual BOOL OnInitDialog();
};
