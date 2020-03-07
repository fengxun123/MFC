// DlgTufenbiao13.cpp : 实现文件
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
#include "DlgTufenbiao13.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"

MYSQL m_mysql13;			//数据库结构
MYSQL_RES* m_res13;         //查询的返回结果集
MYSQL_ROW m_row13;          //获取每一条记录
char query13[150]; //查询语句

// CDlgTufenbiao13 对话框

IMPLEMENT_DYNAMIC(CDlgTufenbiao13, CDialogEx)

CDlgTufenbiao13::CDlgTufenbiao13(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUFENBIAO13, pParent)
	, m_name13(_T(""))
	, m_mianji13(_T(""))
	, m_zhanbi13(_T(""))
{

}

CDlgTufenbiao13::~CDlgTufenbiao13()
{
}

void CDlgTufenbiao13::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_name13);
	DDX_Text(pDX, IDC_EDIT1, m_mianji13);
	DDX_Text(pDX, IDC_EDIT5, m_zhanbi13);
	DDX_Control(pDX, IDC_LIST2, m_list13);
}


BEGIN_MESSAGE_MAP(CDlgTufenbiao13, CDialogEx)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTufenbiao13::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTufenbiao13::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDlgTufenbiao13 消息处理程序


void CDlgTufenbiao13::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	InsertDB();				   //插入数据
	UpdateData(FALSE);//添加纪录后显示出来
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//添加完后清空编辑框
	m_name13.Empty();
	m_mianji13.Empty();
	m_zhanbi13.Empty();
	UpdateData(FALSE);
}


void CDlgTufenbiao13::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	DeleteDB();
}


BOOL CDlgTufenbiao13::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//设置表头
	CString str[] = { TEXT("名称"), TEXT("面积"), TEXT("占比") };
	m_list13.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_list13.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_list13.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_list13.SetExtendedStyle(m_list13.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

BOOL CDlgTufenbiao13::ConnectDB()
{

	//初始化数据库
	mysql_init(&m_mysql13);
	//设置数据库编码格式
	mysql_options(&m_mysql13, MYSQL_SET_CHARSET_NAME, "gbk");
	//连接数据库
	if (!mysql_real_connect(&m_mysql13, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgTufenbiao13::InsertDB()
{
	UpdateData(TRUE);
	if (m_name13.IsEmpty() || m_mianji13.IsEmpty() || m_zhanbi13.IsEmpty())
	{
		AfxMessageBox(TEXT("插入缺少值！不能为空"));
		return FALSE;
	}
	char* name = (char*)m_name13.GetBuffer();//将CString转换为char *
	char* mianji = (char*)m_mianji13.GetBuffer();
	char* zhanbi = (char*)m_zhanbi13.GetBuffer();

	sprintf(query13, "insert into tufen3 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysql13, query13))
	{
		AfxMessageBox(TEXT("插入数据失败！"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgTufenbiao13::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_list13.GetItemCount();

	int j = 0;
	//可以多选然后删除
	for (int i = iCount; i >= 0; i--)
	{
		if (m_list13.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_list13.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(query13, "delete from tufen3 where 名称=\'%s\';", tname);
			if (mysql_query(&m_mysql13, query13))
			{
				AfxMessageBox(TEXT("删除数据失败！"));
				return FALSE;
			}
			//要先删除数据库的记录后才能删除列表中的项，否则GetItemText会返回空
			m_list13.DeleteItem(i);//删除列表中的项
		}
	}
	return TRUE;
}

BOOL CDlgTufenbiao13::SelectDB()
{

	sprintf(query13, "select * from tufen3");
	//查询数据
	if (mysql_query(&m_mysql13, query13))
		return FALSE;
	//获取结果集
	m_res13 = mysql_store_result(&m_mysql13);
	return TRUE;
}

void CDlgTufenbiao13::GetDataFromDB()
{
	//获取记录
	int i = 0;
	while (m_row13 = mysql_fetch_row(m_res13))
	{
		m_data[i].push_back(m_row13[0]);
		m_data[i].push_back(m_row13[1]);
		m_data[i].push_back(m_row13[2]);
		i++;
	}
}

void CDlgTufenbiao13::ShowInfo()
{
	m_list13.DeleteAllItems();
	for (int i = 0; i<m_res13->row_count; i++)
	{
		int iCount = m_list13.GetItemCount();

		m_list13.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysql13.field_count; j++)//number of columns in result set

			m_list13.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgTufenbiao13::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgTufenbiao13::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	//释放结果集
	mysql_free_result(m_res13);
	//关闭数据库
	mysql_close(&m_mysql13);
}
