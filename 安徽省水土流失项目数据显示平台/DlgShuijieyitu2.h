#pragma once
#include "afxwin.h"


// CDlgShuijieyitu2 �Ի���

class CDlgShuijieyitu2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuijieyitu2)

public:
	CDlgShuijieyitu2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgShuijieyitu2();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIJIEYITU2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_shuipic2;
public:
	virtual BOOL OnInitDialog();
};
