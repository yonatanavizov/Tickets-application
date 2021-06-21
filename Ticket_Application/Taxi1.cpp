#include "Taxi1.h"

Taxi1::Taxi1()
{
	this->setNickName("Mercedes Taxi");
	this->setFuelCapacity(60);
	this->setNumberOfSeats(4);
	this->setVelocity(220);
	this->setVehicleType(1);
}

IMPLEMENT_SERIAL(Taxi1, CObject, 1)
void Taxi1::Serialize(CArchive& ar)
{
	Ground1::Serialize(ar);
}
