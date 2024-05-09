
// MFCApplication5Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication5.h"
#include "MFCApplication5Dlg.h"
#include "afxdialogex.h"

#include <vector>
#include <string>

#include "SubDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication5Dlg 대화 상자


CMFCApplication5Dlg::CMFCApplication5Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION5_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CMFCApplication5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MAIN_LIST, m_mainList);
	DDX_Control(pDX, IDC_SECOND_LIST, m_SecondList);
	DDX_Control(pDX, IDC_EDIT_MOD, m_editMod);
}

BEGIN_MESSAGE_MAP(CMFCApplication5Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_DBLCLK, IDC_MAIN_LIST, &CMFCApplication5Dlg::OnNMDblclkMainList)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_SUB_LIST, &CMFCApplication5Dlg::OnLvnItemchangedSubList)
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CMFCApplication5Dlg::OnBnClickedAddButton)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_MAIN_LIST, &CMFCApplication5Dlg::OnLvnItemchangedMainList)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication5Dlg::OnBnClickedMinusButton)

	ON_NOTIFY(NM_CLICK, IDC_MAIN_LIST, &CMFCApplication5Dlg::OnNMClickMainList)
	ON_BN_CLICKED(IDOK, &CMFCApplication5Dlg::OnBnClickedOk)
	ON_NOTIFY(NM_DBLCLK, IDC_SECOND_LIST, &CMFCApplication5Dlg::OnNMDblclkSecondList)
	ON_NOTIFY(NM_CLICK, IDC_SECOND_LIST, &CMFCApplication5Dlg::OnNMClickSecondList)
END_MESSAGE_MAP()


// CMFCApplication5Dlg 메시지 처리기

BOOL CMFCApplication5Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	GetDlgItem(IDC_EDIT_MOD)->SetWindowPos(NULL, 0, 0, 0, 0, SWP_HIDEWINDOW);

	// main list check box 생성
	m_mainList.SetExtendedStyle(LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES );

	m_mainList.InsertColumn(0, _T("ROI"), LVCFMT_LEFT, 160);
	m_mainList.InsertColumn(1, _T("Center X"), LVCFMT_LEFT, 160);
	m_mainList.InsertColumn(2, _T("Center Y"), LVCFMT_LEFT, 160);
	m_mainList.InsertColumn(3, _T("Group"), LVCFMT_LEFT, 160);
	m_mainList.InsertColumn(4, _T("Lower Limit"), LVCFMT_LEFT, 160);
	CString str;

	for (int i = 0; i < 5; i++)
	{
		str.Format(_T("%d"), i);
		m_mainList.InsertItem(i, str);
	}
	
	for (int i = 0; i < 5; i++)
	{
		str.Format(_T("%d"), i);
		m_mainList.SetItem(i, 1, LVIF_TEXT, str, 0, 0, 0, NULL);
	}
	for (int i = 0; i < 5; i++)
	{
		str.Format(_T("%d"), i);
		m_mainList.SetItem(i, 2, LVIF_TEXT, str, 0, 0, 0, NULL);
	}
	for (int i = 0; i < 5; i++)
	{
		str.Format(_T("%d"), i);
		m_mainList.SetItem(i, 3, LVIF_TEXT, str, 0, 0, 0, NULL);
	}

	m_SecondList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_SecondList.InsertColumn(0, _T("ROI"), LVCFMT_LEFT, 160);
	m_SecondList.InsertColumn(1, _T("Center X"), LVCFMT_LEFT, 160);
	m_SecondList.InsertColumn(2, _T("Center Y"), LVCFMT_LEFT, 160);
	m_SecondList.InsertColumn(3, _T("Group"), LVCFMT_LEFT, 160);
	m_SecondList.InsertColumn(4, _T("Lower Limit"), LVCFMT_LEFT, 160);

	m_SecondList.InsertItem(0, _T("first"));
	m_SecondList.InsertItem(1, _T("second"));
	m_SecondList.InsertItem(2, _T("third"));


	m_SecondList.SetItem(0, 1, LVIF_TEXT, _T("1행 2열"), 0, 0, 0, NULL);
	m_SecondList.SetItem(1, 1, LVIF_TEXT, _T("2행 2열"), 0, 0, 0, NULL);
	m_SecondList.SetItem(2, 1, LVIF_TEXT, _T("3행 2열"), 0, 0, 0, NULL);

	int nCol = 4;
	for (int i = 0; i < m_mainList.GetItemCount(); i++) {
		CRect rect;
		m_mainList.GetSubItemRect(i, nCol, LVIR_BOUNDS, rect);

		// 콤보 박스 생성
		pComboBox = new CComboBox();
		pComboBox->Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST , rect, &m_mainList, IDC_COMBO_BOX);

		// 리스트 컨트롤에 콤보 박스 삽입
		m_mainList.SetItemData(i, nCol);

		// 콤보 박스에 항목 추가
		for (int j = 0; j < m_SecondList.GetItemCount(); j++) {
			CString option = m_SecondList.GetItemText(j, 0);
			pComboBox->AddString(option);
		}

		// 배열에 콤보 박스 포인터 저장
		comboBoxArray[i] = pComboBox;
	}

	return TRUE;  
}

void CMFCApplication5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication5Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication5Dlg::OnNMDblclkMainList(NMHDR *pNMHDR, LRESULT *pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	OnNMClickEditBox(pNMItemActivate, m_mainList);
    
    *pResult = 0;
}

void CMFCApplication5Dlg::OnLvnItemchangedSubList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	*pResult = 0;
}
 

void CMFCApplication5Dlg::OnNMDblclkSecondList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	OnNMClickEditBox(pNMItemActivate, m_SecondList);

	*pResult = 0;
}


void CMFCApplication5Dlg::OnLvnItemchangedMainList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	*pResult = 0;
}


void CMFCApplication5Dlg::OnNMClickSecondList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	switchCheckboxState(pNMItemActivate);

	*pResult = 0;
}

void CMFCApplication5Dlg::OnNMClickMainList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	switchCheckboxState(pNMItemActivate);

	*pResult = 0;
}


void CMFCApplication5Dlg::OnBnClickedAddButton()
{
	SubDlg* subDlg = new SubDlg(this);
	subDlg->Create(IDC_SUB_DIALOG, this);
	subDlg->ShowWindow(SW_SHOW);
	m_isValid = 1;
}


void CMFCApplication5Dlg::OnBnClickedMinusButton()
{
	SubDlg* subDlg = new SubDlg(this);
	subDlg->Create(IDC_SUB_DIALOG, this);
	subDlg->ShowWindow(SW_SHOW);
	m_isValid = 0;
}


BOOL CMFCApplication5Dlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN)
		{
			if (pMsg->hwnd == GetDlgItem(IDC_EDIT_MOD)->GetSafeHwnd())
			{
				CString str;
				GetDlgItemText(IDC_EDIT_MOD, str);
				m_mainList.SetItemText(iItemIndex, iItemColumn, str);
				GetDlgItem(IDC_EDIT_MOD)->ShowWindow(SW_HIDE); 
				return TRUE;
			}
		}
		else if (pMsg->wParam == VK_ESCAPE)
		{
			GetDlgItem(IDC_EDIT_MOD)->ShowWindow(SW_HIDE);
			return TRUE;
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}

void CMFCApplication5Dlg::OnNMClickEditBox(LPNMITEMACTIVATE pNMItemActivate, CListCtrl& listControl)
{
	iItemIndex = pNMItemActivate->iItem;
	iItemColumn = pNMItemActivate->iSubItem;

	CRect rect;

	if (iItemColumn == 0)
	{
		listControl.GetItemRect(iItemIndex, rect, LVIR_BOUNDS);
		rect.right = rect.left + listControl.GetColumnWidth(0);
	}
	else
	{
		listControl.GetSubItemRect(iItemIndex, iItemColumn, LVIR_BOUNDS, rect);
	}
	listControl.ClientToScreen(rect);
	this->ScreenToClient(rect);

	GetDlgItem(IDC_EDIT_MOD)->SetWindowText(listControl.GetItemText(iItemIndex, iItemColumn));
	GetDlgItem(IDC_EDIT_MOD)->SetWindowPos(NULL, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, SWP_SHOWWINDOW);
	GetDlgItem(IDC_EDIT_MOD)->SetFocus();

}

void CMFCApplication5Dlg::switchCheckboxState(LPNMITEMACTIVATE pNMItemActivate)
{

	int itemIndex = pNMItemActivate->iItem;

	// edit box 비활성화
	GetDlgItem(IDC_EDIT_MOD)->ShowWindow(SW_HIDE);

	CString str;
	GetDlgItemText(IDC_EDIT_MOD, str);
	if (str != "")
	{
		m_SecondList.SetItemText(iItemIndex, iItemColumn, str);

	}
	else
	{
		str = m_SecondList.GetItemText(iItemIndex, iItemColumn);
		m_SecondList.SetItemText(iItemIndex, iItemColumn, str);
	}

	// 셀 누르면 행 선택돼서 체크박스 check/uncheck
	BOOL checked;
	if (itemIndex != -1)
	{
		checked = m_SecondList.GetCheck(itemIndex);
		m_SecondList.SetCheck(itemIndex, !checked);
	}
}


void CMFCApplication5Dlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}

