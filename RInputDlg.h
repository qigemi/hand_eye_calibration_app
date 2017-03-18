#pragma once
#include "opencv2\opencv.hpp"
#include "afxwin.h"

using namespace std;
using namespace cv;

// CRInputDlg 对话框

class CRInputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRInputDlg)

public:
	CRInputDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CRInputDlg();

	BOOL OnInitDialog();

	vector<CString> s_imageList;
	vector<Mat> rvecs, tvecs;
	vector<Mat> image_corner;
//	Mat A, B;
	Mat R1, R2, T1, T2;

// 对话框数据
	enum { IDD = IDD_RINPUT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listBox;
	afx_msg void OnBnClickedButton1();
	CStatic m_image1;
	CStatic m_image2;
	afx_msg void OnBnClickedButton2();
	Mat R, T;
	/*CString R11;
	CString R12;
	CString R13;
	CString R21;
	CString R22;
	CString R23;
	CString R31;
	CString R32;
	CString R33;
	CString T11;
	CString T21;
	CString T31;*/
};
