// DlgJieyitu2.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgJieyitu2.h"
#include "afxdialogex.h"


// CDlgJieyitu2 对话框

IMPLEMENT_DYNAMIC(CDlgJieyitu2, CDialogEx)

CDlgJieyitu2::CDlgJieyitu2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUJIEYITU2, pParent)
{

}

CDlgJieyitu2::~CDlgJieyitu2()
{
}

void CDlgJieyitu2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_tupic1);
}


BEGIN_MESSAGE_MAP(CDlgJieyitu2, CDialogEx)
END_MESSAGE_MAP()


// CDlgJieyitu2 消息处理程序


BOOL CDlgJieyitu2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_tupic1.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
	//句尾没有；
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//宽高设置按照控件大小

	CRect rect2;

	m_tupic1.GetWindowRect(rect2);

	//静态控件设置bitmap

	m_tupic1.SetBitmap(HBMP(TEXT("./图片10.bmp"), rect2.Width(), rect2.Height()));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
