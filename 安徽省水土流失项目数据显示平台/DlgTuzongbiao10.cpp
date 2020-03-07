// DlgTuzongbiao10.cpp : ʵ���ļ�
//
#include "stdafx.h" 

#ifdef _MSC_VER
#ifdef _WIN64
#include <WinSock2.h>
#elif _WIN32
#include <winsock.h>
#endif
#endif

#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgTuzongbiao10.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"



MYSQL m_mysql;			//���ݿ�ṹ
MYSQL_RES* m_res;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_row;          //��ȡÿһ����¼
char query[150]; //��ѯ���
// CDlgTuzongbiao10 �Ի���

IMPLEMENT_DYNAMIC(CDlgTuzongbiao10, CDialogEx)

CDlgTuzongbiao10::CDlgTuzongbiao10(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUZONGBIAO10, pParent)
	, m_mianji10(_T(""))
	, m_name(_T(""))
	, m_zhanbi10(_T(""))
{

}

CDlgTuzongbiao10::~CDlgTuzongbiao10()
{
}

void CDlgTuzongbiao10::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_mianji10);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT5, m_zhanbi10);
	DDX_Control(pDX, IDC_LIST1, m_list10);
}


BEGIN_MESSAGE_MAP(CDlgTuzongbiao10, CDialogEx)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTuzongbiao10::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTuzongbiao10::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDlgTuzongbiao10 ��Ϣ�������




BOOL CDlgTuzongbiao10::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_list10.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_list10.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_list10.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


	//һ��ʼ����ʾ��������
	//�������ݿ�
	if (!ConnectDB())
	{
		AfxMessageBox(TEXT("�������ݿ�ʧ��"));
		return FALSE;
	}
	//��ѯ����
	SelectDB();
	//��ȡ����;
	GetDataFromDB();
	//��ʾ����
	ShowInfo();

	//�������ԣ�����ѡ��״̬����ʾ���
	m_list10.SetExtendedStyle(m_list10.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CDlgTuzongbiao10::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_name.Empty();
	m_mianji10.Empty();
	m_zhanbi10.Empty();
	UpdateData(FALSE);
}


void CDlgTuzongbiao10::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	DeleteDB();
}




BOOL CDlgTuzongbiao10::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysql);
	//�������ݿ�����ʽ
	mysql_options(&m_mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysql, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgTuzongbiao10::InsertDB()
{
	UpdateData(TRUE);
	if (m_name.IsEmpty() || m_mianji10.IsEmpty() || m_zhanbi10.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_name.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_mianji10.GetBuffer();
	char* zhanbi = (char*)m_zhanbi10.GetBuffer();

	sprintf(query, "insert into tuzong values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysql, query))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgTuzongbiao10::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_list10.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_list10.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_list10.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(query, "delete from tuzong where ����=\'%s\';", tname);
			if (mysql_query(&m_mysql, query))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_list10.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgTuzongbiao10::SelectDB()
{

	sprintf(query, "select * from tuzong");
	//��ѯ����
	if (mysql_query(&m_mysql, query))
		return FALSE;
	//��ȡ�����
	m_res = mysql_store_result(&m_mysql);
	return TRUE;
}

void CDlgTuzongbiao10::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_row = mysql_fetch_row(m_res))
	{
		m_data[i].push_back(m_row[0]);
		m_data[i].push_back(m_row[1]);
		m_data[i].push_back(m_row[2]);
		i++;
	}
}

void CDlgTuzongbiao10::ShowInfo()
{
	m_list10.DeleteAllItems();
	for (int i = 0; i<m_res->row_count; i++)
	{
		int iCount = m_list10.GetItemCount();

		m_list10.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysql.field_count; j++)//number of columns in result set

			m_list10.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgTuzongbiao10::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgTuzongbiao10::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_res);
	//�ر����ݿ�
	mysql_close(&m_mysql);
}

