// DlgZhifenbiao41.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhifenbiao41.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysqlz41;			//���ݿ�ṹ
MYSQL_RES* m_resz41;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_rowz41;          //��ȡÿһ����¼
char queryz41[150]; //��ѯ���

// CDlgZhifenbiao41 �Ի���

IMPLEMENT_DYNAMIC(CDlgZhifenbiao41, CDialogEx)

CDlgZhifenbiao41::CDlgZhifenbiao41(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIFENBIAO41, pParent)
	, m_zhiname41(_T(""))
	, m_zhimianji41(_T(""))
	, m_zhizhanbi41(_T(""))
{

}

CDlgZhifenbiao41::~CDlgZhifenbiao41()
{
}

void CDlgZhifenbiao41::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_zhilist41);
	DDX_Text(pDX, IDC_EDIT2, m_zhiname41);
	DDX_Text(pDX, IDC_EDIT1, m_zhimianji41);
	DDX_Text(pDX, IDC_EDIT5, m_zhizhanbi41);
}


BEGIN_MESSAGE_MAP(CDlgZhifenbiao41, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgZhifenbiao41::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgZhifenbiao41::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgZhifenbiao41 ��Ϣ�������


BOOL CDlgZhifenbiao41::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_zhilist41.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_zhilist41.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_zhilist41.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_zhilist41.SetExtendedStyle(m_zhilist41.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CDlgZhifenbiao41::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_zhiname41.Empty();
	m_zhimianji41.Empty();
	m_zhizhanbi41.Empty();
	UpdateData(FALSE);
}


void CDlgZhifenbiao41::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}
BOOL CDlgZhifenbiao41::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysqlz41);
	//�������ݿ�����ʽ
	mysql_options(&m_mysqlz41, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysqlz41, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgZhifenbiao41::InsertDB()
{
	UpdateData(TRUE);
	if (m_zhiname41.IsEmpty() || m_zhimianji41.IsEmpty() || m_zhizhanbi41.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_zhiname41.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_zhimianji41.GetBuffer();
	char* zhanbi = (char*)m_zhizhanbi41.GetBuffer();

	sprintf(queryz41, "insert into zhifen41 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysqlz41, queryz41))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgZhifenbiao41::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_zhilist41.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_zhilist41.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_zhilist41.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(queryz41, "delete from zhifen41 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysqlz41, queryz41))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_zhilist41.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgZhifenbiao41::SelectDB()
{

	sprintf(queryz41, "select * from zhifen41");
	//��ѯ����
	if (mysql_query(&m_mysqlz41, queryz41))
		return FALSE;
	//��ȡ�����
	m_resz41 = mysql_store_result(&m_mysqlz41);
	return TRUE;
}

void CDlgZhifenbiao41::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_rowz41 = mysql_fetch_row(m_resz41))
	{
		m_data[i].push_back(m_rowz41[0]);
		m_data[i].push_back(m_rowz41[1]);
		m_data[i].push_back(m_rowz41[2]);
		i++;
	}
}

void CDlgZhifenbiao41::ShowInfo()
{
	m_zhilist41.DeleteAllItems();
	for (int i = 0; i<m_resz41->row_count; i++)
	{
		int iCount = m_zhilist41.GetItemCount();

		m_zhilist41.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysqlz41.field_count; j++)//number of columns in result set

			m_zhilist41.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgZhifenbiao41::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgZhifenbiao41::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_resz41);
	//�ر����ݿ�
	mysql_close(&m_mysqlz41);
}
