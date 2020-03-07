// DlgShuifenbiao43.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgShuifenbiao43.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"

// CDlgShuifenbiao43 对话框

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


// CDlgShuifenbiao43 消息处理程序


BOOL CDlgShuifenbiao43::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	MYSQL m_mysql;			//数据库结构
	MYSQL_RES* m_res;         //查询的返回结果集
	MYSQL_ROW m_row;          //获取每一条记录
	char query[150]; //查询语句

					 //设置表头
	CString str[] = { TEXT("名称"), TEXT("2015年"), TEXT("2017年"),TEXT("占比"),TEXT("15至17变化") };
	m_shuilist43.InsertColumn(0, str[0], LVCFMT_LEFT, 150, -1);
	m_shuilist43.InsertColumn(1, str[1], LVCFMT_LEFT, 80, -1);
	m_shuilist43.InsertColumn(2, str[2], LVCFMT_LEFT, 80, -1);
	m_shuilist43.InsertColumn(3, str[3], LVCFMT_LEFT, 80, -1);
	m_shuilist43.InsertColumn(4, str[4], LVCFMT_LEFT, 80, -1);


	//初始化数据库
	mysql_init(&m_mysql);
	//设置数据库编码格式
	mysql_options(&m_mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	//连接数据库
	if (!mysql_real_connect(&m_mysql, "localhost", "root", "12345", "program", 3306, NULL, 0))
	{
		AfxMessageBox(TEXT("连接数据库失败"));
		return FALSE;
	}

	sprintf(query, "select * from shuifen43");
	//查询数据
	if (mysql_query(&m_mysql, query))
	{
		AfxMessageBox(TEXT("查询数据库失败"));
		return FALSE;

	}
	//获取结果集
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
	//关闭数据库
	mysql_close(&m_mysql);

	//设置属性，整行选中状态和显示表格
	m_shuilist43.SetExtendedStyle(m_shuilist43.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
