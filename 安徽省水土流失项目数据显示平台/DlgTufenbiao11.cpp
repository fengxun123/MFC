// DlgTufenbiao11.cpp : ʵ���ļ�
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
#include "DlgTufenbiao11.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"



MYSQL m_mysql11;			//���ݿ�ṹ
MYSQL_RES* m_res11;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_row11;          //��ȡÿһ����¼
char query11[150]; //��ѯ���

// CDlgTufenbiao11 �Ի���

IMPLEMENT_DYNAMIC(CDlgTufenbiao11, CDialogEx)

CDlgTufenbiao11::CDlgTufenbiao11(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUFENBIAO11, pParent)
	, m_name11(_T(""))
	, m_mianji11(_T(""))
	, m_zhanbi11(_T(""))
{

}

CDlgTufenbiao11::~CDlgTufenbiao11()
{
}

void CDlgTufenbiao11::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_name11);
	DDX_Text(pDX, IDC_EDIT1, m_mianji11);
	DDX_Text(pDX, IDC_EDIT5, m_zhanbi11);
	DDX_Control(pDX, IDC_LIST2, m_list11);
}


BEGIN_MESSAGE_MAP(CDlgTufenbiao11, CDialogEx)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTufenbiao11::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTufenbiao11::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDlgTufenbiao11 ��Ϣ�������


BOOL CDlgTufenbiao11::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_list11.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_list11.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_list11.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_list11.SetExtendedStyle(m_list11.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}



BOOL CDlgTufenbiao11::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysql11);
	//�������ݿ�����ʽ
	mysql_options(&m_mysql11, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysql11, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgTufenbiao11::InsertDB()
{
	UpdateData(TRUE);
	if (m_name11.IsEmpty() || m_mianji11.IsEmpty() || m_zhanbi11.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_name11.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_mianji11.GetBuffer();
	char* zhanbi = (char*)m_zhanbi11.GetBuffer();

	sprintf(query11, "insert into tufen1 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysql11, query11))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgTufenbiao11::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_list11.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_list11.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_list11.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(query11, "delete from tufen1 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysql11, query11))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_list11.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgTufenbiao11::SelectDB()
{

	sprintf(query11, "select * from tufen1");
	//��ѯ����
	if (mysql_query(&m_mysql11, query11))
		return FALSE;
	//��ȡ�����
	m_res11 = mysql_store_result(&m_mysql11);
	return TRUE;
}

void CDlgTufenbiao11::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_row11 = mysql_fetch_row(m_res11))
	{
		m_data[i].push_back(m_row11[0]);
		m_data[i].push_back(m_row11[1]);
		m_data[i].push_back(m_row11[2]);
		i++;
	}
}

void CDlgTufenbiao11::ShowInfo()
{
	m_list11.DeleteAllItems();
	for (int i = 0; i<m_res11->row_count; i++)
	{
		int iCount = m_list11.GetItemCount();

		m_list11.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysql11.field_count; j++)//number of columns in result set

			m_list11.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgTufenbiao11::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgTufenbiao11::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_res11);
	//�ر����ݿ�
	mysql_close(&m_mysql11);
}



void CDlgTufenbiao11::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_name11.Empty();
	m_mianji11.Empty();
	m_zhanbi11.Empty();
	UpdateData(FALSE);
}


void CDlgTufenbiao11::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	DeleteDB();
}
