// DlgZhizongbiao10.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgZhizongbiao10.h"
#include "afxdialogex.h"
#include "winsock.h"
#include "mysql.h"


MYSQL m_mysqlz10;			//数据库结构
MYSQL_RES* m_resz10;         //查询的返回结果集
MYSQL_ROW m_rowz10;          //获取每一条记录
char queryz10[150]; //查询语句
// CDlgZhizongbiao10 对话框

IMPLEMENT_DYNAMIC(CDlgZhizongbiao10, CDialogEx)

CDlgZhizongbiao10::CDlgZhizongbiao10(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIZONGBIAO10, pParent)
	, m_zhiname10(_T(""))
	, m_zhimianji10(_T(""))
	, m_zhizhanbi10(_T(""))
{

}

CDlgZhizongbiao10::~CDlgZhizongbiao10()
{
}

void CDlgZhizongbiao10::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_zhilist10);
	DDX_Text(pDX, IDC_EDIT2, m_zhiname10);
	DDX_Text(pDX, IDC_EDIT1, m_zhimianji10);
	DDX_Text(pDX, IDC_EDIT5, m_zhizhanbi10);
}


BEGIN_MESSAGE_MAP(CDlgZhizongbiao10, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgZhizongbiao10::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgZhizongbiao10::OnBnClickedButton2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDlgZhizongbiao10 消息处理程序


BOOL CDlgZhizongbiao10::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//设置表头
	CString str[] = { TEXT("名称"), TEXT("面积"), TEXT("占比") };
	m_zhilist10.InsertColumn(0, str[0], LVCFMT_LEFT, 200, -1);
	m_zhilist10.InsertColumn(1, str[1], LVCFMT_LEFT, 100, -1);
	m_zhilist10.InsertColumn(2, str[2], LVCFMT_LEFT, 100, -1);


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
	m_zhilist10.SetExtendedStyle(m_zhilist10.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgZhizongbiao10::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	InsertDB();				   //插入数据
	UpdateData(FALSE);//添加纪录后显示出来
	SelectDB();
	GetDataFromDB();
	ShowInfo();
	//添加完后清空编辑框
	m_zhiname10.Empty();
	m_zhimianji10.Empty();
	m_zhizhanbi10.Empty();
	UpdateData(FALSE);
}


void CDlgZhizongbiao10::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	DeleteDB();
}
BOOL CDlgZhizongbiao10::ConnectDB()
{

	//初始化数据库
	mysql_init(&m_mysqlz10);
	//设置数据库编码格式
	mysql_options(&m_mysqlz10, MYSQL_SET_CHARSET_NAME, "gbk");
	//连接数据库
	if (!mysql_real_connect(&m_mysqlz10, "localhost", "root", "12345", "program", 3306, NULL, 0))
		return FALSE;
	return TRUE;
}

BOOL CDlgZhizongbiao10::InsertDB()
{
	UpdateData(TRUE);
	if (m_zhiname10.IsEmpty() || m_zhimianji10.IsEmpty() || m_zhizhanbi10.IsEmpty())
	{
		AfxMessageBox(TEXT("插入缺少值！不能为空"));
		return FALSE;
	}
	char* name = (char*)m_zhiname10.GetBuffer();//将CString转换为char *
	char* mianji = (char*)m_zhimianji10.GetBuffer();
	char* zhanbi = (char*)m_zhizhanbi10.GetBuffer();

	sprintf(queryz10, "insert into zhizong1 values (\'%s\',\'%s\',\'%s\');", name, mianji, zhanbi);
	if (mysql_query(&m_mysqlz10, queryz10))
	{
		AfxMessageBox(TEXT("插入数据失败！"));
		return FALSE;
	}
	return TRUE;

}

BOOL CDlgZhizongbiao10::DeleteDB()
{
	UpdateData(TRUE);
	int iCount = m_zhilist10.GetItemCount();
	std::vector<std::string> row[100];
	int j = 0;
	//可以多选然后删除
	for (int i = iCount; i >= 0; i--)
	{
		if (m_zhilist10.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED)
		{
			CString typeName;

			typeName = m_zhilist10.GetItemText(i, 0);
			char * tname = (char *)typeName.GetBuffer();

			sprintf(queryz10, "delete from zhizong1 where 名称=\'%s\';", tname);
			if (mysql_query(&m_mysqlz10, queryz10))
			{
				AfxMessageBox(TEXT("删除数据失败！"));
				return FALSE;
			}
			//要先删除数据库的记录后才能删除列表中的项，否则GetItemText会返回空
			m_zhilist10.DeleteItem(i);//删除列表中的项
		}
	}
	return TRUE;
}

BOOL CDlgZhizongbiao10::SelectDB()
{

	sprintf(queryz10, "select * from zhizong1");
	//查询数据
	if (mysql_query(&m_mysqlz10, queryz10))
		return FALSE;
	//获取结果集
	m_resz10 = mysql_store_result(&m_mysqlz10);
	return TRUE;
}

void CDlgZhizongbiao10::GetDataFromDB()
{
	//获取记录
	int i = 0;
	while (m_rowz10 = mysql_fetch_row(m_resz10))
	{
		m_data[i].push_back(m_rowz10[0]);
		m_data[i].push_back(m_rowz10[1]);
		m_data[i].push_back(m_rowz10[2]);
		i++;
	}
}

void CDlgZhizongbiao10::ShowInfo()
{
	m_zhilist10.DeleteAllItems();
	for (int i = 0; i<m_resz10->row_count; i++)
	{
		int iCount = m_zhilist10.GetItemCount();

		m_zhilist10.InsertItem(iCount, m_data[i][0].c_str());
		for (unsigned int j = 0; j < m_mysqlz10.field_count; j++)//number of columns in result set

			m_zhilist10.SetItemText(iCount, j, m_data[i][j].c_str());
	}

}

void CDlgZhizongbiao10::ClearData()
{
	int i = 0;
	while (!m_data[i].empty())
	{
		m_data[i++].clear();
	}
}

void CDlgZhizongbiao10::OnDestroy()
{

	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	//释放结果集
	mysql_free_result(m_resz10);
	//关闭数据库
	mysql_close(&m_mysqlz10);
}

