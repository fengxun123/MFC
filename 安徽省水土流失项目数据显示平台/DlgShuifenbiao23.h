#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuifenbiao23 �Ի���

class CDlgShuifenbiao23 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuifenbiao23)

public:
	CDlgShuifenbiao23(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgShuifenbiao23();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIFENBIAO23 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist23;
public:
	virtual BOOL OnInitDialog();
};
