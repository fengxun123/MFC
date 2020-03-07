// DlgZhizongbiao40.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhizongbiao40.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysqlz40;			//���ݿ�ṹ
MYSQL_RES* m_resz40;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_rowz40;          //��ȡÿһ����¼
char queryz40[150]; //��ѯ���

// CDlgZhizongbiao40 �Ի���

IMPLEMENT_DYNAMIC(CDlgZhizongbiao40, CDialogEx)

CDlgZhizongbiao40::CDlgZhizongbiao40(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIZONGBIAO40, pParent)
	, m_zhiname40(_T(""))
	, m_zhimianji40(_T(""))
	, m_zhizhanbi40(_T(""))
{

}

CDlgZhizongbiao40::~CDlgZhizongbiao40()
{
}

void CDlgZhizongbiao40::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_zhilist40);
	DDX_Text(pDX, IDC_EDIT2, m_zhiname40);
	DDX_Text(pDX, IDC_EDIT1, m_zhimianji40);
	DDX_Text(pDX, IDC_EDIT5, m_zhizhanbi40);
}


BEGIN_MESSAGE_MAP(CDlgZhizongbiao40, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgZhizongbiao40::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgZhizongbiao40::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgZhizongbiao40 ��Ϣ�������


BOOL CDlgZhizongbiao40::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_zhilist40.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_zhilist40.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_zhilist40.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_zhilist40.SetExtendedStyle(m_zhilist40.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CDlgZhizongbiao40::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_zhiname40.Empty();
	m_zhimianji40.Empty();
	m_zhizhanbi40.Empty();
	UpdateData(FALSE);
}


void CDlgZhizongbiao40::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}
BOOL CDlgZhizongbiao40::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysqlz40);
	//�������ݿ�����ʽ
	mysql_options(&m_mysqlz40, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysqlz40, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgZhizongbiao40::InsertDB()
{
	UpdateData(TRUE);
	if (m_zhiname40.IsEmpty() || m_zhimianji40.IsEmpty() || m_zhizhanbi40.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_zhiname40.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_zhimianji40.GetBuffer();
	char* zhanbi = (char*)m_zhizhanbi40.GetBuffer();

	sprintf(queryz40, "insert into zhizong4 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysqlz40, queryz40))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgZhizongbiao40::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_zhilist40.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_zhilist40.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_zhilist40.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(queryz40, "delete from zhizong4 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysqlz40, queryz40))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_zhilist40.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgZhizongbiao40::SelectDB()
{

	sprintf(queryz40, "select * from zhizong4");
	//��ѯ����
	if (mysql_query(&m_mysqlz40, queryz40))
		return FALSE;
	//��ȡ�����
	m_resz40 = mysql_store_result(&m_mysqlz40);
	return TRUE;
}

void CDlgZhizongbiao40::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_rowz40 = mysql_fetch_row(m_resz40))
	{
		m_data[i].push_back(m_rowz40[0]);
		m_data[i].push_back(m_rowz40[1]);
		m_data[i].push_back(m_rowz40[2]);
		i++;
	}
}

void CDlgZhizongbiao40::ShowInfo()
{
	m_zhilist40.DeleteAllItems();
	for (int i = 0; i<m_resz40->row_count; i++)
	{
		int iCount = m_zhilist40.GetItemCount();

		m_zhilist40.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysqlz40.field_count; j++)//number of columns in result set

			m_zhilist40.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgZhizongbiao40::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgZhizongbiao40::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_resz40);
	//�ر����ݿ�
	mysql_close(&m_mysqlz40);
}

