#pragma once
#include "afxwin.h"


// CDLgJieyitu3 �Ի���

class CDLgJieyitu3 : public CDialogEx
{
	DECLARE_DYNAMIC(CDLgJieyitu3)

public:
	CDLgJieyitu3(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDLgJieyitu3();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUJIEYITU3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_tupic2;
public:
	virtual BOOL OnInitDialog();
};
