// DlgJieyitu4.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgJieyitu4.h"
#include "afxdialogex.h"


// CDlgJieyitu4 �Ի���

IMPLEMENT_DYNAMIC(CDlgJieyitu4, CDialogEx)

CDlgJieyitu4::CDlgJieyitu4(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUJIEYITU4, pParent)
{

}

CDlgJieyitu4::~CDlgJieyitu4()
{
}

void CDlgJieyitu4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_tupic3);
}


BEGIN_MESSAGE_MAP(CDlgJieyitu4, CDialogEx)
END_MESSAGE_MAP()


// CDlgJieyitu4 ��Ϣ�������


BOOL CDlgJieyitu4::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_tupic3.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//ͨ��·����ȡbitmap���
	//��βû�У�
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//������ð��տؼ���С

	CRect rect4;

	m_tupic3.GetWindowRect(rect4);

	//��̬�ؼ�����bitmap

	m_tupic3.SetBitmap(HBMP(TEXT("./ͼƬ12.bmp"), rect4.Width(), rect4.Height()));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
