// DlgZhifenbiao43.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhifenbiao43.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysqlz43;			//���ݿ�ṹ
MYSQL_RES* m_resz43;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_rowz43;          //��ȡÿһ����¼
char queryz43[150]; //��ѯ���

// CDlgZhifenbiao43 �Ի���

IMPLEMENT_DYNAMIC(CDlgZhifenbiao43, CDialogEx)

CDlgZhifenbiao43::CDlgZhifenbiao43(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIFENBIAO43, pParent)
	, m_zhiname43(_T(""))
	, m_zhimianji43(_T(""))
	, m_zhizhanbi43(_T(""))
{

}

CDlgZhifenbiao43::~CDlgZhifenbiao43()
{
}

void CDlgZhifenbiao43::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_zhilist43);
	DDX_Text(pDX, IDC_EDIT2, m_zhiname43);
	DDX_Text(pDX, IDC_EDIT1, m_zhimianji43);
	DDX_Text(pDX, IDC_EDIT5, m_zhizhanbi43);
}


BEGIN_MESSAGE_MAP(CDlgZhifenbiao43, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgZhifenbiao43::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgZhifenbiao43::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgZhifenbiao43 ��Ϣ�������


void CDlgZhifenbiao43::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_zhiname43.Empty();
	m_zhimianji43.Empty();
	m_zhizhanbi43.Empty();
	UpdateData(FALSE);
}


void CDlgZhifenbiao43::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}


BOOL CDlgZhifenbiao43::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_zhilist43.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_zhilist43.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_zhilist43.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_zhilist43.SetExtendedStyle(m_zhilist43.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
BOOL CDlgZhifenbiao43::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysqlz43);
	//�������ݿ�����ʽ
	mysql_options(&m_mysqlz43, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysqlz43, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgZhifenbiao43::InsertDB()
{
	UpdateData(TRUE);
	if (m_zhiname43.IsEmpty() || m_zhimianji43.IsEmpty() || m_zhizhanbi43.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_zhiname43.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_zhimianji43.GetBuffer();
	char* zhanbi = (char*)m_zhizhanbi43.GetBuffer();

	sprintf(queryz43, "insert into zhifen43 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysqlz43, queryz43))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgZhifenbiao43::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_zhilist43.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_zhilist43.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_zhilist43.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(queryz43, "delete from zhifen43 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysqlz43, queryz43))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_zhilist43.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgZhifenbiao43::SelectDB()
{

	sprintf(queryz43, "select * from zhifen43");
	//��ѯ����
	if (mysql_query(&m_mysqlz43, queryz43))
		return FALSE;
	//��ȡ�����
	m_resz43 = mysql_store_result(&m_mysqlz43);
	return TRUE;
}

void CDlgZhifenbiao43::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_rowz43 = mysql_fetch_row(m_resz43))
	{
		m_data[i].push_back(m_rowz43[0]);
		m_data[i].push_back(m_rowz43[1]);
		m_data[i].push_back(m_rowz43[2]);
		i++;
	}
}

void CDlgZhifenbiao43::ShowInfo()
{
	m_zhilist43.DeleteAllItems();
	for (int i = 0; i<m_resz43->row_count; i++)
	{
		int iCount = m_zhilist43.GetItemCount();

		m_zhilist43.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysqlz43.field_count; j++)//number of columns in result set

			m_zhilist43.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgZhifenbiao43::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgZhifenbiao43::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_resz43);
	//�ر����ݿ�
	mysql_close(&m_mysqlz43);
}
