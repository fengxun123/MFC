// UserDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
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


// CUserDlg ���

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


// CUserDlg ��Ϣ�������


void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���

	//��ʼ��
	m_user = TEXT("����Ա");
	CLogin log;
	CString name,pwd;
	log.ReadLogin(name, pwd);
	m_name = name;
	UpdateData(FALSE);//����ͬ�����ؼ���

}


void CUserDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);//�õ����µ�����-������
	if (m_newpwd.IsEmpty() || m_surepwd.IsEmpty())
	{
		MessageBox(TEXT("�������ݲ���Ϊ��"));
		return;
	}
	//�������ȷ���������һ��
	if (m_newpwd != m_surepwd)
	{
		MessageBox(_T("�������ȷ���������һ��"));
		return;
	}

	//�¾��������һ�´���
	CLogin log;
	CString name, pwd;
	log.ReadLogin(name, pwd);
	if (pwd == m_newpwd)
	{
		MessageBox(_T("�¾�����һ�´���"));
		return;
	}
	
	//CString ת��Ϊchar*  
	CStringA tmp, tmp1;
	tmp = name;
	tmp1 = m_newpwd;
	log.WritePwd(tmp.GetBuffer(), tmp1.GetBuffer());
	MessageBox(TEXT("�����޸ĳɹ�������"));


	//�����������
	m_newpwd.Empty();
	m_surepwd.Empty();
	UpdateData(FALSE);//����ͬ�����ؼ���
}


void CUserDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�����������
	m_newpwd.Empty();
	m_surepwd.Empty();
	UpdateData(FALSE);//����ͬ�����ؼ���
}
