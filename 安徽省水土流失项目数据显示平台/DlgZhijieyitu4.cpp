// DlgZhijieyitu4.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhijieyitu4.h"
#include "afxdialogex.h"


// CDlgZhijieyitu4 �Ի���

IMPLEMENT_DYNAMIC(CDlgZhijieyitu4, CDialogEx)

CDlgZhijieyitu4::CDlgZhijieyitu4(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIJIEYITU4, pParent)
{

}

CDlgZhijieyitu4::~CDlgZhijieyitu4()
{
}

void CDlgZhijieyitu4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_zhipic4);
}


BEGIN_MESSAGE_MAP(CDlgZhijieyitu4, CDialogEx)
END_MESSAGE_MAP()


// CDlgZhijieyitu4 ��Ϣ�������


BOOL CDlgZhijieyitu4::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_zhipic4.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//ͨ��·����ȡbitmap���
	//��βû�У�
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//������ð��տؼ���С

	CRect zhirect4;

	m_zhipic4.GetWindowRect(zhirect4);

	//��̬�ؼ�����bitmap

	m_zhipic4.SetBitmap(HBMP(TEXT("./ͼƬ16.bmp"), zhirect4.Width(), zhirect4.Height()));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
