#pragma once
#include "afxwin.h"


// CDlgZhijieyitu4 �Ի���

class CDlgZhijieyitu4 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhijieyitu4)

public:
	CDlgZhijieyitu4(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgZhijieyitu4();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZHIJIEYITU4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_zhipic4;
public:
	virtual BOOL OnInitDialog();
};
