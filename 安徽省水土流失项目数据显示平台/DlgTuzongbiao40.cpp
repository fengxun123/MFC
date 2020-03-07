// DlgTuzongbiao40.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgTuzongbiao40.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"

MYSQL m_mysql40;			//数据库结构
MYSQL_RES* m_res40;         //查询的返回结果集
MYSQL_ROW m_row40;          //获取每一条记录
char query40[150]; //查询语句

// CDlgTuzongbiao40 对话框

IMPLEMENT_DYNAMIC(CDlgTuzongbiao40, CDialogEx)

CDlgTuzongbiao40::CDlgTuzongbiao40(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUZONGBIAO40, pParent)
	, m_name40(_T(""))
	, m_mianji40(_T(""))
	, m_zhanbi40(_T(""))
{

}

CDlgTuzongbiao40::~CDlgTuzongbiao40()
{
}

void CDlgTuzongbiao40::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list40);
	DDX_Text(pDX, IDC_EDIT2, m_name40);
	DDX_Text(pDX, IDC_EDIT1, m_mianji40);
	DDX_Text(pDX, IDC_EDIT5, m_zhanbi40);
}


BEGIN_MESSAGE_MAP(CDlgTuzongbiao40, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTuzongbiao40::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTuzongbiao40::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgTuzongbiao40 消息处理程序


void CDlgTuzongbiao40::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	InsertDB();				   //插入数据
	UpdateData(FALSE);//添加纪录后显示出来
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//添加完后清空编辑框
	m_name40.Empty();
	m_mianji40.Empty();
	m_zhanbi40.Empty();
	UpdateData(FALSE);
}


void CDlgTuzongbiao40::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	DeleteDB();
}


BOOL CDlgTuzongbiao40::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//设置表头
	CString str[] = { TEXT("名称"), TEXT("面积"), TEXT("占比") };
	m_list40.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_list40.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_list40.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_list40.SetExtendedStyle(m_list40.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
BOOL CDlgTuzongbiao40::ConnectDB()
{

	//初始化数据库
	mysql_init(&m_mysql40);
	//设置数据库编码格式
	mysql_options(&m_mysql40, MYSQL_SET_CHARSET_NAME, "gbk");
	//连接数据库
	if (!mysql_real_connect(&m_mysql40, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgTuzongbiao40::InsertDB()
{
	UpdateData(TRUE);
	if (m_name40.IsEmpty() || m_mianji40.IsEmpty() || m_zhanbi40.IsEmpty())
	{
		AfxMessageBox(TEXT("插入缺少值！不能为空"));
		return FALSE;
	}
	char* name = (char*)m_name40.GetBuffer();//将CString转换为char *
	char* mianji = (char*)m_mianji40.GetBuffer();
	char* zhanbi = (char*)m_zhanbi40.GetBuffer();

	sprintf(query40, "insert into tuzong3 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysql40, query40))
	{
		AfxMessageBox(TEXT("插入数据失败！"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgTuzongbiao40::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_list40.GetItemCount();

	int j = 0;
	//可以多选然后删除
	for (int i = iCount; i >= 0; i--)
	{
		if (m_list40.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_list40.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(query40, "delete from tuzong3 where 名称=\'%s\';", tname);
			if (mysql_query(&m_mysql40, query40))
			{
				AfxMessageBox(TEXT("删除数据失败！"));
				return FALSE;
			}
			//要先删除数据库的记录后才能删除列表中的项，否则GetItemText会返回空
			m_list40.DeleteItem(i);//删除列表中的项
		}
	}
	return TRUE;
}

BOOL CDlgTuzongbiao40::SelectDB()
{

	sprintf(query40, "select * from tuzong3");
	//查询数据
	if (mysql_query(&m_mysql40, query40))
		return FALSE;
	//获取结果集
	m_res40 = mysql_store_result(&m_mysql40);
	return TRUE;
}

void CDlgTuzongbiao40::GetDataFromDB()
{
	//获取记录
	int i = 0;
	while (m_row40 = mysql_fetch_row(m_res40))
	{
		m_data[i].push_back(m_row40[0]);
		m_data[i].push_back(m_row40[1]);
		m_data[i].push_back(m_row40[2]);
		i++;
	}
}

void CDlgTuzongbiao40::ShowInfo()
{
	m_list40.DeleteAllItems();
	for (int i = 0; i<m_res40->row_count; i++)
	{
		int iCount = m_list40.GetItemCount();

		m_list40.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysql40.field_count; j++)//number of columns in result set

			m_list40.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgTuzongbiao40::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgTuzongbiao40::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	//释放结果集
	mysql_free_result(m_res40);
	//关闭数据库
	mysql_close(&m_mysql40);
}


