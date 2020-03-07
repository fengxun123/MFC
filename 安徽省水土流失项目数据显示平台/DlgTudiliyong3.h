#pragma once
#include "TabSheet.h"
#include "DlgJieyitu4.h"
#include "DlgTuzongbiao40.h"
#include "DlgTufenbiao41.h"
#include "DlgTufenbiao42.h"
#include "DlgTufenbiao43.h"

// CDlgTudiliyong3 窗体视图

class CDlgTudiliyong3 : public CFormView
{
	DECLARE_DYNCREATE(CDlgTudiliyong3)

protected:
	CDlgTudiliyong3();           // 动态创建所使用的受保护的构造函数
	virtual ~CDlgTudiliyong3();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUDILIYONG3 };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	CTabSheet m_tutab3;
	CDlgJieyitu4 jieyitu4;
	CDlgTuzongbiao40 tuzongbiao40;
	CDlgTufenbiao41 tufenbiao41;
	CDlgTufenbiao42 tufenbiao42;
	CDlgTufenbiao43 tufenbiao43;
	virtual void OnInitialUpdate();
};


