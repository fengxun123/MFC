// DlgZhijieyitu2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhijieyitu2.h"
#include "afxdialogex.h"


// CDlgZhijieyitu2 �Ի���

IMPLEMENT_DYNAMIC(CDlgZhijieyitu2, CDialogEx)

CDlgZhijieyitu2::CDlgZhijieyitu2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIJIEYITU2, pParent)
{

}

CDlgZhijieyitu2::~CDlgZhijieyitu2()
{
}

void CDlgZhijieyitu2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_zhipic2);
}


BEGIN_MESSAGE_MAP(CDlgZhijieyitu2, CDialogEx)
END_MESSAGE_MAP()


// CDlgZhijieyitu2 ��Ϣ�������


BOOL CDlgZhijieyitu2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_zhipic2.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//ͨ��·����ȡbitmap���
	//��βû�У�
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//������ð��տؼ���С

	CRect zhirect2;

	m_zhipic2.GetWindowRect(zhirect2);

	//��̬�ؼ�����bitmap

	m_zhipic2.SetBitmap(HBMP(TEXT("./ͼƬ14.bmp"), zhirect2.Width(), zhirect2.Height()));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
