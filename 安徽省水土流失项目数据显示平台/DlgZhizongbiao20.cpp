// DlgZhizongbiao20.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgZhizongbiao20.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysqlz20;			//数据库结构
MYSQL_RES* m_resz20;         //查询的返回结果集
MYSQL_ROW m_rowz20;          //获取每一条记录
char queryz20[150]; //查询语句

// CDlgZhizongbiao20 对话框

IMPLEMENT_DYNAMIC(CDlgZhizongbiao20, CDialogEx)

CDlgZhizongbiao20::CDlgZhizongbiao20(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIZONGBIAO20, pParent)
	, m_zhiname20(_T(""))
	, m_zhimianji20(_T(""))
	, m_zhizhanbi20(_T(""))
{

}

CDlgZhizongbiao20::~CDlgZhizongbiao20()
{
}

void CDlgZhizongbiao20::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_zhilist20);
	DDX_Text(pDX, IDC_EDIT2, m_zhiname20);
	DDX_Text(pDX, IDC_EDIT1, m_zhimianji20);
	DDX_Text(pDX, IDC_EDIT5, m_zhizhanbi20);
}


BEGIN_MESSAGE_MAP(CDlgZhizongbiao20, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgZhizongbiao20::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgZhizongbiao20::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgZhizongbiao20 消息处理程序


BOOL CDlgZhizongbiao20::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//设置表头
	CString str[] = { TEXT("名称"), TEXT("面积"), TEXT("占比") };
	m_zhilist20.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_zhilist20.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_zhilist20.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_zhilist20.SetExtendedStyle(m_zhilist20.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgZhizongbiao20::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	InsertDB();				   //插入数据
	UpdateData(FALSE);//添加纪录后显示出来
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//添加完后清空编辑框
	m_zhiname20.Empty();
	m_zhimianji20.Empty();
	m_zhizhanbi20.Empty();
	UpdateData(FALSE);
}



void CDlgZhizongbiao20::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	DeleteDB();
}
BOOL CDlgZhizongbiao20::ConnectDB()
{

	//初始化数据库
	mysql_init(&m_mysqlz20);
	//设置数据库编码格式
	mysql_options(&m_mysqlz20, MYSQL_SET_CHARSET_NAME, "gbk");
	//连接数据库
	if (!mysql_real_connect(&m_mysqlz20, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgZhizongbiao20::InsertDB()
{
	UpdateData(TRUE);
	if (m_zhiname20.IsEmpty() || m_zhimianji20.IsEmpty() || m_zhizhanbi20.IsEmpty())
	{
		AfxMessageBox(TEXT("插入缺少值！不能为空"));
		return FALSE;
	}
	char* name = (char*)m_zhiname20.GetBuffer();//将CString转换为char *
	char* mianji = (char*)m_zhimianji20.GetBuffer();
	char* zhanbi = (char*)m_zhizhanbi20.GetBuffer();

	sprintf(queryz20, "insert into zhizong2 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysqlz20, queryz20))
	{
		AfxMessageBox(TEXT("插入数据失败！"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgZhizongbiao20::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_zhilist20.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//可以多选然后删除
	for (int i = iCount; i >= 0; i--)
	{
		if (m_zhilist20.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_zhilist20.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(queryz20, "delete from zhizong2 where 名称=\'%s\';", tname);
			if (mysql_query(&m_mysqlz20, queryz20))
			{
				AfxMessageBox(TEXT("删除数据失败！"));
				return FALSE;
			}
			//要先删除数据库的记录后才能删除列表中的项，否则GetItemText会返回空
			m_zhilist20.DeleteItem(i);//删除列表中的项
		}
	}
	return TRUE;
}

BOOL CDlgZhizongbiao20::SelectDB()
{

	sprintf(queryz20, "select * from zhizong2");
	//查询数据
	if (mysql_query(&m_mysqlz20, queryz20))
		return FALSE;
	//获取结果集
	m_resz20 = mysql_store_result(&m_mysqlz20);
	return TRUE;
}

void CDlgZhizongbiao20::GetDataFromDB()
{
	//获取记录
	int i = 0;
	while (m_rowz20 = mysql_fetch_row(m_resz20))
	{
		m_data[i].push_back(m_rowz20[0]);
		m_data[i].push_back(m_rowz20[1]);
		m_data[i].push_back(m_rowz20[2]);
		i++;
	}
}

void CDlgZhizongbiao20::ShowInfo()
{
	m_zhilist20.DeleteAllItems();
	for (int i = 0; i<m_resz20->row_count; i++)
	{
		int iCount = m_zhilist20.GetItemCount();

		m_zhilist20.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysqlz20.field_count; j++)//number of columns in result set

			m_zhilist20.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgZhizongbiao20::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgZhizongbiao20::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	//释放结果集
	mysql_free_result(m_resz20);
	//关闭数据库
	mysql_close(&m_mysqlz20);
}

