// DlgZhifenbiao12.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhifenbiao12.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysqlz12;			//���ݿ�ṹ
MYSQL_RES* m_resz12;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_rowz12;          //��ȡÿһ����¼
char queryz12[150]; //��ѯ���

// CDlgZhifenbiao12 �Ի���

IMPLEMENT_DYNAMIC(CDlgZhifenbiao12, CDialogEx)

CDlgZhifenbiao12::CDlgZhifenbiao12(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIFENBIAO12, pParent)
	, m_zhiname12(_T(""))
	, m_zhimianji12(_T(""))
	, m_zhizhanbi12(_T(""))
{

}

CDlgZhifenbiao12::~CDlgZhifenbiao12()
{
}

void CDlgZhifenbiao12::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_zhilist12);
	DDX_Text(pDX, IDC_EDIT2, m_zhiname12);
	DDX_Text(pDX, IDC_EDIT1, m_zhimianji12);
	DDX_Text(pDX, IDC_EDIT5, m_zhizhanbi12);
}


BEGIN_MESSAGE_MAP(CDlgZhifenbiao12, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgZhifenbiao12::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgZhifenbiao12::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgZhifenbiao12 ��Ϣ�������


BOOL CDlgZhifenbiao12::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_zhilist12.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_zhilist12.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_zhilist12.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_zhilist12.SetExtendedStyle(m_zhilist12.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CDlgZhifenbiao12::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_zhiname12.Empty();
	m_zhimianji12.Empty();
	m_zhizhanbi12.Empty();
	UpdateData(FALSE);
}


void CDlgZhifenbiao12::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}
BOOL CDlgZhifenbiao12::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysqlz12);
	//�������ݿ�����ʽ
	mysql_options(&m_mysqlz12, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysqlz12, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgZhifenbiao12::InsertDB()
{
	UpdateData(TRUE);
	if (m_zhiname12.IsEmpty() || m_zhimianji12.IsEmpty() || m_zhizhanbi12.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_zhiname12.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_zhimianji12.GetBuffer();
	char* zhanbi = (char*)m_zhizhanbi12.GetBuffer();

	sprintf(queryz12, "insert into zhifen12 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysqlz12, queryz12))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgZhifenbiao12::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_zhilist12.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_zhilist12.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_zhilist12.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(queryz12, "delete from zhifen12 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysqlz12, queryz12))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_zhilist12.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgZhifenbiao12::SelectDB()
{

	sprintf(queryz12, "select * from zhifen12");
	//��ѯ����
	if (mysql_query(&m_mysqlz12, queryz12))
		return FALSE;
	//��ȡ�����
	m_resz12 = mysql_store_result(&m_mysqlz12);
	return TRUE;
}

void CDlgZhifenbiao12::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_rowz12 = mysql_fetch_row(m_resz12))
	{
		m_data[i].push_back(m_rowz12[0]);
		m_data[i].push_back(m_rowz12[1]);
		m_data[i].push_back(m_rowz12[2]);
		i++;
	}
}

void CDlgZhifenbiao12::ShowInfo()
{
	m_zhilist12.DeleteAllItems();
	for (int i = 0; i<m_resz12->row_count; i++)
	{
		int iCount = m_zhilist12.GetItemCount();

		m_zhilist12.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysqlz12.field_count; j++)//number of columns in result set

			m_zhilist12.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgZhifenbiao12::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgZhifenbiao12::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_resz12);
	//�ر����ݿ�
	mysql_close(&m_mysqlz12);
}
