#pragma once
#include "afxwin.h"



// CPictureDlg31 ������ͼ

class CPictureDlg31 : public CFormView
{
	DECLARE_DYNCREATE(CPictureDlg31)

protected:
	CPictureDlg31();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CStatic m_pic31;
	CStatic m_pic32;
	CString m_text31;
	CString m_text32;
public:
	virtual void OnInitialUpdate();
};


