// FormView1.cpp : 实现文件
//

#include "stdafx.h"
#include "hand_eye_calibration_app.h"
#include "FormView1.h"


// FormView1

IMPLEMENT_DYNCREATE(FormView1, CFormView)

FormView1::FormView1()
	: CFormView(FormView1::IDD)
{

}

FormView1::~FormView1()
{
}

void FormView1::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(FormView1, CFormView)
END_MESSAGE_MAP()


// FormView1 诊断

#ifdef _DEBUG
void FormView1::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void FormView1::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// FormView1 消息处理程序
