
// CCOMBODlg.cpp : implementation file
//

#include "stdafx.h"
#include "CCOMBO.h"
#include "CCOMBODlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCCOMBODlg dialog




CCCOMBODlg::CCCOMBODlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCCOMBODlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCCOMBODlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
	DDX_Control(pDX, IDC_COMBO2, m_Combo2);
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCCOMBODlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CCCOMBODlg::OnCbnSelchangeCombo1)
	
	//ON_WM_HOTKEY(THIS_CHECKED, &CCCOMBODlg::OnChecked)
	ON_MESSAGE(THIS_CHECKED, &CCCOMBODlg::OnChecked)
	

	ON_BN_CLICKED(IDC_BUTTON1, &CCCOMBODlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCCOMBODlg::OnBnClickedButton2)


	

END_MESSAGE_MAP()


// CCCOMBODlg message handlers



BOOL CCCOMBODlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here


	m_Combo2.AddString(L"0");
	m_Combo2.AddString(L"1");
	m_Combo2.AddString(L"2");
	m_Combo2.AddString(L"3");
	m_Combo2.AddString(L"4");
	m_Combo2.AddString(L"5");
	m_Combo2.AddString(L"6");
	m_Combo2.AddString(L"7");
	m_Combo2.AddString(L"8");
	m_Combo2.AddString(L"9");

	m_Combo.AddString(L"Red");
	m_Combo.AddString(L"Green");
	m_Combo.AddString(L"Blue");
	m_Combo.AddString(L"Black");
	m_Combo.AddString(L"White");
	m_Combo.AddString(L"Yellow");
	m_Combo.AddString(L"Brown");



	//::SendMessage(m_Combo.GetSafeHwnd(), CB_DELETESTRING,1,1);

	// Select some colors

	m_Combo.SetCheck(0, TRUE);
	m_Combo.SetCheck(1, TRUE);
	m_Combo.SetCheck(2, TRUE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCCOMBODlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCCOMBODlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCCOMBODlg::OnCbnSelchangeCombo1()
{
	DWORD mask = m_Combo.GetChecked();
	wchar_t mask_s[32];
	memset(mask_s, 0, 32 * sizeof(wchar_t));
	wsprintf(mask_s, L"%d", mask);
	GetDlgItem(IDC_STATIC_MASK)->SetWindowText(mask_s);
	return;
	// TODO: Add your control notification handler code here
}




LRESULT CCCOMBODlg::OnChecked(WPARAM wp, LPARAM lp)
{
	int ID = (DWORD)lp;
	int index = LOWORD(wp);
	bool flag = HIWORD(wp);
	
	wchar_t text_s[32];
	memset(text_s, 0, 32 * sizeof(wchar_t));
	wsprintf(text_s, L"%d __ %d", index, flag);
	if(ID == IDC_COMBO1)
		GetDlgItem(IDC_STATIC_CHK)->SetWindowText(text_s);
	return 0;
}

void CCCOMBODlg::OnBnClickedButton1()
{
	GetDlgItem(IDC_COMBO1)->EnableWindow(TRUE);
	// TODO: Add your control notification handler code here
}


void CCCOMBODlg::OnBnClickedButton2()
{
	GetDlgItem(IDC_COMBO1)->EnableWindow(FALSE);
	// TODO: Add your control notification handler code here
}
