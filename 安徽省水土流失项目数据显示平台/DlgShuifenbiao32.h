#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuifenbiao32 �Ի���

class CDlgShuifenbiao32 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuifenbiao32)

public:
	CDlgShuifenbiao32(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgShuifenbiao32();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIFENBIAO32 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist32;
public:
	virtual BOOL OnInitDialog();
};
