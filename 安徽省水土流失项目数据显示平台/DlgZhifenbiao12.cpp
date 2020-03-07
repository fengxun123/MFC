// DlgZhifenbiao12.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgZhifenbiao12.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysqlz12;			//数据库结构
MYSQL_RES* m_resz12;         //查询的返回结果集
MYSQL_ROW m_rowz12;          //获取每一条记录
char queryz12[150]; //查询语句

// CDlgZhifenbiao12 对话框

IMPLEMENT_DYNAMIC(CDlgZhifenbiao12, CDialogEx)

CDlgZhifenbiao12::CDlgZhifenbiao12(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIFENBIAO12, pParent)
	, m_zhiname12(_T(""))
	, m_zhimianji12(_T(""))
	, m_zhizhanbi12(_T(""))
{

}

CDlgZhifenbiao12::~CDlgZhifenbiao12()
{
}

void CDlgZhifenbiao12::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_zhilist12);
	DDX_Text(pDX, IDC_EDIT2, m_zhiname12);
	DDX_Text(pDX, IDC_EDIT1, m_zhimianji12);
	DDX_Text(pDX, IDC_EDIT5, m_zhizhanbi12);
}


BEGIN_MESSAGE_MAP(CDlgZhifenbiao12, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgZhifenbiao12::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgZhifenbiao12::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgZhifenbiao12 消息处理程序


BOOL CDlgZhifenbiao12::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//设置表头
	CString str[] = { TEXT("名称"), TEXT("面积"), TEXT("占比") };
	m_zhilist12.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_zhilist12.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_zhilist12.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_zhilist12.SetExtendedStyle(m_zhilist12.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgZhifenbiao12::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	InsertDB();				   //插入数据
	UpdateData(FALSE);//添加纪录后显示出来
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//添加完后清空编辑框
	m_zhiname12.Empty();
	m_zhimianji12.Empty();
	m_zhizhanbi12.Empty();
	UpdateData(FALSE);
}


void CDlgZhifenbiao12::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	DeleteDB();
}
BOOL CDlgZhifenbiao12::ConnectDB()
{

	//初始化数据库
	mysql_init(&m_mysqlz12);
	//设置数据库编码格式
	mysql_options(&m_mysqlz12, MYSQL_SET_CHARSET_NAME, "gbk");
	//连接数据库
	if (!mysql_real_connect(&m_mysqlz12, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgZhifenbiao12::InsertDB()
{
	UpdateData(TRUE);
	if (m_zhiname12.IsEmpty() || m_zhimianji12.IsEmpty() || m_zhizhanbi12.IsEmpty())
	{
		AfxMessageBox(TEXT("插入缺少值！不能为空"));
		return FALSE;
	}
	char* name = (char*)m_zhiname12.GetBuffer();//将CString转换为char *
	char* mianji = (char*)m_zhimianji12.GetBuffer();
	char* zhanbi = (char*)m_zhizhanbi12.GetBuffer();

	sprintf(queryz12, "insert into zhifen12 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysqlz12, queryz12))
	{
		AfxMessageBox(TEXT("插入数据失败！"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgZhifenbiao12::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_zhilist12.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//可以多选然后删除
	for (int i = iCount; i >= 0; i--)
	{
		if (m_zhilist12.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_zhilist12.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(queryz12, "delete from zhifen12 where 名称=\'%s\';", tname);
			if (mysql_query(&m_mysqlz12, queryz12))
			{
				AfxMessageBox(TEXT("删除数据失败！"));
				return FALSE;
			}
			//要先删除数据库的记录后才能删除列表中的项，否则GetItemText会返回空
			m_zhilist12.DeleteItem(i);//删除列表中的项
		}
	}
	return TRUE;
}

BOOL CDlgZhifenbiao12::SelectDB()
{

	sprintf(queryz12, "select * from zhifen12");
	//查询数据
	if (mysql_query(&m_mysqlz12, queryz12))
		return FALSE;
	//获取结果集
	m_resz12 = mysql_store_result(&m_mysqlz12);
	return TRUE;
}

void CDlgZhifenbiao12::GetDataFromDB()
{
	//获取记录
	int i = 0;
	while (m_rowz12 = mysql_fetch_row(m_resz12))
	{
		m_data[i].push_back(m_rowz12[0]);
		m_data[i].push_back(m_rowz12[1]);
		m_data[i].push_back(m_rowz12[2]);
		i++;
	}
}

void CDlgZhifenbiao12::ShowInfo()
{
	m_zhilist12.DeleteAllItems();
	for (int i = 0; i<m_resz12->row_count; i++)
	{
		int iCount = m_zhilist12.GetItemCount();

		m_zhilist12.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysqlz12.field_count; j++)//number of columns in result set

			m_zhilist12.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgZhifenbiao12::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgZhifenbiao12::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	//释放结果集
	mysql_free_result(m_resz12);
	//关闭数据库
	mysql_close(&m_mysqlz12);
}
