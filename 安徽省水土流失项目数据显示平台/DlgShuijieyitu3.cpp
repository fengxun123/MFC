// DlgShuijieyitu3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgShuijieyitu3.h"
#include "afxdialogex.h"


// CDlgShuijieyitu3 �Ի���

IMPLEMENT_DYNAMIC(CDlgShuijieyitu3, CDialogEx)

CDlgShuijieyitu3::CDlgShuijieyitu3(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SHUIJIEYITU3, pParent)
{

}

CDlgShuijieyitu3::~CDlgShuijieyitu3()
{
}

void CDlgShuijieyitu3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_shuipic3);
}


BEGIN_MESSAGE_MAP(CDlgShuijieyitu3, CDialogEx)
END_MESSAGE_MAP()


// CDlgShuijieyitu3 ��Ϣ�������


BOOL CDlgShuijieyitu3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_shuipic3.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//ͨ��·����ȡbitmap���
	//��βû�У�
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//������ð��տؼ���С

	CRect shuirect3;

	m_shuipic3.GetWindowRect(shuirect3);

	//��̬�ؼ�����bitmap

	m_shuipic3.SetBitmap(HBMP(TEXT("./ͼƬ19.bmp"), shuirect3.Width(), shuirect3.Height()));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
