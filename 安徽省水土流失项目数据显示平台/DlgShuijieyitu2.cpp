// DlgShuijieyitu2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgShuijieyitu2.h"
#include "afxdialogex.h"


// CDlgShuijieyitu2 �Ի���

IMPLEMENT_DYNAMIC(CDlgShuijieyitu2, CDialogEx)

CDlgShuijieyitu2::CDlgShuijieyitu2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SHUIJIEYITU2, pParent)
{

}

CDlgShuijieyitu2::~CDlgShuijieyitu2()
{
}

void CDlgShuijieyitu2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_shuipic2);
}


BEGIN_MESSAGE_MAP(CDlgShuijieyitu2, CDialogEx)
END_MESSAGE_MAP()


// CDlgShuijieyitu2 ��Ϣ�������


BOOL CDlgShuijieyitu2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_shuipic2.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//ͨ��·����ȡbitmap���
	//��βû�У�
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//������ð��տؼ���С

	CRect shuirect2;

	m_shuipic2.GetWindowRect(shuirect2);

	//��̬�ؼ�����bitmap

	m_shuipic2.SetBitmap(HBMP(TEXT("./ͼƬ18.bmp"), shuirect2.Width(), shuirect2.Height()));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
