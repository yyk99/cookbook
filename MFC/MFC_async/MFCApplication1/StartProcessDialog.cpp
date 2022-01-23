// StartProcessDialog.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication1.h"
#include "StartProcessDialog.h"
#include "afxdialogex.h"


// StartProcessDialog dialog

IMPLEMENT_DYNAMIC(StartProcessDialog, CDialogEx)

StartProcessDialog::StartProcessDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_START_PROCESS, pParent)
{
    m_progress_caption.SetW
}

StartProcessDialog::~StartProcessDialog()
{
}

void StartProcessDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_PROGRESS1, m_progress);
    DDX_Control(pDX, IDC_PROGRESS_CAPTION, m_progress_caption);
    DDX_Control(pDX, IDC_PROGRESS_STATUS, m_progress_status);
}


BEGIN_MESSAGE_MAP(StartProcessDialog, CDialogEx)
    ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &StartProcessDialog::OnNMCustomdrawProgress1)
END_MESSAGE_MAP()


// StartProcessDialog message handlers


void StartProcessDialog::OnNMCustomdrawProgress1(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
    // TODO: Add your control notification handler code here
    *pResult = 0;
}
