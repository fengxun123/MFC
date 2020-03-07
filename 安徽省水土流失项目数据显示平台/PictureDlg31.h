#pragma once
#include "afxwin.h"



// CPictureDlg31 窗体视图

class CPictureDlg31 : public CFormView
{
	DECLARE_DYNCREATE(CPictureDlg31)

protected:
	CPictureDlg31();           // 动态创建所使用的受保护的构造函数
	virtual ~CPictureDlg31();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_PICTURE31 };
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
	CStatic m_pic31;
	CStatic m_pic32;
	CString m_text31;
	CString m_text32;
public:
	virtual void OnInitialUpdate();
};


