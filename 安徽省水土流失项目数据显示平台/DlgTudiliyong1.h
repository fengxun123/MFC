#pragma once
#include "TabSheet.h"
#include "DlgJieyitu2.h"
#include "DlgTuzongbiao20.h"
#include "DlgTufenbiao21.h"
#include "DlgTufenbiao22.h"
#include "DlgTufenbiao23.h"



// CDlgTudiliyong1 ������ͼ

class CDlgTudiliyong1 : public CFormView
{
	DECLARE_DYNCREATE(CDlgTudiliyong1)

protected:
	CDlgTudiliyong1();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CDlgTudiliyong1();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUDILIYONG1 };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CTabSheet m_tutab1;
	CDlgJieyitu2 jieyitu2;
	CDlgTuzongbiao20 tuzongbiao20;
	CDlgTufenbiao21 tufenbiao21;
	CDlgTufenbiao22 tufenbiao22;
	CDlgTufenbiao23 tufenbiao23;

public:
	virtual void OnInitialUpdate();
};


