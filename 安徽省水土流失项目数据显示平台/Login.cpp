#include "stdafx.h"
#include "Login.h"

CLogin::CLogin()
{
}


CLogin::~CLogin()
{
}

//��ȡ��¼��Ϣ
void CLogin::ReadLogin( CString &name, CString &pwd )
{
	ifstream ifs;	//�����ļ��������
	ifs.open(_F_LOGIN);

	char buf[1024] ={0};

	ifs.getline(buf, sizeof(buf));	//��ȡһ������
	name = CString(buf);	//��char* ת��ΪCString

	ifs.getline(buf, sizeof(buf));	//��ȡһ������
	pwd = CString(buf);	//��char* ת��ΪCString

	ifs.close();	//�ر��ļ�
}

//�޸�����
void CLogin::WritePwd( char* name, char* pwd )
{
	ofstream ofs;	//�����ļ��������
	ofs.open(_F_LOGIN); //���ļ�
	
	ofs<< name <<endl;	//nameд���ļ�
	ofs<< pwd <<endl;	//pwdд���ļ�
	
	ofs.close();	//�ر��ļ�
}

