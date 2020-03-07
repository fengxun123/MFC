#pragma once
#include "TabSheet.h"
#include "DlgShuijieyitu3.h"
#include "DlgShuizongbiao30.h"
#include "DlgShuifenbiao31.h"
#include "DlgShuifenbiao32.h"




// CDlgShuituliushi3 窗体视图

class CDlgShuituliushi3 : public CFormView
{
	DECLARE_DYNCREATE(CDlgShuituliushi3)

protected:
	CDlgShuituliushi3();           // 动态创建所使用的受保护的构造函数
	virtual ~CDlgShuituliushi3();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUITULIUSHI3 };
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
private:
	CTabSheet m_shuitab3;
	CDlgShuijieyitu3 shuijieyitu3;
	CDlgShuizongbiao30 shuizongbiao30;
	CDlgShuifenbiao31 shuifenbiao31;
	CDlgShuifenbiao32 shuifenbiao32;
public:
	virtual void OnInitialUpdate();
};


