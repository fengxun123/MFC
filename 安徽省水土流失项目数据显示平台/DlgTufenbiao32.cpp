// DlgTufenbiao32.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgTufenbiao32.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"

MYSQL m_mysql32;			//���ݿ�ṹ
MYSQL_RES* m_res32;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_row32;          //��ȡÿһ����¼
char query32[150]; //��ѯ���

// CDlgTufenbiao32 �Ի���

IMPLEMENT_DYNAMIC(CDlgTufenbiao32, CDialogEx)

CDlgTufenbiao32::CDlgTufenbiao32(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUFENBIAO32, pParent)
	, m_name32(_T(""))
	, m_mianji32(_T(""))
	, m_zhanbi32(_T(""))
{

}

CDlgTufenbiao32::~CDlgTufenbiao32()
{
}

void CDlgTufenbiao32::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_name32);
	DDX_Text(pDX, IDC_EDIT1, m_mianji32);
	DDX_Text(pDX, IDC_EDIT5, m_zhanbi32);
	DDX_Control(pDX, IDC_LIST1, m_list32);
}


BEGIN_MESSAGE_MAP(CDlgTufenbiao32, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTufenbiao32::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTufenbiao32::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgTufenbiao32 ��Ϣ�������


void CDlgTufenbiao32::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_name32.Empty();
	m_mianji32.Empty();
	m_zhanbi32.Empty();
	UpdateData(FALSE);

	
}


void CDlgTufenbiao32::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}


BOOL CDlgTufenbiao32::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_list32.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_list32.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_list32.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_list32.SetExtendedStyle(m_list32.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
BOOL CDlgTufenbiao32::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysql32);
	//�������ݿ�����ʽ
	mysql_options(&m_mysql32, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysql32, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgTufenbiao32::InsertDB()
{
	UpdateData(TRUE);
	if (m_name32.IsEmpty() || m_mianji32.IsEmpty() || m_zhanbi32.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_name32.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_mianji32.GetBuffer();
	char* zhanbi = (char*)m_zhanbi32.GetBuffer();

	sprintf(query32, "insert into tufen32 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysql32, query32))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgTufenbiao32::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_list32.GetItemCount();

	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_list32.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_list32.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(query32, "delete from tufen32 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysql32, query32))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_list32.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgTufenbiao32::SelectDB()
{

	sprintf(query32, "select * from tufen32");
	//��ѯ����
	if (mysql_query(&m_mysql32, query32))
		return FALSE;
	//��ȡ�����
	m_res32 = mysql_store_result(&m_mysql32);
	return TRUE;
}

void CDlgTufenbiao32::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_row32 = mysql_fetch_row(m_res32))
	{
		m_data[i].push_back(m_row32[0]);
		m_data[i].push_back(m_row32[1]);
		m_data[i].push_back(m_row32[2]);
		i++;
	}
}

void CDlgTufenbiao32::ShowInfo()
{
	m_list32.DeleteAllItems();
	for (int i = 0; i<m_res32->row_count; i++)
	{
		int iCount = m_list32.GetItemCount();

		m_list32.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysql32.field_count; j++)//number of columns in result set

			m_list32.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgTufenbiao32::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgTufenbiao32::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_res32);
	//�ر����ݿ�
	mysql_close(&m_mysql32);
}

