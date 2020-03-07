#pragma once
#include "TabSheet.h"
#include "DlgShuijieyitu2.h"
#include "DlgShuiZongbiao20.h"
#include "DlgShuifenbiao21.h"
#include "DlgShuifenbiao22.h"
#include "DlgShuifenbiao23.h"



// CDlgShuituliushi2 ������ͼ

class CDlgShuituliushi2 : public CFormView
{
	DECLARE_DYNCREATE(CDlgShuituliushi2)

protected:
	CDlgShuituliushi2();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CDlgShuituliushi2();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHUITULIUSHI2 };
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
	CTabSheet m_shuitab2;
	CDlgShuijieyitu2 shuijieyitu2;
	CDlgShuiZongbiao20 shuizongbiao20;
	CDlgShuifenbiao21 shuifenbiao21;
	CDlgShuifenbiao22 shuifenbiao22;
	CDlgShuifenbiao23 shuifenbiao23;
public:
	virtual void OnInitialUpdate();
};


