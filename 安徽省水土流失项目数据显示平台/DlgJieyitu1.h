#pragma once
#include "afxwin.h"


// CDlgJieyitu1 �Ի���

class CDlgJieyitu1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgJieyitu1)

public:
	CDlgJieyitu1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgJieyitu1();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUJIEYITU1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_tupic;
public:
	virtual BOOL OnInitDialog();
};
