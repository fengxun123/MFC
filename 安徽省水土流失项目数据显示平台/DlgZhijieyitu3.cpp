// DlgZhijieyitu3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "DlgZhijieyitu3.h"
#include "afxdialogex.h"


// CDlgZhijieyitu3 �Ի���

IMPLEMENT_DYNAMIC(CDlgZhijieyitu3, CDialogEx)

CDlgZhijieyitu3::CDlgZhijieyitu3(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ZHIJIEYITU3, pParent)
{

}

CDlgZhijieyitu3::~CDlgZhijieyitu3()
{
}

void CDlgZhijieyitu3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TUPIC, m_zhipic3);
}


BEGIN_MESSAGE_MAP(CDlgZhijieyitu3, CDialogEx)
END_MESSAGE_MAP()


// CDlgZhijieyitu3 ��Ϣ�������


BOOL CDlgZhijieyitu3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_zhipic3.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//ͨ��·����ȡbitmap���
	//��βû�У�
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//������ð��տؼ���С

	CRect zhirect3;

	m_zhipic3.GetWindowRect(zhirect3);

	//��̬�ؼ�����bitmap

	m_zhipic3.SetBitmap(HBMP(TEXT("./ͼƬ15.bmp"), zhirect3.Width(), zhirect3.Height()));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
