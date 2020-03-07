// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "Login.h"


// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(DIALOG_LOGIN, pParent)
	, m_user(_T(""))
	, m_pwd(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_pwd);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLoginDlg::OnBnClickedButton2)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


void CLoginDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);//控件同步到变量中

	if (m_user.IsEmpty() | m_pwd.IsEmpty())
	{
		MessageBox(_T("输入内容不能为空！"));
		return;
	}

	//获取到正确的值
	CLogin log;
	CString name, pwd;
	log.ReadLogin(name, pwd);

	if (name == m_user)//用户名一致
	{
		if (pwd == m_pwd) //密码一致
		{
			//关闭当前对话框
			CDialog::OnCancel();
		}
		else 
		{
			MessageBox(_T("密码有误！"));
		}
	}
	else {
		MessageBox(TEXT("用户名有误！"));
		}
}


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//重写以增加对话框初始化
	//默认登陆信息
	CLogin log;
	CString name, pwd;
	log.ReadLogin(name, pwd);//读取

	m_user = name;
	m_pwd = pwd;
	UpdateData(FALSE);//变量中的值同步到控件中

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CLoginDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


void CLoginDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
	//没输入任何内容，按回车进入系统的BUG，将一下语句注释掉
	//CDialogEx::OnOK();
}


void CLoginDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//关闭当前对话框，注释掉
	//CDialogEx::OnClose();
	
	//退出程序
	exit(0);
}
