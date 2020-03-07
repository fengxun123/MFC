// DlgZhifenbiao31.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhifenbiao31.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysqlz31;			//���ݿ�ṹ
MYSQL_RES* m_resz31;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_rowz31;          //��ȡÿһ����¼
char queryz31[150]; //��ѯ���

// CDlgZhifenbiao31 �Ի���

IMPLEMENT_DYNAMIC(CDlgZhifenbiao31, CDialogEx)

CDlgZhifenbiao31::CDlgZhifenbiao31(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIFENBIAO31, pParent)
	, m_zhiname31(_T(""))
	, m_zhimianji31(_T(""))
	, m_zhizhanbi31(_T(""))
{

}

CDlgZhifenbiao31::~CDlgZhifenbiao31()
{
}

void CDlgZhifenbiao31::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_zhilist31);
	DDX_Text(pDX, IDC_EDIT2, m_zhiname31);
	DDX_Text(pDX, IDC_EDIT1, m_zhimianji31);
	DDX_Text(pDX, IDC_EDIT5, m_zhizhanbi31);
}


BEGIN_MESSAGE_MAP(CDlgZhifenbiao31, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgZhifenbiao31::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgZhifenbiao31::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgZhifenbiao31 ��Ϣ�������


BOOL CDlgZhifenbiao31::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_zhilist31.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_zhilist31.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_zhilist31.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_zhilist31.SetExtendedStyle(m_zhilist31.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CDlgZhifenbiao31::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_zhiname31.Empty();
	m_zhimianji31.Empty();
	m_zhizhanbi31.Empty();
	UpdateData(FALSE);
}


void CDlgZhifenbiao31::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}
BOOL CDlgZhifenbiao31::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysqlz31);
	//�������ݿ�����ʽ
	mysql_options(&m_mysqlz31, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysqlz31, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgZhifenbiao31::InsertDB()
{
	UpdateData(TRUE);
	if (m_zhiname31.IsEmpty() || m_zhimianji31.IsEmpty() || m_zhizhanbi31.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_zhiname31.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_zhimianji31.GetBuffer();
	char* zhanbi = (char*)m_zhizhanbi31.GetBuffer();

	sprintf(queryz31, "insert into zhifen31 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysqlz31, queryz31))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgZhifenbiao31::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_zhilist31.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_zhilist31.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_zhilist31.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(queryz31, "delete from zhifen31 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysqlz31, queryz31))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_zhilist31.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgZhifenbiao31::SelectDB()
{

	sprintf(queryz31, "select * from zhifen31");
	//��ѯ����
	if (mysql_query(&m_mysqlz31, queryz31))
		return FALSE;
	//��ȡ�����
	m_resz31 = mysql_store_result(&m_mysqlz31);
	return TRUE;
}

void CDlgZhifenbiao31::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_rowz31 = mysql_fetch_row(m_resz31))
	{
		m_data[i].push_back(m_rowz31[0]);
		m_data[i].push_back(m_rowz31[1]);
		m_data[i].push_back(m_rowz31[2]);
		i++;
	}
}

void CDlgZhifenbiao31::ShowInfo()
{
	m_zhilist31.DeleteAllItems();
	for (int i = 0; i<m_resz31->row_count; i++)
	{
		int iCount = m_zhilist31.GetItemCount();

		m_zhilist31.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysqlz31.field_count; j++)//number of columns in result set

			m_zhilist31.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgZhifenbiao31::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgZhifenbiao31::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_resz31);
	//�ر����ݿ�
	mysql_close(&m_mysqlz31);
}
