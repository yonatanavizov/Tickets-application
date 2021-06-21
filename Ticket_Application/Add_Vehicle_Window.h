#pragma once


// Add_Vehicle_Window dialog

class Add_Vehicle_Window : public CDialogEx
{
	DECLARE_DYNAMIC(Add_Vehicle_Window)

public:
	Add_Vehicle_Window(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Add_Vehicle_Window();


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	int whichVehicleToCreate=0;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = Add_Vehicle };
#endif

	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio7();
};
