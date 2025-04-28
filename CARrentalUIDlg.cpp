
// CARrentalUIDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CARrentalUI.h"
#include "CARrentalUIDlg.h"
#include "afxdialogex.h"
#include "rentalService.h"
#include "Car.h"
#include "Customer.h"


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
	DDX_Control(pDX, IDC_Car_Model, m_CarModelCombo);
	DDX_Control(pDX, IDC_COMBO_ADD_CAR, m_CarBrandCombo);
	DDX_Control(pDX, IDC_ADD_CAR_COLOR, m_CarColorEdit);
	DDX_Control(pDX, IDC_ADD_CAR_YEAR, m_CarYearEdit);
	DDX_Control(pDX, IDC_ADD_CAR_LICENSE_PLATE, m_CarLicensePlateEdit);
	DDX_Control(pDX, IDC_ADD_CAR_SUBMIT, m_SubmitButton);
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
	ON_BN_CLICKED(IDC_ADD_CAR_SUBMIT, &CCARrentalUIDlg::OnBnClickedAddCarSubmit)
	ON_EN_KILLFOCUS(IDC_ADD_CAR_LICENSE_PLATE, &CCARrentalUIDlg::OnEnKillfocusAddCarLicensePlate)
	ON_EN_SETFOCUS(IDC_ADD_CAR_LICENSE_PLATE, &CCARrentalUIDlg::OnEnSetfocusAddCarLicensePlate)
	ON_EN_KILLFOCUS(IDC_ADD_CAR_YEAR, &CCARrentalUIDlg::OnEnKillfocusAddCarYear)
	ON_EN_SETFOCUS(IDC_ADD_CAR_YEAR, &CCARrentalUIDlg::OnEnSetfocusAddCarYear)
	ON_EN_KILLFOCUS(IDC_ADD_CAR_COLOR, &CCARrentalUIDlg::OnEnKillfocusAddCarColor)
	ON_EN_SETFOCUS(IDC_ADD_CAR_COLOR, &CCARrentalUIDlg::OnEnSetfocusAddCarColor)
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
	CString selectedCar;
	int selectedIndex = m_CarBrandCombo.GetCurSel();
	if (selectedIndex != 0) {
		

		m_CarBrandCombo.GetLBText(selectedIndex, selectedCar);
	}
	if (m_CarModelCombo) {
		m_CarModelCombo.ShowWindow(SW_SHOW);
		if (selectedCar == "Hyundai") {
			m_CarModelCombo.ResetContent();
			m_CarModelCombo.AddString(_T("Select a Model"));

			m_CarModelCombo.AddString(_T("Creta"));
			m_CarModelCombo.AddString(_T("i20"));
			m_CarModelCombo.AddString(_T("Kona"));
			m_CarModelCombo.SetCurSel(0);


		}
		else if (selectedCar == "Tata") {
			m_CarModelCombo.ResetContent();
			m_CarModelCombo.AddString(_T("Select a Model"));

			m_CarModelCombo.AddString(_T("Nexon"));
			m_CarModelCombo.AddString(_T("Harrier"));
			m_CarModelCombo.AddString(_T("Safari"));
			m_CarModelCombo.SetCurSel(0);
		}

		else if (selectedCar == "Mahindra") {
			m_CarModelCombo.ResetContent();
			m_CarModelCombo.AddString(_T("Select a Model"));

			m_CarModelCombo.AddString(_T("Thar"));
			m_CarModelCombo.AddString(_T("XUV700"));
			m_CarModelCombo.AddString(_T("Scorpio"));
			m_CarModelCombo.SetCurSel(0);

		}
		
		

	}
	
	// TODO: Add your control notification handler code here
}

void CCARrentalUIDlg::OnCbnSelchangeCarModel()
{
	CString carModel;
	if (m_CarModelCombo) {
		int selectedIndex = m_CarModelCombo.GetCurSel();
		if (selectedIndex != 0) {
			m_CarModelCombo.GetLBText(selectedIndex, carModel);
		}
		
	}

	if (m_CarColorEdit) {
		m_CarColorEdit.ShowWindow(SW_SHOW);
		SetDlgItemText(IDC_ADD_CAR_COLOR, _T("Enter The color"));

		//m_CarColorEdit.SetWindowText(_T("Enter Car Color"));
	}

	if (m_CarYearEdit) {
		m_CarYearEdit.ShowWindow(SW_SHOW);
		SetDlgItemText(IDC_ADD_CAR_YEAR, _T("Enter Year Of manufacturing"));

	}

	if (m_CarLicensePlateEdit) {
		m_CarLicensePlateEdit.ShowWindow(SW_SHOW);
		SetDlgItemText(IDC_ADD_CAR_LICENSE_PLATE, _T("Enter License Plate"));
	}

	if (m_SubmitButton) {
		m_SubmitButton.ShowWindow(SW_SHOW);
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

#include <string> // Include this header for std::wstring and std::string  
#include <atlconv.h> // Include this header for ATL conversion macros  

void CCARrentalUIDlg::OnBnClickedAddCarSubmit()  
{  
   CString carModel;  
   int selectedIndex = m_CarModelCombo.GetCurSel();  
   m_CarModelCombo.GetLBText(selectedIndex, carModel);  

   CString carBrand;  
   selectedIndex = m_CarBrandCombo.GetCurSel();  
   m_CarBrandCombo.GetLBText(selectedIndex, carBrand);  

   CString carColor;  
   m_CarColorEdit.GetWindowText(carColor);  

   CString carYear;  
   m_CarYearEdit.GetWindowText(carYear);  

   CString carLicensePlate;  
   m_CarLicensePlateEdit.GetWindowText(carLicensePlate);  

   CTime currentTime = CTime::GetCurrentTime();

   CString strDate;
   strDate = currentTime.Format(_T("%d-%m-%Y"));
   // Convert CString (wide string) to std::string (narrow string)  
   std::string carModelStr = CW2A(carModel.GetString());  
   std::string carBrandStr = CW2A(carBrand.GetString());  
   std::string carColorStr = CW2A(carColor.GetString());  
   std::string carLicensePlateStr = CW2A(carLicensePlate.GetString());  
   std::string strDateStr = CW2A(carLicensePlate.GetString());
   rentalService* rentalServiceObj = new rentalService();  
   rentalServiceObj->addCar(carModelStr, carLicensePlateStr, strDateStr, _ttoi(carYear), carColorStr, carBrandStr);
	
  // m_CarLicensePlateEdit.
}

void CCARrentalUIDlg::OnEnKillfocusAddCarLicensePlate()
{
	CString text;

	if (text == "") {
		m_CarLicensePlateEdit.SetWindowText(_T("Enter License Plate"));
	}
	
	// TODO: Add your control notification handler code here
}

void CCARrentalUIDlg::OnEnSetfocusAddCarLicensePlate()
{
	CString text;
	m_CarLicensePlateEdit.GetWindowText(text);
	if (text == "ENTER LICENSE PLATE") {
		m_CarLicensePlateEdit.SetWindowText(_T(""));
	}
	// TODO: Add your control notification handler code here
}

void CCARrentalUIDlg::OnEnKillfocusAddCarYear()
{	
	CString text;
	m_CarYearEdit.GetWindowText(text);
	if (text == "") {
		m_CarYearEdit.SetWindowText(_T("Enter Year Of manufacturing"));
	}
	// TODO: Add your control notification handler code here
}

void CCARrentalUIDlg::OnEnSetfocusAddCarYear()
{	
	CString text;
	m_CarYearEdit.GetWindowText(text);
	if (text == "Enter Year Of manufacturing") {
		m_CarYearEdit.SetWindowText(_T(""));
	}
	// TODO: Add your control notification handler code here
}

void CCARrentalUIDlg::OnEnKillfocusAddCarColor()
{	
	CString text;
	m_CarColorEdit.GetWindowText(text);
	if (text == "") {
		m_CarColorEdit.SetWindowText(_T("Enter The color"));
	}

	// TODO: Add your control notification handler code here
}

void CCARrentalUIDlg::OnEnSetfocusAddCarColor()
{	
	CString text;
	m_CarColorEdit.GetWindowText(text);
	if (text == "Enter The color") {
		m_CarColorEdit.SetWindowText(_T(""));
	}

	// TODO: Add your control notification handler code here
}
