// DlgZhifenbiao21.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhifenbiao21.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysqlz21;			//���ݿ�ṹ
MYSQL_RES* m_resz21;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_rowz21;          //��ȡÿһ����¼
char queryz21[150]; //��ѯ���

// CDlgZhifenbiao21 �Ի���

IMPLEMENT_DYNAMIC(CDlgZhifenbiao21, CDialogEx)

CDlgZhifenbiao21::CDlgZhifenbiao21(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIFENBIAO21, pParent)
	, m_zhiname21(_T(""))
	, m_zhimianji21(_T(""))
	, m_zhizhanbi21(_T(""))
{

}

CDlgZhifenbiao21::~CDlgZhifenbiao21()
{
}

void CDlgZhifenbiao21::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_zhilist21);
	DDX_Text(pDX, IDC_EDIT2, m_zhiname21);
	DDX_Text(pDX, IDC_EDIT1, m_zhimianji21);
	DDX_Text(pDX, IDC_EDIT5, m_zhizhanbi21);
}


BEGIN_MESSAGE_MAP(CDlgZhifenbiao21, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgZhifenbiao21::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgZhifenbiao21::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgZhifenbiao21 ��Ϣ�������


BOOL CDlgZhifenbiao21::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_zhilist21.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_zhilist21.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_zhilist21.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_zhilist21.SetExtendedStyle(m_zhilist21.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CDlgZhifenbiao21::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_zhiname21.Empty();
	m_zhimianji21.Empty();
	m_zhizhanbi21.Empty();
	UpdateData(FALSE);
}


void CDlgZhifenbiao21::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}

BOOL CDlgZhifenbiao21::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysqlz21);
	//�������ݿ�����ʽ
	mysql_options(&m_mysqlz21, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysqlz21, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgZhifenbiao21::InsertDB()
{
	UpdateData(TRUE);
	if (m_zhiname21.IsEmpty() || m_zhimianji21.IsEmpty() || m_zhizhanbi21.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_zhiname21.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_zhimianji21.GetBuffer();
	char* zhanbi = (char*)m_zhizhanbi21.GetBuffer();

	sprintf(queryz21, "insert into zhifen21 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysqlz21, queryz21))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgZhifenbiao21::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_zhilist21.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_zhilist21.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_zhilist21.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(queryz21, "delete from zhifen21 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysqlz21, queryz21))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_zhilist21.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgZhifenbiao21::SelectDB()
{

	sprintf(queryz21, "select * from zhifen21");
	//��ѯ����
	if (mysql_query(&m_mysqlz21, queryz21))
		return FALSE;
	//��ȡ�����
	m_resz21 = mysql_store_result(&m_mysqlz21);
	return TRUE;
}

void CDlgZhifenbiao21::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_rowz21 = mysql_fetch_row(m_resz21))
	{
		m_data[i].push_back(m_rowz21[0]);
		m_data[i].push_back(m_rowz21[1]);
		m_data[i].push_back(m_rowz21[2]);
		i++;
	}
}

void CDlgZhifenbiao21::ShowInfo()
{
	m_zhilist21.DeleteAllItems();
	for (int i = 0; i<m_resz21->row_count; i++)
	{
		int iCount = m_zhilist21.GetItemCount();

		m_zhilist21.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysqlz21.field_count; j++)//number of columns in result set

			m_zhilist21.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgZhifenbiao21::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgZhifenbiao21::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_resz21);
	//�ر����ݿ�
	mysql_close(&m_mysqlz21);
}

