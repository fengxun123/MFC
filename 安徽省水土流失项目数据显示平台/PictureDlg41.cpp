// PictureDlg41.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "PictureDlg41.h"


// CPictureDlg41

IMPLEMENT_DYNCREATE(CPictureDlg41, CFormView)

CPictureDlg41::CPictureDlg41()
	: CFormView(DIALOG_PICTURE41)
	, m_text41(_T(""))
	, m_text42(_T(""))
{

}

CPictureDlg41::~CPictureDlg41()
{
}

void CPictureDlg41::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC11, m_pic41);
	DDX_Control(pDX, IDC_PIC12, m_pic42);
	DDX_Text(pDX, IDC_EDIT1, m_text41);
	DDX_Text(pDX, IDC_EDIT2, m_text42);
}

BEGIN_MESSAGE_MAP(CPictureDlg41, CFormView)
END_MESSAGE_MAP()


// CPictureDlg41 ���

#ifdef _DEBUG
void CPictureDlg41::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPictureDlg41::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPictureDlg41 ��Ϣ�������


void CPictureDlg41::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���

	m_text41 = TEXT("�߷ֶ��ŵ�ͼ����ȡʱ�䣺2017��6��15�գ��ֱ���Ϊ��1�ף�������ϣ�432+ȫɫ��");
	m_text42 = TEXT("DEM�߳�Ӱ��ͼ");
	UpdateData(FALSE);//����ͬ�����ؼ���

					  //������������ͼ
					  //���þ�̬�ؼ����ڷ��Ϊλͼ������ʾ
	m_pic41.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//ͨ��·����ȡbitmap���
	//��βû�У�
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//������ð��տؼ���С

	CRect rect41;

	m_pic41.GetWindowRect(rect41);

	//��̬�ؼ�����bitmap

	m_pic41.SetBitmap(HBMP(TEXT("./ͼƬ7.bmp"), rect41.Width(), rect41.Height()));

	
	//��������EDMͼ
	m_pic42.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//ͨ��·����ȡbitmap���
	//��βû�У�
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//������ð��տؼ���С

	CRect rect42;
	m_pic42.GetWindowRect(rect42);

	//��̬�ؼ�����bitmap

	m_pic42.SetBitmap(HBMP(TEXT("./ͼƬ8.bmp"), rect42.Width(), rect42.Height()));

}
