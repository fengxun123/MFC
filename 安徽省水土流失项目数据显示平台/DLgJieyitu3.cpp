// DLgJieyitu3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DLgJieyitu3.h"
#include "afxdialogex.h"


// CDLgJieyitu3 �Ի���

IMPLEMENT_DYNAMIC(CDLgJieyitu3, CDialogEx)

CDLgJieyitu3::CDLgJieyitu3(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUJIEYITU3, pParent)
{

}

CDLgJieyitu3::~CDLgJieyitu3()
{
}

void CDLgJieyitu3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_tupic2);
}


BEGIN_MESSAGE_MAP(CDLgJieyitu3, CDialogEx)
END_MESSAGE_MAP()


// CDLgJieyitu3 ��Ϣ�������


BOOL CDLgJieyitu3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_tupic2.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//ͨ��·����ȡbitmap���
	//��βû�У�
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//������ð��տؼ���С

	CRect rect3;

	m_tupic2.GetWindowRect(rect3);

	//��̬�ؼ�����bitmap

	m_tupic2.SetBitmap(HBMP(TEXT("./ͼƬ11.bmp"), rect3.Width(), rect3.Height()));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
