#pragma once


// SubDlg 대화 상자
class CMFCApplication5Dlg;
class SubDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SubDlg)

public:
	SubDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~SubDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDC_SUB_DIALOG };
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

protected:
	virtual BOOL OnInitDialog();
	
	DECLARE_MESSAGE_MAP();
public:
	CMFCApplication5Dlg* pParent;
	CListBox m_subList;
	CEdit m_addEdit;
	
	afx_msg void OnBnClickedAddButton();
	afx_msg void OnBnClickedButton2();
};
