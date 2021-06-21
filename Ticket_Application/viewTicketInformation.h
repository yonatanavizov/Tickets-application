#pragma once


// viewTicketInformation dialog

class viewTicketInformation : public CDialogEx
{
	DECLARE_DYNAMIC(viewTicketInformation)

public:
	viewTicketInformation(CWnd* pParent = nullptr);   // standard constructor
	viewTicketInformation(int ticketNumber, CWnd* pParent = nullptr);   // standard constructor
	virtual ~viewTicketInformation();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = viewTicket };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	int thisTicketID;
	CString firstName;
	CString lastName;
	CString passengerID;
	CString vehicleName;
	int vehicleID;
	CString lineName;
	int ticketID;
	int orderPrice;
	int numberOfSeats;
	virtual BOOL OnInitDialog();
public:
	CComboBox seatPositions;
};
