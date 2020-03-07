#pragma once
#include "afxwin.h"



// CPictureDlg11 窗体视图

class CPictureDlg11 : public CFormView
{
	DECLARE_DYNCREATE(CPictureDlg11)

protected:
	CPictureDlg11();           // 动态创建所使用的受保护的构造函数
	virtual ~CPictureDlg11();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_PICTURE11 };
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
	CStatic m_pic11;
	CStatic m_pic12;
public:
	virtual void OnInitialUpdate();
private:
	CString m_text11;
	CString m_text12;

};


