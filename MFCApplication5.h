﻿
// MFCApplication5.h: PROJECT_NAME 응용 프로그램에 대한 주 헤더 파일입니다.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "Resource.h"		// 주 기호입니다.
#define MAX_SIZE_CHK 64

// CMFCApplication5App:
// 이 클래스의 구현에 대해서는 MFCApplication5.cpp을(를) 참조하세요.
//

class CMFCApplication5App : public CWinApp
{
public:
	CMFCApplication5App();
	bool checked_arr[MAX_SIZE_CHK];
// 재정의입니다.
public:
	virtual BOOL InitInstance();

// 구현입니다.

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication5App theApp;
