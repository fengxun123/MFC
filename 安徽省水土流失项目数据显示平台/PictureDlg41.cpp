// PictureDlg41.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "PictureDlg41.h"


// CPictureDlg41

IMPLEMENT_DYNCREATE(CPictureDlg41, CFormView)

CPictureDlg41::CPictureDlg41()
	: CFormView(DIALOG_PICTURE41)
	, m_text41(_T(""))
	, m_text42(_T(""))
{

}

CPictureDlg41::~CPictureDlg41()
{
}

void CPictureDlg41::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC11, m_pic41);
	DDX_Control(pDX, IDC_PIC12, m_pic42);
	DDX_Text(pDX, IDC_EDIT1, m_text41);
	DDX_Text(pDX, IDC_EDIT2, m_text42);
}

BEGIN_MESSAGE_MAP(CPictureDlg41, CFormView)
END_MESSAGE_MAP()


// CPictureDlg41 诊断

#ifdef _DEBUG
void CPictureDlg41::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPictureDlg41::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPictureDlg41 消息处理程序


void CPictureDlg41::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	m_text41 = TEXT("高分二号底图（获取时间：2017年6月15日；分辨率为：1米；波段组合：432+全色）");
	m_text42 = TEXT("DEM高程影像图");
	UpdateData(FALSE);//变量同步到控件中

					  //巢湖东南卫星图
					  //设置静态控件窗口风格为位图居中显示
	m_pic41.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
	//句尾没有；
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//宽高设置按照控件大小

	CRect rect41;

	m_pic41.GetWindowRect(rect41);

	//静态控件设置bitmap

	m_pic41.SetBitmap(HBMP(TEXT("./图片7.bmp"), rect41.Width(), rect41.Height()));

	
	//巢湖东南EDM图
	m_pic42.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
	//句尾没有；
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//宽高设置按照控件大小

	CRect rect42;
	m_pic42.GetWindowRect(rect42);

	//静态控件设置bitmap

	m_pic42.SetBitmap(HBMP(TEXT("./图片8.bmp"), rect42.Width(), rect42.Height()));

}
