#pragma once
#include "afxwin.h"


// CDlgShuijieyitu4 �Ի���

class CDlgShuijieyitu4 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuijieyitu4)

public:
	CDlgShuijieyitu4(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgShuijieyitu4();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIJIEYITU4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_shuipic4;
public:
	virtual BOOL OnInitDialog();
};
