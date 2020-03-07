// DlgZhifenbiao22.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhifenbiao22.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysqlz22;			//���ݿ�ṹ
MYSQL_RES* m_resz22;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_rowz22;          //��ȡÿһ����¼
char queryz22[150]; //��ѯ���

// CDlgZhifenbiao22 �Ի���

IMPLEMENT_DYNAMIC(CDlgZhifenbiao22, CDialogEx)

CDlgZhifenbiao22::CDlgZhifenbiao22(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIFENBIAO22, pParent)
	, m_zhiname22(_T(""))
	, m_zhimianji22(_T(""))
	, m_zhizhanbi22(_T(""))
{

}

CDlgZhifenbiao22::~CDlgZhifenbiao22()
{
}

void CDlgZhifenbiao22::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_zhilist22);
	DDX_Text(pDX, IDC_EDIT2, m_zhiname22);
	DDX_Text(pDX, IDC_EDIT1, m_zhimianji22);
	DDX_Text(pDX, IDC_EDIT5, m_zhizhanbi22);
}


BEGIN_MESSAGE_MAP(CDlgZhifenbiao22, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgZhifenbiao22::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgZhifenbiao22::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgZhifenbiao22 ��Ϣ�������


BOOL CDlgZhifenbiao22::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_zhilist22.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_zhilist22.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_zhilist22.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_zhilist22.SetExtendedStyle(m_zhilist22.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CDlgZhifenbiao22::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_zhiname22.Empty();
	m_zhimianji22.Empty();
	m_zhizhanbi22.Empty();
	UpdateData(FALSE);
}


void CDlgZhifenbiao22::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}
BOOL CDlgZhifenbiao22::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysqlz22);
	//�������ݿ�����ʽ
	mysql_options(&m_mysqlz22, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysqlz22, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}


BOOL CDlgZhifenbiao22::InsertDB()
{
	UpdateData(TRUE);
	if (m_zhiname22.IsEmpty() || m_zhimianji22.IsEmpty() || m_zhizhanbi22.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_zhiname22.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_zhimianji22.GetBuffer();
	char* zhanbi = (char*)m_zhizhanbi22.GetBuffer();

	sprintf(queryz22, "insert into zhifen22 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysqlz22, queryz22))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgZhifenbiao22::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_zhilist22.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_zhilist22.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_zhilist22.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(queryz22, "delete from zhifen22 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysqlz22, queryz22))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_zhilist22.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgZhifenbiao22::SelectDB()
{

	sprintf(queryz22, "select * from zhifen22");
	//��ѯ����
	if (mysql_query(&m_mysqlz22, queryz22))
		return FALSE;
	//��ȡ�����
	m_resz22 = mysql_store_result(&m_mysqlz22);
	return TRUE;
}

void CDlgZhifenbiao22::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_rowz22 = mysql_fetch_row(m_resz22))
	{
		m_data[i].push_back(m_rowz22[0]);
		m_data[i].push_back(m_rowz22[1]);
		m_data[i].push_back(m_rowz22[2]);
		i++;
	}
}

void CDlgZhifenbiao22::ShowInfo()
{
	m_zhilist22.DeleteAllItems();
	for (int i = 0; i<m_resz22->row_count; i++)
	{
		int iCount = m_zhilist22.GetItemCount();

		m_zhilist22.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysqlz22.field_count; j++)//number of columns in result set

			m_zhilist22.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgZhifenbiao22::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgZhifenbiao22::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_resz22);
	//�ر����ݿ�
	mysql_close(&m_mysqlz22);
}

