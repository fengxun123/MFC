// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "Login.h"


// CLoginDlg �Ի���

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


// CLoginDlg ��Ϣ�������


void CLoginDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);//�ؼ�ͬ����������

	if (m_user.IsEmpty() | m_pwd.IsEmpty())
	{
		MessageBox(_T("�������ݲ���Ϊ�գ�"));
		return;
	}

	//��ȡ����ȷ��ֵ
	CLogin log;
	CString name, pwd;
	log.ReadLogin(name, pwd);

	if (name == m_user)//�û���һ��
	{
		if (pwd == m_pwd) //����һ��
		{
			//�رյ�ǰ�Ի���
			CDialog::OnCancel();
		}
		else 
		{
			MessageBox(_T("��������"));
		}
	}
	else {
		MessageBox(TEXT("�û�������"));
		}
}


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//��д�����ӶԻ����ʼ��
	//Ĭ�ϵ�½��Ϣ
	CLogin log;
	CString name, pwd;
	log.ReadLogin(name, pwd);//��ȡ

	m_user = name;
	m_pwd = pwd;
	UpdateData(FALSE);//�����е�ֵͬ�����ؼ���

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CLoginDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}


void CLoginDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	//û�����κ����ݣ����س�����ϵͳ��BUG����һ�����ע�͵�
	//CDialogEx::OnOK();
}


void CLoginDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//�رյ�ǰ�Ի���ע�͵�
	//CDialogEx::OnClose();
	
	//�˳�����
	exit(0);
}
