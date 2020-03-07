// DlgZhifenbiao32.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgZhifenbiao32.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysqlz32;			//数据库结构
MYSQL_RES* m_resz32;         //查询的返回结果集
MYSQL_ROW m_rowz32;          //获取每一条记录
char queryz32[150]; //查询语句

// CDlgZhifenbiao32 对话框

IMPLEMENT_DYNAMIC(CDlgZhifenbiao32, CDialogEx)

CDlgZhifenbiao32::CDlgZhifenbiao32(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIFENBIAO32, pParent)
	, m_zhiname32(_T(""))
	, m_zhimianji32(_T(""))
	, m_zhizhanbi32(_T(""))
{

}

CDlgZhifenbiao32::~CDlgZhifenbiao32()
{
}

void CDlgZhifenbiao32::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_zhilist32);
	DDX_Text(pDX, IDC_EDIT2, m_zhiname32);
	DDX_Text(pDX, IDC_EDIT1, m_zhimianji32);
	DDX_Text(pDX, IDC_EDIT5, m_zhizhanbi32);
}


BEGIN_MESSAGE_MAP(CDlgZhifenbiao32, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgZhifenbiao32::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgZhifenbiao32::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgZhifenbiao32 消息处理程序


BOOL CDlgZhifenbiao32::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//设置表头
	CString str[] = { TEXT("名称"), TEXT("面积"), TEXT("占比") };
	m_zhilist32.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_zhilist32.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_zhilist32.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_zhilist32.SetExtendedStyle(m_zhilist32.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgZhifenbiao32::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	InsertDB();				   //插入数据
	UpdateData(FALSE);//添加纪录后显示出来
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//添加完后清空编辑框
	m_zhiname32.Empty();
	m_zhimianji32.Empty();
	m_zhizhanbi32.Empty();
	UpdateData(FALSE);
}


void CDlgZhifenbiao32::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	DeleteDB();
}
BOOL CDlgZhifenbiao32::ConnectDB()
{

	//初始化数据库
	mysql_init(&m_mysqlz32);
	//设置数据库编码格式
	mysql_options(&m_mysqlz32, MYSQL_SET_CHARSET_NAME, "gbk");
	//连接数据库
	if (!mysql_real_connect(&m_mysqlz32, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgZhifenbiao32::InsertDB()
{
	UpdateData(TRUE);
	if (m_zhiname32.IsEmpty() || m_zhimianji32.IsEmpty() || m_zhizhanbi32.IsEmpty())
	{
		AfxMessageBox(TEXT("插入缺少值！不能为空"));
		return FALSE;
	}
	char* name = (char*)m_zhiname32.GetBuffer();//将CString转换为char *
	char* mianji = (char*)m_zhimianji32.GetBuffer();
	char* zhanbi = (char*)m_zhizhanbi32.GetBuffer();

	sprintf(queryz32, "insert into zhifen32 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysqlz32, queryz32))
	{
		AfxMessageBox(TEXT("插入数据失败！"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgZhifenbiao32::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_zhilist32.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//可以多选然后删除
	for (int i = iCount; i >= 0; i--)
	{
		if (m_zhilist32.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_zhilist32.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(queryz32, "delete from zhifen32 where 名称=\'%s\';", tname);
			if (mysql_query(&m_mysqlz32, queryz32))
			{
				AfxMessageBox(TEXT("删除数据失败！"));
				return FALSE;
			}
			//要先删除数据库的记录后才能删除列表中的项，否则GetItemText会返回空
			m_zhilist32.DeleteItem(i);//删除列表中的项
		}
	}
	return TRUE;
}

BOOL CDlgZhifenbiao32::SelectDB()
{

	sprintf(queryz32, "select * from zhifen32");
	//查询数据
	if (mysql_query(&m_mysqlz32, queryz32))
		return FALSE;
	//获取结果集
	m_resz32 = mysql_store_result(&m_mysqlz32);
	return TRUE;
}

void CDlgZhifenbiao32::GetDataFromDB()
{
	//获取记录
	int i = 0;
	while (m_rowz32 = mysql_fetch_row(m_resz32))
	{
		m_data[i].push_back(m_rowz32[0]);
		m_data[i].push_back(m_rowz32[1]);
		m_data[i].push_back(m_rowz32[2]);
		i++;
	}
}

void CDlgZhifenbiao32::ShowInfo()
{
	m_zhilist32.DeleteAllItems();
	for (int i = 0; i<m_resz32->row_count; i++)
	{
		int iCount = m_zhilist32.GetItemCount();

		m_zhilist32.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysqlz32.field_count; j++)//number of columns in result set

			m_zhilist32.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgZhifenbiao32::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgZhifenbiao32::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	//释放结果集
	mysql_free_result(m_resz32);
	//关闭数据库
	mysql_close(&m_mysqlz32);
}
