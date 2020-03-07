// DlgZhijieyitu3.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "DlgZhijieyitu3.h"
#include "afxdialogex.h"


// CDlgZhijieyitu3 对话框

IMPLEMENT_DYNAMIC(CDlgZhijieyitu3, CDialogEx)

CDlgZhijieyitu3::CDlgZhijieyitu3(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIJIEYITU3, pParent)
{

}

CDlgZhijieyitu3::~CDlgZhijieyitu3()
{
}

void CDlgZhijieyitu3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_zhipic3);
}


BEGIN_MESSAGE_MAP(CDlgZhijieyitu3, CDialogEx)
END_MESSAGE_MAP()


// CDlgZhijieyitu3 消息处理程序


BOOL CDlgZhijieyitu3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_zhipic3.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
	//句尾没有；
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//宽高设置按照控件大小

	CRect zhirect3;

	m_zhipic3.GetWindowRect(zhirect3);

	//静态控件设置bitmap

	m_zhipic3.SetBitmap(HBMP(TEXT("./图片15.bmp"), zhirect3.Width(), zhirect3.Height()));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
