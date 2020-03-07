// DlgTufenbiao23.cpp : ʵ���ļ�
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
#include "DlgTufenbiao23.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"

MYSQL m_mysql23;			//���ݿ�ṹ
MYSQL_RES* m_res23;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_row23;          //��ȡÿһ����¼
char query23[150]; //��ѯ���


// CDlgTufenbiao23 �Ի���

IMPLEMENT_DYNAMIC(CDlgTufenbiao23, CDialogEx)

CDlgTufenbiao23::CDlgTufenbiao23(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUFENBIAO23, pParent)
	, m_mianji23(_T(""))
	, m_zhanbi23(_T(""))
	, m_name23(_T(""))
{

}

CDlgTufenbiao23::~CDlgTufenbiao23()
{
}

void CDlgTufenbiao23::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT2, m_name23);
	DDX_Text(pDX, IDC_EDIT1, m_mianji23);
	DDX_Text(pDX, IDC_EDIT5, m_zhanbi23);
	DDX_Control(pDX, IDC_LIST1, m_list23);
	DDX_Text(pDX, IDC_EDIT2, m_name23);
}


BEGIN_MESSAGE_MAP(CDlgTufenbiao23, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTufenbiao23::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTufenbiao23::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgTufenbiao23 ��Ϣ�������


void CDlgTufenbiao23::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_name23.Empty();
	m_mianji23.Empty();
	m_zhanbi23.Empty();
	UpdateData(FALSE);
}


void CDlgTufenbiao23::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}


BOOL CDlgTufenbiao23::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_list23.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_list23.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_list23.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_list23.SetExtendedStyle(m_list23.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CDlgTufenbiao23::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysql23);
	//�������ݿ�����ʽ
	mysql_options(&m_mysql23, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysql23, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgTufenbiao23::InsertDB()
{
	UpdateData(TRUE);
	if (m_name23.IsEmpty() || m_mianji23.IsEmpty() || m_zhanbi23.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_name23.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_mianji23.GetBuffer();
	char* zhanbi = (char*)m_zhanbi23.GetBuffer();

	sprintf(query23, "insert into tufen23 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysql23, query23))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgTufenbiao23::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_list23.GetItemCount();

	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_list23.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_list23.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(query23, "delete from tufen23 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysql23, query23))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_list23.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgTufenbiao23::SelectDB()
{

	sprintf(query23, "select * from tufen23");
	//��ѯ����
	if (mysql_query(&m_mysql23, query23))
		return FALSE;
	//��ȡ�����
	m_res23 = mysql_store_result(&m_mysql23);
	return TRUE;
}

void CDlgTufenbiao23::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_row23 = mysql_fetch_row(m_res23))
	{
		m_data[i].push_back(m_row23[0]);
		m_data[i].push_back(m_row23[1]);
		m_data[i].push_back(m_row23[2]);
		i++;
	}
}

void CDlgTufenbiao23::ShowInfo()
{
	m_list23.DeleteAllItems();
	for (int i = 0; i<m_res23->row_count; i++)
	{
		int iCount = m_list23.GetItemCount();

		m_list23.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysql23.field_count; j++)//number of columns in result set

			m_list23.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgTufenbiao23::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgTufenbiao23::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_res23);
	//�ر����ݿ�
	mysql_close(&m_mysql23);
}

