// DlgShuijieyitu4.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgShuijieyitu4.h"
#include "afxdialogex.h"


// CDlgShuijieyitu4 对话框

IMPLEMENT_DYNAMIC(CDlgShuijieyitu4, CDialogEx)

CDlgShuijieyitu4::CDlgShuijieyitu4(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SHUIJIEYITU4, pParent)
{

}

CDlgShuijieyitu4::~CDlgShuijieyitu4()
{
}

void CDlgShuijieyitu4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_shuipic4);
}


BEGIN_MESSAGE_MAP(CDlgShuijieyitu4, CDialogEx)
END_MESSAGE_MAP()


// CDlgShuijieyitu4 消息处理程序


BOOL CDlgShuijieyitu4::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_shuipic4.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
	//句尾没有；
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//宽高设置按照控件大小

	CRect shuirect4;

	m_shuipic4.GetWindowRect(shuirect4);

	//静态控件设置bitmap

	m_shuipic4.SetBitmap(HBMP(TEXT("./图片20.bmp"), shuirect4.Width(), shuirect4.Height()));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
