
// Ticket_ApplicationDlg.h : header file
//

#pragma once
#include <fstream>

// CTicketApplicationDlg dialog
class CTicketApplicationDlg : public CDialogEx
{
// Construction
public:
	CTicketApplicationDlg(CWnd* pParent = nullptr);	

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TICKET_APPLICATION_DIALOG };
#endif

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
	afx_msg void OnBnClickedOk3();
	afx_msg void OnBnClickedButton2();

	DECLARE_EVENTSINK_MAP()
	void ClickTickets();
	void ClickVehicles();
	afx_msg void OnBnClickedButton1();
};
