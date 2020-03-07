// DlgZhifenbiao13.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgZhifenbiao13.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysqlz13;			//数据库结构
MYSQL_RES* m_resz13;         //查询的返回结果集
MYSQL_ROW m_rowz13;          //获取每一条记录
char queryz13[150]; //查询语句


// CDlgZhifenbiao13 对话框

IMPLEMENT_DYNAMIC(CDlgZhifenbiao13, CDialogEx)

CDlgZhifenbiao13::CDlgZhifenbiao13(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIFENBIAO13, pParent)
	, m_zhiname13(_T(""))
	, m_zhimianji13(_T(""))
	, m_zhizhanbi13(_T(""))
{

}

CDlgZhifenbiao13::~CDlgZhifenbiao13()
{
}

void CDlgZhifenbiao13::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_zhilist13);
	DDX_Text(pDX, IDC_EDIT2, m_zhiname13);
	DDX_Text(pDX, IDC_EDIT1, m_zhimianji13);
	DDX_Text(pDX, IDC_EDIT5, m_zhizhanbi13);
}


BEGIN_MESSAGE_MAP(CDlgZhifenbiao13, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgZhifenbiao13::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgZhifenbiao13::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgZhifenbiao13 消息处理程序


BOOL CDlgZhifenbiao13::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//设置表头
	CString str[] = { TEXT("名称"), TEXT("面积"), TEXT("占比") };
	m_zhilist13.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_zhilist13.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_zhilist13.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_zhilist13.SetExtendedStyle(m_zhilist13.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgZhifenbiao13::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	InsertDB();				   //插入数据
	UpdateData(FALSE);//添加纪录后显示出来
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//添加完后清空编辑框
	m_zhiname13.Empty();
	m_zhimianji13.Empty();
	m_zhizhanbi13.Empty();
	UpdateData(FALSE);
}


void CDlgZhifenbiao13::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	DeleteDB();
}
BOOL CDlgZhifenbiao13::ConnectDB()
{

	//初始化数据库
	mysql_init(&m_mysqlz13);
	//设置数据库编码格式
	mysql_options(&m_mysqlz13, MYSQL_SET_CHARSET_NAME, "gbk");
	//连接数据库
	if (!mysql_real_connect(&m_mysqlz13, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgZhifenbiao13::InsertDB()
{
	UpdateData(TRUE);
	if (m_zhiname13.IsEmpty() || m_zhimianji13.IsEmpty() || m_zhizhanbi13.IsEmpty())
	{
		AfxMessageBox(TEXT("插入缺少值！不能为空"));
		return FALSE;
	}
	char* name = (char*)m_zhiname13.GetBuffer();//将CString转换为char *
	char* mianji = (char*)m_zhimianji13.GetBuffer();
	char* zhanbi = (char*)m_zhizhanbi13.GetBuffer();

	sprintf(queryz13, "insert into zhifen13 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysqlz13, queryz13))
	{
		AfxMessageBox(TEXT("插入数据失败！"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgZhifenbiao13::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_zhilist13.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//可以多选然后删除
	for (int i = iCount; i >= 0; i--)
	{
		if (m_zhilist13.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_zhilist13.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(queryz13, "delete from zhifen13 where 名称=\'%s\';", tname);
			if (mysql_query(&m_mysqlz13, queryz13))
			{
				AfxMessageBox(TEXT("删除数据失败！"));
				return FALSE;
			}
			//要先删除数据库的记录后才能删除列表中的项，否则GetItemText会返回空
			m_zhilist13.DeleteItem(i);//删除列表中的项
		}
	}
	return TRUE;
}

BOOL CDlgZhifenbiao13::SelectDB()
{

	sprintf(queryz13, "select * from zhifen13");
	//查询数据
	if (mysql_query(&m_mysqlz13, queryz13))
		return FALSE;
	//获取结果集
	m_resz13 = mysql_store_result(&m_mysqlz13);
	return TRUE;
}

void CDlgZhifenbiao13::GetDataFromDB()
{
	//获取记录
	int i = 0;
	while (m_rowz13 = mysql_fetch_row(m_resz13))
	{
		m_data[i].push_back(m_rowz13[0]);
		m_data[i].push_back(m_rowz13[1]);
		m_data[i].push_back(m_rowz13[2]);
		i++;
	}
}

void CDlgZhifenbiao13::ShowInfo()
{
	m_zhilist13.DeleteAllItems();
	for (int i = 0; i<m_resz13->row_count; i++)
	{
		int iCount = m_zhilist13.GetItemCount();

		m_zhilist13.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysqlz13.field_count; j++)//number of columns in result set

			m_zhilist13.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgZhifenbiao13::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgZhifenbiao13::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	//释放结果集
	mysql_free_result(m_resz13);
	//关闭数据库
	mysql_close(&m_mysqlz13);
}