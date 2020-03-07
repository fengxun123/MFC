
// 安徽省水土流失项目数据显示平台View.cpp : C安徽省水土流失项目数据显示平台View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "安徽省水土流失项目数据显示平台.h"
#endif

#include "安徽省水土流失项目数据显示平台Doc.h"
#include "安徽省水土流失项目数据显示平台View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C安徽省水土流失项目数据显示平台View

IMPLEMENT_DYNCREATE(C安徽省水土流失项目数据显示平台View, CView)

BEGIN_MESSAGE_MAP(C安徽省水土流失项目数据显示平台View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C安徽省水土流失项目数据显示平台View 构造/析构

C安徽省水土流失项目数据显示平台View::C安徽省水土流失项目数据显示平台View()
{
	// TODO: 在此处添加构造代码

}

C安徽省水土流失项目数据显示平台View::~C安徽省水土流失项目数据显示平台View()
{
}

BOOL C安徽省水土流失项目数据显示平台View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C安徽省水土流失项目数据显示平台View 绘制

void C安徽省水土流失项目数据显示平台View::OnDraw(CDC* /*pDC*/)
{
	C安徽省水土流失项目数据显示平台Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C安徽省水土流失项目数据显示平台View 打印

BOOL C安徽省水土流失项目数据显示平台View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C安徽省水土流失项目数据显示平台View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C安徽省水土流失项目数据显示平台View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C安徽省水土流失项目数据显示平台View 诊断

#ifdef _DEBUG
void C安徽省水土流失项目数据显示平台View::AssertValid() const
{
	CView::AssertValid();
}

void C安徽省水土流失项目数据显示平台View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C安徽省水土流失项目数据显示平台Doc* C安徽省水土流失项目数据显示平台View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C安徽省水土流失项目数据显示平台Doc)));
	return (C安徽省水土流失项目数据显示平台Doc*)m_pDocument;
}
#endif //_DEBUG


// C安徽省水土流失项目数据显示平台View 消息处理程序
