// VisualCardMonitor.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "VisualCardMonitor.h"
#include "VisualCardMonitorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define PROC_ID "0x50dd5230, 0xba8a, 0x11d1, 0xbf, 0x5d,0x00, 0x00, 0xf8, 0x05, 0xf5, 0x30"

// CVisualCardMonitorApp

BEGIN_MESSAGE_MAP(CVisualCardMonitorApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CVisualCardMonitorApp construction

CVisualCardMonitorApp::CVisualCardMonitorApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CVisualCardMonitorApp object

CVisualCardMonitorApp theApp;

HANDLE AppHandle;

// CVisualCardMonitorApp initialization

BOOL CVisualCardMonitorApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	AppHandle = CreateMutex(NULL, FALSE, PROC_ID);
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		AfxMessageBox("�����Ѿ�����");
		return FALSE;
	}

	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CVisualCardMonitorDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
