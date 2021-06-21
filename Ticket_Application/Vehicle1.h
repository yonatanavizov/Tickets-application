#pragma once
#include <afx.h>
#include <iostream>

using namespace std;

class Vehicle1 :
	public CObject
{
private:
	static int id; // initialized in the cpp file
	int this_id;
	int type; // aerial or ground or sea
	int vehicleType; // |1 Taxi |2 Bus |3 Train |4 Boeing 737 |5 Golden Queen
	int numberOfSeats;
	CString nickName;
	CString* destinations; // array of destinations
	int maxVelocity;
	double fuelCapacity; // can be either liquid fuel or Battery
	int numOfDestinations;
	int numOfEmptySeats;
	void setNumOfEmptySeats(int _emptySeats) { this->numOfEmptySeats = _emptySeats; };


protected:
	//--setters
	void setType(int _type) { this->type = _type; };
	void setVehicleType(int _Vtype) { this->vehicleType = _Vtype; };
	void setNumberOfSeats(int _numberOfSeats) { this->numberOfSeats = _numberOfSeats; this->setNumOfEmptySeats(_numberOfSeats); }
	void setNickName(CString _nickName) { this->nickName = _nickName; };
	void setDestinationsArray(CString* _array) { this->destinations = _array; }; // will be implemented in each class
	void setVelocity(int _velocity) { this->maxVelocity = _velocity; };
	void setFuelCapacity(double _fuelCapacity) { this->fuelCapacity = _fuelCapacity; };
	void setNumOfDestinations(int _amount) { this->numOfDestinations = _amount; };

	//-- other functions
	int whoFastest(string destinaion1, string destination2, Vehicle1& second); // add to vehicle array and show the user the fastest vehicle to get to the destination
	virtual double fuelConsumption() { return 1.0; };//per 100 km, how "green" and enviuorment friendly is the vehicle
	virtual void setDestinations() {}; // will be implemented in each class

public:
	//--constructors
	Vehicle1();
	//---getters
	int getID()const { return this_id; };
	int getType()const { return this->type; };
	int getVehicleType()const { return this->vehicleType; };
	int getNumberOfSeats()const { return this->numberOfSeats; };
	int getNumberOfEmptySeats()const { return this->numOfEmptySeats; };
	CString getNickName()const { return this->nickName; };
	CString* getDestinations()const { return this->destinations; };
	int getVelocity() const { return this->maxVelocity; };
	double getFuelCapacity()const { return this->fuelCapacity; };
	int getNumOfDestinations() { return this->numOfDestinations; };
	virtual CString print();
	bool isFull();
	bool updateEmptySeats(int _numberOfOrderedTickets);
	virtual void Serialize(CArchive& archive)
	{
		CObject::Serialize(archive);

		if (archive.IsStoring()) {
			archive << id << this_id << type << vehicleType << numberOfSeats << nickName
				 << maxVelocity << fuelCapacity << numOfDestinations << numOfEmptySeats;
		}
		else {
			archive >> id >> this_id >> type >> vehicleType >> numberOfSeats >> nickName
				 >> maxVelocity >> fuelCapacity >> numOfDestinations >> numOfEmptySeats;
		}
	};

	//--distructor
	virtual ~Vehicle1() { delete[] destinations; };
};

