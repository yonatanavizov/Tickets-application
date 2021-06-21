#pragma once


// deleteVehicleDlg dialog

class deleteVehicleDlg : public CDialogEx
{
	DECLARE_DYNAMIC(deleteVehicleDlg)

public:
	deleteVehicleDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~deleteVehicleDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = delete_Vehicle };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int vehicleID;
	afx_msg void OnBnClickedOk();
	CString deleteStatus;
	afx_msg void OnEnChangeEdit2();
};
