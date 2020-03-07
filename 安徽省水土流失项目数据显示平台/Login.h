#pragma once


#include <fstream>
#include <iostream>
#include <string>

#define _F_LOGIN "./login.ini"


using namespace std;



class CLogin
{
public:
	CLogin();
	~CLogin();

	//读取登录信息
	void ReadLogin(CString &name, CString &pwd);

	//修改密码
	void WritePwd(char* name, char* pwd);

};

