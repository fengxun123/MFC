#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuifenbiao31 �Ի���

class CDlgShuifenbiao31 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuifenbiao31)

public:
	CDlgShuifenbiao31(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgShuifenbiao31();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIFENBIAO31 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist31;
public:
	virtual BOOL OnInitDialog();
};
