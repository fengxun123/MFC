#pragma once
#include "afxcmn.h"
#include <vector>

// CDlgShuizongbiao40 �Ի���

class CDlgShuizongbiao40 : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgShuizongbiao40)

public:
	CDlgShuizongbiao40(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgShuizongbiao40();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUIZONGBIAO40 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	std::vector<std::string> m_data[100];  //������ݿ��¼�����Ϊ100��
	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_shuilist40;
public:
	virtual BOOL OnInitDialog();
};
