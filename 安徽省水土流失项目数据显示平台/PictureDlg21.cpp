// PictureDlg21.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ʡˮ����ʧ��Ŀ������ʾƽ̨.h"
#include "PictureDlg21.h"


// CPictureDlg21

IMPLEMENT_DYNCREATE(CPictureDlg21, CFormView)

CPictureDlg21::CPictureDlg21()
	: CFormView(DIALOG_PICTURE21)
	, m_text21(_T(""))
	, m_text22(_T(""))
{

}

CPictureDlg21::~CPictureDlg21()
{
}

void CPictureDlg21::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC21, m_pic21);
	DDX_Control(pDX, IDC_PIC22, m_pic22);
	DDX_Text(pDX, IDC_EDIT1, m_text21);
	DDX_Text(pDX, IDC_EDIT2, m_text22);
}

BEGIN_MESSAGE_MAP(CPictureDlg21, CFormView)
END_MESSAGE_MAP()


// CPictureDlg21 ���

#ifdef _DEBUG
void CPictureDlg21::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPictureDlg21::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPictureDlg21 ��Ϣ�������


void CPictureDlg21::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���

	m_text21 = TEXT("�߷ֶ��ŵ�ͼ����ȡʱ�䣺2017��6��15�գ��ֱ���Ϊ��1�ף�������ϣ�432+ȫɫ��");
	m_text22 = TEXT("DEM�߳�Ӱ��ͼ");
	UpdateData(FALSE);//����ͬ�����ؼ���

					  //����ɽ����ͼ
					  //���þ�̬�ؼ����ڷ��Ϊλͼ������ʾ
	m_pic21.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//ͨ��·����ȡbitmap���
	//��βû�У�
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//������ð��տؼ���С

	CRect rect21;

	m_pic21.GetWindowRect(rect21);

	//��̬�ؼ�����bitmap

	m_pic21.SetBitmap(HBMP(TEXT("./ͼƬ3.bmp"), rect21.Width(), rect21.Height()));

	//����ɽEDMͼ
	m_pic22.ModifyStyle(0xf, SS_BITMAP | SS_CENTERIMAGE);

	//ͨ��·����ȡbitmap���
	//��βû�У�
#define HBMP(filepath,width,height)(HBITMAP)LoadImage(AfxGetInstanceHandle(),filepath,IMAGE_BITMAP,width,height,LR_LOADFROMFILE|LR_CREATEDIBSECTION)

	//������ð��տؼ���С

	CRect rect22;
	m_pic22.GetWindowRect(rect22);

	//��̬�ؼ�����bitmap

	m_pic22.SetBitmap(HBMP(TEXT("./ͼƬ4.bmp"), rect22.Width(), rect22.Height()));


}
