// DlgZhijieyitu1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhijieyitu1.h"
#include "afxdialogex.h"


// CDlgZhijieyitu1 �Ի���

IMPLEMENT_DYNAMIC(CDlgZhijieyitu1, CDialogEx)

CDlgZhijieyitu1::CDlgZhijieyitu1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIJIEYITU1, pParent)
{

}

CDlgZhijieyitu1::~CDlgZhijieyitu1()
{
}

void CDlgZhijieyitu1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_zhipic1);
}


BEGIN_MESSAGE_MAP(CDlgZhijieyitu1, CDialogEx)
END_MESSAGE_MAP()


// CDlgZhijieyitu1 ��Ϣ�������


BOOL CDlgZhijieyitu1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_zhipic1.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//ͨ��·����ȡbitmap���
	//��βû�У�
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//������ð��տؼ���С

	CRect zhirect1;

	m_zhipic1.GetWindowRect(zhirect1);

	//��̬�ؼ�����bitmap

	m_zhipic1.SetBitmap(HBMP(TEXT("./ͼƬ13.bmp"), zhirect1.Width(), zhirect1.Height()));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
