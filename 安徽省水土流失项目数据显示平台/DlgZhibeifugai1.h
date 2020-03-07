#pragma once
#include "TabSheet.h"
#include "DlgZhijieyitu1.h"
#include "DlgZhizongbiao10.h"
#include "DlgZhifenbiao11.h"
#include "DlgZhifenbiao12.h"
#include "DlgZhifenbiao13.h"


// CDlgZhibeifugai1 ������ͼ

class CDlgZhibeifugai1 : public CFormView
{
	DECLARE_DYNCREATE(CDlgZhibeifugai1)

protected:
	CDlgZhibeifugai1();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CDlgZhibeifugai1();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZHIBEIFUGAI1 };
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
	CTabSheet m_zhitab1;
	CDlgZhijieyitu1 zhijieyitu1;
	CDlgZhizongbiao10 zhizongbiao10;
	CDlgZhifenbiao11 zhifenbiao11;
	CDlgZhifenbiao12 zhifenbiao12;
	CDlgZhifenbiao13 zhifenbiao13;

public:
	virtual void OnInitialUpdate();
};


