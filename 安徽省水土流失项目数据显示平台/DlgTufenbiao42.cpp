// DlgTufenbiao42.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgTufenbiao42.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"

MYSQL m_mysql42;			//数据库结构
MYSQL_RES* m_res42;         //查询的返回结果集
MYSQL_ROW m_row42;          //获取每一条记录
char query42[150]; //查询语句


// CDlgTufenbiao42 对话框

IMPLEMENT_DYNAMIC(CDlgTufenbiao42, CDialogEx)

CDlgTufenbiao42::CDlgTufenbiao42(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUFENBIAO42, pParent)
	, m_name42(_T(""))
	
	, m_zhanbi42(_T(""))
	, m_mianji42(_T(""))
{

}

CDlgTufenbiao42::~CDlgTufenbiao42()
{
}

void CDlgTufenbiao42::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list42);
	DDX_Text(pDX, IDC_EDIT2, m_name42);
	//  DDX_Text(pDX, IDC_EDIT1, m_mianji41);
	DDX_Text(pDX, IDC_EDIT5, m_zhanbi42);
	DDX_Text(pDX, IDC_EDIT1, m_mianji42);
}


BEGIN_MESSAGE_MAP(CDlgTufenbiao42, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTufenbiao42::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTufenbiao42::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgTufenbiao42 消息处理程序


void CDlgTufenbiao42::OnBnClickedButton1()
{
	UpdateData(TRUE);
	InsertDB();				   //插入数据
	UpdateData(FALSE);//添加纪录后显示出来
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//添加完后清空编辑框
	m_name42.Empty();
	m_mianji42.Empty();
	m_zhanbi42.Empty();
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CDlgTufenbiao42::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	DeleteDB();
}


BOOL CDlgTufenbiao42::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//设置表头
	CString str[] = { TEXT("名称"), TEXT("面积"), TEXT("占比") };
	m_list42.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_list42.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_list42.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);

	//一开始先显示所有数据
	//连接数据库
	if (!ConnectDB())
	{
		AfxMessageBox(TEXT("连接数据库失败"));
		return FALSE;
	}
	//查询数据
	SelectDB();
	//获取数据;
	GetDataFromDB();
	//显示数据
	ShowInfo();

	//设置属性，整行选中状态和显示表格
	m_list42.SetExtendedStyle(m_list42.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
BOOL CDlgTufenbiao42::ConnectDB()
{

	//初始化数据库
	mysql_init(&m_mysql42);
	//设置数据库编码格式
	mysql_options(&m_mysql42, MYSQL_SET_CHARSET_NAME, "gbk");
	//连接数据库
	if (!mysql_real_connect(&m_mysql42, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgTufenbiao42::InsertDB()
{
	UpdateData(TRUE);
	if (m_name42.IsEmpty() || m_mianji42.IsEmpty() || m_zhanbi42.IsEmpty())
	{
		AfxMessageBox(TEXT("插入缺少值！不能为空"));
		return FALSE;
	}
	char* name = (char*)m_name42.GetBuffer();//将CString转换为char *
	char* mianji = (char*)m_mianji42.GetBuffer();
	char* zhanbi = (char*)m_zhanbi42.GetBuffer();

	sprintf(query42, "insert into tufen42 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysql42, query42))
	{
		AfxMessageBox(TEXT("插入数据失败！"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgTufenbiao42::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_list42.GetItemCount();

	int j = 0;
	//可以多选然后删除
	for (int i = iCount; i >= 0; i--)
	{
		if (m_list42.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_list42.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(query42, "delete from tufen42 where 名称=\'%s\';", tname);
			if (mysql_query(&m_mysql42, query42))
			{
				AfxMessageBox(TEXT("删除数据失败！"));
				return FALSE;
			}
			//要先删除数据库的记录后才能删除列表中的项，否则GetItemText会返回空
			m_list42.DeleteItem(i);//删除列表中的项
		}
	}
	return TRUE;
}

BOOL CDlgTufenbiao42::SelectDB()
{

	sprintf(query42, "select * from tufen42");
	//查询数据
	if (mysql_query(&m_mysql42, query42))
		return FALSE;
	//获取结果集
	m_res42 = mysql_store_result(&m_mysql42);
	return TRUE;
}

void CDlgTufenbiao42::GetDataFromDB()
{
	//获取记录
	int i = 0;
	while (m_row42 = mysql_fetch_row(m_res42))
	{
		m_data[i].push_back(m_row42[0]);
		m_data[i].push_back(m_row42[1]);
		m_data[i].push_back(m_row42[2]);
		i++;
	}
}

void CDlgTufenbiao42::ShowInfo()
{
	m_list42.DeleteAllItems();
	for (int i = 0; i<m_res42->row_count; i++)
	{
		int iCount = m_list42.GetItemCount();

		m_list42.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysql42.field_count; j++)//number of columns in result set

			m_list42.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgTufenbiao42::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgTufenbiao42::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	//释放结果集
	mysql_free_result(m_res42);
	//关闭数据库
	mysql_close(&m_mysql42);
}





