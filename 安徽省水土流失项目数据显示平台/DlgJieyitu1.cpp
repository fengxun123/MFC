// DlgJieyitu1.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgJieyitu1.h"
#include "afxdialogex.h"


// CDlgJieyitu1 对话框

IMPLEMENT_DYNAMIC(CDlgJieyitu1, CDialogEx)

CDlgJieyitu1::CDlgJieyitu1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUJIEYITU1, pParent)
{

}

CDlgJieyitu1::~CDlgJieyitu1()
{
}

void CDlgJieyitu1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_tupic);
}


BEGIN_MESSAGE_MAP(CDlgJieyitu1, CDialogEx)
END_MESSAGE_MAP()


// CDlgJieyitu1 消息处理程序


BOOL CDlgJieyitu1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_tupic.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
	//句尾没有；
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//宽高设置按照控件大小

	CRect rect1;

	m_tupic.GetWindowRect(rect1);

	//静态控件设置bitmap

	m_tupic.SetBitmap(HBMP(TEXT("./图片9.bmp"), rect1.Width(), rect1.Height()));


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
