#pragma once
#include "TabSheet.h"
#include "DlgShuijieyitu4.h"
#include "DlgShuizongbiao40.h"
#include "DlgShuifenbiao41.h"
#include "DlgShuifenbiao42.h"
#include "DlgShuifenbiao43.h"



// CDlgShuituliushi4 窗体视图

class CDlgShuituliushi4 : public CFormView
{
	DECLARE_DYNCREATE(CDlgShuituliushi4)

protected:
	CDlgShuituliushi4();           // 动态创建所使用的受保护的构造函数
	virtual ~CDlgShuituliushi4();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUITULIUSHI4 };
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
	CTabSheet m_shuitab4;
	CDlgShuijieyitu4 shuijieyitu4;
	CDlgShuizongbiao40 shuizongbiao40;
	CDlgShuifenbiao41 shuifenbiao41;
	CDlgShuifenbiao42 shuifenbiao42;
	CDlgShuifenbiao43 shuifenbiao43;
public:
	virtual void OnInitialUpdate();
};


