
// ����ʡˮ����ʧ��Ŀ������ʾƽ̨View.h : C����ʡˮ����ʧ��Ŀ������ʾƽ̨View ��Ľӿ�
//

#pragma once


class C����ʡˮ����ʧ��Ŀ������ʾƽ̨View : public CView
{
protected: // �������л�����
	C����ʡˮ����ʧ��Ŀ������ʾƽ̨View();
	DECLARE_DYNCREATE(C����ʡˮ����ʧ��Ŀ������ʾƽ̨View)

// ����
public:
	C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C����ʡˮ����ʧ��Ŀ������ʾƽ̨View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ����ʡˮ����ʧ��Ŀ������ʾƽ̨View.cpp �еĵ��԰汾
inline C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc* C����ʡˮ����ʧ��Ŀ������ʾƽ̨View::GetDocument() const
   { return reinterpret_cast<C����ʡˮ����ʧ��Ŀ������ʾƽ̨Doc*>(m_pDocument); }
#endif

