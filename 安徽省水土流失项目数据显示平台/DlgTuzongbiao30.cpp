// DlgTuzongbiao30.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgTuzongbiao30.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"

MYSQL m_mysql30;			//���ݿ�ṹ
MYSQL_RES* m_res30;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_row30;          //��ȡÿһ����¼
char query30[150]; //��ѯ���

// CDlgTuzongbiao30 �Ի���

IMPLEMENT_DYNAMIC(CDlgTuzongbiao30, CDialogEx)

CDlgTuzongbiao30::CDlgTuzongbiao30(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUZONGBIAO30, pParent)
	, m_name30(_T(""))
	, m_mianji30(_T(""))
	, m_zhanbi30(_T(""))
{

}

CDlgTuzongbiao30::~CDlgTuzongbiao30()
{
}

void CDlgTuzongbiao30::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_name30);
	DDX_Text(pDX, IDC_EDIT1, m_mianji30);
	DDX_Text(pDX, IDC_EDIT5, m_zhanbi30);
	DDX_Control(pDX, IDC_LIST1, m_list30);
}


BEGIN_MESSAGE_MAP(CDlgTuzongbiao30, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTuzongbiao30::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTuzongbiao30::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgTuzongbiao30 ��Ϣ�������


void CDlgTuzongbiao30::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_name30.Empty();
	m_mianji30.Empty();
	m_zhanbi30.Empty();
	UpdateData(FALSE);
}


void CDlgTuzongbiao30::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}


BOOL CDlgTuzongbiao30::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_list30.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_list30.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_list30.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_list30.SetExtendedStyle(m_list30.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
BOOL CDlgTuzongbiao30::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysql30);
	//�������ݿ�����ʽ
	mysql_options(&m_mysql30, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysql30, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgTuzongbiao30::InsertDB()
{
	UpdateData(TRUE);
	if (m_name30.IsEmpty() || m_mianji30.IsEmpty() || m_zhanbi30.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_name30.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_mianji30.GetBuffer();
	char* zhanbi = (char*)m_zhanbi30.GetBuffer();

	sprintf(query30, "insert into tuzong2 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysql30, query30))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgTuzongbiao30::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_list30.GetItemCount();
	
	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_list30.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_list30.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(query30, "delete from tuzong2 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysql30, query30))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_list30.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgTuzongbiao30::SelectDB()
{

	sprintf(query30, "select * from tuzong2");
	//��ѯ����
	if (mysql_query(&m_mysql30, query30))
		return FALSE;
	//��ȡ�����
	m_res30 = mysql_store_result(&m_mysql30);
	return TRUE;
}

void CDlgTuzongbiao30::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_row30 = mysql_fetch_row(m_res30))
	{
		m_data[i].push_back(m_row30[0]);
		m_data[i].push_back(m_row30[1]);
		m_data[i].push_back(m_row30[2]);
		i++;
	}
}

void CDlgTuzongbiao30::ShowInfo()
{
	m_list30.DeleteAllItems();
	for (int i = 0; i<m_res30->row_count; i++)
	{
		int iCount = m_list30.GetItemCount();

		m_list30.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysql30.field_count; j++)//number of columns in result set

			m_list30.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgTuzongbiao30::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgTuzongbiao30::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_res30);
	//�ر����ݿ�
	mysql_close(&m_mysql30);
}


