
// ����ʡˮ����ʧ��Ŀ������ʾƽ̨.h : ����ʡˮ����ʧ��Ŀ������ʾƽ̨ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C����ʡˮ����ʧ��Ŀ������ʾƽ̨App:
// �йش����ʵ�֣������ ����ʡˮ����ʧ��Ŀ������ʾƽ̨.cpp
//

class C����ʡˮ����ʧ��Ŀ������ʾƽ̨App : public CWinApp
{
public:
	C����ʡˮ����ʧ��Ŀ������ʾƽ̨App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C����ʡˮ����ʧ��Ŀ������ʾƽ̨App theApp;
