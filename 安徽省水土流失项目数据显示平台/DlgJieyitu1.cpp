// DlgJieyitu1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgJieyitu1.h"
#include "afxdialogex.h"


// CDlgJieyitu1 �Ի���

IMPLEMENT_DYNAMIC(CDlgJieyitu1, CDialogEx)

CDlgJieyitu1::CDlgJieyitu1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUJIEYITU1, pParent)
{

}

CDlgJieyitu1::~CDlgJieyitu1()
{
}

void CDlgJieyitu1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_tupic);
}


BEGIN_MESSAGE_MAP(CDlgJieyitu1, CDialogEx)
END_MESSAGE_MAP()


// CDlgJieyitu1 ��Ϣ�������


BOOL CDlgJieyitu1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_tupic.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//ͨ��·����ȡbitmap���
	//��βû�У�
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//������ð��տؼ���С

	CRect rect1;

	m_tupic.GetWindowRect(rect1);

	//��̬�ؼ�����bitmap

	m_tupic.SetBitmap(HBMP(TEXT("./ͼƬ9.bmp"), rect1.Width(), rect1.Height()));


	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
