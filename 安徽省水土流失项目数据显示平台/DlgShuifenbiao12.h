#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuifenbiao12 �Ի���

class CDlgShuifenbiao12 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuifenbiao12)

public:
	CDlgShuifenbiao12(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgShuifenbiao12();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIFENBIAO12 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist12;
public:
	virtual BOOL OnInitDialog();
};
