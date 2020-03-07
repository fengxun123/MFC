// DlgJieyitu4.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgJieyitu4.h"
#include "afxdialogex.h"


// CDlgJieyitu4 对话框

IMPLEMENT_DYNAMIC(CDlgJieyitu4, CDialogEx)

CDlgJieyitu4::CDlgJieyitu4(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUJIEYITU4, pParent)
{

}

CDlgJieyitu4::~CDlgJieyitu4()
{
}

void CDlgJieyitu4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_tupic3);
}


BEGIN_MESSAGE_MAP(CDlgJieyitu4, CDialogEx)
END_MESSAGE_MAP()


// CDlgJieyitu4 消息处理程序


BOOL CDlgJieyitu4::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_tupic3.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
	//句尾没有；
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//宽高设置按照控件大小

	CRect rect4;

	m_tupic3.GetWindowRect(rect4);

	//静态控件设置bitmap

	m_tupic3.SetBitmap(HBMP(TEXT("./图片12.bmp"), rect4.Width(), rect4.Height()));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
