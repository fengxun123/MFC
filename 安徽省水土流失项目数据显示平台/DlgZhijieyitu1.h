#pragma once
#include "afxwin.h"


// CDlgZhijieyitu1 �Ի���

class CDlgZhijieyitu1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhijieyitu1)

public:
	CDlgZhijieyitu1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgZhijieyitu1();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZHIJIEYITU1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_zhipic1;
public:
	virtual BOOL OnInitDialog();
};
