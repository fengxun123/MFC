// PictureDlg31.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "PictureDlg31.h"


// CPictureDlg31

IMPLEMENT_DYNCREATE(CPictureDlg31, CFormView)

CPictureDlg31::CPictureDlg31()
	: CFormView(DIALOG_PICTURE31)
	, m_text31(_T(""))
	, m_text32(_T(""))
{

}

CPictureDlg31::~CPictureDlg31()
{
}

void CPictureDlg31::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC21, m_pic31);
	DDX_Control(pDX, IDC_PIC23, m_pic32);
	DDX_Text(pDX, IDC_EDIT1, m_text31);
	DDX_Text(pDX, IDC_EDIT2, m_text32);
}

BEGIN_MESSAGE_MAP(CPictureDlg31, CFormView)
END_MESSAGE_MAP()


// CPictureDlg31 诊断

#ifdef _DEBUG
void CPictureDlg31::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPictureDlg31::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPictureDlg31 消息处理程序


void CPictureDlg31::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	m_text31 = TEXT("高分二号底图（获取时间：2017年6月15日；分辨率为：1米；波段组合：432+全色）");
	m_text32 = TEXT("DEM高程影像图");
	UpdateData(FALSE);//变量同步到控件中

					  //三公山卫星图
					  //设置静态控件窗口风格为位图居中显示
	m_pic31.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
	//句尾没有；
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//宽高设置按照控件大小

	CRect rect31;

	m_pic31.GetWindowRect(rect31);

	//静态控件设置bitmap

	m_pic31.SetBitmap(HBMP(TEXT("./图片5.bmp"), rect31.Width(), rect31.Height()));

	//三公山EDM图
	m_pic32.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
	//句尾没有；
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//宽高设置按照控件大小

	CRect rect32;
	m_pic32.GetWindowRect(rect32);

	//静态控件设置bitmap

	m_pic32.SetBitmap(HBMP(TEXT("./图片6.bmp"), rect32.Width(), rect32.Height()));

}
