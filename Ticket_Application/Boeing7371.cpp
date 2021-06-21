#include "Boeing7371.h"


Boeing7371::Boeing7371()
{
	this->setNickName("Boeing 737");
	this->setNumberOfSeats(120);
	this->setFuelCapacity(26000.00);
	this->setVelocity(583);//per houre
	this->setVehicleType(4);
}

IMPLEMENT_SERIAL(Boeing7371, CObject, 1)
void Boeing7371::Serialize(CArchive& ar)
{
	Aerial1::Serialize(ar);
}