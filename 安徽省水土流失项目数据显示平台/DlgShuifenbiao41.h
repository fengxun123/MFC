#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuifenbiao41 �Ի���

class CDlgShuifenbiao41 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuifenbiao41)

public:
	CDlgShuifenbiao41(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgShuifenbiao41();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIFENBIAO41 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist41;
public:
	virtual BOOL OnInitDialog();
};
