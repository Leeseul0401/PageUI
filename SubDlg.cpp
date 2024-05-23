// SubDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication5.h"
#include "SubDlg.h"
#include "afxdialogex.h"

#include "MFCApplication5Dlg.h"

// SubDlg 대화 상자 

IMPLEMENT_DYNAMIC(SubDlg, CDialogEx)

SubDlg::SubDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDC_SUB_DIALOG, pParent)
{
	this->pParent = (CMFCApplication5Dlg*)(pParent);
	//CString str;
	//int itemCount = pParent->m_mainList.GetItemCount();
	//for (int i = 0; i < itemCount; ++i) {
	//	CString itemText = pParent->m_mainList.GetItemText(i, 0);
	//	//m_subListCntrl.InsertItem(i, _T("0행 1열")); 
	//}
	////m_subListCntrl.SetExtendedStyle(LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	//m_subListCntrl.InsertColumn(0, _T("ROI"), LVCFMT_LEFT, 100);
	//m_subListCntrl.InsertItem(0, _T("TEMP"));
}

SubDlg::~SubDlg()
{
}


BOOL SubDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	int itemCount = pParent->m_SecondList.GetItemCount();
	for (int i = 0; i < itemCount; i++) {
		CString itemText = pParent->m_SecondList.GetItemText(i, 0);

		m_subList.AddString(itemText);
	}
	return TRUE;
}

void SubDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ADD_EDIT, m_addEdit);
	DDX_Control(pDX, IDC_SUB_LIST, m_subList);
}

BEGIN_MESSAGE_MAP(SubDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_BUTTON, &SubDlg::OnBnClickedAddButton)
	ON_BN_CLICKED(IDC_BUTTON2, &SubDlg::OnBnClickedButton2)
END_MESSAGE_MAP()



// SubDlg 메시지 처리기


void SubDlg::OnBnClickedAddButton()
{
	int isValid = pParent->m_isValid;
	CString strInput;
	m_addEdit.GetWindowTextW(strInput);
	if (isValid == 1)
	{
		// SecondList에 원소 추가
		pParent->m_SecondList.InsertItem(pParent->m_SecondList.GetItemCount() , strInput);
		int count = pParent->m_mainList.GetItemCount();

		for (int i = 0; i < count; i++) {
			//CString option = pParent->m_SecondList.GetItemText(i, 0);
			pParent->comboBoxArray[i]->AddString(strInput);
		}

		::SendMessage(this->m_hWnd, WM_CLOSE, NULL, NULL);
	}
	else
	{
 		int index = m_subList.GetCurSel();
		if (index != LB_ERR) 
		{
			CString strItemText;
			m_subList.GetText(index, strItemText);

			int count = pParent->m_SecondList.GetItemCount();
			for (int i = 0; i < count; i++)
			{
				CString strListItem = pParent->m_SecondList.GetItemText(i, 0);
				if (strListItem == strItemText)
				{
					pParent->m_SecondList.DeleteItem(i);
					for (int j = 0; j < pParent->m_mainList.GetItemCount(); j++) 
					{
						pParent->comboBoxArray[j]->DeleteString(index);
					}
					::SendMessage(this->m_hWnd, WM_CLOSE, NULL, NULL);
					break;
				}
			}
		}


	}
}

void SubDlg::OnBnClickedButton2()
{
	CDialogEx::OnOK();
}
