#pragma once
#include <afx.h>
#include "Vehicle1.h"

class Ticket1 :
	public CObject
{
	DECLARE_SERIAL(Ticket1)
private:
	static int staticTicketID; // initialized in the cpp file
	int ticketID;
	int price;
	int numberOfSeatsForThisTicket; // you can buy ticket for  multiply people.
	CString lineName;
	int* seatPosition; // array of seat positions
	int seatStartPosition;
	Vehicle1* myVehicle;
	int myVehicleID;
	CString firstName;
	CString lastName;
	CString City;
	CString id;
	void  SetFirstName(CString name) { this->firstName = name; };
	void  SetLastName(CString name) { this->lastName = name; };
	void SetCity(CString name) { this->City = name; };
	void  SetId(CString _id) { this->id = _id; };

public:
	Ticket1();
	Ticket1(CString _firstName, CString _lastName, CString _city, CString _id, Vehicle1* _orderedVehicle, int _price, int _numberOfPassengers, CString _lineName, int _seatPosition);
	~Ticket1() { delete[] seatPosition; };

	//setters:
	void setPrice(int _price) { this->price = _price; };
	void setnumberOfSeatsForThisTicket(int _numberOfPassengers) { this->numberOfSeatsForThisTicket = _numberOfPassengers; };
	void setLineName(CString _lineName) { this->lineName = _lineName; };
	void setSeatPosition(int _startPosition);
	void setVehiclePtr(Vehicle1* insertVehicle) { this->myVehicle = insertVehicle; };
	void setStartSeatPosition(int position) { this->seatStartPosition = position; }

	//getters:
	CString   GetFirstName() { return firstName; };
	CString GetLastName() { return lastName; };
	CString  GetCity() { return City; };
	CString  GetId() { return id; };
	int getPrice() { return this->price; };
	int getTicketID() { return this->ticketID; };
	int getnumberOfSeatsForThisTicket() { return this->numberOfSeatsForThisTicket; };
	CString getLineName() { return this->lineName; };
	int* getSeatPosition() { return this->seatPosition; };
	int getStartSeatPosition() { return this->seatStartPosition; }
	Vehicle1* getVehicle() { return this->myVehicle; };
	int getVehicleID() { return this->myVehicleID; };
	void Serialize(CArchive& archive);
};

