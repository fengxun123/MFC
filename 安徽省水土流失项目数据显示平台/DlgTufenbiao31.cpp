// DlgTufenbiao31.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgTufenbiao31.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"

MYSQL m_mysql31;			//���ݿ�ṹ
MYSQL_RES* m_res31;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_row31;          //��ȡÿһ����¼
char query31[150]; //��ѯ���

// CDlgTufenbiao31 �Ի���

IMPLEMENT_DYNAMIC(CDlgTufenbiao31, CDialogEx)

CDlgTufenbiao31::CDlgTufenbiao31(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUFENBIAO31, pParent)
	, m_name31(_T(""))
	, m_mianji31(_T(""))
	, m_zhanbi31(_T(""))
{

}

CDlgTufenbiao31::~CDlgTufenbiao31()
{
}

void CDlgTufenbiao31::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list31);
	DDX_Text(pDX, IDC_EDIT2, m_name31);
	DDX_Text(pDX, IDC_EDIT1, m_mianji31);
	DDX_Text(pDX, IDC_EDIT5, m_zhanbi31);
}


BEGIN_MESSAGE_MAP(CDlgTufenbiao31, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTufenbiao31::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTufenbiao31::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgTufenbiao31 ��Ϣ�������


void CDlgTufenbiao31::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_name31.Empty();
	m_mianji31.Empty();
	m_zhanbi31.Empty();
	UpdateData(FALSE);

}


void CDlgTufenbiao31::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}


BOOL CDlgTufenbiao31::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_list31.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_list31.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_list31.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_list31.SetExtendedStyle(m_list31.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
BOOL CDlgTufenbiao31::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysql31);
	//�������ݿ�����ʽ
	mysql_options(&m_mysql31, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysql31, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgTufenbiao31::InsertDB()
{
	UpdateData(TRUE);
	if (m_name31.IsEmpty() || m_mianji31.IsEmpty() || m_zhanbi31.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_name31.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_mianji31.GetBuffer();
	char* zhanbi = (char*)m_zhanbi31.GetBuffer();

	sprintf(query31, "insert into tufen31 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysql31, query31))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgTufenbiao31::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_list31.GetItemCount();

	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_list31.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_list31.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(query31, "delete from tufen31 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysql31, query31))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_list31.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgTufenbiao31::SelectDB()
{

	sprintf(query31, "select * from tufen31");
	//��ѯ����
	if (mysql_query(&m_mysql31, query31))
		return FALSE;
	//��ȡ�����
	m_res31 = mysql_store_result(&m_mysql31);
	return TRUE;
}

void CDlgTufenbiao31::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_row31 = mysql_fetch_row(m_res31))
	{
		m_data[i].push_back(m_row31[0]);
		m_data[i].push_back(m_row31[1]);
		m_data[i].push_back(m_row31[2]);
		i++;
	}
}

void CDlgTufenbiao31::ShowInfo()
{
	m_list31.DeleteAllItems();
	for (int i = 0; i<m_res31->row_count; i++)
	{
		int iCount = m_list31.GetItemCount();

		m_list31.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysql31.field_count; j++)//number of columns in result set

			m_list31.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgTufenbiao31::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgTufenbiao31::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_res31);
	//�ر����ݿ�
	mysql_close(&m_mysql31);
}


