#pragma once
#include "opencv2\opencv.hpp"
#include "afxwin.h"

using namespace std;
using namespace cv;

// CHandeyeParaDlg 对话框

class CHandeyeParaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHandeyeParaDlg)

public:
	CHandeyeParaDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CHandeyeParaDlg();

	vector<Mat> A, B;
	int i;
	vector<CString> s_imageList;
	vector<Mat> rvecs, tvecs;
	vector<Mat> image_corner;

// 对话框数据
	enum { IDD = IDD_HANDEYEPARA_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	CListBox m_listBox;
	afx_msg void OnBnClickedButton1();
};
