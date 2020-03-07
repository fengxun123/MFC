// DlgTuzongbiao40.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgTuzongbiao40.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"

MYSQL m_mysql40;			//���ݿ�ṹ
MYSQL_RES* m_res40;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_row40;          //��ȡÿһ����¼
char query40[150]; //��ѯ���

// CDlgTuzongbiao40 �Ի���

IMPLEMENT_DYNAMIC(CDlgTuzongbiao40, CDialogEx)

CDlgTuzongbiao40::CDlgTuzongbiao40(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUZONGBIAO40, pParent)
	, m_name40(_T(""))
	, m_mianji40(_T(""))
	, m_zhanbi40(_T(""))
{

}

CDlgTuzongbiao40::~CDlgTuzongbiao40()
{
}

void CDlgTuzongbiao40::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list40);
	DDX_Text(pDX, IDC_EDIT2, m_name40);
	DDX_Text(pDX, IDC_EDIT1, m_mianji40);
	DDX_Text(pDX, IDC_EDIT5, m_zhanbi40);
}


BEGIN_MESSAGE_MAP(CDlgTuzongbiao40, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTuzongbiao40::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTuzongbiao40::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgTuzongbiao40 ��Ϣ�������


void CDlgTuzongbiao40::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_name40.Empty();
	m_mianji40.Empty();
	m_zhanbi40.Empty();
	UpdateData(FALSE);
}


void CDlgTuzongbiao40::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}


BOOL CDlgTuzongbiao40::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_list40.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_list40.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_list40.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_list40.SetExtendedStyle(m_list40.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
BOOL CDlgTuzongbiao40::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysql40);
	//�������ݿ�����ʽ
	mysql_options(&m_mysql40, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysql40, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgTuzongbiao40::InsertDB()
{
	UpdateData(TRUE);
	if (m_name40.IsEmpty() || m_mianji40.IsEmpty() || m_zhanbi40.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_name40.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_mianji40.GetBuffer();
	char* zhanbi = (char*)m_zhanbi40.GetBuffer();

	sprintf(query40, "insert into tuzong3 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysql40, query40))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgTuzongbiao40::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_list40.GetItemCount();

	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_list40.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_list40.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(query40, "delete from tuzong3 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysql40, query40))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_list40.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgTuzongbiao40::SelectDB()
{

	sprintf(query40, "select * from tuzong3");
	//��ѯ����
	if (mysql_query(&m_mysql40, query40))
		return FALSE;
	//��ȡ�����
	m_res40 = mysql_store_result(&m_mysql40);
	return TRUE;
}

void CDlgTuzongbiao40::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_row40 = mysql_fetch_row(m_res40))
	{
		m_data[i].push_back(m_row40[0]);
		m_data[i].push_back(m_row40[1]);
		m_data[i].push_back(m_row40[2]);
		i++;
	}
}

void CDlgTuzongbiao40::ShowInfo()
{
	m_list40.DeleteAllItems();
	for (int i = 0; i<m_res40->row_count; i++)
	{
		int iCount = m_list40.GetItemCount();

		m_list40.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysql40.field_count; j++)//number of columns in result set

			m_list40.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgTuzongbiao40::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgTuzongbiao40::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_res40);
	//�ر����ݿ�
	mysql_close(&m_mysql40);
}


