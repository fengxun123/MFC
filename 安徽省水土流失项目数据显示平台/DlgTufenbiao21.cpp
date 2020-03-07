// DlgTufenbiao21.cpp : ʵ���ļ�
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
#include "DlgTufenbiao21.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysql21;			//���ݿ�ṹ
MYSQL_RES* m_res21;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_row21;          //��ȡÿһ����¼
char query21[150]; //��ѯ���


// CDlgTufenbiao21 �Ի���

IMPLEMENT_DYNAMIC(CDlgTufenbiao21, CDialogEx)

CDlgTufenbiao21::CDlgTufenbiao21(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUFENBIAO21, pParent)
	, m_name21(_T(""))
	, m_mianji21(_T(""))
	, m_zhanbi21(_T(""))
{

}

CDlgTufenbiao21::~CDlgTufenbiao21()
{
}

void CDlgTufenbiao21::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_name21);
	DDX_Text(pDX, IDC_EDIT1, m_mianji21);
	DDX_Text(pDX, IDC_EDIT5, m_zhanbi21);
	DDX_Control(pDX, IDC_LIST1, m_list21);
}


BEGIN_MESSAGE_MAP(CDlgTufenbiao21, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTufenbiao21::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTufenbiao21::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgTufenbiao21 ��Ϣ�������


BOOL CDlgTufenbiao21::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_list21.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_list21.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_list21.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_list21.SetExtendedStyle(m_list21.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CDlgTufenbiao21::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_name21.Empty();
	m_mianji21.Empty();
	m_zhanbi21.Empty();
	UpdateData(FALSE);
}


void CDlgTufenbiao21::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}


BOOL CDlgTufenbiao21::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysql21);
	//�������ݿ�����ʽ
	mysql_options(&m_mysql21, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysql21, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgTufenbiao21::InsertDB()
{
	UpdateData(TRUE);
	if (m_name21.IsEmpty() || m_mianji21.IsEmpty() || m_zhanbi21.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_name21.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_mianji21.GetBuffer();
	char* zhanbi = (char*)m_zhanbi21.GetBuffer();

	sprintf(query21, "insert into tufen21 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysql21, query21))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgTufenbiao21::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_list21.GetItemCount();

	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_list21.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_list21.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(query21, "delete from tufen21 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysql21, query21))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_list21.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgTufenbiao21::SelectDB()
{

	sprintf(query21, "select * from tufen21");
	//��ѯ����
	if (mysql_query(&m_mysql21, query21))
		return FALSE;
	//��ȡ�����
	m_res21 = mysql_store_result(&m_mysql21);
	return TRUE;
}

void CDlgTufenbiao21::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_row21 = mysql_fetch_row(m_res21))
	{
		m_data[i].push_back(m_row21[0]);
		m_data[i].push_back(m_row21[1]);
		m_data[i].push_back(m_row21[2]);
		i++;
	}
}

void CDlgTufenbiao21::ShowInfo()
{
	m_list21.DeleteAllItems();
	for (int i = 0; i<m_res21->row_count; i++)
	{
		int iCount = m_list21.GetItemCount();

		m_list21.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysql21.field_count; j++)//number of columns in result set

			m_list21.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgTufenbiao21::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgTufenbiao21::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_res21);
	//�ر����ݿ�
	mysql_close(&m_mysql21);
}

