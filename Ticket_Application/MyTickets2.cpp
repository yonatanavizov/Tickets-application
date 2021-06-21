
// MyTickets2.cpp : implementation file
//


#include "pch.h"
#include "Ticket_Application.h"
#include "MyTickets2.h"
#include "afxdialogex.h"
#include "Ticket1.h"
#include "orderTicket.h"


// MyTickets2 dialog

IMPLEMENT_DYNAMIC(MyTickets2, CDialogEx)

MyTickets2::MyTickets2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, ticketID1(0)
	, ticketID2(0)
	, ticketID3(0)
	, ticketID4(0)
	, ticketID5(0)
	, ticketID6(0)
	, ticketID7(0)
	, ticketID8(0)
	, ticketID9(0)
	, chosenTicketPosition(10)
{
}

MyTickets2::~MyTickets2()
{
}

void MyTickets2::DoDataExchange(CDataExchange* pDX)
{
	int numberOfTick = myTicketsArray.GetCount();
	DDX_Text(pDX, IDC_EDIT1, numberOfTick);
	DDX_Text(pDX, IDC_EDIT2, ticketID1);
	DDX_Text(pDX, IDC_EDIT3, ticketID2);
	DDX_Text(pDX, IDC_EDIT4, ticketID3);
	DDX_Text(pDX, IDC_EDIT5, ticketID4);
	DDX_Text(pDX, IDC_EDIT24, ticketID5);
	DDX_Text(pDX, IDC_EDIT25, ticketID6);
	DDX_Text(pDX, IDC_EDIT26, ticketID7);
	DDX_Text(pDX, IDC_EDIT45, ticketID8);
	DDX_Text(pDX, IDC_EDIT46, ticketID9);
}


BEGIN_MESSAGE_MAP(MyTickets2, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO2, &MyTickets2::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &MyTickets2::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &MyTickets2::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &MyTickets2::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &MyTickets2::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO7, &MyTickets2::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO25, &MyTickets2::OnBnClickedRadio25)
	ON_BN_CLICKED(IDC_RADIO26, &MyTickets2::OnBnClickedRadio26)
	ON_BN_CLICKED(IDC_RADIO27, &MyTickets2::OnBnClickedRadio27)
	ON_BN_CLICKED(IDC_BUTTON1, &MyTickets2::openTicketInformation)
	ON_BN_CLICKED(IDC_BUTTON2, &MyTickets2::deleteTicket)
END_MESSAGE_MAP()


// MyTickets2 message handlers

BEGIN_EVENTSINK_MAP(MyTickets2, CDialogEx)
	ON_EVENT(MyTickets2, IDC_IMAGE1, DISPID_CLICK, MyTickets2::ClickImage1, VTS_NONE)
	ON_EVENT(MyTickets2, israrail, DISPID_CLICK, MyTickets2::Clickisrarail, VTS_NONE)
	ON_EVENT(MyTickets2, Egged, DISPID_CLICK, MyTickets2::ClickEgged, VTS_NONE)
	ON_EVENT(MyTickets2, elal, DISPID_CLICK, MyTickets2::Clickelal, VTS_NONE)
	ON_EVENT(MyTickets2, getTaxi, DISPID_CLICK, MyTickets2::Clickgettaxi, VTS_NONE)
	ON_EVENT(MyTickets2, mano, DISPID_CLICK, MyTickets2::Clickmano, VTS_NONE)
END_EVENTSINK_MAP()


void MyTickets2::ClickImage1()
{
	orderTicket ticket1;
	ticket1.DoModal();
}


void MyTickets2::Clickisrarail()
{
	if (isExist(3))
	{
		orderTicket newTicket( 3,nullptr);
		newTicket.DoModal();
	}
}


void MyTickets2::ClickEgged()
{
	if (isExist(2))
	{
		orderTicket newTicket(2, nullptr);
		newTicket.DoModal();
	}
}


void MyTickets2::Clickelal()
{
	if (isExist(4))
	{
		orderTicket newTicket(4, nullptr);
		newTicket.DoModal();
	}
}


void MyTickets2::Clickgettaxi()
{
	if (isExist(1))
	{
		orderTicket newTicket(1, nullptr);
		newTicket.DoModal();
	}
}


void MyTickets2::Clickmano()
{
	if (isExist(5))
	{
		orderTicket newTicket(5, nullptr);
		newTicket.DoModal();
	}
}

bool MyTickets2::isExist(int _type)
{
	for (int i = 0; i < myVehicleArray.GetCount(); i++)
	{
		if (myVehicleArray[i]->getVehicleType() == _type)
			return true;
	}

	return false;
}


BOOL MyTickets2::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	updateInformation();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void MyTickets2::OnBnClickedRadio2()
{
	chosenTicketPosition = 1;
}


void MyTickets2::OnBnClickedRadio3()
{
	chosenTicketPosition = 2;
}


void MyTickets2::OnBnClickedRadio4()
{
	chosenTicketPosition = 3;
}


void MyTickets2::OnBnClickedRadio5()
{
	chosenTicketPosition = 4;
}


void MyTickets2::OnBnClickedRadio6()
{
	chosenTicketPosition = 5;
}


void MyTickets2::OnBnClickedRadio7()
{
	chosenTicketPosition = 6;
}


void MyTickets2::OnBnClickedRadio25()
{
	chosenTicketPosition = 7;
}


void MyTickets2::OnBnClickedRadio26()
{
	chosenTicketPosition = 8;
}


void MyTickets2::OnBnClickedRadio27()
{
	chosenTicketPosition = 9;
}


void MyTickets2::openTicketInformation()
{
	if (chosenTicketPosition > myTicketsArray.GetCount()) // check if ticket exist
	{
		TRACE("\nTicket not Exist\n");

	}
	else // you can open the ticket details
	{
		viewTicketInformation ticketDlg (chosenTicketPosition - 1, nullptr);
		ticketDlg.DoModal();
	}
}

void MyTickets2::deleteTicket()
{
	if (chosenTicketPosition > myTicketsArray.GetCount()) // check if ticket exist
	{
		TRACE("\nTicket not Exist\n");

	}
	else // you can open the ticket details
	{
		dummyTicket = myTicketsArray[chosenTicketPosition - 1];
		int numberOfTicketsDeleted = dummyTicket->getnumberOfSeatsForThisTicket();
		int vehicleDeletedTicket = dummyTicket->getVehicle()->getID(); // remember for fixing ticket seat postions
		dummyTicket->getVehicle()->updateEmptySeats(-dummyTicket->getnumberOfSeatsForThisTicket());

		delete dummyTicket;
		myTicketsArray.RemoveAt(chosenTicketPosition - 1);


		//move original ticket array left
		int ticketPosition;

		for (ticketPosition = chosenTicketPosition - 1; ticketPosition < myTicketsArray.GetCount(); ticketPosition++) // update the sitting positons
		{
			if (myTicketsArray[ticketPosition]->getVehicle()->getID() == vehicleDeletedTicket) 
			{
				myTicketsArray[ticketPosition]->setStartSeatPosition(myTicketsArray[ticketPosition]->getStartSeatPosition() - numberOfTicketsDeleted);
				myTicketsArray[ticketPosition]->setSeatPosition(myTicketsArray[ticketPosition]->getStartSeatPosition());
			}
		}


		//update window view

		int** ticketIdArray = new int* [9];
		ticketIdArray[0] = &ticketID1;
		ticketIdArray[1] = &ticketID2;
		ticketIdArray[2] = &ticketID3;
		ticketIdArray[3] = &ticketID4;
		ticketIdArray[4] = &ticketID5;
		ticketIdArray[5] = &ticketID6;
		ticketIdArray[6] = &ticketID7;
		ticketIdArray[7] = &ticketID8;
		ticketIdArray[8] = &ticketID9;

		int i;
		for (i = chosenTicketPosition - 1; i < MAX_NUMBER_OF_TICKETS-1 ; i++)
		{
			*ticketIdArray[i] = *ticketIdArray[i + 1];
		}

		*ticketIdArray[i] = 0;

		UpdateData(false);
		delete[] ticketIdArray;
	}
}

void MyTickets2::updateInformation()
{
	int** ticketIdArray = new int* [9];
	ticketIdArray[0] = &ticketID1;
	ticketIdArray[1] = &ticketID2;
	ticketIdArray[2] = &ticketID3;
	ticketIdArray[3] = &ticketID4;
	ticketIdArray[4] = &ticketID5;
	ticketIdArray[5] = &ticketID6;
	ticketIdArray[6] = &ticketID7;
	ticketIdArray[7] = &ticketID8;
	ticketIdArray[8] = &ticketID9;

	for (int i = 0; i < myTicketsArray.GetCount(); i++)
	{
		*ticketIdArray[i] = myTicketsArray[i]->getTicketID();
	}

	UpdateData(false);
	delete[] ticketIdArray;
}
