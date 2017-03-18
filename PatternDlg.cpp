// PatternDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "hand_eye_calibration_app.h"
#include "PatternDlg.h"
#include "afxdialogex.h"


// CPatternDlg 对话框

IMPLEMENT_DYNAMIC(CPatternDlg, CDialogEx)

CPatternDlg::CPatternDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPatternDlg::IDD, pParent)
	, m_SquareSize(0)
	, m_PatternWidth(0)
	, m_PatternHeight(0)
	, m_IsChess(FALSE)
	, m_IsWhite(FALSE)
{

}

CPatternDlg::~CPatternDlg()
{
}

void CPatternDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SQUARE_SIZE, m_SquareSize);
	DDX_Text(pDX, IDC_PATTERN_WIDTH, m_PatternWidth);
	DDX_Text(pDX, IDC_PATTERN_HEIGHT, m_PatternHeight);
	DDX_Radio(pDX, IDC_PATTERN_CHESS, m_IsChess);
	DDX_Radio(pDX, IDC_EDGE_WHITE, m_IsWhite);
}


BEGIN_MESSAGE_MAP(CPatternDlg, CDialogEx)
END_MESSAGE_MAP()


// CPatternDlg 消息处理程序
