#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuifenbiao22 �Ի���

class CDlgShuifenbiao22 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuifenbiao22)

public:
	CDlgShuifenbiao22(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgShuifenbiao22();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIFENBIAO22 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist22;
public:
	virtual BOOL OnInitDialog();
};
