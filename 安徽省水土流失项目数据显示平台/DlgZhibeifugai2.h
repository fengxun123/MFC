#pragma once
#include "TabSheet.h"
#include "DlgZhijieyitu2.h"
#include "DlgZhizongbiao20.h"
#include "DlgZhifenbiao21.h"
#include "DlgZhifenbiao22.h"
#include "DlgZhifenbiao23.h"


// CDlgZhibeifugai2 ������ͼ

class CDlgZhibeifugai2 : public CFormView
{
	DECLARE_DYNCREATE(CDlgZhibeifugai2)

protected:
	CDlgZhibeifugai2();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CDlgZhibeifugai2();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZHIBEIFUGAI2 };
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
	CTabSheet m_zhitab2;
	CDlgZhijieyitu2 zhijieyitu2;
	CDlgZhizongbiao20 zhizongbiao20;
	CDlgZhifenbiao21 zhifenbiao21;
	CDlgZhifenbiao22 zhifenbiao22;
	CDlgZhifenbiao23 zhifenbiao23;
public:
	virtual void OnInitialUpdate();
};


