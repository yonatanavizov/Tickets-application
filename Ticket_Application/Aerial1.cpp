#include "Aerial1.h"

void Aerial1::setDestinations()
{
	this->setNumOfDestinations(7);
	CString* destinationArray = new CString[7];
	destinationArray[0] = "Spain";
	destinationArray[1] = "England";
	destinationArray[2] = "United States";
	destinationArray[3] = "Canada";
	destinationArray[4] = "Mexico";
	destinationArray[5] = "India";
	destinationArray[6] = "Japan";

	this->setDestinationsArray(destinationArray);
}


Aerial1::Aerial1()
{
	this->engineJetPropelor = 0;
	this->setDestinations();
	Vehicle1::setType(2);
}
