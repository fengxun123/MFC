#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuifenbiao21 �Ի���

class CDlgShuifenbiao21 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuifenbiao21)

public:
	CDlgShuifenbiao21(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgShuifenbiao21();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIFENBIAO21 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist21;
public:
	virtual BOOL OnInitDialog();
};
