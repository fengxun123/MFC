// DlgZhifenbiao13.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhifenbiao13.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysqlz13;			//���ݿ�ṹ
MYSQL_RES* m_resz13;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_rowz13;          //��ȡÿһ����¼
char queryz13[150]; //��ѯ���


// CDlgZhifenbiao13 �Ի���

IMPLEMENT_DYNAMIC(CDlgZhifenbiao13, CDialogEx)

CDlgZhifenbiao13::CDlgZhifenbiao13(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIFENBIAO13, pParent)
	, m_zhiname13(_T(""))
	, m_zhimianji13(_T(""))
	, m_zhizhanbi13(_T(""))
{

}

CDlgZhifenbiao13::~CDlgZhifenbiao13()
{
}

void CDlgZhifenbiao13::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_zhilist13);
	DDX_Text(pDX, IDC_EDIT2, m_zhiname13);
	DDX_Text(pDX, IDC_EDIT1, m_zhimianji13);
	DDX_Text(pDX, IDC_EDIT5, m_zhizhanbi13);
}


BEGIN_MESSAGE_MAP(CDlgZhifenbiao13, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgZhifenbiao13::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgZhifenbiao13::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgZhifenbiao13 ��Ϣ�������


BOOL CDlgZhifenbiao13::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_zhilist13.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_zhilist13.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_zhilist13.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_zhilist13.SetExtendedStyle(m_zhilist13.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CDlgZhifenbiao13::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_zhiname13.Empty();
	m_zhimianji13.Empty();
	m_zhizhanbi13.Empty();
	UpdateData(FALSE);
}


void CDlgZhifenbiao13::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}
BOOL CDlgZhifenbiao13::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysqlz13);
	//�������ݿ�����ʽ
	mysql_options(&m_mysqlz13, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysqlz13, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgZhifenbiao13::InsertDB()
{
	UpdateData(TRUE);
	if (m_zhiname13.IsEmpty() || m_zhimianji13.IsEmpty() || m_zhizhanbi13.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_zhiname13.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_zhimianji13.GetBuffer();
	char* zhanbi = (char*)m_zhizhanbi13.GetBuffer();

	sprintf(queryz13, "insert into zhifen13 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysqlz13, queryz13))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgZhifenbiao13::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_zhilist13.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_zhilist13.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_zhilist13.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(queryz13, "delete from zhifen13 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysqlz13, queryz13))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_zhilist13.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgZhifenbiao13::SelectDB()
{

	sprintf(queryz13, "select * from zhifen13");
	//��ѯ����
	if (mysql_query(&m_mysqlz13, queryz13))
		return FALSE;
	//��ȡ�����
	m_resz13 = mysql_store_result(&m_mysqlz13);
	return TRUE;
}

void CDlgZhifenbiao13::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_rowz13 = mysql_fetch_row(m_resz13))
	{
		m_data[i].push_back(m_rowz13[0]);
		m_data[i].push_back(m_rowz13[1]);
		m_data[i].push_back(m_rowz13[2]);
		i++;
	}
}

void CDlgZhifenbiao13::ShowInfo()
{
	m_zhilist13.DeleteAllItems();
	for (int i = 0; i<m_resz13->row_count; i++)
	{
		int iCount = m_zhilist13.GetItemCount();

		m_zhilist13.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysqlz13.field_count; j++)//number of columns in result set

			m_zhilist13.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgZhifenbiao13::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgZhifenbiao13::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_resz13);
	//�ر����ݿ�
	mysql_close(&m_mysqlz13);
}