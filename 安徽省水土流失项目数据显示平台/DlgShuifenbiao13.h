#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuifenbiao13 �Ի���

class CDlgShuifenbiao13 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuifenbiao13)

public:
	CDlgShuifenbiao13(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgShuifenbiao13();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIFENBIAO13 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist13;
public:
	virtual BOOL OnInitDialog();
};
