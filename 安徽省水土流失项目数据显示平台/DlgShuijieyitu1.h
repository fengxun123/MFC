#pragma once
#include "afxwin.h"


// CDlgShuijieyitu1 �Ի���

class CDlgShuijieyitu1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuijieyitu1)

public:
	CDlgShuijieyitu1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgShuijieyitu1();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIJIEYITU1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_shuipic1;
public:
	virtual BOOL OnInitDialog();
};
