#pragma once
#include "afxwin.h"


// CDlgZhijieyitu2 �Ի���

class CDlgZhijieyitu2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgZhijieyitu2)

public:
	CDlgZhijieyitu2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgZhijieyitu2();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZHIJIEYITU2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_zhipic2;
public:
	virtual BOOL OnInitDialog();
};
