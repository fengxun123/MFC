// DlgZhifenbiao32.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhifenbiao32.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysqlz32;			//���ݿ�ṹ
MYSQL_RES* m_resz32;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_rowz32;          //��ȡÿһ����¼
char queryz32[150]; //��ѯ���

// CDlgZhifenbiao32 �Ի���

IMPLEMENT_DYNAMIC(CDlgZhifenbiao32, CDialogEx)

CDlgZhifenbiao32::CDlgZhifenbiao32(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIFENBIAO32, pParent)
	, m_zhiname32(_T(""))
	, m_zhimianji32(_T(""))
	, m_zhizhanbi32(_T(""))
{

}

CDlgZhifenbiao32::~CDlgZhifenbiao32()
{
}

void CDlgZhifenbiao32::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_zhilist32);
	DDX_Text(pDX, IDC_EDIT2, m_zhiname32);
	DDX_Text(pDX, IDC_EDIT1, m_zhimianji32);
	DDX_Text(pDX, IDC_EDIT5, m_zhizhanbi32);
}


BEGIN_MESSAGE_MAP(CDlgZhifenbiao32, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgZhifenbiao32::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgZhifenbiao32::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgZhifenbiao32 ��Ϣ�������


BOOL CDlgZhifenbiao32::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_zhilist32.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_zhilist32.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_zhilist32.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_zhilist32.SetExtendedStyle(m_zhilist32.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CDlgZhifenbiao32::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_zhiname32.Empty();
	m_zhimianji32.Empty();
	m_zhizhanbi32.Empty();
	UpdateData(FALSE);
}


void CDlgZhifenbiao32::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}
BOOL CDlgZhifenbiao32::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysqlz32);
	//�������ݿ�����ʽ
	mysql_options(&m_mysqlz32, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysqlz32, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgZhifenbiao32::InsertDB()
{
	UpdateData(TRUE);
	if (m_zhiname32.IsEmpty() || m_zhimianji32.IsEmpty() || m_zhizhanbi32.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_zhiname32.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_zhimianji32.GetBuffer();
	char* zhanbi = (char*)m_zhizhanbi32.GetBuffer();

	sprintf(queryz32, "insert into zhifen32 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysqlz32, queryz32))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgZhifenbiao32::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_zhilist32.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_zhilist32.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_zhilist32.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(queryz32, "delete from zhifen32 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysqlz32, queryz32))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_zhilist32.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgZhifenbiao32::SelectDB()
{

	sprintf(queryz32, "select * from zhifen32");
	//��ѯ����
	if (mysql_query(&m_mysqlz32, queryz32))
		return FALSE;
	//��ȡ�����
	m_resz32 = mysql_store_result(&m_mysqlz32);
	return TRUE;
}

void CDlgZhifenbiao32::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_rowz32 = mysql_fetch_row(m_resz32))
	{
		m_data[i].push_back(m_rowz32[0]);
		m_data[i].push_back(m_rowz32[1]);
		m_data[i].push_back(m_rowz32[2]);
		i++;
	}
}

void CDlgZhifenbiao32::ShowInfo()
{
	m_zhilist32.DeleteAllItems();
	for (int i = 0; i<m_resz32->row_count; i++)
	{
		int iCount = m_zhilist32.GetItemCount();

		m_zhilist32.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysqlz32.field_count; j++)//number of columns in result set

			m_zhilist32.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgZhifenbiao32::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgZhifenbiao32::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_resz32);
	//�ر����ݿ�
	mysql_close(&m_mysqlz32);
}
