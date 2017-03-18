#pragma once


// CPatternDlg 对话框

class CPatternDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPatternDlg)

public:
	CPatternDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPatternDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	float m_SquareSize;
	int m_PatternWidth;
	int m_PatternHeight;
	BOOL m_IsChess;
	BOOL m_IsWhite;
};
