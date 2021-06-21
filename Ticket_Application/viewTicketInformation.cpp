// viewTicketInformation.cpp : implementation file
//

#include "pch.h"
#include "Ticket_Application.h"
#include "viewTicketInformation.h"
#include "afxdialogex.h"


// viewTicketInformation dialog

IMPLEMENT_DYNAMIC(viewTicketInformation, CDialogEx)


viewTicketInformation::viewTicketInformation(CWnd* pParent /*=nullptr*/)
	: CDialogEx(viewTicket, pParent)
	, firstName(_T(""))
	, lastName(_T(""))
	, passengerID(_T(""))
	, vehicleName(_T(""))
	, vehicleID(0)
	, lineName(_T(""))
	, ticketID(0)
	, orderPrice(0)
	, numberOfSeats(0)
{

}

viewTicketInformation::viewTicketInformation(int ticketNumber, CWnd* pParent /*=nullptr*/)
	: CDialogEx(viewTicket, pParent) , thisTicketID(ticketNumber)
{
}


viewTicketInformation::~viewTicketInformation()
{
}

void viewTicketInformation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT46, firstName);
	DDX_Text(pDX, IDC_EDIT26, lastName);
	DDX_Text(pDX, IDC_EDIT7, passengerID);
	DDX_Text(pDX, IDC_EDIT24, vehicleName);
	DDX_Text(pDX, IDC_EDIT5, vehicleID);
	DDX_Text(pDX, IDC_EDIT1, lineName);
	DDX_Text(pDX, IDC_EDIT47, ticketID);
	DDX_Text(pDX, IDC_EDIT48, orderPrice);
	DDX_Text(pDX, IDC_EDIT49, numberOfSeats);
	DDX_Control(pDX, IDC_COMBO1, seatPositions);
}


BEGIN_MESSAGE_MAP(viewTicketInformation, CDialogEx)
END_MESSAGE_MAP()


// viewTicketInformation message handlers


BOOL viewTicketInformation::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//passenger details:
	firstName.Format( myTicketsArray[thisTicketID]->GetFirstName());
	lastName.Format(myTicketsArray[thisTicketID]->GetLastName());
	passengerID.Format(myTicketsArray[thisTicketID]->GetId());

	//vehicle details:
	vehicleName.Format(myTicketsArray[thisTicketID]->getVehicle()->getNickName());
	vehicleID = myTicketsArray[thisTicketID]->getVehicleID();
	lineName.Format(myTicketsArray[thisTicketID]->getLineName());
	ticketID = myTicketsArray[thisTicketID]->getTicketID();
	orderPrice = myTicketsArray[thisTicketID]->getPrice();
	numberOfSeats = myTicketsArray[thisTicketID]->getnumberOfSeatsForThisTicket();

	CString position;
	for (int i = 0; i < myTicketsArray[thisTicketID]->getnumberOfSeatsForThisTicket(); i++)
	{
		int positionNum = (myTicketsArray[thisTicketID]->getSeatPosition()[i]+1);
		position.Format(_T("%d"), positionNum);
		seatPositions.AddString(position);
	}

	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
