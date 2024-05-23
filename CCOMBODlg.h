
// CCOMBODlg.h : header file
//

#pragma once
#include "Combo.h"

// CCCOMBODlg dialog
class CCCOMBODlg : public CDialogEx
{
// Construction
public:
	ChkCombo m_Combo;
	ChkCombo m_Combo2;
	CCCOMBODlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
//	enum { IDD = IDD_CCOMBO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
		
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();


	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo1();
	LRESULT OnChecked(WPARAM wp, LPARAM lp);

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
