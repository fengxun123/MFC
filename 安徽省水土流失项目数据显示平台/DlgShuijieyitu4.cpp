// DlgShuijieyitu4.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgShuijieyitu4.h"
#include "afxdialogex.h"


// CDlgShuijieyitu4 �Ի���

IMPLEMENT_DYNAMIC(CDlgShuijieyitu4, CDialogEx)

CDlgShuijieyitu4::CDlgShuijieyitu4(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SHUIJIEYITU4, pParent)
{

}

CDlgShuijieyitu4::~CDlgShuijieyitu4()
{
}

void CDlgShuijieyitu4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_shuipic4);
}


BEGIN_MESSAGE_MAP(CDlgShuijieyitu4, CDialogEx)
END_MESSAGE_MAP()


// CDlgShuijieyitu4 ��Ϣ�������


BOOL CDlgShuijieyitu4::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_shuipic4.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//ͨ��·����ȡbitmap���
	//��βû�У�
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//������ð��տؼ���С

	CRect shuirect4;

	m_shuipic4.GetWindowRect(shuirect4);

	//��̬�ؼ�����bitmap

	m_shuipic4.SetBitmap(HBMP(TEXT("./ͼƬ20.bmp"), shuirect4.Width(), shuirect4.Height()));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
