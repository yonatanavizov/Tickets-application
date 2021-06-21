#pragma once
#include "Vehicle1.h"
#include "viewTicketInformation.h"


// MyTickets2 dialog

class MyTickets2 : public CDialogEx
{
	DECLARE_DYNAMIC(MyTickets2)

public:
	MyTickets2(CWnd* pParent = nullptr);   // standard constructor
	//MyTickets2(Vehicle** _ptr, CWnd* pParent = nullptr) : CDialogEx(IDD_DIALOG2, pParent ) { this->ptr = _ptr; };  // standard constructor
	virtual ~MyTickets2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	DECLARE_EVENTSINK_MAP()
	void ClickImage1();
	void Clickisrarail();
	void ClickEgged();
	void Clickelal();
	void Clickgettaxi();
	void Clickmano();

private:
	bool isExist(int _type);
	int chosenTicketPosition;
public:
	virtual BOOL OnInitDialog();
	int ticketID1;
	int ticketID2;
	int ticketID3;
	int ticketID4;
	int ticketID5;
	int ticketID6;
	int ticketID7;
	int ticketID8;
	int ticketID9;
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedRadio25();
	afx_msg void OnBnClickedRadio26();
	afx_msg void OnBnClickedRadio27();
	afx_msg void openTicketInformation();
	void updateInformation();
	afx_msg void deleteTicket();
};
