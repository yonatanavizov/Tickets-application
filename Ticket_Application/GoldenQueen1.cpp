#include "GoldenQueen1.h"

GoldenQueen1::GoldenQueen1()
{
	this->setFuelCapacity(200000);
	this->setNickName("Golden Queen");
	this->setNumberOfSeats(2000);
	this->setVelocity(43);
	this->setVehicleType(5);
}

IMPLEMENT_SERIAL(GoldenQueen1, CObject, 1)
void GoldenQueen1::Serialize(CArchive& ar)
{
	Sea1::Serialize(ar);
}