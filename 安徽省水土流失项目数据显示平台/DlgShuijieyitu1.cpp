// DlgShuijieyitu1.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgShuijieyitu1.h"
#include "afxdialogex.h"


// CDlgShuijieyitu1 对话框

IMPLEMENT_DYNAMIC(CDlgShuijieyitu1, CDialogEx)

CDlgShuijieyitu1::CDlgShuijieyitu1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SHUIJIEYITU1, pParent)
{

}

CDlgShuijieyitu1::~CDlgShuijieyitu1()
{
}

void CDlgShuijieyitu1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_shuipic1);
}


BEGIN_MESSAGE_MAP(CDlgShuijieyitu1, CDialogEx)
END_MESSAGE_MAP()


// CDlgShuijieyitu1 消息处理程序


BOOL CDlgShuijieyitu1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_shuipic1.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
	//句尾没有；
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//宽高设置按照控件大小

	CRect shuirect1;

	m_shuipic1.GetWindowRect(shuirect1);

	//静态控件设置bitmap

	m_shuipic1.SetBitmap(HBMP(TEXT("./图片17.bmp"), shuirect1.Width(), shuirect1.Height()));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
