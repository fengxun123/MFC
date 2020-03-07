// UserDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "UserDlg.h"
#include "Login.h"

// CUserDlg

IMPLEMENT_DYNCREATE(CUserDlg, CFormView)

CUserDlg::CUserDlg()
	: CFormView(DIALOG_USER)
	, m_user(_T(""))
	, m_name(_T(""))
	, m_newpwd(_T(""))
	, m_surepwd(_T(""))
{

}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_newpwd);
	DDX_Text(pDX, IDC_EDIT4, m_surepwd);
}

BEGIN_MESSAGE_MAP(CUserDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON3, &CUserDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CUserDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CUserDlg 诊断

#ifdef _DEBUG
void CUserDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserDlg 消息处理程序


void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	//初始化
	m_user = TEXT("管理员");
	CLogin log;
	CString name,pwd;
	log.ReadLogin(name, pwd);
	m_name = name;
	UpdateData(FALSE);//变量同步到控件中

}


void CUserDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);//拿到最新的数据-新密码
	if (m_newpwd.IsEmpty() || m_surepwd.IsEmpty())
	{
		MessageBox(TEXT("输入内容不能为空"));
		return;
	}
	//新密码和确定密码必须一致
	if (m_newpwd != m_surepwd)
	{
		MessageBox(_T("新密码和确定密码必须一致"));
		return;
	}

	//新旧密码必须一致错误！
	CLogin log;
	CString name, pwd;
	log.ReadLogin(name, pwd);
	if (pwd == m_newpwd)
	{
		MessageBox(_T("新旧密码一致错误！"));
		return;
	}
	
	//CString 转换为char*  
	CStringA tmp, tmp1;
	tmp = name;
	tmp1 = m_newpwd;
	log.WritePwd(tmp.GetBuffer(), tmp1.GetBuffer());
	MessageBox(TEXT("密码修改成功！！！"));


	//清空密码内容
	m_newpwd.Empty();
	m_surepwd.Empty();
	UpdateData(FALSE);//变量同步到控件中
}


void CUserDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	//清空密码内容
	m_newpwd.Empty();
	m_surepwd.Empty();
	UpdateData(FALSE);//变量同步到控件中
}
