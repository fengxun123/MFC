// PictureDlg21.cpp : 实现文件
//

#include "stdafx.h"
#include "安徽省水土流失项目数据显示平台.h"
#include "PictureDlg21.h"


// CPictureDlg21

IMPLEMENT_DYNCREATE(CPictureDlg21, CFormView)

CPictureDlg21::CPictureDlg21()
	: CFormView(DIALOG_PICTURE21)
	, m_text21(_T(""))
	, m_text22(_T(""))
{

}

CPictureDlg21::~CPictureDlg21()
{
}

void CPictureDlg21::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC21, m_pic21);
	DDX_Control(pDX, IDC_PIC22, m_pic22);
	DDX_Text(pDX, IDC_EDIT1, m_text21);
	DDX_Text(pDX, IDC_EDIT2, m_text22);
}

BEGIN_MESSAGE_MAP(CPictureDlg21, CFormView)
END_MESSAGE_MAP()


// CPictureDlg21 诊断

#ifdef _DEBUG
void CPictureDlg21::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPictureDlg21::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPictureDlg21 消息处理程序


void CPictureDlg21::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	m_text21 = TEXT("高分二号底图（获取时间：2017年6月15日；分辨率为：1米；波段组合：432+全色）");
	m_text22 = TEXT("DEM高程影像图");
	UpdateData(FALSE);//变量同步到控件中

					  //三公山卫星图
					  //设置静态控件窗口风格为位图居中显示
	m_pic21.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
	//句尾没有；
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//宽高设置按照控件大小

	CRect rect21;

	m_pic21.GetWindowRect(rect21);

	//静态控件设置bitmap

	m_pic21.SetBitmap(HBMP(TEXT("./图片3.bmp"), rect21.Width(), rect21.Height()));

	//三公山EDM图
	m_pic22.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//通过路径获取bitmap句柄
	//句尾没有；
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//宽高设置按照控件大小

	CRect rect22;
	m_pic22.GetWindowRect(rect22);

	//静态控件设置bitmap

	m_pic22.SetBitmap(HBMP(TEXT("./图片4.bmp"), rect22.Width(), rect22.Height()));


}
