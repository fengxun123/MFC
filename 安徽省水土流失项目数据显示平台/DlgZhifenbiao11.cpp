// DlgZhifenbiao11.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhifenbiao11.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysqlz11;			//���ݿ�ṹ
MYSQL_RES* m_resz11;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_rowz11;          //��ȡÿһ����¼
char queryz11[150]; //��ѯ���

// CDlgZhifenbiao11 �Ի���

IMPLEMENT_DYNAMIC(CDlgZhifenbiao11, CDialogEx)

CDlgZhifenbiao11::CDlgZhifenbiao11(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIFENBIAO11, pParent)
	, m_zhiname11(_T(""))
	, m_zhimianji11(_T(""))
	, m_zhizhanbi11(_T(""))
{

}

CDlgZhifenbiao11::~CDlgZhifenbiao11()
{
}

void CDlgZhifenbiao11::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_zhilist11);
	DDX_Text(pDX, IDC_EDIT2, m_zhiname11);
	DDX_Text(pDX, IDC_EDIT1, m_zhimianji11);
	DDX_Text(pDX, IDC_EDIT5, m_zhizhanbi11);
}


BEGIN_MESSAGE_MAP(CDlgZhifenbiao11, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgZhifenbiao11::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgZhifenbiao11::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgZhifenbiao11 ��Ϣ�������


void CDlgZhifenbiao11::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_zhiname11.Empty();
	m_zhimianji11.Empty();
	m_zhizhanbi11.Empty();
	UpdateData(FALSE);
}


void CDlgZhifenbiao11::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}


BOOL CDlgZhifenbiao11::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_zhilist11.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_zhilist11.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_zhilist11.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_zhilist11.SetExtendedStyle(m_zhilist11.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
BOOL CDlgZhifenbiao11::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysqlz11);
	//�������ݿ�����ʽ
	mysql_options(&m_mysqlz11, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysqlz11, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgZhifenbiao11::InsertDB()
{
	UpdateData(TRUE);
	if (m_zhiname11.IsEmpty() || m_zhimianji11.IsEmpty() || m_zhizhanbi11.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_zhiname11.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_zhimianji11.GetBuffer();
	char* zhanbi = (char*)m_zhizhanbi11.GetBuffer();

	sprintf(queryz11, "insert into zhifen11 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysqlz11, queryz11))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgZhifenbiao11::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_zhilist11.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_zhilist11.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_zhilist11.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(queryz11, "delete from zhifen11 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysqlz11, queryz11))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_zhilist11.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgZhifenbiao11::SelectDB()
{

	sprintf(queryz11, "select * from zhifen11");
	//��ѯ����
	if (mysql_query(&m_mysqlz11, queryz11))
		return FALSE;
	//��ȡ�����
	m_resz11 = mysql_store_result(&m_mysqlz11);
	return TRUE;
}

void CDlgZhifenbiao11::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_rowz11 = mysql_fetch_row(m_resz11))
	{
		m_data[i].push_back(m_rowz11[0]);
		m_data[i].push_back(m_rowz11[1]);
		m_data[i].push_back(m_rowz11[2]);
		i++;
	}
}

void CDlgZhifenbiao11::ShowInfo()
{
	m_zhilist11.DeleteAllItems();
	for (int i = 0; i<m_resz11->row_count; i++)
	{
		int iCount = m_zhilist11.GetItemCount();

		m_zhilist11.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysqlz11.field_count; j++)//number of columns in result set

			m_zhilist11.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgZhifenbiao11::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgZhifenbiao11::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_resz11);
	//�ر����ݿ�
	mysql_close(&m_mysqlz11);
}

