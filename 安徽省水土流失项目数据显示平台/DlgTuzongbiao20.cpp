// DlgTuzongbiao20.cpp : ʵ���ļ�
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
#include "DlgTuzongbiao20.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysql20;			//���ݿ�ṹ
MYSQL_RES* m_res20;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_row20;          //��ȡÿһ����¼
char query20[150]; //��ѯ���

// CDlgTuzongbiao20 �Ի���

IMPLEMENT_DYNAMIC(CDlgTuzongbiao20, CDialogEx)

CDlgTuzongbiao20::CDlgTuzongbiao20(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUZONGBIAO20, pParent)
	, m_name20(_T(""))
	, m_mianji20(_T(""))
	, m_zhanbi20(_T(""))
{

}

CDlgTuzongbiao20::~CDlgTuzongbiao20()
{
}

void CDlgTuzongbiao20::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_name20);
	DDX_Text(pDX, IDC_EDIT1, m_mianji20);
	DDX_Text(pDX, IDC_EDIT5, m_zhanbi20);
	//  DDX_Control(pDX, IDC_LIST1, m_list20);
	DDX_Control(pDX, IDC_LIST1, m_list20);
}


BEGIN_MESSAGE_MAP(CDlgTuzongbiao20, CDialogEx)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTuzongbiao20::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTuzongbiao20::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDlgTuzongbiao20 ��Ϣ�������


BOOL CDlgTuzongbiao20::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_list20.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_list20.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_list20.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_list20.SetExtendedStyle(m_list20.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CDlgTuzongbiao20::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_name20.Empty();
	m_mianji20.Empty();
	m_zhanbi20.Empty();
	UpdateData(FALSE);
}


void CDlgTuzongbiao20::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}

BOOL CDlgTuzongbiao20::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysql20);
	//�������ݿ�����ʽ
	mysql_options(&m_mysql20, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysql20, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgTuzongbiao20::InsertDB()
{
	UpdateData(TRUE);
	if (m_name20.IsEmpty() || m_mianji20.IsEmpty() || m_zhanbi20.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_name20.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_mianji20.GetBuffer();
	char* zhanbi = (char*)m_zhanbi20.GetBuffer();

	sprintf(query20, "insert into tuzong1 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysql20, query20))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgTuzongbiao20::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_list20.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_list20.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_list20.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(query20, "delete from tuzong1 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysql20, query20))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_list20.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgTuzongbiao20::SelectDB()
{

	sprintf(query20, "select * from tuzong1");
	//��ѯ����
	if (mysql_query(&m_mysql20, query20))
		return FALSE;
	//��ȡ�����
	m_res20 = mysql_store_result(&m_mysql20);
	return TRUE;
}

void CDlgTuzongbiao20::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_row20 = mysql_fetch_row(m_res20))
	{
		m_data[i].push_back(m_row20[0]);
		m_data[i].push_back(m_row20[1]);
		m_data[i].push_back(m_row20[2]);
		i++;
	}
}

void CDlgTuzongbiao20::ShowInfo()
{
	m_list20.DeleteAllItems();
	for (int i = 0; i<m_res20->row_count; i++)
	{
		int iCount = m_list20.GetItemCount();

		m_list20.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysql20.field_count; j++)//number of columns in result set

			m_list20.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgTuzongbiao20::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgTuzongbiao20::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_res20);
	//�ر����ݿ�
	mysql_close(&m_mysql20);
}

