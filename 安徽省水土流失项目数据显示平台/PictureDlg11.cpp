// PictureDlg11.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "PictureDlg11.h"


// CPictureDlg11

IMPLEMENT_DYNCREATE(CPictureDlg11, CFormView)

CPictureDlg11::CPictureDlg11()
	: CFormView(DIALOG_PICTURE11)
	, m_text11(_T(""))
	, m_text12(_T(""))
{

}

CPictureDlg11::~CPictureDlg11()
{
}

void CPictureDlg11::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC11, m_pic11);
	DDX_Control(pDX, IDC_PIC12, m_pic12);
	//  DDX_Control(pDX, IDC_EDIT1, m_text11);
	//  DDX_Control(pDX, IDC_EDIT2, m_text12);
	//  DDX_Text(pDX, IDC_EDIT2, m_text11);
	DDX_Text(pDX, IDC_EDIT1, m_text11);
	DDX_Text(pDX, IDC_EDIT2, m_text12);
}

BEGIN_MESSAGE_MAP(CPictureDlg11, CFormView)
	
END_MESSAGE_MAP()


// CPictureDlg11 ���

#ifdef _DEBUG
void CPictureDlg11::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPictureDlg11::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPictureDlg11 ��Ϣ�������


void CPictureDlg11::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	m_text11 =TEXT("�߷ֶ��ŵ�ͼ����ȡʱ�䣺2017��6��15�գ��ֱ���Ϊ��1�ף�������ϣ�432+ȫɫ��");
	m_text12 = TEXT("DEM�߳�Ӱ��ͼ");
	UpdateData(FALSE);//����ͬ�����ؼ���

	//����ɽ����ͼ
	//���þ�̬�ؼ����ڷ��Ϊλͼ������ʾ
	m_pic11.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//ͨ��·����ȡbitmap���
	//��βû�У�
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//������ð��տؼ���С

	CRect rect11;

	m_pic11.GetWindowRect(rect11);

	//��̬�ؼ�����bitmap

	m_pic11.SetBitmap(HBMP(TEXT("./ͼƬ1.bmp"), rect11.Width(), rect11.Height()));

	//����ɽEDMͼ
	m_pic12.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//ͨ��·����ȡbitmap���
	//��βû�У�
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//������ð��տؼ���С

	CRect rect12;
	m_pic12.GetWindowRect(rect12);

	//��̬�ؼ�����bitmap

	m_pic12.SetBitmap(HBMP(TEXT("./ͼƬ2.bmp"), rect12.Width(), rect12.Height()));


}


