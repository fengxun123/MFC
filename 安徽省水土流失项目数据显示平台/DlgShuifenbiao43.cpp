// DlgShuifenbiao43.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgShuifenbiao43.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"

// CDlgShuifenbiao43 �Ի���

IMPLEMENT_DYNAMIC(CDlgShuifenbiao43, CDialogEx)

CDlgShuifenbiao43::CDlgShuifenbiao43(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SHUIFENBIAO43, pParent)
{

}

CDlgShuifenbiao43::~CDlgShuifenbiao43()
{
}

void CDlgShuifenbiao43::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_shuilist43);
}


BEGIN_MESSAGE_MAP(CDlgShuifenbiao43, CDialogEx)
END_MESSAGE_MAP()


// CDlgShuifenbiao43 ��Ϣ�������


BOOL CDlgShuifenbiao43::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	MYSQL m_mysql;			//���ݿ�ṹ
	MYSQL_RES* m_res;         //��ѯ�ķ��ؽ����
	MYSQL_ROW m_row;          //��ȡÿһ����¼
	char query[150]; //��ѯ���

					 //���ñ�ͷ
	CString str[] = { TEXT("����"), TEXT("2015��"), TEXT("2017��"),TEXT("ռ��"),TEXT("15��17�仯") };
	m_shuilist43.InsertColumn(0, str[0], LVCFMT_LEFT, 150, -1);
	m_shuilist43.InsertColumn(1, str[1], LVCFMT_LEFT, 80, -1);
	m_shuilist43.InsertColumn(2, str[2], LVCFMT_LEFT, 80, -1);
	m_shuilist43.InsertColumn(3, str[3], LVCFMT_LEFT, 80, -1);
	m_shuilist43.InsertColumn(4, str[4], LVCFMT_LEFT, 80, -1);


	//��ʼ�����ݿ�
	mysql_init(&m_mysql);
	//�������ݿ�����ʽ
	mysql_options(&m_mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	//�������ݿ�
	if (!mysql_real_connect(&m_mysql, "localhost", "root", "12345", "program", 3306, NULL, 0))
	{
		AfxMessageBox(TEXT("�������ݿ�ʧ��"));
		return FALSE;
	}

	sprintf(query, "select * from shuifen43");
	//��ѯ����
	if (mysql_query(&m_mysql, query))
	{
		AfxMessageBox(TEXT("��ѯ���ݿ�ʧ��"));
		return FALSE;

	}
	//��ȡ�����
	m_res = mysql_store_result(&m_mysql);

	int i = 0;
	while (m_row = mysql_fetch_row(m_res))
	{
		m_data[i].push_back(m_row[0]);
		m_data[i].push_back(m_row[1]);
		m_data[i].push_back(m_row[2]);
		m_data[i].push_back(m_row[3]);
		m_data[i].push_back(m_row[4]);
		i++;
	}

	m_shuilist43.DeleteAllItems();
	for (int i = 0; i<m_res->row_count; i++)
	{
		int iCount = m_shuilist43.GetItemCount();

		m_shuilist43.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysql.field_count; j++)//number of columns in result set

			m_shuilist43.SetItemText(iCount, j, m_data[i][j].c_str());
	}

	mysql_free_result(m_res);
	//�ر����ݿ�
	mysql_close(&m_mysql);

	//�������ԣ�����ѡ��״̬����ʾ���
	m_shuilist43.SetExtendedStyle(m_shuilist43.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
