#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuifenbiao43 �Ի���

class CDlgShuifenbiao43 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuifenbiao43)

public:
	CDlgShuifenbiao43(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgShuifenbiao43();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIFENBIAO43 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist43;
public:
	virtual BOOL OnInitDialog();
};
