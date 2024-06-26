﻿
// MFCApplication5Dlg.h: 헤더 파일
//

#pragma once
#include <vector>
#include <afxwin.h>
#include <map>
#include "Combo.h"

class SubDlg;
class CCheckComboBox;
// CMFCApplication5Dlg 대화 상자
class CMFCApplication5Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplication5Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION5_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	std::vector<CString> m_comboOptions;
	std::map<std::pair<int, int>, CComboBox*> comboBoxMap;
	DECLARE_MESSAGE_MAP();
	HWND m_hFocus;
public:
	int iItemIndex;
	int iItemColumn;
	int m_isValid;
	void OnDblclkMainList(NMHDR *pNMHDR, LRESULT *pResult);
	void OnNMClickEditBox(LPNMITEMACTIVATE pNMItemActivate, CListCtrl& listControl);
	void switchCheckboxStateSecondList(LPNMITEMACTIVATE pNMItemActivate);
	void switchCheckboxStateList(LPNMITEMACTIVATE pNMItemActivate, CListCtrl& listControl);
	void CreateComboBox();
	BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnLvnItemchangedSubList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedAddButton();
	afx_msg void OnLvnItemchangedMainList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedMinusButton();                  
	afx_msg void OnNMClickMainList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnNMDblclkSecondList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSecondList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeComboBox();
private:
	CEdit* m_pEdit;
	CEdit m_editMod;
	static const int MAX_ROWS = 100;
public:
	std::vector<CString> m_comboItems;
	CComboBox* pComboBox;
	ChkCombo* combo;
	CComboBox* comboBoxArray[MAX_ROWS];
	CListCtrl m_mainList;
	CListCtrl m_SecondList;
	CImageList UserImgList;
	CString m_strModelName;
	CArray<int, int> m_selectedItems;
	
	CStatic m_staticList;
};
