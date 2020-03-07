// DlgZhizongbiao30.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhizongbiao30.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysqlz30;			//���ݿ�ṹ
MYSQL_RES* m_resz30;         //��ѯ�ķ��ؽ����
MYSQL_ROW m_rowz30;          //��ȡÿһ����¼
char queryz30[150]; //��ѯ���

// CDlgZhizongbiao30 �Ի���

IMPLEMENT_DYNAMIC(CDlgZhizongbiao30, CDialogEx)

CDlgZhizongbiao30::CDlgZhizongbiao30(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIZONGBIAO30, pParent)
	, m_zhiname30(_T(""))
	, m_zhimianji30(_T(""))
	, m_zhizhanbi30(_T(""))
{

}

CDlgZhizongbiao30::~CDlgZhizongbiao30()
{
}

void CDlgZhizongbiao30::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_zhilist30);
	DDX_Text(pDX, IDC_EDIT2, m_zhiname30);
	DDX_Text(pDX, IDC_EDIT1, m_zhimianji30);
	DDX_Text(pDX, IDC_EDIT5, m_zhizhanbi30);
}


BEGIN_MESSAGE_MAP(CDlgZhizongbiao30, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgZhizongbiao30::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgZhizongbiao30::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgZhizongbiao30 ��Ϣ�������


BOOL CDlgZhizongbiao30::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("���"), TEXT("ռ��") };
	m_zhilist30.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_zhilist30.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_zhilist30.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_zhilist30.SetExtendedStyle(m_zhilist30.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CDlgZhizongbiao30::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	InsertDB();				   //��������
	UpdateData(FALSE);//��Ӽ�¼����ʾ����
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//��������ձ༭��
	m_zhiname30.Empty();
	m_zhimianji30.Empty();
	m_zhizhanbi30.Empty();
	UpdateData(FALSE);
}


void CDlgZhizongbiao30::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	DeleteDB();
}
BOOL CDlgZhizongbiao30::ConnectDB()
{

	//��ʼ�����ݿ�
	mysql_init(&m_mysqlz30);
	//�������ݿ�����ʽ
	mysql_options(&m_mysqlz30, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysqlz30, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgZhizongbiao30::InsertDB()
{
	UpdateData(TRUE);
	if (m_zhiname30.IsEmpty() || m_zhimianji30.IsEmpty() || m_zhizhanbi30.IsEmpty())
	{
		AfxMessageBox(TEXT("����ȱ��ֵ������Ϊ��"));
		return FALSE;
	}
	char* name = (char*)m_zhiname30.GetBuffer();//��CStringת��Ϊchar *
	char* mianji = (char*)m_zhimianji30.GetBuffer();
	char* zhanbi = (char*)m_zhizhanbi30.GetBuffer();

	sprintf(queryz30, "insert into zhizong3 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysqlz30, queryz30))
	{
		AfxMessageBox(TEXT("��������ʧ�ܣ�"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgZhizongbiao30::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_zhilist30.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//���Զ�ѡȻ��ɾ��
	for (int i = iCount; i >= 0; i--)
	{
		if (m_zhilist30.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_zhilist30.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(queryz30, "delete from zhizong3 where ����=\'%s\';", tname);
			if (mysql_query(&m_mysqlz30, queryz30))
			{
				AfxMessageBox(TEXT("ɾ������ʧ�ܣ�"));
				return FALSE;
			}
			//Ҫ��ɾ�����ݿ�ļ�¼�����ɾ���б��е������GetItemText�᷵�ؿ�
			m_zhilist30.DeleteItem(i);//ɾ���б��е���
		}
	}
	return TRUE;
}

BOOL CDlgZhizongbiao30::SelectDB()
{

	sprintf(queryz30, "select * from zhizong3");
	//��ѯ����
	if (mysql_query(&m_mysqlz30, queryz30))
		return FALSE;
	//��ȡ�����
	m_resz30 = mysql_store_result(&m_mysqlz30);
	return TRUE;
}

void CDlgZhizongbiao30::GetDataFromDB()
{
	//��ȡ��¼
	int i = 0;
	while (m_rowz30 = mysql_fetch_row(m_resz30))
	{
		m_data[i].push_back(m_rowz30[0]);
		m_data[i].push_back(m_rowz30[1]);
		m_data[i].push_back(m_rowz30[2]);
		i++;
	}
}

void CDlgZhizongbiao30::ShowInfo()
{
	m_zhilist30.DeleteAllItems();
	for (int i = 0; i<m_resz30->row_count; i++)
	{
		int iCount = m_zhilist30.GetItemCount();

		m_zhilist30.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysqlz30.field_count; j++)//number of columns in result set

			m_zhilist30.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgZhizongbiao30::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgZhizongbiao30::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	//�ͷŽ����
	mysql_free_result(m_resz30);
	//�ر����ݿ�
	mysql_close(&m_mysqlz30);
}

