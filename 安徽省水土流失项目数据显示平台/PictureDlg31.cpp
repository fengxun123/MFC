// PictureDlg31.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "PictureDlg31.h"


// CPictureDlg31

IMPLEMENT_DYNCREATE(CPictureDlg31, CFormView)

CPictureDlg31::CPictureDlg31()
	: CFormView(DIALOG_PICTURE31)
	, m_text31(_T(""))
	, m_text32(_T(""))
{

}

CPictureDlg31::~CPictureDlg31()
{
}

void CPictureDlg31::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC21, m_pic31);
	DDX_Control(pDX, IDC_PIC23, m_pic32);
	DDX_Text(pDX, IDC_EDIT1, m_text31);
	DDX_Text(pDX, IDC_EDIT2, m_text32);
}

BEGIN_MESSAGE_MAP(CPictureDlg31, CFormView)
END_MESSAGE_MAP()


// CPictureDlg31 ���

#ifdef _DEBUG
void CPictureDlg31::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPictureDlg31::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPictureDlg31 ��Ϣ�������


void CPictureDlg31::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	m_text31 = TEXT("�߷ֶ��ŵ�ͼ����ȡʱ�䣺2017��6��15�գ��ֱ���Ϊ��1�ף�������ϣ�432+ȫɫ��");
	m_text32 = TEXT("DEM�߳�Ӱ��ͼ");
	UpdateData(FALSE);//����ͬ�����ؼ���

					  //����ɽ����ͼ
					  //���þ�̬�ؼ����ڷ��Ϊλͼ������ʾ
	m_pic31.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//ͨ��·����ȡbitmap���
	//��βû�У�
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//������ð��տؼ���С

	CRect rect31;

	m_pic31.GetWindowRect(rect31);

	//��̬�ؼ�����bitmap

	m_pic31.SetBitmap(HBMP(TEXT("./ͼƬ5.bmp"), rect31.Width(), rect31.Height()));

	//����ɽEDMͼ
	m_pic32.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//ͨ��·����ȡbitmap���
	//��βû�У�
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//������ð��տؼ���С

	CRect rect32;
	m_pic32.GetWindowRect(rect32);

	//��̬�ؼ�����bitmap

	m_pic32.SetBitmap(HBMP(TEXT("./ͼƬ6.bmp"), rect32.Width(), rect32.Height()));

}
