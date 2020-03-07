// DlgZhifenbiao31.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgZhifenbiao31.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysqlz31;			//数据库结构
MYSQL_RES* m_resz31;         //查询的返回结果集
MYSQL_ROW m_rowz31;          //获取每一条记录
char queryz31[150]; //查询语句

// CDlgZhifenbiao31 对话框

IMPLEMENT_DYNAMIC(CDlgZhifenbiao31, CDialogEx)

CDlgZhifenbiao31::CDlgZhifenbiao31(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIFENBIAO31, pParent)
	, m_zhiname31(_T(""))
	, m_zhimianji31(_T(""))
	, m_zhizhanbi31(_T(""))
{

}

CDlgZhifenbiao31::~CDlgZhifenbiao31()
{
}

void CDlgZhifenbiao31::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_zhilist31);
	DDX_Text(pDX, IDC_EDIT2, m_zhiname31);
	DDX_Text(pDX, IDC_EDIT1, m_zhimianji31);
	DDX_Text(pDX, IDC_EDIT5, m_zhizhanbi31);
}


BEGIN_MESSAGE_MAP(CDlgZhifenbiao31, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgZhifenbiao31::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgZhifenbiao31::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgZhifenbiao31 消息处理程序


BOOL CDlgZhifenbiao31::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//设置表头
	CString str[] = { TEXT("名称"), TEXT("面积"), TEXT("占比") };
	m_zhilist31.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_zhilist31.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_zhilist31.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_zhilist31.SetExtendedStyle(m_zhilist31.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgZhifenbiao31::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	InsertDB();				   //插入数据
	UpdateData(FALSE);//添加纪录后显示出来
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//添加完后清空编辑框
	m_zhiname31.Empty();
	m_zhimianji31.Empty();
	m_zhizhanbi31.Empty();
	UpdateData(FALSE);
}


void CDlgZhifenbiao31::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	DeleteDB();
}
BOOL CDlgZhifenbiao31::ConnectDB()
{

	//初始化数据库
	mysql_init(&m_mysqlz31);
	//设置数据库编码格式
	mysql_options(&m_mysqlz31, MYSQL_SET_CHARSET_NAME, "gbk");
	//连接数据库
	if (!mysql_real_connect(&m_mysqlz31, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgZhifenbiao31::InsertDB()
{
	UpdateData(TRUE);
	if (m_zhiname31.IsEmpty() || m_zhimianji31.IsEmpty() || m_zhizhanbi31.IsEmpty())
	{
		AfxMessageBox(TEXT("插入缺少值！不能为空"));
		return FALSE;
	}
	char* name = (char*)m_zhiname31.GetBuffer();//将CString转换为char *
	char* mianji = (char*)m_zhimianji31.GetBuffer();
	char* zhanbi = (char*)m_zhizhanbi31.GetBuffer();

	sprintf(queryz31, "insert into zhifen31 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysqlz31, queryz31))
	{
		AfxMessageBox(TEXT("插入数据失败！"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgZhifenbiao31::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_zhilist31.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//可以多选然后删除
	for (int i = iCount; i >= 0; i--)
	{
		if (m_zhilist31.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_zhilist31.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(queryz31, "delete from zhifen31 where 名称=\'%s\';", tname);
			if (mysql_query(&m_mysqlz31, queryz31))
			{
				AfxMessageBox(TEXT("删除数据失败！"));
				return FALSE;
			}
			//要先删除数据库的记录后才能删除列表中的项，否则GetItemText会返回空
			m_zhilist31.DeleteItem(i);//删除列表中的项
		}
	}
	return TRUE;
}

BOOL CDlgZhifenbiao31::SelectDB()
{

	sprintf(queryz31, "select * from zhifen31");
	//查询数据
	if (mysql_query(&m_mysqlz31, queryz31))
		return FALSE;
	//获取结果集
	m_resz31 = mysql_store_result(&m_mysqlz31);
	return TRUE;
}

void CDlgZhifenbiao31::GetDataFromDB()
{
	//获取记录
	int i = 0;
	while (m_rowz31 = mysql_fetch_row(m_resz31))
	{
		m_data[i].push_back(m_rowz31[0]);
		m_data[i].push_back(m_rowz31[1]);
		m_data[i].push_back(m_rowz31[2]);
		i++;
	}
}

void CDlgZhifenbiao31::ShowInfo()
{
	m_zhilist31.DeleteAllItems();
	for (int i = 0; i<m_resz31->row_count; i++)
	{
		int iCount = m_zhilist31.GetItemCount();

		m_zhilist31.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysqlz31.field_count; j++)//number of columns in result set

			m_zhilist31.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgZhifenbiao31::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgZhifenbiao31::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	//释放结果集
	mysql_free_result(m_resz31);
	//关闭数据库
	mysql_close(&m_mysqlz31);
}
