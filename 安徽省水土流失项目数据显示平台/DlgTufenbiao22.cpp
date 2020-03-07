// DlgTufenbiao22.cpp : ʵ���ļ�
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
#include "DlgTufenbiao22.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"

MYSQL m_mysql22;			//���ݿ�ṹ
MYSQL_RES* m_res22;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_row22;          //��ȡÿһ����¼
char query22[150]; //��ѯ���



// CDlgTufenbiao22 �Ի���

IMPLEMENT_DYNAMIC(CDlgTufenbiao22, CDialogEx)

CDlgTufenbiao22::CDlgTufenbiao22(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUFENBIAO22, pParent)
	, m_name22(_T(""))
	, m_mianji22(_T(""))
	, m_zhanbi22(_T(""))
{

}

CDlgTufenbiao22::~CDlgTufenbiao22()
{
}

void CDlgTufenbiao22::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_name22);
	DDX_Text(pDX, IDC_EDIT1, m_mianji22);
	DDX_Text(pDX, IDC_EDIT5, m_zhanbi22);
	DDX_Control(pDX, IDC_LIST1, m_list22);
}


BEGIN_MESSAGE_MAP(CDlgTufenbiao22, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTufenbiao22::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTufenbiao22::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgTufenbiao22 ��Ϣ�������


void CDlgTufenbiao22::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_name22.Empty();
	m_mianji22.Empty();
	m_zhanbi22.Empty();
	UpdateData(FALSE);
}


void CDlgTufenbiao22::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}


BOOL CDlgTufenbiao22::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_list22.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_list22.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_list22.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_list22.SetExtendedStyle(m_list22.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CDlgTufenbiao22::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysql22);
	//�������ݿ�����ʽ
	mysql_options(&m_mysql22, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysql22, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgTufenbiao22::InsertDB()
{
	UpdateData(TRUE);
	if (m_name22.IsEmpty() || m_mianji22.IsEmpty() || m_zhanbi22.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_name22.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_mianji22.GetBuffer();
	char* zhanbi = (char*)m_zhanbi22.GetBuffer();

	sprintf(query22, "insert into tufen22 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysql22, query22))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgTufenbiao22::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_list22.GetItemCount();

	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_list22.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_list22.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(query22, "delete from tufen22 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysql22, query22))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_list22.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgTufenbiao22::SelectDB()
{

	sprintf(query22, "select * from tufen22");
	//��ѯ����
	if (mysql_query(&m_mysql22, query22))
		return FALSE;
	//��ȡ�����
	m_res22 = mysql_store_result(&m_mysql22);
	return TRUE;
}

void CDlgTufenbiao22::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_row22 = mysql_fetch_row(m_res22))
	{
		m_data[i].push_back(m_row22[0]);
		m_data[i].push_back(m_row22[1]);
		m_data[i].push_back(m_row22[2]);
		i++;
	}
}

void CDlgTufenbiao22::ShowInfo()
{
	m_list22.DeleteAllItems();
	for (int i = 0; i<m_res22->row_count; i++)
	{
		int iCount = m_list22.GetItemCount();

		m_list22.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysql22.field_count; j++)//number of columns in result set

			m_list22.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgTufenbiao22::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgTufenbiao22::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_res22);
	//�ر����ݿ�
	mysql_close(&m_mysql22);
}

