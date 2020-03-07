// DlgZhifenbiao23.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhifenbiao23.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysqlz23;			//���ݿ�ṹ
MYSQL_RES* m_resz23;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_rowz23;          //��ȡÿһ����¼
char queryz23[150]; //��ѯ���

// CDlgZhifenbiao23 �Ի���

IMPLEMENT_DYNAMIC(CDlgZhifenbiao23, CDialogEx)

CDlgZhifenbiao23::CDlgZhifenbiao23(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIFENBIAO23, pParent)
	, m_zhiname23(_T(""))
	, m_zhimianji23(_T(""))
	, m_zhizhanbi23(_T(""))
{

}

CDlgZhifenbiao23::~CDlgZhifenbiao23()
{
}

void CDlgZhifenbiao23::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_zhilist23);
	DDX_Text(pDX, IDC_EDIT2, m_zhiname23);
	DDX_Text(pDX, IDC_EDIT1, m_zhimianji23);
	DDX_Text(pDX, IDC_EDIT5, m_zhizhanbi23);
}


BEGIN_MESSAGE_MAP(CDlgZhifenbiao23, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgZhifenbiao23::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgZhifenbiao23::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgZhifenbiao23 ��Ϣ�������


BOOL CDlgZhifenbiao23::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_zhilist23.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_zhilist23.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_zhilist23.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_zhilist23.SetExtendedStyle(m_zhilist23.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CDlgZhifenbiao23::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_zhiname23.Empty();
	m_zhimianji23.Empty();
	m_zhizhanbi23.Empty();
	UpdateData(FALSE);
}


void CDlgZhifenbiao23::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}

BOOL CDlgZhifenbiao23::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysqlz23);
	//�������ݿ�����ʽ
	mysql_options(&m_mysqlz23, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysqlz23, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgZhifenbiao23::InsertDB()
{
	UpdateData(TRUE);
	if (m_zhiname23.IsEmpty() || m_zhimianji23.IsEmpty() || m_zhizhanbi23.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_zhiname23.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_zhimianji23.GetBuffer();
	char* zhanbi = (char*)m_zhizhanbi23.GetBuffer();

	sprintf(queryz23, "insert into zhifen23 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysqlz23, queryz23))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgZhifenbiao23::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_zhilist23.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_zhilist23.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_zhilist23.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(queryz23, "delete from zhifen23 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysqlz23, queryz23))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_zhilist23.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgZhifenbiao23::SelectDB()
{

	sprintf(queryz23, "select * from zhifen23");
	//��ѯ����
	if (mysql_query(&m_mysqlz23, queryz23))
		return FALSE;
	//��ȡ�����
	m_resz23 = mysql_store_result(&m_mysqlz23);
	return TRUE;
}

void CDlgZhifenbiao23::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_rowz23 = mysql_fetch_row(m_resz23))
	{
		m_data[i].push_back(m_rowz23[0]);
		m_data[i].push_back(m_rowz23[1]);
		m_data[i].push_back(m_rowz23[2]);
		i++;
	}
}

void CDlgZhifenbiao23::ShowInfo()
{
	m_zhilist23.DeleteAllItems();
	for (int i = 0; i<m_resz23->row_count; i++)
	{
		int iCount = m_zhilist23.GetItemCount();

		m_zhilist23.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysqlz23.field_count; j++)//number of columns in result set

			m_zhilist23.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgZhifenbiao23::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgZhifenbiao23::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_resz23);
	//�ر����ݿ�
	mysql_close(&m_mysqlz23);
}

