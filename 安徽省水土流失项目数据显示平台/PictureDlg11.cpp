// PictureDlg11.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "PictureDlg11.h"


// CPictureDlg11

IMPLEMENT_DYNCREATE(CPictureDlg11, CFormView)

CPictureDlg11::CPictureDlg11()
	: CFormView(DIALOG_PICTURE11)
	, m_text11(_T(""))
	, m_text12(_T(""))
{

}

CPictureDlg11::~CPictureDlg11()
{
}

void CPictureDlg11::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC11, m_pic11);
	DDX_Control(pDX, IDC_PIC12, m_pic12);
	//  DDX_Control(pDX, IDC_EDIT1, m_text11);
	//  DDX_Control(pDX, IDC_EDIT2, m_text12);
	//  DDX_Text(pDX, IDC_EDIT2, m_text11);
	DDX_Text(pDX, IDC_EDIT1, m_text11);
	DDX_Text(pDX, IDC_EDIT2, m_text12);
}

BEGIN_MESSAGE_MAP(CPictureDlg11, CFormView)
	
END_MESSAGE_MAP()


// CPictureDlg11 诊断

#ifdef _DEBUG
void CPictureDlg11::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPictureDlg11::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPictureDlg11 消息处理程序


void CPictureDlg11::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	m_text11 =TEXT("高分二号底图（获取时间：2017年6月15日；分辨率为：1米；波段组合：432+全色）");
	m_text12 = TEXT("DEM高程影像图");
	UpdateData(FALSE);//变量同步到控件中

	//大龙山卫星图
	//设置静态控件窗口风格为位图居中显示
	m_pic11.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
	//句尾没有；
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//宽高设置按照控件大小

	CRect rect11;

	m_pic11.GetWindowRect(rect11);

	//静态控件设置bitmap

	m_pic11.SetBitmap(HBMP(TEXT("./图片1.bmp"), rect11.Width(), rect11.Height()));

	//大龙山EDM图
	m_pic12.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
	//句尾没有；
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//宽高设置按照控件大小

	CRect rect12;
	m_pic12.GetWindowRect(rect12);

	//静态控件设置bitmap

	m_pic12.SetBitmap(HBMP(TEXT("./图片2.bmp"), rect12.Width(), rect12.Height()));


}


