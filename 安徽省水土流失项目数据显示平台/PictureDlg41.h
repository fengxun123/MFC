#pragma once
#include "afxwin.h"



// CPictureDlg41 窗体视图

class CPictureDlg41 : public CFormView
{
	DECLARE_DYNCREATE(CPictureDlg41)

protected:
	CPictureDlg41();           // 动态创建所使用的受保护的构造函数
	virtual ~CPictureDlg41();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_PICTURE41 };
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
	CStatic m_pic41;
	CStatic m_pic42;
	CString m_text41;
	CString m_text42;
public:
	virtual void OnInitialUpdate();
};


