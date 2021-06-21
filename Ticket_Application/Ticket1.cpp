#include "Ticket1.h"
int Ticket1::staticTicketID = 0; //initialize the id

Ticket1::Ticket1()
{
	this->ticketID = staticTicketID;
	this->SetFirstName("New Passenger");
	this->SetLastName("Last Name");
	this->SetCity("n/a");
	this->SetId("000000000");
	this->price = 0;
	this->numberOfSeatsForThisTicket = 0;
	this->lineName = "No Ticket";
	this->setSeatPosition(0);
	this->myVehicle = NULL;
	this->myVehicleID = 0;
	this->seatPosition[numberOfSeatsForThisTicket];
	this->setStartSeatPosition(0);
}


Ticket1::Ticket1(CString _firstName, CString _lastName, CString _city, CString _id, Vehicle1* _orderedVehicle, int _price, int _numberOfPassengers, CString _lineName, int _seatPosition)
{
	staticTicketID++;
	this->ticketID = staticTicketID;
	this->SetFirstName(_firstName);
	this->SetLastName(_lastName);
	this->SetCity(_city);
	this->SetId(_id);
	this->lineName = _lineName;
	this->numberOfSeatsForThisTicket = _numberOfPassengers;
	this->setStartSeatPosition(_seatPosition);
	this->setSeatPosition(_seatPosition);
	this->price = _price;
	this->myVehicle = _orderedVehicle;
	this->myVehicleID = myVehicle->getID();
}

void Ticket1::setSeatPosition(int _startPosition)
{
	if (seatPosition == NULL) // in case we update seats after ticket delete for same vehicle
	{
		delete[] seatPosition;
	}

	seatPosition = new int[numberOfSeatsForThisTicket];

	for (int i = 0; i < numberOfSeatsForThisTicket; i++)
	{
		seatPosition[i] = _startPosition + i;
	}
}


IMPLEMENT_SERIAL(Ticket1, CObject, 1)
void Ticket1::Serialize(CArchive& archive)
{
	{
		CObject::Serialize(archive);

		if (archive.IsStoring()) {
			archive << staticTicketID << ticketID << price << numberOfSeatsForThisTicket << lineName
				<< seatStartPosition << myVehicleID << firstName << lastName << City << id;
		}
		else {
			archive >> staticTicketID >> ticketID >> price >> numberOfSeatsForThisTicket >> lineName
				>> seatStartPosition >> myVehicleID >> firstName >> lastName >> City >> id;
		}
	}
}
