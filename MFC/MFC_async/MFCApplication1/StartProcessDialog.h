#pragma once


// StartProcessDialog dialog

class StartProcessDialog : public CDialogEx
{
    DECLARE_DYNAMIC(StartProcessDialog)

public:
    StartProcessDialog(CWnd* pParent = nullptr);   // standard constructor
    virtual ~StartProcessDialog();

    // Dialog Data
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_START_PROCESS };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnNMCustomdrawProgress1(NMHDR* pNMHDR, LRESULT* pResult);
    CProgressCtrl m_progress;
    CStatic m_progress_caption;
    CStatic m_progress_status;
};
