#pragma once
#include "afxwin.h"


// CDlgShuijieyitu3 �Ի���

class CDlgShuijieyitu3 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuijieyitu3)

public:
	CDlgShuijieyitu3(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgShuijieyitu3();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIJIEYITU3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_shuipic3;
public:
	virtual BOOL OnInitDialog();
};
