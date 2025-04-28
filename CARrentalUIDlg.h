
// CARrentalUIDlg.h : header file
//

#pragma once


// CCARrentalUIDlg dialog
class CCARrentalUIDlg : public CDialogEx
{
// Construction
public:
	CCARrentalUIDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CARRENTALUI_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAddCar();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnCbnSelchangeComboAddCar();
	afx_msg void OnCbnSelchangeCarModel();
	afx_msg void OnEnChangeAddCarColor();
	afx_msg void OnEnChangeAddCarYear();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeAddCarLicensePlate();
};
