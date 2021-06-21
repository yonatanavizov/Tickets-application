#include "Train1.h"

Train1::Train1()
{
	this->setNickName("Siemens Train");
	this->setVehicleType(3);
	this->setVelocity(150);
	this->setFuelCapacity(500);
	this->setNumberOfWheels(100);
	this->setNumberOfSeats(200);
}

IMPLEMENT_SERIAL(Train1, CObject, 1)
void Train1::Serialize(CArchive& ar)
{
	Ground1::Serialize(ar);
}

