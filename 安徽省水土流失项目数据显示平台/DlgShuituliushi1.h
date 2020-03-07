#pragma once
#include "TabSheet.h"
#include "DlgShuijieyitu1.h"
#include "DlgShuizongbiao10.h"
#include "DlgShuifenbiao11.h"
#include "DlgShuifenbiao12.h"
#include "DlgShuifenbiao13.h"



// CDlgShuituliushi1 ������ͼ

class CDlgShuituliushi1 : public CFormView
{
	DECLARE_DYNCREATE(CDlgShuituliushi1)

protected:
	CDlgShuituliushi1();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CDlgShuituliushi1();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUITULIUSHI1 };
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
	CTabSheet m_shuitab1;
	CDlgShuijieyitu1 shuijieyitu1;
	CDlgShuizongbiao10 shuizongbiao10;
	CDlgShuifenbiao11 shuifenbiao11;
	CDlgShuifenbiao12 shuifenbiao12;
	CDlgShuifenbiao13 shuifenbiao13;
public:
	virtual void OnInitialUpdate();
};


