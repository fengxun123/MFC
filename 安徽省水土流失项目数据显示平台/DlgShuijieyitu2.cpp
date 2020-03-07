// DlgShuijieyitu2.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgShuijieyitu2.h"
#include "afxdialogex.h"


// CDlgShuijieyitu2 对话框

IMPLEMENT_DYNAMIC(CDlgShuijieyitu2, CDialogEx)

CDlgShuijieyitu2::CDlgShuijieyitu2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SHUIJIEYITU2, pParent)
{

}

CDlgShuijieyitu2::~CDlgShuijieyitu2()
{
}

void CDlgShuijieyitu2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_shuipic2);
}


BEGIN_MESSAGE_MAP(CDlgShuijieyitu2, CDialogEx)
END_MESSAGE_MAP()


// CDlgShuijieyitu2 消息处理程序


BOOL CDlgShuijieyitu2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_shuipic2.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
	//句尾没有；
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//宽高设置按照控件大小

	CRect shuirect2;

	m_shuipic2.GetWindowRect(shuirect2);

	//静态控件设置bitmap

	m_shuipic2.SetBitmap(HBMP(TEXT("./图片18.bmp"), shuirect2.Width(), shuirect2.Height()));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
