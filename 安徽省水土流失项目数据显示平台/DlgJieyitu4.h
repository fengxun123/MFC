#pragma once
#include "afxwin.h"


// CDlgJieyitu4 �Ի���

class CDlgJieyitu4 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgJieyitu4)

public:
	CDlgJieyitu4(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgJieyitu4();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUJIEYITU4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_tupic3;
public:
	virtual BOOL OnInitDialog();
};
