// DlgTufenbiao42.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgTufenbiao42.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"

MYSQL m_mysql42;			//���ݿ�ṹ
MYSQL_RES* m_res42;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_row42;          //��ȡÿһ����¼
char query42[150]; //��ѯ���


// CDlgTufenbiao42 �Ի���

IMPLEMENT_DYNAMIC(CDlgTufenbiao42, CDialogEx)

CDlgTufenbiao42::CDlgTufenbiao42(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUFENBIAO42, pParent)
	, m_name42(_T(""))
	
	, m_zhanbi42(_T(""))
	, m_mianji42(_T(""))
{

}

CDlgTufenbiao42::~CDlgTufenbiao42()
{
}

void CDlgTufenbiao42::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list42);
	DDX_Text(pDX, IDC_EDIT2, m_name42);
	//  DDX_Text(pDX, IDC_EDIT1, m_mianji41);
	DDX_Text(pDX, IDC_EDIT5, m_zhanbi42);
	DDX_Text(pDX, IDC_EDIT1, m_mianji42);
}


BEGIN_MESSAGE_MAP(CDlgTufenbiao42, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTufenbiao42::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTufenbiao42::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgTufenbiao42 ��Ϣ�������


void CDlgTufenbiao42::OnBnClickedButton1()
{
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_name42.Empty();
	m_mianji42.Empty();
	m_zhanbi42.Empty();
	UpdateData(FALSE);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDlgTufenbiao42::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}


BOOL CDlgTufenbiao42::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_list42.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_list42.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_list42.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);

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
	m_list42.SetExtendedStyle(m_list42.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
BOOL CDlgTufenbiao42::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysql42);
	//�������ݿ�����ʽ
	mysql_options(&m_mysql42, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysql42, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgTufenbiao42::InsertDB()
{
	UpdateData(TRUE);
	if (m_name42.IsEmpty() || m_mianji42.IsEmpty() || m_zhanbi42.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_name42.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_mianji42.GetBuffer();
	char* zhanbi = (char*)m_zhanbi42.GetBuffer();

	sprintf(query42, "insert into tufen42 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysql42, query42))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgTufenbiao42::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_list42.GetItemCount();

	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_list42.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_list42.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(query42, "delete from tufen42 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysql42, query42))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_list42.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgTufenbiao42::SelectDB()
{

	sprintf(query42, "select * from tufen42");
	//��ѯ����
	if (mysql_query(&m_mysql42, query42))
		return FALSE;
	//��ȡ�����
	m_res42 = mysql_store_result(&m_mysql42);
	return TRUE;
}

void CDlgTufenbiao42::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_row42 = mysql_fetch_row(m_res42))
	{
		m_data[i].push_back(m_row42[0]);
		m_data[i].push_back(m_row42[1]);
		m_data[i].push_back(m_row42[2]);
		i++;
	}
}

void CDlgTufenbiao42::ShowInfo()
{
	m_list42.DeleteAllItems();
	for (int i = 0; i<m_res42->row_count; i++)
	{
		int iCount = m_list42.GetItemCount();

		m_list42.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysql42.field_count; j++)//number of columns in result set

			m_list42.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgTufenbiao42::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgTufenbiao42::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_res42);
	//�ر����ݿ�
	mysql_close(&m_mysql42);
}





