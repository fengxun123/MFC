// DlgZhijieyitu4.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgZhijieyitu4.h"
#include "afxdialogex.h"


// CDlgZhijieyitu4 对话框

IMPLEMENT_DYNAMIC(CDlgZhijieyitu4, CDialogEx)

CDlgZhijieyitu4::CDlgZhijieyitu4(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIJIEYITU4, pParent)
{

}

CDlgZhijieyitu4::~CDlgZhijieyitu4()
{
}

void CDlgZhijieyitu4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_zhipic4);
}


BEGIN_MESSAGE_MAP(CDlgZhijieyitu4, CDialogEx)
END_MESSAGE_MAP()


// CDlgZhijieyitu4 消息处理程序


BOOL CDlgZhijieyitu4::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_zhipic4.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
	//句尾没有；
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//宽高设置按照控件大小

	CRect zhirect4;

	m_zhipic4.GetWindowRect(zhirect4);

	//静态控件设置bitmap

	m_zhipic4.SetBitmap(HBMP(TEXT("./图片16.bmp"), zhirect4.Width(), zhirect4.Height()));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
