// DlgZhijieyitu1.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgZhijieyitu1.h"
#include "afxdialogex.h"


// CDlgZhijieyitu1 对话框

IMPLEMENT_DYNAMIC(CDlgZhijieyitu1, CDialogEx)

CDlgZhijieyitu1::CDlgZhijieyitu1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIJIEYITU1, pParent)
{

}

CDlgZhijieyitu1::~CDlgZhijieyitu1()
{
}

void CDlgZhijieyitu1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_zhipic1);
}


BEGIN_MESSAGE_MAP(CDlgZhijieyitu1, CDialogEx)
END_MESSAGE_MAP()


// CDlgZhijieyitu1 消息处理程序


BOOL CDlgZhijieyitu1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_zhipic1.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
	//句尾没有；
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//宽高设置按照控件大小

	CRect zhirect1;

	m_zhipic1.GetWindowRect(zhirect1);

	//静态控件设置bitmap

	m_zhipic1.SetBitmap(HBMP(TEXT("./图片13.bmp"), zhirect1.Width(), zhirect1.Height()));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
