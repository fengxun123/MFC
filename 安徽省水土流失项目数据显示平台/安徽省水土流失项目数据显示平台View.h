
// 安徽省水土流失项目数据显示平台View.h : C安徽省水土流失项目数据显示平台View 类的接口
//

#pragma once


class C安徽省水土流失项目数据显示平台View : public CView
{
protected: // 仅从序列化创建
	C安徽省水土流失项目数据显示平台View();
	DECLARE_DYNCREATE(C安徽省水土流失项目数据显示平台View)

// 特性
public:
	C安徽省水土流失项目数据显示平台Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C安徽省水土流失项目数据显示平台View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 安徽省水土流失项目数据显示平台View.cpp 中的调试版本
inline C安徽省水土流失项目数据显示平台Doc* C安徽省水土流失项目数据显示平台View::GetDocument() const
   { return reinterpret_cast<C安徽省水土流失项目数据显示平台Doc*>(m_pDocument); }
#endif

