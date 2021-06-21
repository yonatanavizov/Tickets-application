#pragma once

// ExistingVehicles dialog

class ExistingVehicles : public CDialogEx
{
	DECLARE_DYNAMIC(ExistingVehicles)

public:
	ExistingVehicles(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ExistingVehicles();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton19();
};
