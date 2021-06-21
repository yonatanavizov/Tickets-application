#include "Passenger.h"

Passenger::Passenger()
{
	this->SetFirstName("New Passenger");
	this->SetLastName("Last Name");
	this->SetCity("n/a");
	this->SetId(000000000);
	this->SetYearBirth(1990);
	this->SetMonthBirth(01);
	this->SetDayBirth(01);
}

Passenger::Passenger(string _firstName, string _lastName, string _city, int _id, int _day, int _month, int _year)
{
	this->SetFirstName(_firstName);
	this->SetLastName(_lastName);
	this->SetCity(_city);
	this->SetId(_id);
	this->SetDayBirth(_day);
	this->SetMonthBirth(_month);
	this->SetYearBirth(_year);
}
