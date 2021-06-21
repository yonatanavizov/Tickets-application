#include "MAN_NL1.h"

MAN_NL1::MAN_NL1()
{
	this->setNumberOfWheels(8);
	this->setNumberOfSeats(40);
	this->setNickName("Egged MAN NL Bus");
	this->setVelocity(160);
	this->setFuelCapacity(100);
	this->setVehicleType(2);
}

IMPLEMENT_SERIAL(MAN_NL1, CObject, 1)
void MAN_NL1::Serialize(CArchive& ar)
{
	Ground1::Serialize(ar);
}