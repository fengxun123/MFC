#pragma once
#include "TabSheet.h"
#include "DlgZhijieyitu4.h"
#include "DlgZhizongbiao40.h"
#include "DlgZhifenbiao41.h"
#include "DlgZhifenbiao42.h"
#include "DlgZhifenbiao43.h"


// CDlgZhibeifugai4 ������ͼ

class CDlgZhibeifugai4 : public CFormView
{
	DECLARE_DYNCREATE(CDlgZhibeifugai4)

protected:
	CDlgZhibeifugai4();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CDlgZhibeifugai4();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZHIBEIFUGAI4 };
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
	CTabSheet m_zhitab4;
	CDlgZhijieyitu4 zhijieyitu4;
	CDlgZhizongbiao40 zhizongbiao40;
	CDlgZhifenbiao41 zhifenbiao41;
	CDlgZhifenbiao42 zhifenbiao42;
	CDlgZhifenbiao43 zhifenbiao43;
public:
	virtual void OnInitialUpdate();
};


