#include "Vehicle1.h"

int Vehicle1::id = 0; //initialize the id

Vehicle1::Vehicle1()
{
	this->id++;
	this->this_id = id;
	this->type = 0;
	this->numberOfSeats = 0;
	this->nickName = "Empty Vehicle";
	this->destinations = NULL;
	this->maxVelocity = 0;
	this->fuelCapacity = 0;
	this->numOfEmptySeats = 0;
}

CString Vehicle1::print()
{

	CString returnThis = "This Vehicle name is : " + this->getNickName();
	return returnThis;
}

bool Vehicle1::isFull()
{
	if (this->getNumberOfEmptySeats() == 0)
		return true;

	return false;
}

bool Vehicle1::updateEmptySeats(int _numberOfOrderedTickets)
{
	if ((this->numOfEmptySeats - _numberOfOrderedTickets) < 0)
		return false;

	this->setNumOfEmptySeats(numOfEmptySeats - _numberOfOrderedTickets);
	return true;
}
