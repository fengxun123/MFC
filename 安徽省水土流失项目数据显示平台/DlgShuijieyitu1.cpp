// DlgShuijieyitu1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgShuijieyitu1.h"
#include "afxdialogex.h"


// CDlgShuijieyitu1 �Ի���

IMPLEMENT_DYNAMIC(CDlgShuijieyitu1, CDialogEx)

CDlgShuijieyitu1::CDlgShuijieyitu1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SHUIJIEYITU1, pParent)
{

}

CDlgShuijieyitu1::~CDlgShuijieyitu1()
{
}

void CDlgShuijieyitu1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_shuipic1);
}


BEGIN_MESSAGE_MAP(CDlgShuijieyitu1, CDialogEx)
END_MESSAGE_MAP()


// CDlgShuijieyitu1 ��Ϣ�������


BOOL CDlgShuijieyitu1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_shuipic1.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//ͨ��·����ȡbitmap���
	//��βû�У�
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//������ð��տؼ���С

	CRect shuirect1;

	m_shuipic1.GetWindowRect(shuirect1);

	//��̬�ؼ�����bitmap

	m_shuipic1.SetBitmap(HBMP(TEXT("./ͼƬ17.bmp"), shuirect1.Width(), shuirect1.Height()));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
