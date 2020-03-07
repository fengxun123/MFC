// DlgTufenbiao13.cpp : ʵ���ļ�
//

#include "stdafx.h"
#ifdef _MSC_VER
#ifdef _WIN64
#include <WinSock2.h>
#elif _WIN32
#include <winsock.h>
#endif
#endif

#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgTufenbiao13.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"

MYSQL m_mysql13;			//���ݿ�ṹ
MYSQL_RES* m_res13;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_row13;          //��ȡÿһ����¼
char query13[150]; //��ѯ���

// CDlgTufenbiao13 �Ի���

IMPLEMENT_DYNAMIC(CDlgTufenbiao13, CDialogEx)

CDlgTufenbiao13::CDlgTufenbiao13(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUFENBIAO13, pParent)
	, m_name13(_T(""))
	, m_mianji13(_T(""))
	, m_zhanbi13(_T(""))
{

}

CDlgTufenbiao13::~CDlgTufenbiao13()
{
}

void CDlgTufenbiao13::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_name13);
	DDX_Text(pDX, IDC_EDIT1, m_mianji13);
	DDX_Text(pDX, IDC_EDIT5, m_zhanbi13);
	DDX_Control(pDX, IDC_LIST2, m_list13);
}


BEGIN_MESSAGE_MAP(CDlgTufenbiao13, CDialogEx)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTufenbiao13::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTufenbiao13::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDlgTufenbiao13 ��Ϣ�������


void CDlgTufenbiao13::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_name13.Empty();
	m_mianji13.Empty();
	m_zhanbi13.Empty();
	UpdateData(FALSE);
}


void CDlgTufenbiao13::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}


BOOL CDlgTufenbiao13::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_list13.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_list13.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_list13.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_list13.SetExtendedStyle(m_list13.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

BOOL CDlgTufenbiao13::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysql13);
	//�������ݿ�����ʽ
	mysql_options(&m_mysql13, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysql13, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgTufenbiao13::InsertDB()
{
	UpdateData(TRUE);
	if (m_name13.IsEmpty() || m_mianji13.IsEmpty() || m_zhanbi13.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_name13.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_mianji13.GetBuffer();
	char* zhanbi = (char*)m_zhanbi13.GetBuffer();

	sprintf(query13, "insert into tufen3 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysql13, query13))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgTufenbiao13::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_list13.GetItemCount();

	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_list13.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_list13.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(query13, "delete from tufen3 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysql13, query13))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_list13.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgTufenbiao13::SelectDB()
{

	sprintf(query13, "select * from tufen3");
	//��ѯ����
	if (mysql_query(&m_mysql13, query13))
		return FALSE;
	//��ȡ�����
	m_res13 = mysql_store_result(&m_mysql13);
	return TRUE;
}

void CDlgTufenbiao13::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_row13 = mysql_fetch_row(m_res13))
	{
		m_data[i].push_back(m_row13[0]);
		m_data[i].push_back(m_row13[1]);
		m_data[i].push_back(m_row13[2]);
		i++;
	}
}

void CDlgTufenbiao13::ShowInfo()
{
	m_list13.DeleteAllItems();
	for (int i = 0; i<m_res13->row_count; i++)
	{
		int iCount = m_list13.GetItemCount();

		m_list13.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysql13.field_count; j++)//number of columns in result set

			m_list13.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgTufenbiao13::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgTufenbiao13::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_res13);
	//�ر����ݿ�
	mysql_close(&m_mysql13);
}
