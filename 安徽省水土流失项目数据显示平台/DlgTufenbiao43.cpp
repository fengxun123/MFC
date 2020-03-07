// DlgTufenbiao43.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgTufenbiao43.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"

MYSQL m_mysql43;			//���ݿ�ṹ
MYSQL_RES* m_res43;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_row43;          //��ȡÿһ����¼
char query43[150]; //��ѯ���


// CDlgTufenbiao43 �Ի���

IMPLEMENT_DYNAMIC(CDlgTufenbiao43, CDialogEx)

CDlgTufenbiao43::CDlgTufenbiao43(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUFENBIAO43, pParent)
	, m_name43(_T(""))
	, m_mianji43(_T(""))
	, m_zhanbi43(_T(""))
{

}

CDlgTufenbiao43::~CDlgTufenbiao43()
{
}

void CDlgTufenbiao43::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_name43);
	DDX_Text(pDX, IDC_EDIT1, m_mianji43);
	DDX_Text(pDX, IDC_EDIT5, m_zhanbi43);
	DDX_Control(pDX, IDC_LIST1, m_list43);
}


BEGIN_MESSAGE_MAP(CDlgTufenbiao43, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTufenbiao43::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTufenbiao43::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgTufenbiao43 ��Ϣ�������


void CDlgTufenbiao43::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_name43.Empty();
	m_mianji43.Empty();
	m_zhanbi43.Empty();
	UpdateData(FALSE);
}


void CDlgTufenbiao43::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}


BOOL CDlgTufenbiao43::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_list43.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_list43.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_list43.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_list43.SetExtendedStyle(m_list43.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
BOOL CDlgTufenbiao43::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysql43);
	//�������ݿ�����ʽ
	mysql_options(&m_mysql43, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysql43, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgTufenbiao43::InsertDB()
{
	UpdateData(TRUE);
	if (m_name43.IsEmpty() || m_mianji43.IsEmpty() || m_zhanbi43.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_name43.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_mianji43.GetBuffer();
	char* zhanbi = (char*)m_zhanbi43.GetBuffer();

	sprintf(query43, "insert into tufen43 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysql43, query43))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgTufenbiao43::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_list43.GetItemCount();

	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_list43.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_list43.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(query43, "delete from tufen43 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysql43, query43))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_list43.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgTufenbiao43::SelectDB()
{

	sprintf(query43, "select * from tufen43");
	//��ѯ����
	if (mysql_query(&m_mysql43, query43))
		return FALSE;
	//��ȡ�����
	m_res43 = mysql_store_result(&m_mysql43);
	return TRUE;
}

void CDlgTufenbiao43::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_row43 = mysql_fetch_row(m_res43))
	{
		m_data[i].push_back(m_row43[0]);
		m_data[i].push_back(m_row43[1]);
		m_data[i].push_back(m_row43[2]);
		i++;
	}
}

void CDlgTufenbiao43::ShowInfo()
{
	m_list43.DeleteAllItems();
	for (int i = 0; i<m_res43->row_count; i++)
	{
		int iCount = m_list43.GetItemCount();

		m_list43.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysql43.field_count; j++)//number of columns in result set

			m_list43.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgTufenbiao43::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgTufenbiao43::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_res43);
	//�ر����ݿ�
	mysql_close(&m_mysql43);
}


