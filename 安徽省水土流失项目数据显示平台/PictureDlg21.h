#pragma once
#include "afxwin.h"



// CPictureDlg21 窗体视图

class CPictureDlg21 : public CFormView
{
	DECLARE_DYNCREATE(CPictureDlg21)

protected:
	CPictureDlg21();           // 动态创建所使用的受保护的构造函数
	virtual ~CPictureDlg21();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_PICTURE21 };
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
	CStatic m_pic21;
	CStatic m_pic22;
	CString m_text21;
	CString m_text22;
public:
	virtual void OnInitialUpdate();
};


