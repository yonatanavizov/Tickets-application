#include "Ground1.h"

Ground1::Ground1()
{
	this->setDestinations();
	this->numberOfWheels = 4;
	Vehicle1::setType(1);
}

void Ground1::setDestinations()
{
	this->setNumOfDestinations(10);
	CString* destinationArray = new CString[10];
	destinationArray[0] = "Tel-Aviv";
	destinationArray[1] = "Haifa";
	destinationArray[2] = "Rishon Le Tsion";
	destinationArray[3] = "Hod Hasharon";
	destinationArray[4] = "Rehovot";
	destinationArray[5] = "Beer Sheva";
	destinationArray[6] = "Haifa";
	destinationArray[7] = "Rosh Ha'ain";
	destinationArray[8] = "Yehud";
	destinationArray[9] = "Dimona";

	this->setDestinationsArray(destinationArray);
}


