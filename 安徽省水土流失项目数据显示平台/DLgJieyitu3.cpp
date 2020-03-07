// DLgJieyitu3.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DLgJieyitu3.h"
#include "afxdialogex.h"


// CDLgJieyitu3 对话框

IMPLEMENT_DYNAMIC(CDLgJieyitu3, CDialogEx)

CDLgJieyitu3::CDLgJieyitu3(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUJIEYITU3, pParent)
{

}

CDLgJieyitu3::~CDLgJieyitu3()
{
}

void CDLgJieyitu3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_tupic2);
}


BEGIN_MESSAGE_MAP(CDLgJieyitu3, CDialogEx)
END_MESSAGE_MAP()


// CDLgJieyitu3 消息处理程序


BOOL CDLgJieyitu3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_tupic2.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
	//句尾没有；
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//宽高设置按照控件大小

	CRect rect3;

	m_tupic2.GetWindowRect(rect3);

	//静态控件设置bitmap

	m_tupic2.SetBitmap(HBMP(TEXT("./图片11.bmp"), rect3.Width(), rect3.Height()));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
