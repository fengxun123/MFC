#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuifenbiao42 �Ի���

class CDlgShuifenbiao42 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuifenbiao42)

public:
	CDlgShuifenbiao42(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgShuifenbiao42();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIFENBIAO42 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist42;
public:
	virtual BOOL OnInitDialog();
};
