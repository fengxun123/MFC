#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuifenbiao11 �Ի���

class CDlgShuifenbiao11 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuifenbiao11)

public:
	CDlgShuifenbiao11(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgShuifenbiao11();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIFENBIAO11 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist11;
public:
	virtual BOOL OnInitDialog();
};
