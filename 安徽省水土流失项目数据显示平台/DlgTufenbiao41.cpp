// DlgTufenbiao41.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgTufenbiao41.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"

MYSQL m_mysql41;			//���ݿ�ṹ
MYSQL_RES* m_res41;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_row41;          //��ȡÿһ����¼
char query41[150]; //��ѯ���

// CDlgTufenbiao41 �Ի���

IMPLEMENT_DYNAMIC(CDlgTufenbiao41, CDialogEx)

CDlgTufenbiao41::CDlgTufenbiao41(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUFENBIAO41, pParent)
	, m_mianji41(_T(""))
	, m_zhanbi41(_T(""))
	, m_name41(_T(""))
{

}

CDlgTufenbiao41::~CDlgTufenbiao41()
{
}

void CDlgTufenbiao41::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list41);
	//  DDX_Control(pDX, IDC_EDIT2, m_name41);
	DDX_Text(pDX, IDC_EDIT1, m_mianji41);
	DDX_Text(pDX, IDC_EDIT5, m_zhanbi41);
	DDX_Text(pDX, IDC_EDIT2, m_name41);
}


BEGIN_MESSAGE_MAP(CDlgTufenbiao41, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTufenbiao41::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTufenbiao41::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgTufenbiao41 ��Ϣ�������


void CDlgTufenbiao41::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_name41.Empty();
	m_mianji41.Empty();
	m_zhanbi41.Empty();
	UpdateData(FALSE);
}


void CDlgTufenbiao41::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}





BOOL CDlgTufenbiao41::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_list41.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_list41.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_list41.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_list41.SetExtendedStyle(m_list41.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
BOOL CDlgTufenbiao41::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysql41);
	//�������ݿ�����ʽ
	mysql_options(&m_mysql41, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysql41, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgTufenbiao41::InsertDB()
{
	UpdateData(TRUE);
	if (m_name41.IsEmpty() || m_mianji41.IsEmpty() || m_zhanbi41.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_name41.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_mianji41.GetBuffer();
	char* zhanbi = (char*)m_zhanbi41.GetBuffer();

	sprintf(query41, "insert into tufen41 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysql41, query41))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgTufenbiao41::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_list41.GetItemCount();

	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_list41.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_list41.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(query41, "delete from tufen41 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysql41, query41))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_list41.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgTufenbiao41::SelectDB()
{

	sprintf(query41, "select * from tufen41");
	//��ѯ����
	if (mysql_query(&m_mysql41, query41))
		return FALSE;
	//��ȡ�����
	m_res41 = mysql_store_result(&m_mysql41);
	return TRUE;
}

void CDlgTufenbiao41::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_row41 = mysql_fetch_row(m_res41))
	{
		m_data[i].push_back(m_row41[0]);
		m_data[i].push_back(m_row41[1]);
		m_data[i].push_back(m_row41[2]);
		i++;
	}
}

void CDlgTufenbiao41::ShowInfo()
{
	m_list41.DeleteAllItems();
	for (int i = 0; i<m_res41->row_count; i++)
	{
		int iCount = m_list41.GetItemCount();

		m_list41.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysql41.field_count; j++)//number of columns in result set

			m_list41.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgTufenbiao41::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgTufenbiao41::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_res41);
	//�ر����ݿ�
	mysql_close(&m_mysql41);
}


