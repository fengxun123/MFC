#pragma once
#include "DLgJieyitu3.h"
#include "DlgTuzongbiao30.h"
#include "DlgTufenbiao31.h"
#include "DlgTufenbiao32.h"
#include "TabSheet.h"



// CDlgTudiliyong2 窗体视图

class CDlgTudiliyong2 : public CFormView
{
	DECLARE_DYNCREATE(CDlgTudiliyong2)

protected:
	CDlgTudiliyong2();           // 动态创建所使用的受保护的构造函数
	virtual ~CDlgTudiliyong2();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUDILIYONG2 };
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
	virtual void OnInitialUpdate();
private:
	CTabSheet m_tutab2;
	CDLgJieyitu3 jieyitu3;
	CDlgTuzongbiao30 tuzongbiao30;
	CDlgTufenbiao31 tufenbiao31;
	CDlgTufenbiao32 tufenbiao32;
	
};


