
// CARrentalUIDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CARrentalUI.h"
#include "CARrentalUIDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAddCar();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_ADD_CAR, &CAboutDlg::OnBnClickedAddCar)
END_MESSAGE_MAP()


// CCARrentalUIDlg dialog



CCARrentalUIDlg::CCARrentalUIDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CARRENTALUI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCARrentalUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCARrentalUIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_CAR, &CCARrentalUIDlg::OnBnClickedAddCar)
	ON_CBN_SELCHANGE(IDC_COMBO_ADD_CAR, &CCARrentalUIDlg::OnCbnSelchangeComboAddCar)
	ON_CBN_SELCHANGE(IDC_Car_Model, &CCARrentalUIDlg::OnCbnSelchangeCarModel)
	ON_EN_CHANGE(IDC_ADD_CAR_COLOR, &CCARrentalUIDlg::OnEnChangeAddCarColor)
	ON_EN_CHANGE(IDC_ADD_CAR_YEAR, &CCARrentalUIDlg::OnEnChangeAddCarYear)
	ON_EN_CHANGE(IDC_ADD_CAR_LICENSE_PLATE, &CCARrentalUIDlg::OnEnChangeAddCarLicensePlate)
END_MESSAGE_MAP()


// CCARrentalUIDlg message handlers

BOOL CCARrentalUIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCARrentalUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCARrentalUIDlg::OnPaint()
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
HCURSOR CCARrentalUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CAboutDlg::OnBnClickedAddCar()
{
	
	// TODO: Add your control notification handler code here
}

void CCARrentalUIDlg::OnBnClickedAddCar()
{
	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO_ADD_CAR);
	if (pCombo) {
		pCombo->ShowWindow(SW_SHOW);
		pCombo->AddString(_T("Select a Brand"));
		pCombo->AddString(_T("Hyundai"));
		pCombo->AddString(_T("Tata"));
		pCombo->AddString(_T("Mahindra"));
		pCombo->SetCurSel(0);

	}
	
	// TODO: Add your control notification handler code here
}



void CCARrentalUIDlg::OnCbnSelchangeComboAddCar()
{
	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_COMBO_ADD_CAR);
	CString selectedCar;
	int selectedIndex = pCombo->GetCurSel();
	if (selectedIndex != 0) {
		

		pCombo->GetLBText(selectedIndex, selectedCar);
	}
	CComboBox* pCarModelCombo = (CComboBox*)GetDlgItem(IDC_Car_Model);
	if (pCarModelCombo) {
		pCarModelCombo->ShowWindow(SW_SHOW);
		if (selectedCar == "Hyundai") {
			pCarModelCombo->ResetContent();
			pCarModelCombo->AddString(_T("Select a Model"));

			pCarModelCombo->AddString(_T("Creta"));
			pCarModelCombo->AddString(_T("i20"));
			pCarModelCombo->AddString(_T("Kona"));
			pCarModelCombo->SetCurSel(0);


		}
		else if (selectedCar == "Tata") {
			pCarModelCombo->ResetContent();
			pCarModelCombo->AddString(_T("Select a Model"));

			pCarModelCombo->AddString(_T("Nexon"));
			pCarModelCombo->AddString(_T("Harrier"));
			pCarModelCombo->AddString(_T("Safari"));
			pCarModelCombo->SetCurSel(0);
		}

		else if (selectedCar == "Mahindra") {
			pCarModelCombo->ResetContent();
			pCarModelCombo->AddString(_T("Select a Model"));

			pCarModelCombo->AddString(_T("Thar"));
			pCarModelCombo->AddString(_T("XUV700"));
			pCarModelCombo->AddString(_T("Scorpio"));
			pCarModelCombo->SetCurSel(0);

		}
		
		

	}
	
	// TODO: Add your control notification handler code here
}

void CCARrentalUIDlg::OnCbnSelchangeCarModel()
{
	CComboBox* pCarModelCombo = (CComboBox*)GetDlgItem(IDC_Car_Model);
	CString carModel;
	if (pCarModelCombo) {
		int selectedIndex = pCarModelCombo->GetCurSel();
		if (selectedIndex != 0) {
			pCarModelCombo->GetLBText(selectedIndex, carModel);
		}
		
	}
	CEdit* pCarColorEdit = (CEdit*)GetDlgItem(IDC_ADD_CAR_COLOR);

	if (pCarColorEdit) {
		pCarColorEdit->ShowWindow(SW_SHOW);
		SetDlgItemText(IDC_ADD_CAR_COLOR, _T("Enter The color"));

		//pCarColorEdit->SetWindowText(_T("Enter Car Color"));
	}

	CEdit* pCaryearEdit = (CEdit*)GetDlgItem(IDC_ADD_CAR_YEAR);
	if (pCaryearEdit) {
		pCaryearEdit->ShowWindow(SW_SHOW);
		SetDlgItemText(IDC_ADD_CAR_YEAR, _T("Enter Year Of manufacturing"));

	}

	CEdit* pCarLicensePlateEdit = (CEdit*)GetDlgItem(IDC_ADD_CAR_LICENSE_PLATE);
	if (pCarLicensePlateEdit) {
		pCarLicensePlateEdit->ShowWindow(SW_SHOW);
		SetDlgItemText(IDC_ADD_CAR_LICENSE_PLATE, _T("Enter License Plate"));
	}
	// TODO: Add your control notification handler code here
}

void CCARrentalUIDlg::OnEnChangeAddCarColor()
{
	CString carColor;
	GetDlgItemText(IDC_ADD_CAR_COLOR, carColor);
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CCARrentalUIDlg::OnEnChangeAddCarYear()
{
	int carYear;
	carYear = GetDlgItemInt(IDC_ADD_CAR_YEAR);
	std::cout << carYear << std::endl;
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CCARrentalUIDlg::OnEnChangeAddCarLicensePlate()
{	
	CString licensePlate;
	GetDlgItemText(IDC_ADD_CAR_LICENSE_PLATE, licensePlate);
	std::cout << licensePlate.GetString() << std::endl;
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
