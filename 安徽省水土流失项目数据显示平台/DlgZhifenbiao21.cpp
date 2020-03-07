// DlgZhifenbiao21.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgZhifenbiao21.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysqlz21;			//数据库结构
MYSQL_RES* m_resz21;         //查询的返回结果集
MYSQL_ROW m_rowz21;          //获取每一条记录
char queryz21[150]; //查询语句

// CDlgZhifenbiao21 对话框

IMPLEMENT_DYNAMIC(CDlgZhifenbiao21, CDialogEx)

CDlgZhifenbiao21::CDlgZhifenbiao21(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIFENBIAO21, pParent)
	, m_zhiname21(_T(""))
	, m_zhimianji21(_T(""))
	, m_zhizhanbi21(_T(""))
{

}

CDlgZhifenbiao21::~CDlgZhifenbiao21()
{
}

void CDlgZhifenbiao21::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_zhilist21);
	DDX_Text(pDX, IDC_EDIT2, m_zhiname21);
	DDX_Text(pDX, IDC_EDIT1, m_zhimianji21);
	DDX_Text(pDX, IDC_EDIT5, m_zhizhanbi21);
}


BEGIN_MESSAGE_MAP(CDlgZhifenbiao21, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgZhifenbiao21::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgZhifenbiao21::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgZhifenbiao21 消息处理程序


BOOL CDlgZhifenbiao21::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//设置表头
	CString str[] = { TEXT("名称"), TEXT("面积"), TEXT("占比") };
	m_zhilist21.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_zhilist21.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_zhilist21.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_zhilist21.SetExtendedStyle(m_zhilist21.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgZhifenbiao21::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	InsertDB();				   //插入数据
	UpdateData(FALSE);//添加纪录后显示出来
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//添加完后清空编辑框
	m_zhiname21.Empty();
	m_zhimianji21.Empty();
	m_zhizhanbi21.Empty();
	UpdateData(FALSE);
}


void CDlgZhifenbiao21::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	DeleteDB();
}

BOOL CDlgZhifenbiao21::ConnectDB()
{

	//初始化数据库
	mysql_init(&m_mysqlz21);
	//设置数据库编码格式
	mysql_options(&m_mysqlz21, MYSQL_SET_CHARSET_NAME, "gbk");
	//连接数据库
	if (!mysql_real_connect(&m_mysqlz21, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgZhifenbiao21::InsertDB()
{
	UpdateData(TRUE);
	if (m_zhiname21.IsEmpty() || m_zhimianji21.IsEmpty() || m_zhizhanbi21.IsEmpty())
	{
		AfxMessageBox(TEXT("插入缺少值！不能为空"));
		return FALSE;
	}
	char* name = (char*)m_zhiname21.GetBuffer();//将CString转换为char *
	char* mianji = (char*)m_zhimianji21.GetBuffer();
	char* zhanbi = (char*)m_zhizhanbi21.GetBuffer();

	sprintf(queryz21, "insert into zhifen21 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysqlz21, queryz21))
	{
		AfxMessageBox(TEXT("插入数据失败！"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgZhifenbiao21::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_zhilist21.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//可以多选然后删除
	for (int i = iCount; i >= 0; i--)
	{
		if (m_zhilist21.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_zhilist21.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(queryz21, "delete from zhifen21 where 名称=\'%s\';", tname);
			if (mysql_query(&m_mysqlz21, queryz21))
			{
				AfxMessageBox(TEXT("删除数据失败！"));
				return FALSE;
			}
			//要先删除数据库的记录后才能删除列表中的项，否则GetItemText会返回空
			m_zhilist21.DeleteItem(i);//删除列表中的项
		}
	}
	return TRUE;
}

BOOL CDlgZhifenbiao21::SelectDB()
{

	sprintf(queryz21, "select * from zhifen21");
	//查询数据
	if (mysql_query(&m_mysqlz21, queryz21))
		return FALSE;
	//获取结果集
	m_resz21 = mysql_store_result(&m_mysqlz21);
	return TRUE;
}

void CDlgZhifenbiao21::GetDataFromDB()
{
	//获取记录
	int i = 0;
	while (m_rowz21 = mysql_fetch_row(m_resz21))
	{
		m_data[i].push_back(m_rowz21[0]);
		m_data[i].push_back(m_rowz21[1]);
		m_data[i].push_back(m_rowz21[2]);
		i++;
	}
}

void CDlgZhifenbiao21::ShowInfo()
{
	m_zhilist21.DeleteAllItems();
	for (int i = 0; i<m_resz21->row_count; i++)
	{
		int iCount = m_zhilist21.GetItemCount();

		m_zhilist21.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysqlz21.field_count; j++)//number of columns in result set

			m_zhilist21.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgZhifenbiao21::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgZhifenbiao21::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	//释放结果集
	mysql_free_result(m_resz21);
	//关闭数据库
	mysql_close(&m_mysqlz21);
}

