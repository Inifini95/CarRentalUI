
// CARrentalUI.h : main header file for the PROJECT_NAME application
//
#include "pch.h"
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCARrentalUIApp:
// See CARrentalUI.cpp for the implementation of this class
//

class CCARrentalUIApp : public CWinApp
{
public:
	CCARrentalUIApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CCARrentalUIApp theApp;
