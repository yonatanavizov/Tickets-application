// orderTicket.cpp : implementation file
//

#include "pch.h"
#include "Ticket_Application.h"
#include "orderTicket.h"
#include "afxdialogex.h"

using namespace ::std;

// orderTicket dialog

IMPLEMENT_DYNAMIC(orderTicket, CDialogEx)

orderTicket::orderTicket(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, orderPrice(0)
	, numberOfTicketsChosen(0)
	, emptySeatsChosen(0)
	, selected(_T(""))
	, fName(_T(""))
	, lName(_T(""))
	, city(_T(""))
	, passengerID(_T(""))
	, orderStatus(_T(""))
{

}

orderTicket::orderTicket(int _type, CWnd* pParent) : CDialogEx(IDD_DIALOG3, pParent) 
, ticketType(_type) 
{
	for (int i = 0; i < myVehicleArray.GetCount(); i++) // saves the first vehicle from the type
	{
		if (myVehicleArray[i]->getVehicleType() == _type)
		{
			firstVehicleType = myVehicleArray[i];
			break;
		}
	}

	switch (_type)
	{
	case 1: // Taxi
		_price = 30;
			break;
	case 2: // Bus
		_price = 6;
		break;
	case 3: // Train
		_price = 20;
		break;
	case 4: // 737
		_price = 500;
		break;
	case 5: // Ship
		_price = 700;
		break;
	default:
		_price = 0;
		break;
	}
}

orderTicket::~orderTicket()
{
}

void orderTicket::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT7, _price);
	DDX_Control(pDX, IDC_COMBO3, fromComboBox);
	DDX_Control(pDX, IDC_COMBO4, toDestinations);
	DDX_Text(pDX, IDC_EDIT6, orderPrice);
	DDX_Text(pDX, IDC_EDIT5, numberOfTicketsChosen);
	DDX_Control(pDX, IDC_COMBO1, vehicleList);
	DDX_Text(pDX, IDC_EDIT9, emptySeatsChosen);
	DDX_CBString(pDX, IDC_COMBO1, selected);
	DDX_Text(pDX, IDC_EDIT1, fName);
	DDX_Text(pDX, IDC_EDIT2, lName);
	DDX_Text(pDX, IDC_EDIT3, city);
	DDX_Text(pDX, IDC_EDIT4, passengerID);
	DDX_Text(pDX, IDC_EDIT8, orderStatus);
}


BEGIN_MESSAGE_MAP(orderTicket, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO3, &orderTicket::fromUpdate)
	ON_EN_CHANGE(IDC_EDIT5, &orderTicket::OnEnChangeEdit5)
	ON_CBN_SELCHANGE(IDC_COMBO1, &orderTicket::updateFreeSeats)
	ON_BN_CLICKED(IDOK, &orderTicket::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO4, &orderTicket::toUpdate)
END_MESSAGE_MAP()


// orderTicket message handlers


void orderTicket::fromUpdate()
{
	fromComboBox.GetLBText(fromComboBox.GetCurSel(), fromDestination);
}

void orderTicket::toUpdate()
{
	fromComboBox.GetLBText(toDestinations.GetCurSel(), toDestination);
}

void orderTicket::OnEnChangeEdit5()
{
	UpdateData(true);
	orderPrice = _price * numberOfTicketsChosen;
	UpdateData(false);
}


void orderTicket::updateFreeSeats()
{
	UpdateData(true);
	CString data;
	vehicleList.GetLBText(vehicleList.GetCurSel(), data);
	int chosen =_ttoi(data); 

	for (int i = 0; i < myVehicleArray.GetCount(); i++)
	{
		if (myVehicleArray[i]->getID() == chosen)
		{
			emptySeatsChosen = myVehicleArray[i]->getNumberOfEmptySeats();
			orderForThisVehicle = myVehicleArray[i];
			break;
		}
	}
   UpdateData(false);
}


BOOL orderTicket::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	for (int i = 0; i < firstVehicleType->getNumOfDestinations(); i++) // filling destinations of the vehicle
	{
		CString insert;
		insert = firstVehicleType->getDestinations()[i];
		fromComboBox.InsertString(i, insert);
		toDestinations.InsertString(i, insert);
	}

	int comboPos = 0;
	for (int i = 0; i < myVehicleArray.GetCount(); i++) // filling destinations of the vehicle
	{
		if (firstVehicleType->getVehicleType() == myVehicleArray[i]->getVehicleType())
		{
			int insert;
			insert = myVehicleArray[i]->getID();
			CString convert;
			convert.Format(_T("%d"), insert);
			vehicleList.InsertString(comboPos++, convert);
		}
	}

	orderStatus.Format(_T("Not Ordered Yet"));

	return TRUE;  
}


void orderTicket::OnBnClickedOk()
{
	UpdateData(true);

	if ( (myTicketsArray.GetCount() < 9) && orderForThisVehicle != NULL && (numberOfTicketsChosen <= orderForThisVehicle->getNumberOfEmptySeats())
		&& !(fName.Compare(_T(""))==0) && !(lName.Compare(_T("")) == 0) && !(city.Compare(_T("")) == 0) && !(passengerID.Compare(_T("")) == 0) 
		&& numberOfTicketsChosen > 0)
	{
		CString lineName =_T("From ") + fromDestination + _T(" to ") + toDestination; 
	
		dummyTicket = new Ticket1(fName , lName, city, passengerID, orderForThisVehicle, orderPrice, numberOfTicketsChosen , lineName ,
			(orderForThisVehicle->getNumberOfSeats() - orderForThisVehicle->getNumberOfEmptySeats()) );

		myTicketsArray.Add(dummyTicket);
		orderStatus.Format(_T("Order Sent."));
		orderForThisVehicle->updateEmptySeats(numberOfTicketsChosen);

		dummyTicket = NULL;
	}
	else // can not order more tickets
	{
		orderStatus.Format(_T("Order Not Sent."));
	}
	ticketsDlg.updateInformation();
	UpdateData(false);
}



