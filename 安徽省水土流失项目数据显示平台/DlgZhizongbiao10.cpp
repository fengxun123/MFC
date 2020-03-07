// DlgZhizongbiao10.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhizongbiao10.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysqlz10;			//���ݿ�ṹ
MYSQL_RES* m_resz10;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_rowz10;          //��ȡÿһ����¼
char queryz10[150]; //��ѯ���
// CDlgZhizongbiao10 �Ի���

IMPLEMENT_DYNAMIC(CDlgZhizongbiao10, CDialogEx)

CDlgZhizongbiao10::CDlgZhizongbiao10(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIZONGBIAO10, pParent)
	, m_zhiname10(_T(""))
	, m_zhimianji10(_T(""))
	, m_zhizhanbi10(_T(""))
{

}

CDlgZhizongbiao10::~CDlgZhizongbiao10()
{
}

void CDlgZhizongbiao10::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_zhilist10);
	DDX_Text(pDX, IDC_EDIT2, m_zhiname10);
	DDX_Text(pDX, IDC_EDIT1, m_zhimianji10);
	DDX_Text(pDX, IDC_EDIT5, m_zhizhanbi10);
}


BEGIN_MESSAGE_MAP(CDlgZhizongbiao10, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgZhizongbiao10::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgZhizongbiao10::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgZhizongbiao10 ��Ϣ�������


BOOL CDlgZhizongbiao10::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_zhilist10.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_zhilist10.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_zhilist10.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_zhilist10.SetExtendedStyle(m_zhilist10.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CDlgZhizongbiao10::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_zhiname10.Empty();
	m_zhimianji10.Empty();
	m_zhizhanbi10.Empty();
	UpdateData(FALSE);
}


void CDlgZhizongbiao10::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}
BOOL CDlgZhizongbiao10::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysqlz10);
	//�������ݿ�����ʽ
	mysql_options(&m_mysqlz10, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysqlz10, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgZhizongbiao10::InsertDB()
{
	UpdateData(TRUE);
	if (m_zhiname10.IsEmpty() || m_zhimianji10.IsEmpty() || m_zhizhanbi10.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_zhiname10.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_zhimianji10.GetBuffer();
	char* zhanbi = (char*)m_zhizhanbi10.GetBuffer();

	sprintf(queryz10, "insert into zhizong1 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysqlz10, queryz10))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgZhizongbiao10::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_zhilist10.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_zhilist10.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_zhilist10.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(queryz10, "delete from zhizong1 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysqlz10, queryz10))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_zhilist10.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgZhizongbiao10::SelectDB()
{

	sprintf(queryz10, "select * from zhizong1");
	//��ѯ����
	if (mysql_query(&m_mysqlz10, queryz10))
		return FALSE;
	//��ȡ�����
	m_resz10 = mysql_store_result(&m_mysqlz10);
	return TRUE;
}

void CDlgZhizongbiao10::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_rowz10 = mysql_fetch_row(m_resz10))
	{
		m_data[i].push_back(m_rowz10[0]);
		m_data[i].push_back(m_rowz10[1]);
		m_data[i].push_back(m_rowz10[2]);
		i++;
	}
}

void CDlgZhizongbiao10::ShowInfo()
{
	m_zhilist10.DeleteAllItems();
	for (int i = 0; i<m_resz10->row_count; i++)
	{
		int iCount = m_zhilist10.GetItemCount();

		m_zhilist10.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysqlz10.field_count; j++)//number of columns in result set

			m_zhilist10.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgZhizongbiao10::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgZhizongbiao10::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_resz10);
	//�ر����ݿ�
	mysql_close(&m_mysqlz10);
}

