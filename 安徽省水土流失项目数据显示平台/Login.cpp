#include "stdafx.h"
#include "Login.h"

CLogin::CLogin()
{
}


CLogin::~CLogin()
{
}

//读取登录信息
void CLogin::ReadLogin( CString &name, CString &pwd )
{
	ifstream ifs;	//创建文件输入对象
	ifs.open(_F_LOGIN);

	char buf[1024] ={0};

	ifs.getline(buf, sizeof(buf));	//读取一行内容
	name = CString(buf);	//将char* 转换为CString

	ifs.getline(buf, sizeof(buf));	//读取一行内容
	pwd = CString(buf);	//将char* 转换为CString

	ifs.close();	//关闭文件
}

//修改密码
void CLogin::WritePwd( char* name, char* pwd )
{
	ofstream ofs;	//创建文件输出对象
	ofs.open(_F_LOGIN); //打开文件
	
	ofs<< name <<endl;	//name写入文件
	ofs<< pwd <<endl;	//pwd写入文件
	
	ofs.close();	//关闭文件
}

