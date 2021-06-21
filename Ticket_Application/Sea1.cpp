#include "Sea1.h"

Sea1::Sea1()
{
	this->setDestinations();
	Vehicle1::setType(3);
}

void Sea1::setDestinations()
{
	this->setNumOfDestinations(6);
	CString* destinationArray = new CString[6];
	destinationArray[0] = "Greece";
	destinationArray[1] = "Italy";
	destinationArray[2] = "United States";
	destinationArray[3] = "Portugal";
	destinationArray[4] = "Cyprus";
	destinationArray[5] = "Spain";

	this->setDestinationsArray(destinationArray);
}
