#pragma once
#include "afxwin.h"


// CDlgZhijieyitu3 �Ի���

class CDlgZhijieyitu3 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhijieyitu3)

public:
	CDlgZhijieyitu3(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgZhijieyitu3();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZHIJIEYITU3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_zhipic3;
public:
	virtual BOOL OnInitDialog();
};
