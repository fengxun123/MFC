// DlgTuzongbiao20.cpp : 实现文件
//

#include "stdafx.h" 

#ifdef _MSC_VER
#ifdef _WIN64
#include <WinSock2.h>
#elif _WIN32
#include <winsock.h>
#endif
#endif

#include "安徽省水土流失项目数据显示平台.h"
#include "DlgTuzongbiao20.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysql20;			//数据库结构
MYSQL_RES* m_res20;         //查询的返回结果集
MYSQL_ROW m_row20;          //获取每一条记录
char query20[150]; //查询语句

// CDlgTuzongbiao20 对话框

IMPLEMENT_DYNAMIC(CDlgTuzongbiao20, CDialogEx)

CDlgTuzongbiao20::CDlgTuzongbiao20(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUZONGBIAO20, pParent)
	, m_name20(_T(""))
	, m_mianji20(_T(""))
	, m_zhanbi20(_T(""))
{

}

CDlgTuzongbiao20::~CDlgTuzongbiao20()
{
}

void CDlgTuzongbiao20::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_name20);
	DDX_Text(pDX, IDC_EDIT1, m_mianji20);
	DDX_Text(pDX, IDC_EDIT5, m_zhanbi20);
	//  DDX_Control(pDX, IDC_LIST1, m_list20);
	DDX_Control(pDX, IDC_LIST1, m_list20);
}


BEGIN_MESSAGE_MAP(CDlgTuzongbiao20, CDialogEx)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTuzongbiao20::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTuzongbiao20::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDlgTuzongbiao20 消息处理程序


BOOL CDlgTuzongbiao20::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//设置表头
	CString str[] = { TEXT("名称"), TEXT("面积"), TEXT("占比") };
	m_list20.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_list20.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_list20.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_list20.SetExtendedStyle(m_list20.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgTuzongbiao20::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	InsertDB();				   //插入数据
	UpdateData(FALSE);//添加纪录后显示出来
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//添加完后清空编辑框
	m_name20.Empty();
	m_mianji20.Empty();
	m_zhanbi20.Empty();
	UpdateData(FALSE);
}


void CDlgTuzongbiao20::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	DeleteDB();
}

BOOL CDlgTuzongbiao20::ConnectDB()
{

	//初始化数据库
	mysql_init(&m_mysql20);
	//设置数据库编码格式
	mysql_options(&m_mysql20, MYSQL_SET_CHARSET_NAME, "gbk");
	//连接数据库
	if (!mysql_real_connect(&m_mysql20, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgTuzongbiao20::InsertDB()
{
	UpdateData(TRUE);
	if (m_name20.IsEmpty() || m_mianji20.IsEmpty() || m_zhanbi20.IsEmpty())
	{
		AfxMessageBox(TEXT("插入缺少值！不能为空"));
		return FALSE;
	}
	char* name = (char*)m_name20.GetBuffer();//将CString转换为char *
	char* mianji = (char*)m_mianji20.GetBuffer();
	char* zhanbi = (char*)m_zhanbi20.GetBuffer();

	sprintf(query20, "insert into tuzong1 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysql20, query20))
	{
		AfxMessageBox(TEXT("插入数据失败！"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgTuzongbiao20::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_list20.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//可以多选然后删除
	for (int i = iCount; i >= 0; i--)
	{
		if (m_list20.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_list20.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(query20, "delete from tuzong1 where 名称=\'%s\';", tname);
			if (mysql_query(&m_mysql20, query20))
			{
				AfxMessageBox(TEXT("删除数据失败！"));
				return FALSE;
			}
			//要先删除数据库的记录后才能删除列表中的项，否则GetItemText会返回空
			m_list20.DeleteItem(i);//删除列表中的项
		}
	}
	return TRUE;
}

BOOL CDlgTuzongbiao20::SelectDB()
{

	sprintf(query20, "select * from tuzong1");
	//查询数据
	if (mysql_query(&m_mysql20, query20))
		return FALSE;
	//获取结果集
	m_res20 = mysql_store_result(&m_mysql20);
	return TRUE;
}

void CDlgTuzongbiao20::GetDataFromDB()
{
	//获取记录
	int i = 0;
	while (m_row20 = mysql_fetch_row(m_res20))
	{
		m_data[i].push_back(m_row20[0]);
		m_data[i].push_back(m_row20[1]);
		m_data[i].push_back(m_row20[2]);
		i++;
	}
}

void CDlgTuzongbiao20::ShowInfo()
{
	m_list20.DeleteAllItems();
	for (int i = 0; i<m_res20->row_count; i++)
	{
		int iCount = m_list20.GetItemCount();

		m_list20.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysql20.field_count; j++)//number of columns in result set

			m_list20.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgTuzongbiao20::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgTuzongbiao20::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	//释放结果集
	mysql_free_result(m_res20);
	//关闭数据库
	mysql_close(&m_mysql20);
}

