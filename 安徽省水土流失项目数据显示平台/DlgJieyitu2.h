#pragma once
#include "afxwin.h"


// CDlgJieyitu2 �Ի���

class CDlgJieyitu2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgJieyitu2)

public:
	CDlgJieyitu2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgJieyitu2();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUJIEYITU2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_tupic1;
public:
	virtual BOOL OnInitDialog();
};
