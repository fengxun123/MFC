// DlgJieyitu2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgJieyitu2.h"
#include "afxdialogex.h"


// CDlgJieyitu2 �Ի���

IMPLEMENT_DYNAMIC(CDlgJieyitu2, CDialogEx)

CDlgJieyitu2::CDlgJieyitu2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUJIEYITU2, pParent)
{

}

CDlgJieyitu2::~CDlgJieyitu2()
{
}

void CDlgJieyitu2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_tupic1);
}


BEGIN_MESSAGE_MAP(CDlgJieyitu2, CDialogEx)
END_MESSAGE_MAP()


// CDlgJieyitu2 ��Ϣ�������


BOOL CDlgJieyitu2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_tupic1.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//ͨ��·����ȡbitmap���
	//��βû�У�
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//������ð��տؼ���С

	CRect rect2;

	m_tupic1.GetWindowRect(rect2);

	//��̬�ؼ�����bitmap

	m_tupic1.SetBitmap(HBMP(TEXT("./ͼƬ10.bmp"), rect2.Width(), rect2.Height()));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
