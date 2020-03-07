#pragma once
#include "TabSheet.h"
#include "DlgJieyitu1.h"
#include "DlgTuzongbiao10.h"
#include "DlgTufenbiao11.h"
#include "DlgTufenbiao12.h"
#include "DlgTufenbiao13.h"

// CDlgTudiliyong ������ͼ

class CDlgTudiliyong : public CFormView
{
	DECLARE_DYNCREATE(CDlgTudiliyong)

protected:
	CDlgTudiliyong();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CDlgTudiliyong();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUDILIYONG };
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
	CTabSheet m_tutab;
	CDlgJieyitu1 jieyitu1;
	CDlgTuzongbiao10 tuzongbiao10;
	CDlgTufenbiao11 tufenbiao11;
	CDlgTufenbiao12 tufenbiao12;
	CDlgTufenbiao13 tufenbiao13;

public:
	virtual void OnInitialUpdate();
};


