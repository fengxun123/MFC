// DlgTufenbiao12.cpp : ʵ���ļ�
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
#include "DlgTufenbiao12.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"

MYSQL m_mysql12;			//���ݿ�ṹ
MYSQL_RES* m_res12;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_row12;          //��ȡÿһ����¼
char query12[150]; //��ѯ���
// CDlgTufenbiao12 �Ի���

IMPLEMENT_DYNAMIC(CDlgTufenbiao12, CDialogEx)

CDlgTufenbiao12::CDlgTufenbiao12(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUFENBIAO12, pParent)
	, m_name12(_T(""))
	, m_mianji12(_T(""))
	, m_zhanbi12(_T(""))
{

}

CDlgTufenbiao12::~CDlgTufenbiao12()
{
}

void CDlgTufenbiao12::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_name12);
	DDX_Text(pDX, IDC_EDIT1, m_mianji12);
	DDX_Text(pDX, IDC_EDIT5, m_zhanbi12);
	DDX_Control(pDX, IDC_LIST2, m_list12);
}


BEGIN_MESSAGE_MAP(CDlgTufenbiao12, CDialogEx)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTufenbiao12::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTufenbiao12::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDlgTufenbiao12 ��Ϣ�������


void CDlgTufenbiao12::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_name12.Empty();
	m_mianji12.Empty();
	m_zhanbi12.Empty();
	UpdateData(FALSE);
}


void CDlgTufenbiao12::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}


BOOL CDlgTufenbiao12::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_list12.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_list12.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_list12.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_list12.SetExtendedStyle(m_list12.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
BOOL CDlgTufenbiao12::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysql12);
	//�������ݿ�����ʽ
	mysql_options(&m_mysql12, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysql12, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgTufenbiao12::InsertDB()
{
	UpdateData(TRUE);
	if (m_name12.IsEmpty() || m_mianji12.IsEmpty() || m_zhanbi12.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_name12.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_mianji12.GetBuffer();
	char* zhanbi = (char*)m_zhanbi12.GetBuffer();

	sprintf(query12, "insert into tufen2 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysql12, query12))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgTufenbiao12::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_list12.GetItemCount();
	
	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_list12.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_list12.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(query12, "delete from tufen2 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysql12, query12))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_list12.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgTufenbiao12::SelectDB()
{

	sprintf(query12, "select * from tufen2");
	//��ѯ����
	if (mysql_query(&m_mysql12, query12))
		return FALSE;
	//��ȡ�����
	m_res12 = mysql_store_result(&m_mysql12);
	return TRUE;
}

void CDlgTufenbiao12::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_row12 = mysql_fetch_row(m_res12))
	{
		m_data[i].push_back(m_row12[0]);
		m_data[i].push_back(m_row12[1]);
		m_data[i].push_back(m_row12[2]);
		i++;
	}
}

void CDlgTufenbiao12::ShowInfo()
{
	m_list12.DeleteAllItems();
	for (int i = 0; i<m_res12->row_count; i++)
	{
		int iCount = m_list12.GetItemCount();

		m_list12.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysql12.field_count; j++)//number of columns in result set

			m_list12.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgTufenbiao12::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgTufenbiao12::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_res12);
	//�ر����ݿ�
	mysql_close(&m_mysql12);
}

