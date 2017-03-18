// RInputDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "hand_eye_calibration_app.h"
#include "RInputDlg.h"
#include "afxdialogex.h"


// CRInputDlg 对话框

IMPLEMENT_DYNAMIC(CRInputDlg, CDialogEx)

CRInputDlg::CRInputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRInputDlg::IDD, pParent)
	, R(3, 3, CV_32F, Scalar(0))
	, T(3, 1, CV_32F, Scalar(0))
{
}

CRInputDlg::~CRInputDlg()
{
}

BOOL CRInputDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	auto iter_image_list = s_imageList.begin();
	for (; iter_image_list != s_imageList.end(); iter_image_list++){
		m_listBox.AddString(*iter_image_list);
	}
	return TRUE;
}

void CRInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listBox);
	DDX_Control(pDX, IDC_IMAGE1, m_image1);
	DDX_Control(pDX, IDC_IMAGE2, m_image2);
	DDX_Text(pDX, IDC_EDIT1, R.at<float>(0, 0));
	DDX_Text(pDX, IDC_EDIT2, R.at<float>(0, 1));
	DDX_Text(pDX, IDC_EDIT3, R.at<float>(0, 2));
	DDX_Text(pDX, IDC_EDIT4, R.at<float>(1, 0));
	DDX_Text(pDX, IDC_EDIT5, R.at<float>(1, 1));
	DDX_Text(pDX, IDC_EDIT6, R.at<float>(1, 2));
	DDX_Text(pDX, IDC_EDIT7, R.at<float>(2, 0));
	DDX_Text(pDX, IDC_EDIT8, R.at<float>(2, 1));
	DDX_Text(pDX, IDC_EDIT9, R.at<float>(2, 2));
	DDX_Text(pDX, IDC_EDIT14, T.at<float>(0));
	DDX_Text(pDX, IDC_EDIT15, T.at<float>(1));
	DDX_Text(pDX, IDC_EDIT16, T.at<float>(2));
}


BEGIN_MESSAGE_MAP(CRInputDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CRInputDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRInputDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CRInputDlg 消息处理程序


void CRInputDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	int nCursel;
	nCursel = m_listBox.GetCurSel();
	Rodrigues(rvecs[nCursel], R1);
	T1 = tvecs[nCursel];

	//显示图片

	CImage c_image;
	Mat image = image_corner[nCursel];

	//create new CImage  
	int width = image.cols;
	int height = image.rows;
	int channels = image.channels();

	c_image.Destroy(); //clear  
	c_image.Create(width,
		height, //positive: left-bottom-up   or negative: left-top-down  
		8 * channels); //numbers of bits per pixel  

	//copy values  
	uchar* ps;
	uchar* pimg = (uchar*)c_image.GetBits(); //A pointer to the bitmap buffer  

	//The pitch is the distance, in bytes. represent the beginning of   
	// one bitmap line and the beginning of the next bitmap line  
	int step = c_image.GetPitch();

	for (int i = 0; i < height; ++i)
	{
		ps = (image.ptr<uchar>(i));
		for (int j = 0; j < width*3; ++j)
		{
			*(pimg + i*step + j) = ps[j];
		}
	}

	CRect rect;//定义矩形类  
	int cx = c_image.GetWidth();//获取图片宽度  
	int cy = c_image.GetHeight();//获取图片高度  

	GetDlgItem(IDC_IMAGE1)->GetWindowRect(&rect);//将窗口矩形选中到picture控件上  
	ScreenToClient(&rect);//将客户区选中到Picture控件表示的矩形区域内  
	GetDlgItem(IDC_IMAGE1)->MoveWindow(rect, TRUE);//将窗口移动到Picture控件表示的矩形区域  

	CWnd *pWnd = GetDlgItem(IDC_IMAGE1);//获得pictrue控件窗口的句柄  

	pWnd->GetClientRect(&rect);//获得pictrue控件所在的矩形区域  

	CDC *pDC = pWnd->GetDC();//获得pictrue控件的DC  

	pDC->SetStretchBltMode(COLORONCOLOR);
//	img.Draw(pDC->m_hDC, dispRect);

	c_image.Draw(pDC->m_hDC, rect); //将图片画到Picture控件表示的矩形区域  
	ReleaseDC(pDC);//释放picture控件的DC  
}


void CRInputDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	int nCursel;
	nCursel = m_listBox.GetCurSel();
	Rodrigues(rvecs[nCursel], R2);
	T2 = tvecs[nCursel];

	//显示图片

	CImage c_image;
	Mat image = image_corner[nCursel];

	//create new CImage  
	int width = image.cols;
	int height = image.rows;
	int channels = image.channels();

	c_image.Destroy(); //clear  
	c_image.Create(width,
		height, //positive: left-bottom-up   or negative: left-top-down  
		8 * channels); //numbers of bits per pixel  

	//copy values  
	uchar* ps;
	uchar* pimg = (uchar*)c_image.GetBits(); //A pointer to the bitmap buffer  

	//The pitch is the distance, in bytes. represent the beginning of   
	// one bitmap line and the beginning of the next bitmap line  
	int step = c_image.GetPitch();

	for (int i = 0; i < height; ++i)
	{
		ps = (image.ptr<uchar>(i));
		for (int j = 0; j < width; ++j)
		{
			if (channels == 1) //gray  
			{
				*(pimg + i*step + j) = ps[j];
			}
			else if (channels == 3) //color  
			{
				for (int k = 0; k < 3; ++k)
				{
					*(pimg + i*step + j * 3 + k) = ps[j * 3 + k];
				}
			}
		}
	}

	CRect rect;//定义矩形类  
	int cx = c_image.GetWidth();//获取图片宽度  
	int cy = c_image.GetHeight();//获取图片高度  

	GetDlgItem(IDC_IMAGE2)->GetWindowRect(&rect);//将窗口矩形选中到picture控件上  
	ScreenToClient(&rect);//将客户区选中到Picture控件表示的矩形区域内  
	GetDlgItem(IDC_IMAGE2)->MoveWindow(rect, TRUE);//将窗口移动到Picture控件表示的矩形区域  

	CWnd *pWnd = GetDlgItem(IDC_IMAGE2);//获得pictrue控件窗口的句柄  

	pWnd->GetClientRect(&rect);//获得pictrue控件所在的矩形区域  

	CDC *pDC = pWnd->GetDC();//获得pictrue控件的DC  

	pDC->SetStretchBltMode(COLORONCOLOR);

	c_image.Draw(pDC->m_hDC, rect); //将图片画到Picture控件表示的矩形区域  
	ReleaseDC(pDC);//释放picture控件的DC  
}
