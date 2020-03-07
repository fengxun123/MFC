#pragma once
#include "TabSheet.h"
#include "DlgZhijieyitu3.h"
#include "DlgZhizongbiao30.h"
#include "DlgZhifenbiao31.h"
#include "DlgZhifenbiao32.h"



// CDlgZhibeifugai3 ������ͼ

class CDlgZhibeifugai3 : public CFormView
{
	DECLARE_DYNCREATE(CDlgZhibeifugai3)

protected:
	CDlgZhibeifugai3();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CDlgZhibeifugai3();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZHIBEIFUGAI3 };
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
	CTabSheet m_zhitab3;
	CDlgZhijieyitu3 zhijieyitu3;
	CDlgZhizongbiao30 zhizongbiao30;
	CDlgZhifenbiao31 zhifenbiao31;
	CDlgZhifenbiao32 zhifenbiao32;
	

public:
	virtual void OnInitialUpdate();
};


