
// 安徽省水土流失项目数据显示平台.h : 安徽省水土流失项目数据显示平台 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// C安徽省水土流失项目数据显示平台App:
// 有关此类的实现，请参阅 安徽省水土流失项目数据显示平台.cpp
//

class C安徽省水土流失项目数据显示平台App : public CWinApp
{
public:
	C安徽省水土流失项目数据显示平台App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C安徽省水土流失项目数据显示平台App theApp;
