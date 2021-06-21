#pragma once
#include "Ticket1.h"

// orderTicket dialog

class orderTicket : public CDialogEx
{
	DECLARE_DYNAMIC(orderTicket)

public:
	orderTicket(CWnd* pParent = nullptr);   // standard constructor
	orderTicket(int _type, CWnd* pParent = nullptr);   // standard constructor
	virtual ~orderTicket();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

private:
	int ticketType; // for which vehicle the ticket is ordered for
	Ticket1 thisTicket;
	Vehicle1* firstVehicleType;
	

	DECLARE_MESSAGE_MAP()
public:
	int _price;
	CString* _array;
	afx_msg void fromUpdate();
	CComboBox fromComboBox;
	CComboBox toDestinations;
	int orderPrice;
	int numberOfTicketsChosen;
	afx_msg void OnEnChangeEdit5();
	CComboBox vehicleList;
	int emptySeatsChosen;
	afx_msg void updateFreeSeats();
	CString selected;
	virtual BOOL OnInitDialog();
	Vehicle1* orderForThisVehicle;
	afx_msg void OnBnClickedOk();
	CString fName;
	CString lName;
	CString city;
	CString passengerID;
	CString fromDestination;
	CString toDestination;
	afx_msg void toUpdate();
	CString orderStatus;
};
